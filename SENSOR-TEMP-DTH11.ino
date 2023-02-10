#include <DHT.h>

#define DHTPIN 4
#define TYPESENSOR DHT11
#define PINLED 2
#define PINRELE 13
DHT dht(DHTPIN,TYPESENSOR);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(PINLED,OUTPUT);
  pinMode(PINRELE,OUTPUT);
}

void loop() {
  
  delay(5000);
 
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados 
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahrenheit
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
  float hic = dht.computeHeatIndex(t, h, false);
  if(t>=26)
  {
    digitalWrite(PINLED,HIGH);
    digitalWrite(PINRELE,HIGH);
  }
  else
  {
    digitalWrite(PINLED,LOW);
    digitalWrite(PINRELE,LOW);
  }
   Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.println("");

}
