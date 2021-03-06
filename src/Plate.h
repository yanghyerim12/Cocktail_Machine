// Plate.h

#ifndef _PLATE_h
#define _PLATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Stepper.h>

struct Coord {
	int pos_x, pos_y, pos_z;
	Coord() { pos_x = 0;  pos_y = 0;  pos_z = 0; }
	Coord(int ax, int ay, int az) {
		pos_x = ax;  pos_y = ay;  pos_z = az;
	}
	Coord& set(int ax = 0, int ay = 0, int az = 0) {
		pos_x = ax;  pos_y = ay;  pos_z = az;
	}
};


class Plate {
private:
	const static int STEPS_PER_REVOLUTION = 200;
	const static int STEPPER_SPEED = 30;

	Coord position;
	Stepper stepper_x;
	Stepper stepper_y;

	const int PIN_ENDSTOP_X = 1;
	const int PIN_ENDSTOP_Y = 2;
	const int PIN_ENDSTOP_Z = 3;

	// 액츄에이터 관련 코드도 추가해야함.

public:
	Plate();
	Coord get_current_position();
	void move_horizontally(Coord a_des_pos);
	void move_to_initial_position();
	void set_stepper_speed(long a_speed);
	void push_dispenser(double a_amount);
};

inline Plate::Plate() {
	position = Coord(0, 0, 0);
}



#endif


/* 스테퍼 레퍼런스:
https://github.com/arduino-libraries/Stepper
https://www.arduino.cc/en/reference/stepper
*/