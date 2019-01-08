#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

int data[5];
const byte address[6] = "47851";
RF24 radio(9, 10); // CE, CSN pin of nRF24L01+

const int servoPin0 = A0;
const int servoPin1 = A1;
const int servoPin2 = A2;
const int servoPin3 = A3;
const int servoPin4 = A4;

Servo servoM0;
Servo servoM1;
Servo servoM2;
Servo servoM3;
Servo servoM4;

void setup() {

	Serial.begin(9600);
	radio.begin();
	radio.openReadingPipe(1, address);
	radio.setPALevel(RF24_PA_MIN);
	radio.startListening();
	servoM0.attach(servoPin0);
	servoM1.attach(servoPin1);
	servoM2.attach(servoPin2);
	servoM3.attach(servoPin3);
	servoM4.attach(servoPin4);
	Serial.begin(9600);

}
void loop() {

	if (radio.available()) {
	radio.read(&data, sizeof(data));

	servoM0.write(data[0]);
	servoM1.write(data[1]);
	servoM2.write(data[2]);
	servoM3.write(data[3]);
	servoM4.write(data[4]);
	}

//reset();
}

//function to reset the position of servos.
void reset() {
servoM0.write(10);
servoM1.write(10);
servoM2.write(10);
servoM3.write(10);
servoM4.write(10);
}
