#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <ctime>

class Chronometer {

private:

    // Armazena o tempo de início da contagem
    static clock_t begin;

    // Armazena o tempo do fim da contagem
    static clock_t end;

    // Armazena a diferença de tempo, i.e., o tempo total gasto
    static double timeElapsed;

public:

	static void start();

	static void stop();

	static double elapsedTime();

};

#endif // CHRONOMETER_H
