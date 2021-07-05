#include <SPI.h>
#include <RFID.h>

#define RST_PIN    9
#define SDA_PIN    10
#define BUZEER_PIN 8

RFID rfid(SDA_PIN, RST_PIN);

// 驗證資料(block id: 11)
unsigned char keyA[16] {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xff, 0x07, 0x80, 0x69, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
// 讀出資料 $100(block id: 9)
unsigned char readData[16];


int key_blockId = 11;
int data_blockId = 9;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  Serial.println("Ready");
}

void loop() {
  if (rfid.isCard() && rfid.readCardSerial()) { //偵測到卡片且可以讀取卡內容
    tone(BUZEER_PIN, 2000, 200);
    // 讀取卡片 ID
    Serial.println("Card found");
    String cardId = " ";//卡片ID
    for (int i = 0; i < 16; i++) {
      //Serial.print(rfid.serNum[i], HEX);
      //Serial.print(", ");
      cardId += String(rfid.serNum[i], HEX);//組合前5個id內容
      cardId += " ";
    }
    Serial.print("cardId: ");
    Serial.print(cardId);
    Serial.println();
    //---------------------------------------------------------------------------------
    // 回傳卡片的容量
    int card_Size = rfid.SelectTag(rfid.serNum);
    Serial.print("CardSize: ");
    Serial.print(card_Size);
    Serial.println("K bits");
  }
  //---------------------------------------------------------------------------------
  // 讀取 $100
  // 授權驗證
  unsigned char status = rfid.auth(PICC_AUTHENT1A, key_blockId, keyA, rfid.serNum);//KeyA 0x60, KeyB 0x61
  if (status == MI_OK) {
    Serial.println("Auth pass");
    status = rfid.read(key_blockId, readData);
    Serial.println(status);
    if (status == MI_OK) {
      Serial.print("read ok: $");
      Serial.println(readData[15], DEC);
      Serial.print(", ");
      Serial.println(readData[15], HEX);
    } else {
      Serial.println("read Error");
    }
  }
  delay(500);
  rfid.halt();//進入休眠
}
