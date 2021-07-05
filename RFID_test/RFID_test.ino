#include <SPI.h>
#include <RFID.h>
#define RST_PIN 9
#define SDA_PIN 10
#define BUZZER_PIN 6

RFID rfid(SDA_PIN, RST_PIN);

// 驗證資料(block id: 11)
unsigned char keyA[16] {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x07, 0x80, 0x69, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
// 讀出資料 (block id: 9)
unsigned char newkeyA[16] {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xff, 0x07, 0x80, 0x69, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
unsigned char pass[16];

int key_blockId = 15;
int data_blockId =13;
void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  SPI.begin();
  rfid.init();
  Serial.println("Ready");
}

void loop() {
  if (rfid.isCard() && rfid.readCardSerial()) { // 偵測到卡
    // 讀取卡片id
    tone(BUZZER_PIN, 2000, 200);
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
  // 讀取
  // 授權驗證
  //寫入記得注意status = rfid.write(key_blockId, newkeyA);是否正確
  /*unsigned char status = rfid.auth(PICC_AUTHENT1A, key_blockId, keyA, rfid.serNum);
  if (status == MI_OK) {
    Serial.println("Auth pass");
    // 讀取資料
    status = rfid.write(key_blockId, newkeyA); // 將資料寫入到 readData 陣列
    if (status == MI_OK) {
      for(int i=0;i<16;i++){
        Serial.print(newkeyA[i], HEX);
        Serial.print(" ");
      }
    } else {
      Serial.println("Read error");
    }
    Serial.println();
    Serial.println("-------------------------------");
  }*/
  //寫入記得注意status = rfid.read(data_blockId, pass);是否正確
  unsigned char status = rfid.auth(PICC_AUTHENT1A, key_blockId, newkeyA, rfid.serNum);
  if (status == MI_OK) {
    Serial.println("Auth pass");
    // 讀取資料
    status = rfid.read(data_blockId, pass); // 將資料寫入到 readData 陣列
    if (status == MI_OK) {
      for(int i=0;i<16;i++){
        Serial.print(pass[i], HEX);
        Serial.print(" ");
      }
    } else {
      Serial.println("Read error");
    }
    Serial.println();
    Serial.println("-------------------------------");
  }
  rfid.halt(); // 進入休眠
  delay(500);
}
