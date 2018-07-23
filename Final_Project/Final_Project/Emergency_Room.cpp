//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#include "Emergency_Room.h"
std::queue<Patient*>needs_medical;

//goes if nurse or doc is not working
void Emergency_Room::add_patient_to_needs_medical(int clock)
{
	if (needs_medical.empty())
	{
		if (!resident_queue->patient_priority_queue.empty())
		{

			Patient *patient = resident_queue->patient_priority_queue.top();

			Medical_Help *mh1 = NULL;

			// see who is available
			std::vector <Medical_Help*> unavailable_medical_help;
			std::vector <Medical_Help*> available_medical_help;
			s->get_med_help_Vector();

			for (int i = 0; i < s->medical_help.size(); i++)
			{
				mh1 = s->medical_help[i];
				if (mh1->get_working() == false)
				{
					available_medical_help.push_back(mh1);
				}
				else
				{
					unavailable_medical_help.push_back(mh1);
				}
			}
			//people who cant be treated 
			std::stack<Patient*> patient_stack;

			//one help is found goes
			for (int i = 0; i < available_medical_help.size(); i++)
			{
				//if no patients stop 
				if (resident_queue->patient_priority_queue.empty())
				{
					break;
				}


				mh1 = available_medical_help[i];
				int mh_time = 0;
				mh_time = mh1->get_care_time();

				//find highest  priroty 
				patient = resident_queue->patient_priority_queue.top();
				//Remove that patient from the priority queue
				resident_queue->patient_priority_queue.pop();

				//determine if they can be treated
				if (patient->getPriority() > mh1->get_max_priority()) {
					patient_stack.push(patient);
				}
				else {
					//add help 
					needs_medical.push(patient);

					//Set patient's treatment time
					patient->set_med_help_time(mh_time);
					mh1->set_working();

					//Update 
					int t_time = clock;
					patient->set_start_med_help_time(t_time);
					patient->set_med_help(mh1);
				}

			}

			//Add patients back to priority queue to be treated
			for (int i = 0; i < patient_stack.size(); i++)
			{
				Patient *p2 = NULL;
				p2 = patient_stack.top();
				patient_stack.pop();
				resident_queue->patient_priority_queue.push(p2);
			}

		}
	}
};
