#include "Chronometer.h"

clock_t Chronometer::begin;
clock_t Chronometer::end;
double Chronometer::timeElapsed;

void Chronometer::start() {
	begin = clock();
	end = 0;
	timeElapsed = 0;
}

void Chronometer::stop() {
	end = clock();
	timeElapsed = double(end - begin) / CLOCKS_PER_SEC;
}

double Chronometer::elapsedTime() {
	return timeElapsed;
}