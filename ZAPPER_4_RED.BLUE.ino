// Zapper code for Swarm Bots Multi Player Mode
// Red/Main code is standard player One. Or pick your favorate color 
// Check out SwarmBots.online for more info

#include <Arduino.h>
#include <ButtonDebounce.h>
#include <IRremote.h>

#if defined(ARDUINO_ARCH_SAMD)
#define Serial SerialUSB
#endif

const int LED_0 = 9;
const int LED_1 = 8;
const int LED_2 = 7;
const int LED_3 = 6;
const int LED_4 = 4;
const int LED_5 = 3;
const int LED_6 = 15;
const int LED_7 = 14;
const int LED_8 = 16;
const int LED_9 = 10;

const int Rgb = A0;
const int rGb = A1;
const int rgB = A2;

const int buttonPin = 2; 
const int IR_SEND_PIN = 5;

const int debounceDelay = 50;
int buttonState = 0;    


void setup() {
    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_4, OUTPUT);
    pinMode(LED_5, OUTPUT);
    pinMode(LED_6, OUTPUT);
    pinMode(LED_7, OUTPUT);
    pinMode(LED_8, OUTPUT);
    pinMode(LED_9, OUTPUT);    
    pinMode(Rgb, OUTPUT);
    pinMode(rGb, OUTPUT);
    pinMode(rgB, OUTPUT);
    pinMode(buttonPin, INPUT);
    pinMode(IR_SEND_PIN, OUTPUT);

/////////////////////////////////////////////////
//START UP RGB SEQUENCE 
/////////////////////////////////////////////////

    digitalWrite(Rgb, HIGH);
    delay (350);
    digitalWrite(Rgb, LOW);  
    digitalWrite(rGb, HIGH);
    delay (350);
    digitalWrite(rGb, LOW);
    digitalWrite(rgB, HIGH);
    delay (350);
    digitalWrite(rgB, LOW);


////////////////////////////////////////////////
//LED RING START UP SEQUENCE 
////////////////////////////////////////////////
    
    digitalWrite(LED_0, HIGH);
    delay (50);
    digitalWrite(LED_9, HIGH);
    delay (50);
    digitalWrite(LED_1, HIGH);
    delay (50);
    digitalWrite(LED_8, HIGH);
    delay (50);
    digitalWrite(LED_2, HIGH);
    delay (50);
    digitalWrite(LED_7, HIGH);
    delay (50);
    digitalWrite(LED_3, HIGH);
    delay (50);
    digitalWrite(LED_6, HIGH);
    delay (50);
    digitalWrite(LED_4, HIGH);
    delay (50);
    digitalWrite(LED_5, HIGH);
    delay (250);

    digitalWrite(LED_0, LOW);
    digitalWrite(LED_9, LOW);
    delay (100);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_8, LOW);
    delay (300);

    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_2, LOW);
    delay (50);
    digitalWrite(LED_9, HIGH);
    digitalWrite(LED_3, LOW);
    delay (50);
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_4, LOW);
    delay (50);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_5, LOW);
    delay (50);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_6, LOW);
    delay (50);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_7, LOW);
    delay (50);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_8, LOW);
    delay (50);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_8, LOW);
    delay (50);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_9, LOW);
    delay (50);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_0, LOW);
    delay (50);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_1, LOW);
    delay (50);
    digitalWrite(LED_9, HIGH);
    digitalWrite(LED_2, LOW);
    delay (50);

    digitalWrite(LED_3, LOW);
    delay (50);
    digitalWrite(LED_4, LOW);
    delay (50);
    digitalWrite(LED_5, LOW);
    delay (50);
    digitalWrite(LED_6, LOW);
    delay (50);
    digitalWrite(LED_7, LOW);
    delay (50);
    digitalWrite(LED_8, LOW);
    delay (50);
    digitalWrite(LED_9, LOW);

    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    delay(100);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_9, LOW);
    delay(100);
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    delay(100);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_9, LOW);
    delay(100);
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    delay(100);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_9, LOW);
    delay(500);
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    delay(750);
    
////////////////////////////////////////////////
// RGB LED MAIN COLOR 
///////////////////////////////////////////////

    digitalWrite(Rgb, HIGH);
    digitalWrite(rGb, LOW);
    digitalWrite(rgB, HIGH);
    delay(250);
    digitalWrite(Rgb, LOW);
    digitalWrite(rgB, LOW);
    delay(250);
    digitalWrite(Rgb, HIGH);
    digitalWrite(rgB, HIGH);

////////////////////////////////////////////////
//END STATRT UP SEQUENCES 
////////////////////////////////////////////////    
     
    Serial.begin(115200);
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)  || defined(ARDUINO_attiny3217)
    delay(1000); // To be able to connect Serial monitor after reset or power up and before first printout
#endif
    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}
uint32_t botSTOP = 0xFF10EF; 
uint8_t nbits = 32;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;


void loop() {
    if (digitalRead(buttonPin) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(botSTOP, sCommand, sRepeats);
    delay(600);

/////////////////////////////////////////////////////
//  ZAP SEQUENCE
////////////////////////////////////////////////////

    digitalWrite(LED_0, LOW);
    delay(10);
    digitalWrite(LED_1, LOW);
    delay(10);
    digitalWrite(LED_2, LOW);
    delay(10);
    digitalWrite(LED_3, LOW);
    delay(10);
    digitalWrite(LED_4, LOW);
    delay(10);
    digitalWrite(LED_5, LOW);
    delay(10);
    digitalWrite(LED_6, LOW);
    delay(10);
    digitalWrite(LED_7, LOW);
    delay(10);
    digitalWrite(LED_8, LOW);
    delay(10);
    digitalWrite(LED_9, LOW);
    delay(10);

    digitalWrite(LED_0, HIGH);
    delay(10);
    digitalWrite(LED_1, HIGH);
    delay(10);
    digitalWrite(LED_2, HIGH);
    delay(10);
    digitalWrite(LED_3, HIGH);
    delay(10);
    digitalWrite(LED_4, HIGH);
    delay(10);
    digitalWrite(LED_5, HIGH);
    delay(10);
    digitalWrite(LED_6, HIGH);
    delay(10);
    digitalWrite(LED_7, HIGH);
    delay(10);
    digitalWrite(LED_8, HIGH);
    delay(10);
    digitalWrite(LED_9, HIGH);
    delay(10);
    }
}
