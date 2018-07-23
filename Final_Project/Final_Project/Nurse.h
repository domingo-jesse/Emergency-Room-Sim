//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#ifndef Nurse_h
#define Nurse_h
// create Nurse Class inheriting from the nurse class 
class Nurse : public Medical_Help
{
protected:
	// create the maxmimun protorty time 
	const int max_priority = 10;
	//intiatilize care time 
	int care_time;
	// create Emergency Room pointer 
	Emergency_Room *emergency_room;

public:
	//Constructor for Nurse object inheriting form Medica_Help 
	Nurse(Emergency_Room *emergency_room) : Medical_Help(emergency_room) {}
	// create a random care time ranging from 1-10 
	int get_care_time() {
		care_time = (rand() % (9) + 1);
		return care_time;
	}
	// return max prority which in this case is 10. 
	int get_max_priority() {
		return max_priority;
	}

};

#endif 
