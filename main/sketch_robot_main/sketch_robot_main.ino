#include"InverseKinematics.h"
#include <SoftwareSerial.h>

SoftwareSerial robot(5,4);
// extern void setup1();
extern void vector(double x,double y);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  robot.begin(115200);
  
  // serial_robot.println("reset");

  char buf[10] = {0};
  int end = 0;
  Serial.println("waiting robot");

  while( strncmp(buf,"ok",2) != 0 ) {
    int ch = robot.read();
    if( ch >=0) {
      Serial.println( ch );
      buf[end++] = (char) ch;
      buf[end] = 0;
    }
  }
  Serial.println("robot ready!");
  // setup1();
}

extern bool touch_read(int&x, int&y);

extern double corA, corB, corC;
Machine machine(6,7.5,5.2,6.3);

void loop() {
  // put your main code here, to run repeatedly:
  // for( int i=90;i<=150;i+=10) {
  //   serial_robot.println("0 " + String(i) );
  //   Serial.println("sent");
  //   delay(1000);
  // }
  int x,y;
  double xx,yy;
  if( touch_read(x,y)) {
    yy =(y*13.0/700-6.5)/(6.5*4);
    xx = (x*17.0/700-8.5)/(8.5*4);
    Serial.println( String(xx) + "," + String(yy));
    double leg0 = machine.theta(0,8,-xx,-yy);
    double leg1 = machine.theta(1,8,-xx,-yy);
    double leg2 = machine.theta(2,8,-xx,-yy);
    robot.println("0 "+String(int(leg0-30)));
    robot.println("1 "+String(int(leg1-30)));    
    robot.println("2 "+String(int(leg2-30)));
    // vector(xx,yy);
    Serial.println(String(leg0) + "," + String(leg1) +","+ String(leg2));
  }
  
}
