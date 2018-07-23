//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#ifndef Patient_h
#define Patient_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Medical_Help;

std::string get_rand_name(std::string);

struct Patient
{
	Patient(int clock, int priority_level, std::string p_name) : priority_level(priority_level), name(p_name), patient_visits(-1), arrival_time(clock), start_med_help_time(-1), med_help_time(-1) {}

	Patient(std::string n)
	{
		name = n;
	}

	//Patient's info
	int priority_level;
	std::string name;
	int patient_visits;
	int arrival_time;
	int start_med_help_time;
	int med_help_time;
	Medical_Help *mh = NULL;


	// get and set name 
	std::string getName() const { return name; }
	void setName() { name = get_rand_name(); }

	//get and set med help time
	int get_start_med_help_time() { return start_med_help_time; }
	void set_med_help_time(int t) { med_help_time = t; }

	// get and set patient visits 
	int get_patient_visits() { return patient_visits; }
	void set_patient_visits() { patient_visits++; }

	// get the arrival time
	int get_arrival_time() { return arrival_time; }

	// get the priority number 
	double getPriority() const { return priority_level; }

	// set when med help was started 
	void set_start_med_help_time(int t) { start_med_help_time = t; }

	// set up the medical helper 
	void set_med_help(Medical_Help *med_help) { mh = med_help; }


	//Random Name Generator
	static std::string get_rand_name()
	{
		static std::vector<std::string> Firstnames;
		std::string final_name;

		while (Firstnames.size() == 0)
		{
			std::string line;

			//First Names
			std::vector<std::string> fnames;
			std::fstream FirstNames;

			//open the file with the names of the residents
			FirstNames.open("/Users/Jesse/Desktop/residents_of_273ville.txt");

			if (FirstNames.fail())
			{
				std::cout << "Cannot open first name file" << std::endl;
			}

			//store the first names in the vector names
			if (FirstNames.is_open())
			{

				while (std::getline(FirstNames, line))
				{
					fnames.push_back(line);
				}
				FirstNames.close();
			}


			for (int i = 0; i < fnames.size() - 1; i++)
			{
				int fnum = std::rand() % 1999 + 1;

				std::string RandomName = fnames.at(fnum);

				Firstnames.push_back(RandomName);
			}

		}

		int fn = rand() % 1998 + 1;
		final_name = Firstnames.at(fn);

		//ge the final randomized name 
		return final_name;
	}

	friend class Simulator;
};


#endif 
