//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#ifndef Medical_Help_h
#define Medical_Help_h

class Emergency_Room;

class Medical_Help {
protected:
	// create Emergcy room pointer
	Emergency_Room * emergency_room;
	bool working = false;
public:

	Medical_Help(Emergency_Room *emergency_room) {
		emergency_room = emergency_room;
	};
	// abstract class so set to zero doctor and nurse will inherit this 
	virtual int get_care_time() = 0;
	// abstract class so set to zero doctor and nurse will inherit this 
	virtual int get_max_priority() = 0;

	//sets Medical Help to working or not on a patient 
	void set_working() {
		working = true;
	}
	//sets Medical Help to not working
	void set_is_not_working() {
		working = false;
	}
	// determines if the Help is busy 
	bool get_working() {
		return working;
	}

	friend class Emergency_Room;
};


#endif 
