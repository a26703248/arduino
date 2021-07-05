void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
//開始分析
turnRightDirection(times, distances, startTime, interval);

void turnRightDirection(unsigned long ts[], int ds[], unsigned long beginTime, int interval) {
  int maxValue = 0;
  Serial.println("==============");
  for (int i = 0; i < 20; i++) {
    maxValue = max(ds[i], maxValue); //max(val1, val2)函式會比較兩個參數，並回傳比較大的值
    Serial.println(maxValue);
  }
  Serial.println("================");
  Serial.println(maxValue);

  //計算maxValue的數量
  int count = 0;
  for (int i = 0; i < 20; i++) {
    if (maxValue == ds[i]) {
      count++;
    }
  }
  Serial.println("==============");
  Serial.println(maxValue);
  Serial.println(count);

  //建立maxValue的時間陣列
  unsigned long maxValueTimes[count];
  int n = 0;
  for (int i = 0; i < 20; i++) {
    if (maxValue == ds[i]) {
      maxValueTimes[n] = ts[i];
      n++;
    }
  }

  Serial.println("================");
  for (int i = 0; i < count; i++) {
    Serial.print("maxValueTime:");
    Serial.println(maxValueTimes[i]);
  }

}
