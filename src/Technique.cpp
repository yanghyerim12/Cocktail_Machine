// 
// ok
// 

#include "Technique.h"

void Technique::stir() {
	// 추가해야함 (이동, led, oled, 거품기)

}

void Technique::build() {
	// 추가해야함 (이동, led, oled)
}

void Technique::f(TechniqueMethod method) {

	switch (method) {
	case TechniqueMethod::BUILD:
		build();
	case TechniqueMethod::STIR:
		stir();
	}

}

