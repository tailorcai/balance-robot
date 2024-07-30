#include"InverseKinematics.h"
#include <SoftwareSerial.h>

SoftwareSerial robot(5,4);
// extern void setup1();
extern void vector(double x,double y);

int readline(int readch, char *buffer, int len) {
  static int pos = 0;
  int rpos;

  if (readch > 0) {
      switch (readch) {
          case '\r': // Ignore CR
              break;
          case '\n': // Return on new-line
              rpos = pos;
              pos = 0;  // Reset position index ready for next time
              return rpos;
          default:
              if (pos < len-1) {
                  buffer[pos++] = readch;
                  buffer[pos] = 0;
              }
      }
  }
  return 0;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  robot.begin(115200);
  
  // serial_robot.println("reset");

  Serial.println("waiting robot");
  serial_robot.println("reset");
  bool success = false;
  unsigned long tm = millis();
  while( millis() < tm + 15000 ) {
    char buf[80];
    if(readline(serial_robot.read(), buf, 80) > 0) {
      if( strncmp(buf,"ok",2)==0) {
        success = true;
        break;
      }
    }
  }

  Serial.println(success?"robot ready!":"robot does not respond!");
  if( success ) {
    for( int i=150;i>=90;i-=2) {
      serial_robot.println("0 "+String(i));
      serial_robot.println("1 "+String(i));
      serial_robot.println("2 "+String(i));
      delay(100);
    }
  }

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
