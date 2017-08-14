#pragma once
#include <String>
#include <iostream>

class Employee
{
public:
	Employee();
	~Employee();

	std::string getID();
	std::string getName();
	std::string getGender();
	std::string getDateOfBirth();
	std::string getDesignation();
	std::string getDepartment();
	int getSalary();
	std::string getInfo();
	
private: 
	std::string m_Name;
	std::string m_ID;
	char m_Gender;
	std::string m_DateOfBirth;
	std::string m_Designation;
	std::string m_Department;
	std::string m_DateOfJoining;
	int m_Salary;
};

