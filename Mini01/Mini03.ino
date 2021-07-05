#include <MatrixMini.h>

float u = 0;
char y = ' ';
char x = ' ';
float p = 0;
float a = 0;
float h = 0;
float w = 0;

void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();

}

void loop() {
  Serial.print("c.圓形 s.長方形: ");
  while (true) {
    x = Serial.read();
    if (x == 'c') {
      Serial.println(x);
      Serial.print("請輸入半徑: ");
      circleCompute();
    } else if (x == 's') {
      Serial.println(x);
      Serial.print("請輸入長: ");
      squeraCompute();
    }
    if (y != ' ' && u != 0) {
      y = ' ';
      u = 0;
      x = ' ';
      break;
    }
  }
}
void circleCompute() {
  while (true) {
    if (Serial.available() > 0 && u == 0) {
      u = Serial.parseInt();
      Serial.println(u);
      Serial.print("a.面積 p.周長 : ");
    } else if (Serial.available() > 0 && u != 0) {
      y = Serial.read();
      Serial.println(y);
    } else if (y != ' ' && u != 0.0) {
      Serial.print(y == 'p' ? "周長為: " : "面積為: ");
      Serial.println(circle(u, y));
      break;
    }
  }
}
void squeraCompute() {
  while (true) {
    if (Serial.available() > 0 && h == 0) {
      h = Serial.parseInt();
      Serial.println(h);
      Serial.print("請輸入寬: ");
    } else if (Serial.available() > 0 && h != 0 && w == 0) {
      w = Serial.parseInt();
      Serial.println(w);
      Serial.print("a.面積 p.周長 : ");
    } else if (Serial.available() > 0 && w != 0 && h != 0) {
      y = Serial.read();
      Serial.println(y);
    }else if (h != 0 && w != 0 && y != ' ') {
      Serial.print(y == 'p' ? "周長為: " : "面積為: ");
      Serial.println(square(h, w, y));
      Serial.println(1);
      break;
    }
  }
}
float circle(float r, char c) {
  float sum;
  if (c == 'p') {
    sum = r * 2 * PI;
    return sum;
  } else {
    sum = r * r * PI;
    return sum;
  }
}
float square(float h, float w, char c) {
  float sum;
  if (c == 'p') {
    sum = (h * w) * 2;
    return sum;
  } else {
    sum = h * w;
    return sum;
  }
}





void LongRGB(int i, int l) {
  switch (l) {
    case 1:
      Mini.RGB1.setRGB(i, 0, 0);
      Mini.RGB2.setRGB(i, 0, 0);
      break;
    case 2:
      Mini.RGB1.setRGB(0, i, 0);
      Mini.RGB2.setRGB(0, i, 0);
      break;
    case 3:
      Mini.RGB1.setRGB(0, 0, i);
      Mini.RGB2.setRGB(0, 0, i);
      break;

  }
}

void shortRGB(int i, int l) {
  switch (l) {
    case 1:
      Mini.RGB1.setRGB(i, 0, 0);
      Mini.RGB2.setRGB(i, 0, 0);
      break;
    case 2:
      Mini.RGB1.setRGB(0, i, 0);
      Mini.RGB2.setRGB(0, i, 0);
      break;
    case 3:
      Mini.RGB1.setRGB(0, 0, i);
      Mini.RGB2.setRGB(0, 0, i);
      break;
  }
  Mini.RGB1.setRGB(0, 0, 0);
  Mini.RGB2.setRGB(0, 0, 0);
}
