#pragma once
#include <String>
#include <iostream>

class Employee
{
public:
	Employee();
	Employee(std::string argName, std::string argID, std::string argGender, std::string argDateOfBirth, std::string argDesignation, std::string argDepartment, int argSalary) {
		m_Name = argName;
		m_ID = argID;
		m_Gender = argGender;
		m_DateOfBirth = argDateOfBirth;
		m_Designation = argDesignation;
		m_Department = argDepartment;
		m_Salary = argSalary;
	};
	~Employee();

	std::string getID();
	std::string getName();
	std::string getGender();
	std::string getDateOfBirth();
	std::string getDesignation();
	std::string getDepartment();
	std::string getDateOfJoining();
	int getSalary();
	void getInfo();
	
private: 
	std::string m_Name;
	std::string m_ID;
	std::string m_Gender;
	std::string m_DateOfBirth;
	std::string m_Designation;
	std::string m_Department;
	std::string m_DateOfJoining;
	int m_Salary;
};

