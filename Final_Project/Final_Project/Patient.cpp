//Jesse Domingo 
// Pete Tucker 
// CS273 
// FInal Project 
//
#include "Patient.h"
class Patient;

//Orders the patients priority
bool operator<(const Patient& first, const Patient& second)
{
	if (first.getPriority() < second.getPriority())
		return true;
	else if (first.getPriority() > second.getPriority())
		return true;
	else
		return false;
}
