# ESP32-DH11-RELAY
Este proyecto esta pensado para controlar un rele dependiente de la temperatura hambiente, esta ideado para mantener un espacio con la misma temperatura 

Para este proyecto hemos usado el sensor de temperatura DHT11 en un integrado que incorpora ya la resistencia de pull-up.
Por motivos de Hardware entre lectura y lectura tenemos que esperar 5 segundos 

El esquema electrico quedaria de la siguiente manera 

<img width="488" alt="1" src="https://user-images.githubusercontent.com/14801079/218171258-b5fdd8af-7db7-4b1f-a7b8-2350f35ef2e8.png">

 <h3>------Metodos------</h3>

dht.readHumidity() = Obtenemos la humedad relativa del sensor <br>
dht.readTemperature() = Obtenemos la temperatura en Cº<br>
dht.readTemperature(true) = Obtenemos la temperatura en Fahrenheit<br>
dht.computeHeatIndex(temperatura, humedad, false) = Obtenemos la sensacion termica. <br>

