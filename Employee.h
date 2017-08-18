#pragma once
#include <String>
#include <iostream>

using namespace std;

class Employee
{
public:
	Employee();
	Employee(string argName, string argGender, string argID, string argDOB, string argDesignation, string argDepartment, int argSalary) {
		m_Name = argName;
		m_Gender = argGender;
		m_ID = argID;
		m_DateOfBirth = argDOB;
		m_Designation = argDesignation;
		m_Department = argDepartment;
		m_Salary = argSalary;
	};
	~Employee();

	void setName(string argName);
	void setGender(string argGender);
	void setDateOfBirth(string argDOB);
	void setDesignation(string argDesignation);
	void setDepartment(string argDepartment);
	void setDateOfJoining(string argDOJ);
	void setSalary(int argSalary);
	string getID();
	string getName();
	string getGender();
	string getDateOfBirth();
	string getDesignation();
	string getDepartment();
	string getDateOfJoining();
	int getSalary();
	void getInfo();

	
private: 
	string m_ID;
	string m_Name;
	string m_Gender;
	string m_DateOfBirth;
	string m_Designation;
	string m_Department;
	string m_DateOfJoining;
	int m_Salary;
};

