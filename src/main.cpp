#include <Arduino.h>
// int this simple example we set up a pin change interrupt on PC0 and PC1
// if we toggle PC0 LED on PB5 lights up and if we toggle PC1 LED on PB5 lights up


int main(void) {
  // setting up the pullup resistor for pin A0,A1
  DDRC &= ~((1<< PC0)|(1<<PC1));
  PORTC |= ((1 << PC0)|(1 << PC1));
  DDRB |= ((1<<PB5)|(1<<PB4));

  // setting up pin A0,A1 to be used as a PCINTERRUPT
  PCMSK1 |= ((1<<PCINT8)|(1<<PCINT9));
  PCICR |= (1<<PCIE1);
  sei();
  while(1){

  }
  return 0;
}

ISR(PCINT1_vect){
  if(bit_is_clear(PINC, PC0))
  PORTB ^= (1<<PB5); //toggles the led on pin 13

  if(bit_is_clear(PINC, PC1))
  PORTB ^=(1<<PB4); // toggles an LED on pin 12
}
