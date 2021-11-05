#include <Arduino.h>
#include <IRremote.h>

int ReceptorIR = 8;
IRrecv irrecv(ReceptorIR);
decode_results Codigo;

void setup()
{
    Serial.begin(9600);
    Serial.print("...Initialize receptor...");
    irrecv.enableIRIn();
}

void loop()
{
    if (irrecv.decode(&Codigo))
    {
        Serial.print("0x");
        Serial.println(Codigo.value, HEX);
        delay(100);
        irrecv.resume();
    }
}