//libraries
#include <Arduino.h>
#include <IRremote.h>


void setup()
{
    Serial.begin(9600);   
    //IrReceiver in pin 8
    IrReceiver.begin(8, ENABLE_LED_FEEDBACK);
}

    
void loop()
{  
     if (IrReceiver.decode()) 
     {  
        //print the code in serial
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        delay(200);
        // Enable receiving of the next value
        IrReceiver.resume(); 
     }
}