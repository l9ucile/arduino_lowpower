const boolean PRESSED = 0;
const int BUTTONPIN = 1
const int LEDPIN = 2;
int counter = 0;
boolean tampon_value ;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTONPIN,INPUT);
  pinMode(LEDPIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (PRESSED = digitalRead(BUTTONPIN) )
  {
    while (PRESSED = digitalRead(BUTTONPIN) );
    delay(1);
    digitalWrite(LEDPIN, !digitalRead(LEDPIN));
    ++ counter;
  }
}
