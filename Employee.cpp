#include "Employee.h"



Employee::Employee()
{
}


Employee::~Employee()
{
}

std::string Employee::getID()
{
	return m_ID;
}

std::string Employee::getName()
{
	return m_Name;
}

std::string Employee::getGender()
{	
	std::string M = "Male"; 
	std::string F = "Female";

	if (m_Gender == 'M') {
		return "Male";
	}
	else return "Female";
}
