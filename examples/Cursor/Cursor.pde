/*
  SerialLCD Library - Cursor
 
 Demonstrates the use a 16x2 LCD SerialLCD driver from Seeedstudio.
 
 This sketch prints "Hello World!" to the LCD and
 uses the cursor()  and noCursor() methods to turn
 on and off the cursor.
 
 Library originally added 16 Dec. 2010
 by Jimbo.we 
 http://www.seeedstudio.com
 */

// include the library code:
#include <SerialLCD.h>
#if ARDUINO < 100
#include <NewSoftSerial.h> //this is a must
#else
#include <SoftwareSerial.h>
#endif

// initialize the library
SerialLCD slcd(11,12);//this is a must, assign soft serial pins

void setup() {
  // set up
  slcd.begin();
  // Print a message to the LCD.
  slcd.print("hello, world!");
}

void loop() {
  // Turn off the cursor:
  slcd.noCursor();
  delay(1000);
   // Turn on the cursor:
  slcd.cursor();
  delay(1000);
}
