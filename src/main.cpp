//libraries
#include <Arduino.h>
#include <IRremote.h>

//pin receptor IR
int ReceptorIR = 8;
IRrecv irrecv(ReceptorIR);
decode_results Codigo;

void setup()
{
    //Initilize serial port
    Serial.begin(9600);
    Serial.print("...Initialize receptor...");
    //Initialize IRremote receptor
    irrecv.enableIRIn();
}

void loop()
{
    //When receive a signal IR
    if (irrecv.decode(&Codigo))
    {
        //Value in HEX
        Serial.print("0x");
        Serial.println(Codigo.value, HEX);
        delay(100);
        //return the control to receiver
        irrecv.resume();
    }
}