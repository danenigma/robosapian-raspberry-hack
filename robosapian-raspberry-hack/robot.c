#include <wiringPi.h>
#define IR_PIN  0
#include<stdio.h>
void delay(unsigned int units) {
	usleep(833 * units);
}
void tell(unsigned int arg) {

	unsigned int command = arg;
	// Preamble. Set IR signal line LOW
	digitalWrite(IR_PIN,LOW);
	delay(8);
	// Pulse the 8 bit command. Delay 4 slices for 1-bit and 1 slice for a 0-bit.
	int b;
	for(b = 0; b < 8; b++){

		digitalWrite(IR_PIN,HIGH);
		delay( ( (command & 128) != 0) ? 4 : 1);
		int d =( (command & 128 )!=0 ? 4:1);
		printf("%d\n",d);
		digitalWrite(IR_PIN,LOW);
		delay(1);
		command <<= 1;
	}
	// Finally, reset IR signal line HIGH
	digitalWrite(IR_PIN,HIGH);

}
void init() {
	wiringPiSetup();
	piHiPri(99);
	pinMode(0, INPUT);
	pinMode(IR_PIN, OUTPUT);
	digitalWrite(IR_PIN, HIGH);
}
