#include "User.h"



User::User()
{
}

User::User(string argname, string argPassword, string argGender, string argDateOfBirth)
{
	m_Name = argname; 
	m_Password = argPassword;
	m_Gender = argGender;
	m_DateOfBirth = argDateOfBirth;

}


User::~User()
{
}

void User::setName(string argName)
{
	m_Name = argName;
}

void User::setGender(string argGender)
{
	m_Gender = argGender;
}

void User::setDateOfBirth(string argDOB)
{
	m_DateOfBirth = argDOB;
}

string User::getID()
{
	return m_ID;
}

string User::getName()
{
	return m_Name;
}

string User::getGender()
{
	return m_Gender;
}

string User::getDateOfBirth()
{
	return m_DateOfBirth;
}
