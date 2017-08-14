#include "Employee.h"
#include <iostream>

using namespace std;

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
	return m_Gender;
}

std::string Employee::getDateOfBirth()
{
	return m_DateOfBirth;
}

std::string Employee::getDesignation()
{
	return m_Designation;
}

std::string Employee::getDepartment()
{
	return m_Department;
}

int Employee::getSalary()
{
	return m_Salary;
}
void Employee::getInfo()
{
	cout << "ID: " << m_ID << endl;
	cout << "Name: " << m_Name << endl;
	cout << "Gender: " << m_Gender << endl;
	cout << "Date of birth: " << m_DateOfBirth << endl;
	cout << "Designation: " << m_Designation << endl;
	cout << "Department: " << m_Department << endl;
	cout << "Salary: " << m_Salary << endl;
}
