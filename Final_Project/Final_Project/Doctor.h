//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#ifndef Doctor_h
#define Doctor_h

#include "Emergency_Room.h"
// create the doctor class inheriting form medical_Help 
class Doctor : public Medical_Help
{
protected:
	//  intialize caretime 
	int care_time;
	// set the max priority to 20 
	const int max_priority = 20;
	// create and emergency room pointer. 
	Emergency_Room *emergency_room;

public:
	// polymorphism from Medical Help
	Doctor(Emergency_Room *emergency_room) : Medical_Help(emergency_room) {}
	// creates the maximum care time randomly is form 1-20 minutes 
	int get_care_time() {
		care_time = rand() % (20) + 1;
		return care_time;
	}
	// returns the max priority for the doctor which in this case is priority number 20. 
	int get_max_priority() {
		return max_priority;
	}

};

#endif 
