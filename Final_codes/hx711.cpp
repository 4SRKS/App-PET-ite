#include <stdio.h>
#include <inttypes.h>
#include <wiringPi.h>

#include "hx711.h"

HX711::HX711(uint8_t clockPin, uint8_t dataPin, uint8_t skipSetup) :
	mGainBits(1),
	mScale(1.0f),
	mOffset(0),
	mClockPin(clockPin),
	mDataPin(dataPin)
{
	this->initialize(skipSetup);
}

void HX711::initialize(uint8_t skipSetup){
	if((!skipSetup) && wiringPiSetup() == -1){
		printf("initialization failed");
	}
	pinMode(mClockPin, OUTPUT);
	pinMode(mDataPin, INPUT);
}

bool HX711::isReady(){
	return digitalRead(mDataPin) == LOW;
}

void HX711::setGain(uint8_t gain){
	switch(gain){
		case GAIN_128:
			this->mGainBits = 1;
		break;
		case GAIN_64:
			this->mGainBits = 3;
		break;
		case GAIN_32:
			this->mGainBits = 2;
		break;
		default:
			//invalid gain, ignore
		break;
	}

	digitalWrite(mClockPin, LOW);
	read();
}

int32_t HX711::read() {
	// wait for the chip to become ready
	while (!this->isReady());

	int32_t data = 0;
	// pulse the clock pin 24 times to read the data
	for(uint8_t i = 24; i--;){
		digitalWrite(mClockPin, HIGH);

		digitalRead(mDataPin);
		data |= (digitalRead(mDataPin) << i);

		digitalWrite(mClockPin, LOW);
	}

	// set the channel and the gain factor for the next reading using the clock pin
	for (int i = 0; i < mGainBits; i++) {
		digitalWrite(mClockPin, HIGH);
		digitalWrite(mClockPin, LOW);
	}

	if(data & 0x800000){
		data |= (long) ~0xffffff;
	}

	return data;
}

int32_t HX711::readAverage(uint8_t times) {
	int64_t sum = 0;
	for (uint8_t i = 0; i < times; i++) {
		sum += read();
	}
	return sum / times;
}

int32_t HX711::getRawValue(uint8_t times) {
	return mOffset - readAverage(times) ;
}

float HX711::getUnits(uint8_t times) {
	return getRawValue(times) / mScale;
}

void HX711::tare(uint8_t times) {
	uint64_t sum = readAverage(times);
	setOffset(sum);
}

void HX711::setScale(float scale) {
	mScale = scale;
}

void HX711::setOffset(int32_t offset) {
	mOffset = offset;
}

void HX711::powerDown() {
	digitalWrite(mClockPin, LOW);
	digitalWrite(mClockPin, HIGH);
}

void HX711::powerUp() {
	digitalWrite(mClockPin, LOW);
}

int32_t HX711::getOffset(){
	return this->mOffset;
}

float HX711::getScale(){
	return this->mScale;
}

int loadcell(){
	HX711 sensor(7, 0, 0);
	sensor.tare(25);
        sensor.setOffset(35000);
	sensor.setScale(500);
	int i=1;
	
	//i++;
	//printf("%d%s\n", i,"iteration");

	//printf("%f\n%s\n", sensor.getUnits(),"unit");
	//printf("%f\n%s\n", sensor.getRawValue(10),"raw");
	//printf("%d\n%s\n", sensor.readAverage(30),"av");
	//printf("%d\n%s\n", sensor.getOffset(),"offset");
/*		printf("%d\n", sensor.getOffset());*/
	 return sensor.getUnits();  
	
}

