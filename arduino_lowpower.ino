#include <avr/power.h>
//const boolean PRESSED = 0;
//const int BUTTONPIN = 1
const int LEDPIN = 2;
//int counter = 0;
//boolean tampon_value ;

void setup() {
  // put your setup code here, to run once:
  
  /*pinMode(BUTTONPIN,INPUT);
  pinMode(LEDPIN,OUTPUT);
  Serial.begin(9600);
  */

  onOffLed(2); // LED blipping to show the start

  power_usb_disable();
  onOffLed(1);
  power_spi_disable();
  onOffLed(1);
  power_adc_disable();
  onOffLed(1);
  power_twi_disable();
  onOffLed(1);
  power_usart0_disable();
  onOffLed(1);
 // Selection of the iddle mode with SMCR register
  SMCR &= ~(1 << SMO); 
  SMCR &= ~(1 << SM1);
  SMCR &= ~(1 << SM2);

  delay(3); // Delay to permit to switch clocks

  //Switch from External Clock to RC Clock
  if ((UDINT  & ~(1 << SUSPI) == 1)       // if (UDINT.SUSPI == 1)
  UDINT  &= ~(1 << SUSPI);                //UDINT.SUSPI = 0;
  USBCON |= ( 1 <<FRZCLK);                //USBCON.FRZCLK = 1;
  PLLCSR &= ~(1 << PLLE);                 //PLLCSR.PLLE = 0;
  CLKSEL0 |= (1 << RCE);                  //CLKSEL0.RCE = 1;
  while ( (CLKSTA & (1 << RCON)) == 0){}  //while (CLKSTA.RCON != 1);
  CLKSEL0 &= ~(1 << CLKS);                //CLKSEL0.CLKS = 0;
  CLKSEL0 &= ~(1 << EXTE);                //CLKSEL0.EXTE = 0;
  onOffLed(3);

}

void loop() {
  // put your main code here, to run repeatedly:
  /*if (PRESSED = digitalRead(BUTTONPIN) )
  {
    while (PRESSED = digitalRead(BUTTONPIN) );
    delay(1);
    digitalWrite(LEDPIN, !digitalRead(LEDPIN));
    ++ counter;
  }*/
}

void onOffLed(int times) { 
  pinMode(LEDPIN,OUTPUT); 
  for(int i=0;i<times;i++){
    digitalWrite(LEDPIN,HIGH);
    delay(500);
    digitalWrite(LEDPIN,LOW);
    delay(500);
  }
} 
 

