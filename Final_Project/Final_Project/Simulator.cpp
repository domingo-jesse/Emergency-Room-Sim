//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#include "Residents.h"
#include "Emergency_Room.h"
#include "Treated.h"
#include "Patient.h"
#include "Medical_Help.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Simulator.h"


Simulator::Simulator()
{

	// create queues - priority and treated queue
	patient_priority_queue = new Residents();
	e1 = new Emergency_Room(this);
	Treated_queue = new Treated();

}
void Simulator::data_input()
{
	std::cout << std::endl;

	// ask for user input for the rate 
	int rate = read_int("	Enter the average rate of patients per hour (1-59) : ", 1, 59);
	// arrival rate 
	double arrival_rate = rate / 60.0;

	// set rate for priorty queue 
	patient_priority_queue->set_arrival_rate(arrival_rate);

	//ask user for input for doctors 
	num_doctors = read_int("	Enter the the numbers of Doctors (1-1000) : ", 1, 1000);

	for (int i = 0; i < num_doctors; i++) {
		medical_help.push_back(new Doctor(e1));
	}

	// ask user for input for number of nurses
	num_nurses = read_int("	Please enter the number of nurses(1-1000): ", 1, 1000);

	//add a new nurse to the Medical Help vector
	for (int i = 0; i < num_nurses; i++) {
		medical_help.push_back(new Nurse(e1));
	}

	//pass references 
	e1->set_num_doctors(num_doctors);
	e1->set_num_nurses(num_nurses);
	e1->set_resident_queue(patient_priority_queue);
	e1->set_patient_Treated_queue(Treated_queue);

}

//update the clock 
void Simulator::update_medical_help(int clock) {
	e1->add_patient_to_needs_medical(clock);
	e1->add_patient_to_Treated(clock);
}


//runs the sim 
void Simulator::run_sim() {
	//Run the simulation
	for (clock = 0; clock < total_time; ++clock)
	{

		//update residents
		patient_priority_queue->update(clock);

		//check to see doctor availibity 
		update_medical_help(clock);

		//update the treated 
		Treated_queue->update(clock);
	}
}



//Function to display menu
void Simulator::display_results()
{
	//User input for menu option
	int ans = 0;

	//menu 
	std::cout << "		What Do you want to do?  " << std::endl;

	std::cout << "	       --------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "	1. Look at all the treated Patients " << std::endl;

	std::cout << "	2. Search by name to see if a Resident was treated. " << std::endl;

	std::cout << "	3. Find the avergage time for treatment " << std::endl;

	std::cout << "	4. Exit " << std::endl;
	do
	{// ask for user input 
		std::cout << std::endl;
		std::cout << "		Enter what you want to do" << std::endl;
		std::cin >> ans;
		if (ans != 1 && ans != 2 && ans != 3 && ans != 4) {
			std::cout << "		Invaild entry. Please Try again." << std::endl;
		}

	} while (ans != 1 && ans != 2 && ans != 3 && ans != 4);

	// switch statment for answer 
	switch (ans)
	{
	case 1:

		List_Names();
		break;

	case 2:

		Search_Name();
		break;

	case 3:
		Calc_Ave_Time();
		break;

	case 4:
		break;
	}
}

//Output list of Patients treated
void Simulator::List_Names()
{

	std::multimap<std::string, std::string> display_names = Treated_queue->get_treated_patients();


	// same sourced use eailer on how to merge two vectors found it useful for displaying the list of names https://stackoverflow.com/questions/15912877/how-do-i-convert-values-from-a-vector-to-a-map-in-c
	// helps give patient number which is helpful info 
	for (auto it = display_names.cbegin(); it != display_names.cend(); ++it)
		std::cout << "		 [" << (*it).first << " Patient number  : " << (*it).second << ']' << std::endl;


	//Display menu to user again
	std::cout << std::endl;
	display_results();
}

//Output Individual Patients by name to user
void Simulator::Search_Name()
{
	std::string search_name;

	//ask user to input a name
	std::cout << "		Please enter a name to search. ";
	std::cin >> search_name;
	int num_visits = 0;

	// using upper and lower bound to idenify several names 
	std::multimap<std::string, std::string> t_patients = Treated_queue->get_treated_patients();
	std::multimap<std::string, std::string>::iterator it = t_patients.lower_bound(search_name);

	if (it == t_patients.end())
		std::cout << "		The person you entered did not vist the Hospital";
	else
	{
		// maps are super helpful to see how many people came that where the same name. 
		for (; it != t_patients.upper_bound(search_name); it++) {
			std::cout << "		Hospital Visted By : "
				<< it->first << " ->  Paitent Number : " << it->second;
			num_visits++;
			std::cout << std::endl;
		}

	}


	std::cout << std::endl;

	std::cout << "		" << search_name << " visited the hospital " << num_visits << " times. ";

	//display  menu to user again
	std::cout << std::endl;
	display_results();

}
void Simulator::Calc_Ave_Time()
{
	//total cured 
	double total_patients = Treated_queue->get_num_cured();
	//total wait 
	double wait_time = Treated_queue->get_total_wait();

	//Ave wait 
	double total_visit_time = (wait_time / total_patients);
	//Output results 
	std::cout << "		Average wait time for patients " << total_visit_time << " minutes " << std::endl;
	std::cout << std::endl;

	//display menu
	std::cout << std::endl;
	display_results();
}

