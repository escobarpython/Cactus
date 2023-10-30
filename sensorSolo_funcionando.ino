
#include <LiquidCrystal.h>
#include "dht.h"
 

 


 

const int pinoSensor = A0; //PINO UTILIZADO PELO SENSOR
int valorLido; //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO
//VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO
int analogSoloSeco = 400; //VALOR MEDIDO COM O SOLO SECO (VOCÊ PODE FAZER TESTES E AJUSTAR ESTE VALOR)
int analogSoloMolhado = 150; //VALOR MEDIDO COM O SOLO MOLHADO (VOCÊ PODE FAZER TESTES E AJUSTAR ESTE VALOR)
int percSoloSeco = 0; //MENOR PERCENTUAL DO SOLO SECO (0% - NÃO ALTERAR)
int percSoloMolhado = 100; //MAIOR PERCENTUAL DO SOLO MOLHADO (100% - NÃO ALTERAR)

int uar;
int temp;

 const int pinoDHT11 = A1; //PINO ANALÓGICO UTILIZADO PELO DHT11
dht DHT; //VARIÁVEL DO TIPO DHT

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

 

 

void setup() {

  // put your setup code here, to run once:

Serial.begin (9600);

lcd.begin (16, 2);

}

 

void loop() {
DHT.read11(pinoDHT11);
 

  valorLido = constrain(analogRead(pinoSensor),analogSoloMolhado,analogSoloSeco); //MANTÉM valorLido DENTRO DO INTERVALO (ENTRE analogSoloMolhado E analogSoloSeco)

 valorLido = map(valorLido,analogSoloMolhado,analogSoloSeco,percSoloMolhado,percSoloSeco); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS

 uar = DHT.humidity;
temp = DHT.temperature, 0;
 

 

lcd.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL

  lcd.print(valorLido); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO

  lcd.print("%"); //ESCREVE O TEXTO EM SEGUIDA

 

 

if (valorLido <= 70 && valorLido >= 60) {

  lcd.setCursor(0,1);

  lcd.print("ideal");

}

 

else if (valorLido < 60){

lcd.setCursor(0,1);

lcd.print("solo_seco");

}

 

else if (valorLido > 70) {

  lcd.setCursor(0,1);

lcd.print("solo_umido");

 

}

 

delay(4000);

  lcd.clear();

lcd.print("Umidade-ar:");
lcd.print(uar);
lcd.print("%");

delay(4000);

lcd.clear();

lcd.print("temperatura:");
 lcd.print(temp);
lcd.print("C");

delay(4000);
lcd.clear();

 if (Serial. available()) {

  

 

  Serial.println(valorLido);




  delay(2000);

Serial.print("temperatura:"); 
Serial.print(temp);
Serial.print("C");
delay(2000);
Serial.print("umidade do ar:");
Serial.print(uar);
Serial.print("%");
 

 }

 

 

 

}