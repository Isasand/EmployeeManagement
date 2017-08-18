#include "User.h"



User::User()
{
}

User::User(string argUserName, string argPassword)
{
	m_UserName = argUserName; 
	m_Password = argPassword;

}

User::~User()
{
}

void User::setPassword(string argPassword)
{
	m_Password = argPassword;
}

void User::setUserName(string argUserName)
{
	m_UserName = argUserName;
}

string User::getUserName()
{
	return m_UserName;
}