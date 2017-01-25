/*
  Boton de parpadeo
  Programa que prende y apaga el el pin 13 al calcular el tiempo
  que se mantiene apretado el pushbutton del pin 2

  Circuito:
   LED del arduino (títpicamente 13)
   pushbutton en el pin 2 conectado a +5V
   Resistencia
*/

// Pines
const int pinButton = 3;    // pin del push button
const int pinLed =  13;      // Pin Led

// variables
int intStateButton = 0;         // estado del boton
unsigned long timer0;
unsigned long timer1;
unsigned long timerRead;
unsigned long timerDiff;
unsigned long timerAux = 0;
unsigned long timerNow;
bool boolBlink = false;
bool boolStart = false;
int i = 0;

void blink();

void setup() {
  Serial.begin(9600);
  // inicializando pines
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinButton), blink, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(pinButton), blink1, FALLING);
  //attachInterrupt(digitalPinToInterrupt(pinButton), blink, RISING);
  timerRead = millis();

}

void loop() {

  if (!boolBlink) {
    timer1 = timerRead;
    timerDiff = timer1 - timer0;
    if (timerDiff != timerAux || (timerNow + (timerDiff * 2) < millis())) {
      timerAux = timerDiff;
      timerNow = millis();
    }
  } else {
    timer0 = timerRead;
    /*
      digitalWrite(pinLed,LOW);
      Serial.println(timer0);
      delay(1000);
    */
  }

  if (millis() < (timerNow + timerDiff)) {
    digitalWrite(pinLed, HIGH);
  } else {
    if (millis() < (timerNow + (timerDiff * 2))) {
      digitalWrite(pinLed, LOW);
    }
  }

}
void blink() {
  boolBlink = !boolBlink;
  timerRead = millis();
}

