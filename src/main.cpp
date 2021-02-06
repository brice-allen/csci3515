
#include <Arduino.h>
#include <time.h>
int temppin = A0;
unsigned long time_1;
int data1, curr1;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int reading = analogRead(temppin);
    double thermoresist = 10000.0 * ((1024.0 / reading - 1));
    double logofthermoresist = log(thermoresist);
    double tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * logofthermoresist * logofthermoresist)) * logofthermoresist);
    float tempC = tempK - 273.15;
    float tempF = (tempC * 9.0) / 5.0 + 32.0;
    time_1 = millis();
    Serial.print("-----------------\n");
    Serial.print("Elapsed time in milliseconds: ");
    Serial.print(time_1);
    Serial.print("\n-----------------\n");
    Serial.print("Kelvin: ");
    Serial.print(tempK);
    Serial.print('\n');
    Serial.print("Celcius: ");
    Serial.print(tempC);
    Serial.print('\n');
    Serial.print("Fahrenheit: ");
    Serial.println(tempF);

    delay(1000);
}