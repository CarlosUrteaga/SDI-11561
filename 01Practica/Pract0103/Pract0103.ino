/*
  Boton de parpadeo
 Programa que prende y apaga el el pin 13 al calcular el tiempo
 que se mantiene apretado el pushbutton del pin 2
 
 Circuito:
 * LED del arduino (títpicamente 13)
 * pushbutton en el pin 2 conectado a +5V
 * Resistencia 
 */

// Pines
const int pinButton= 2;     // pin del push button
const int pinLed =  13;      // Pin Led

// variables
int intStateButton = 0;         // estado del boton
unsigned long time0 = 0;
unsigned long time1 = 0;
bool boolRead = false;
bool boolOnlyOnce =false;
void setup() {
  Serial.begin(9600);
  // inicializando pines
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT);
}

void loop() {
  cli();
  blink();
  sei();
  if(boolRead && !boolOnlyOnce){
    Serial.print(time0);
    boolOnlyOnce = true;
  }
    
}

void blink(){
  intStateButton = digitalRead(pinButton);
  if (intStateButton == HIGH ) {
       if(!boolRead){
        time0 =millis();
        boolRead=false;
       }
  }
  else{
    if(!boolRead && time0!=0){
      time1 = millis()-time0;
      boolRead=true;
    }
  }
}

