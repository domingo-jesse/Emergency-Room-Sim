//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#ifndef Treated_h
#define Treated_h

#include <queue>
#include "Patient.h"
#include <map>

class Treated {
private:
	//queue of paitenst that have been treated 
	std::queue<Patient *> Treated_queue;

	//and string of patients that have been seen 
	std::vector<Patient *> treated_patients;

	//total wait time 
	int total_wait_time;
	//total of patients cured
	int num_cured;
	// total patient wait
	int patient_wait;

public:
	Treated() : total_wait_time(0), num_cured(0) {}

	int get_num_cured() {
		return num_cured;
	}

	int get_total_wait() {
		return total_wait_time;
	}
	// used to convert two vectors into 1 single map  found at https://stackoverflow.com/questions/15912877/how-do-i-convert-values-from-a-vector-to-a-map-in-c
	std::multimap<std::string, std::string> convert_to_map(const std::vector<std::string>& vec)
	{
		std::multimap<std::string, std::string> mp;
		std::pair<std::string, std::string> par;

		for (unsigned int i = 0; i<vec.size(); i++)
		{
			if (i == 0 || i % 2 == 0)
			{
				par.first = vec.at(i);
				par.second = std::string();
				if (i == (vec.size() - 1))
				{
					mp.insert(par);
				}
			}
			else
			{
				par.second = vec.at(i);
				mp.insert(par);
			}
		}

		return mp;
	}

	//create a map to  to get ready to merge two vectors 
	std::multimap<std::string, std::string> get_treated_patients()
	{
		//vectors containing names of treated Patients
		std::vector<std::string> treated_patients_names;
		std::string treated_name;

		//loop and make two vectors which will be pushed together and made into one map 
		for (int i = 0; i < treated_patients.size(); i++)
		{
			treated_name = treated_patients[i]->getName();
			treated_patients_names.push_back(treated_name);
			std::string s = std::to_string(i);
			treated_patients_names.push_back(s);

		}
		std::multimap<std::string, std::string> mp = convert_to_map(treated_patients_names);

		return mp;


	}

	void update(int clock)
	{
		//check if empy 
		if (!Treated_queue.empty()) {
			//see pateint in front of que 
			Patient *patient = Treated_queue.front();
			//Remove 
			Treated_queue.pop();
			patient->set_patient_visits();
			//Calc time of visit
			patient_wait = clock - patient->get_arrival_time();

			//add times
			total_wait_time += patient_wait;
			// get how many patients there are 

			num_cured++;

			//add to treated
			treated_patients.push_back(patient);
		}
	}

	friend class Emergency_Room;
};

#endif 
