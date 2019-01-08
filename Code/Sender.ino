#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int data[5];
const byte address[6] = "47851";
RF24 radio(7, 8); //CE, CSN pins of nRF24L01+

const int flexPin0 = A0;
const int flexPin1 = A1;
const int flexPin2 = A2;
const int flexPin3 = A3;
const int flexPin4 = A4;


void setup()
{
	radio.begin();
	radio.openWritingPipe(address);
	radio.setPALevel(RF24_PA_MIN);
	radio.stopListening();
	Serial.begin(9600);
}

void loop()
{
	int flexPosition0;
	int flexPosition1;
	int flexPosition2;
	int flexPosition3;
	int flexPosition4;
	flexPosition0 = analogRead(flexPin0);
	flexPosition1 = analogRead(flexPin1);
	flexPosition2 = analogRead(flexPin2);
	flexPosition3 = analogRead(flexPin3);
	flexPosition4 = analogRead(flexPin4);
	
	int flexValue0;
	int flexValue1;
	int flexValue2;
	int flexValue3;
	int flexValue4;

	flexValue0 = map(flexPosition0, 496, 506, 10, 150);
	flexValue1 = map(flexPosition1, 448, 462, 10, 150);
	flexValue2 = map(flexPosition2, 430, 456, 10, 150);
	flexValue3 = map(flexPosition3, 390, 399, 10, 150);
	flexValue4 = map(flexPosition4, 558, 580, 10, 150);

	data[0] = flexValue0;
	data[1] = flexValue1;
	data[2] = flexValue2;
	data[3] = flexValue3;
	data[4] = flexValue4;
	
	/*
	Yours may vary
	4=middle
	3=pinky
	1=ring finger
	2=thumb
	0=index
	*/

	radio.write(&data, sizeof(data));
	Serial.println("wrote");
	Serial.print("sensor0:");
	Serial.print("0--");
	Serial.println(flexPosition0);
	Serial.print("1--");
	Serial.println(flexPosition1);
	Serial.print("2--");
	Serial.println(flexPosition2);
	Serial.print("3--");Serial.println(flexPosition3);
	Serial.print("4--");
	Serial.println(flexPosition4);
}
