#include <OneWire.h>
#include <DallasTemperature.h>

#define termo 5
#define flow 7
#define pyra A2
#define current A3
#define pressure A4
#define anemo A5
#define voltage A1

#define Vhigh 11.28

OneWire oneWire(termo);

DallasTemperature sensors(&oneWire);


float Celcius=0;
int t=0;
float currentChange = 57/(Vhigh/8.0);
float currentVoltageRelation = 0.016/(4.3-0.86);

void setup(void)
{ 
  Serial.begin(9600); // startar seriell com
  sensors.begin(); // startarr temp
  pinMode(flow,INPUT);
}

void loop(void)
{ 
  t = t+1;

  // matte enligt datablad för anemometern
  int anemoSensorValue = analogRead(anemo);
  float anemoVoltage = anemoSensorValue * (5.0 / 1023.0);
  int anemoLevel = 6*anemoVoltage;

  float pyraOutput = analogRead(pyra); // har ett värde, osäker på vad det betyder
  //float pyraACC = pyraOutput/0.8*10;
  float pyrAcc = pyraOutput/(1023/1.5);
  
  float currentOut = analogRead(current) * (5.0 / 1023.0);
  
  float CurrentAcc = currentFunc(currentOut);

  float pressureOut = analogRead(pressure) * (5.0 / 1023.0);

  float voltageOut = analogRead(voltage) * (5.0 / 1023.0) * 21.0/2.0;
  
  float pressureAcc = pressureFunc(pressureOut);

  int ontime = pulseIn(flow,HIGH);
  int offtime = pulseIn(flow,LOW);
  float period = ontime+offtime;
  float freq = 1000000.0/period;
  
  if (period <= 0)
    freq = 0;
    
  sensors.requestTemperatures(); 
  Celcius = sensors.getTempCByIndex(0);
  delay(250);
  
 // printar til seriell com
 // Serial.println(t); //vilken iteration av mätvärden
    
  //Serial.print("Temp: ");
  Serial.println(Celcius);
  //Serial.print("Voltage: ");
  Serial.println(voltageOut);
  //Serial.print("Wind speed: ");
  Serial.println(anemoLevel);
  //Serial.println(anemoSensorValue);
  //Serial.print("Pyramometer: ");
  Serial.println(pyraACC);
  //Serial.print("Current sensor: ");
  Serial.println(CurrentAcc);
  //Serial.print("Pressure(kPa): ");
  Serial.println(pressureAcc);
  //Serial.print("Flow sensor(Hz): ");
  Serial.println(freq);

  //Serial.println();
  //Serial.println();
  //Serial.println();
  
  

}

float pressureFunc(float sensorOut)
{
  float current = currentVoltageRelation*sensorOut;
  float pressureOut = current * 750.0/0.016 - 280; // ändra på denna term för att nolla vid kalibrering
  return pressureOut;
}

float currentFunc(float sensorOut)
{
  float currentOut = sensorOut * currentChange - 105.8; // ändra på denna term för att nolla vid kalibrering
  return currentOut;
}
