
#include <SoftwareSerial.h>

SoftwareSerial serial_robot(5,4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  serial_robot.begin(115200);
  
  // serial_robot.println("reset");

  char buf[10] = {0};
  int end = 0;
  Serial.println("waiting robot");

  while( strncmp(buf,"ok",2) != 0 ) {
    int ch = serial_robot.read();
    if( ch >=0) {
      Serial.println( ch );
      buf[end++] = (char) ch;
      buf[end] = 0;
    }
  }
  Serial.println("robot ready!");
}

extern bool touch_read(int&x, int&y);

void loop() {
  // put your main code here, to run repeatedly:
  // for( int i=90;i<=150;i+=10) {
  //   serial_robot.println("0 " + String(i) );
  //   Serial.println("sent");
  //   delay(1000);
  // }
  int x,y;
  if( touch_read(x,y)) {
    Serial.println( String(x) + "," + String(y));
  }
}
