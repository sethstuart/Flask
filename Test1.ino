#include <Servo.h>

Servo x1;
Servo x2;
Servo y1;
Servo y2;
Servo z0;

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data
int x;  // forward/back axis
int y; // left/right axis
int z; // Up/down Axis

boolean newData = false;
boolean parsedData = false;

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
    x1.attach(8,1000,2000);
    x2.attach(9,1000,2000);
    z0.attach(10,1000,2000);
    y1.attach(11,1000,2000);
    y2.attach(12,1000,2000);
    
}

void loop() {
    recvWithEndMarker();
    parseRX();
    updateXZProp();
}

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void parseRX() {
  if (newData == true) {
    sscanf(receivedChars,"%*c %d %*c %d %*c %d",&x,&y,&z);
    newData = false;
    parsedData = true;
  }
}

void updateXZProp() {
    if (parsedData == true) {
        int xRX = x;
        int yRX = y;
        int zRX = z;
        Serial.println(x);
        Serial.println(y);
        Serial.println(z);
        x1.write(xRX);
        x2.write(xRX);
        z0.write(zRX);
        parsedData = false;
    }
}
