// Technique.h

#ifndef _TECHNIQUE_h
#define _TECHNIQUE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


enum class TechniqueMethod {
	BUILD,
	STIR,
};


class Technique {
private:
	void build();
	void stir();
	TechniqueMethod method;
public:
	void f(TechniqueMethod method);
	Technique set_technique(TechniqueMethod tm) { method = tm; }

};


#endif

