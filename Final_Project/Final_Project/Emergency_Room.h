//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#ifndef Emergency_Room_h
#define Emergency_Room_h


#include "Patient.h"
#include "Treated.h"
#include "Medical_Help.h"
#include "Simulator.h"
#include <stack>

class Simulator;

using std::queue;


extern std::queue<Patient*>needs_medical;

class Emergency_Room
{
protected:
	// input doctors and nurses 
	int num_doctors;
	int num_nurses;

	Simulator *s = NULL;
	Medical_Help *Medical_Help_pointer;

	Treated *patient_Treated_queue;

	Residents *resident_queue;


public:
	Emergency_Room(Simulator *s1) {
		s = s1;
	}

	//Set the discharge queue
	void set_resident_queue(Residents *patient_priority_queue) {
		this->resident_queue = patient_priority_queue;
	}

	void set_patient_Treated_queue(Treated *patient_Treated_queue) {
		this->patient_Treated_queue = patient_Treated_queue;
	}
	void set_num_nurses(int num_nurses) {
		this->num_nurses = num_nurses;
	}

	void set_num_doctors(int num_doctors) {
		this->num_doctors = num_doctors;
	}


	//put treated away 
	void add_patient_to_Treated(int clock)
	{

		if (!needs_medical.empty()) {

			Patient *patient = needs_medical.front();

			// treatment complete? 
			if ((clock - patient->start_med_help_time) > patient->med_help_time) {

				needs_medical.pop();

				//adds the Patient to the Treated queue
				patient_Treated_queue->Treated_queue.push(patient);
			}
			//able to treat others 
			Medical_Help *med_help = NULL;
			med_help = patient->mh;
			med_help->set_is_not_working();
		}
	}

	//if doc or nurse is ready
	void add_patient_to_needs_medical(int clock);

	friend class Treated;
	friend class Medical_Help;
};

#endif 
