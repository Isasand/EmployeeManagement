#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee()
{
}

Employee::~Employee()
{
}

void Employee::setName(string argName)
{
	m_Name = argName;
}

void Employee::setGender(string argGender)
{
	m_Gender = argGender;
}

void Employee::setDateOfBirth(string argDOB)
{
	m_DateOfBirth = argDOB;
}

void Employee::setDesignation(std::string argDesignation)
{
	m_Designation = argDesignation;
}

void Employee::setDepartment(std::string argDepartment)
{
	m_Department = argDepartment;
}

void Employee::setDateOfJoining(std::string argDOJ)
{
	m_DateOfJoining = argDOJ;
}

void Employee::setSalary(int argSalary) {
	m_Salary = argSalary;
}

string Employee::getID()
{
	return m_ID;
}

string Employee::getName()
{
	return m_Name;
}

string Employee::getGender()
{
	return m_Gender;
}

string Employee::getDateOfBirth()
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

std::string Employee::getDateOfJoining()
{
	return m_DateOfJoining;
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
	cout << "Salary: " << m_Salary << endl << endl;
}
