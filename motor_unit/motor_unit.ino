// make ARDUINO DAGU board as a servo controller board
// serial 115200
// id angle [New Line]


  #include <Servo.h>
Servo myservos[3];

char buf[80];
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
  for( int i=0;i<3;i++)
    myservos[i].attach(i+4);

  Serial.println("ok");
}
void loop() {
  if (readline(Serial.read(), buf, 80) > 0) {
      Serial.print("You entered: >");
      Serial.print(buf);
      Serial.println("<");
      int id, angle;
      int n = sscanf(buf, "%d %d", &id, &angle);
      if( n == 2 ) {
        myservos[id].write( angle );
      }
  }
}
