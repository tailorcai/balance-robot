/*
  test for touchscreen
*/
#define xLow  A1
#define xHigh A3
#define yLow A0
#define yHigh A2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(xLow,OUTPUT);
  pinMode(xHigh,OUTPUT);
  digitalWrite(xLow,LOW);
  digitalWrite(xHigh,HIGH);

  digitalWrite(yLow,LOW);
  digitalWrite(yHigh,LOW);

  pinMode(yLow,INPUT);
  pinMode(yHigh,INPUT);
  delay(10);

  //xLow has analog port -14 !!
  int x=analogRead(yLow);

  pinMode(yLow,OUTPUT);
  pinMode(yHigh,OUTPUT);
  digitalWrite(yLow,LOW);
  digitalWrite(yHigh,HIGH);

  digitalWrite(xLow,LOW);
  digitalWrite(xHigh,LOW);

  pinMode(xLow,INPUT);
  pinMode(xHigh,INPUT);
  delay(10);

  //xLow has analog port -14 !!
  int y=analogRead(xLow);

  Serial.print("x=");Serial.print(x);
  Serial.print(",y=");Serial.println(y);
  delay(100);
}
