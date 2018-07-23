//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#ifndef Simulator_h
#define Simulator_h

#include "Residents.h"
#include "Doctor.h"
#include "Nurse.h"
class Patient;

using std::queue;

class Simulator
{
private:
	// week of time 
	int total_time = 10080;
	//	minute by minute snap shot using the clock
	int clock;
	//number of doctors
	int num_doctors;
	//number of nurses
	int num_nurses;


	Emergency_Room *e1 = NULL; //Emergency_Room pointer

	std::vector<Medical_Help*> medical_help; //medical_help vec to easily add help

	Residents *patient_priority_queue; // create a queue where prority is maintained
	Treated *Treated_queue;	// create que where the treated people go to 


							//is the input vaild. 
	int read_int(const std::string &prompt, int low, int high)
	{
		//Executes if number is in an invalid range
		if (low >= high)
			throw std::invalid_argument("invalid range specified");

		std::cin.exceptions(std::ios_base::failbit);

		int num = 0;
		while (true) {
			try {
				while (true) {
					std::cout << prompt;
					std::cin >> num;
					//Executes if number is within the specified range
					if (num >= low && num <= high) {
						std::cout << std::endl;
						return num;
					}
				}
			}
			catch (std::ios_base::failure) {
				std::cout << "Bad numeric string -- try again\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}
	}

public:
	Simulator();

	//Medical Helper objects
	std::vector<Medical_Help*> get_med_help_Vector() { return medical_help; }

	//functions used in Simulator
	void data_input();
	void update_medical_help(int clock);
	void run_sim();
	void display_results();
	void List_Names();
	void Search_Name();
	void Calc_Ave_Time();


	friend class Emergency_Room;
};

#endif 
