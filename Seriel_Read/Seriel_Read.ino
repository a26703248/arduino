void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  //  判斷arduino 是否收到傳來的資料 (例如:PC)
  if(Serial.available()>0){
    //char c = Serial.read(); //讀一個字
    //Serial.println(c);
    
    //int num = Serial.read();// 讀一個字轉ASCII(A->65, B->66...)
    //Serial.println(num);

    String str =Serial.readString();
    Serial.println(str);
  }
}
