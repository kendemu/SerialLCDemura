#ifndef SERIAL_LCD_H
#define SERIAL_LCD_H

#include <inttypes.h>

#if ARDUINO < 100
#include <WProgram.h>
#include <NewSoftSerial.h>
#else
#include <Arduino.h>
#include <SoftwareSerial.h>
#endif

//Initialization Commands or Responses
#define UART_READY		0xA3
#define SLCD_INIT_ACK		0xA5
#define SLCD_INIT_DONE		0xAA
#define SLCD_INVALIDCOMMAND	0x46

//WorkingMode Commands or Responses
#define SLCD_CONTROL_HEADER	0x9F
#define SLCD_CHAR_HEADER	0xFE
#define SLCD_CURSOR_HEADER	0xFF
#define SLCD_CURSOR_ACK		0x5A
#define SLCD_RETURN_HOME	0x61
#define SLCD_DISPLAY_OFF	0x63
#define SLCD_DISPLAY_ON		0x64
#define SLCD_CLEAR_DISPLAY	0x65
#define SLCD_CURSOR_OFF		0x66
#define SLCD_CURSOR_ON		0x67
#define SLCD_BLINK_OFF		0x68
#define SLCD_BLINK_ON		0x69
#define SLCD_SCROLL_LEFT	0x6C
#define SLCD_SCROLL_RIGHT	0x72
#define SLCD_NO_AUTO_SCROLL	0x6A
#define SLCD_AUTO_SCROLL	0x6D
#define SLCD_LEFT_TO_RIGHT	0x70
#define SLCD_RIGHT_TO_LEFT	0x71

// Only used on firmware 1.0b and above
#define SLCD_BACKLIGHT_ON	0x81
#define SLCD_BACKLIGHT_OFF	0x80
#define SLCD_POWER_ON    	0x83
#define SLCD_POWER_OFF  	0x82


#if ARDUINO < 100
class SerialLCD : public NewSoftSerial{
#else
class SerialLCD : public SoftwareSerial{
#endif
public:

    SerialLCD(uint8_t, uint8_t);

    void autoscroll();
    void backlight();
    void begin();
    int  beginAndCheck(); // add by demura
    void blink();
    void clear();
    void cursor();
    void display();
    void home();
    void leftToRight();
    void noAutoscroll();
    void noBacklight();
    void noBlink();
    void noCursor();
    void noDisplay();
    void noPower();
    void power();
    void print(const char[]);
    void print(uint8_t b);
    void print(unsigned long n, uint8_t base);
    void rightToLeft();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    void setCursor(uint8_t, uint8_t);

};

#endif
