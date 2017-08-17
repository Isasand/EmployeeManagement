#pragma once
#include "User.h"
#include <String>
#include <iostream>

class Employee : public User
{
public:
	Employee();
	Employee(string argName, string argPassword, string argGender, string argDateOfBirth) : User(argName, argPassword, argGender, argDateOfBirth) {};
	Employee(std::string argDesignation, std::string argDepartment, string dateOfJoining, int argSalary) {
		m_Designation = argDesignation;
		m_Department = argDepartment;
		m_Salary = argSalary;
	};
	~Employee();

	void setDesignation(std::string argDesignation);
	void setDepartment(std::string argDepartment);
	void setDateOfJoining(std::string argDOJ);
	void setSalary(int argSalary);
	std::string getDesignation();
	std::string getDepartment();
	std::string getDateOfJoining();
	int getSalary();
	void getInfo();
	
private: 
	std::string m_Designation;
	std::string m_Department;
	std::string m_DateOfJoining;
	int m_Salary;
};

