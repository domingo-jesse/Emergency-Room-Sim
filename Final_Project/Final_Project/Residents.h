//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#ifndef Residents_h
#define Residents_h
#include <queue>
#include "Patient.h"


using std::queue;
class Residents {
private:
	//the arrival rate 
	double arrival_rate;
	//queue of residnets that could be treated 
	std::priority_queue<Patient*> patient_priority_queue;

public:
	Residents() {}
	// set the rate 
	void set_arrival_rate(double arrival_rate) {
		this->arrival_rate = arrival_rate;
	}


	void update(int clock)
	{
		//get random name of patient 
		std::string patient_name = Patient::get_rand_name();

		// get random double from 0-1 
		double rand_double = (double)rand() / (RAND_MAX);
		if (rand_double < arrival_rate)
		{
			// a random priority level

			double rand_priority = (double)rand() / (RAND_MAX);
			double priority_level = rand_priority;

			int patient_priority_level;

			// break down the precentages of the random give random number 1-20 
			if (priority_level <= 0.7)
			{
				patient_priority_level = rand() % (9) + 1;
			}
			if (priority_level > 0.7 && priority_level <= 0.9)
			{
				patient_priority_level = rand() % (4) + 10;

			}
			else
			{
				patient_priority_level = rand() % (4) + 15;
			}

			// new patient with the new info. 
			patient_priority_queue.push(new Patient(clock, patient_priority_level, patient_name));
		}
	}

	friend class Emergency_Room;

};

#endif 
