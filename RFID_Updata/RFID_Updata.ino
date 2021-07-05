/*
RFID 扣款/儲值
每次感應扣款 30 元
扣款成功要顯示 "ok" + 最新餘額 $
若不足要顯示 not enough
*/
#include <SPI.h>
#include <RFID.h>
#define RST_PIN 9
#define SDA_PIN 10
#define BUZEER_PIN 8

RFID rfid(SDA_PIN, RST_PIN);

// 驗證資料(block id: 11)
unsigned char keyA[16] {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xff, 0x07, 0x80, 0x69, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
// 寫入資料 $100 (block id: 9)
unsigned char readData[16];

int key_blockId = 19;
int data_blockId = 17;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  Serial.println("Ready");
}

void loop() {
  if (rfid.isCard() && rfid.readCardSerial()) { // 偵測到卡
    tone(BUZEER_PIN, 976, 200);
    // 讀取卡片id
    Serial.println("Card found");
    String cardId = ""; // 卡片 id
    for (int i = 0; i < 5; i++) {
      //Serial.print(rfid.serNum[i], HEX);
      //Serial.print(", ");
      cardId += String(rfid.serNum[i], HEX); // 組合前5個id內容
    }
    Serial.print("cardId: ");
    Serial.println(cardId);
    // 回傳卡片容量
    int card_size = rfid.SelectTag(rfid.serNum);
    Serial.print("Card size: ");
    Serial.print(card_size);
    Serial.println("K bits");
  }
  //--------------------------------------------------------
  // 寫入 100
  // 授權驗證
  unsigned char status = rfid.auth(PICC_AUTHENT1A, key_blockId, keyA, rfid.serNum);
  if (status == MI_OK) {
    Serial.println("Auth pass");
    status = rfid.read(data_blockId, readData);
    if (status == MI_OK) {
      if((readData[15]-30) > 0){
        readData[15] = readData[15]-30;
        status = rfid.write(data_blockId, readData);
        if(status == MI_OK){
          Serial.print("扣款成功 餘額: $");
          Serial.println(readData[15], DEC);
        }
      }else{
        Serial.print("餘額不足 餘額: $");
        Serial.println(readData[15], DEC);
      }
    }else{
      Serial.println("Read fail");
    }
  }
  delay(500);
  rfid.halt(); // 進入休眠
}
