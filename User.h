#include <String>

using namespace std;

class User
{
public:
	User();
	User(string argname, string argPassword, string argGender, string argDateOfBirth);
	~User();

	void setName(string argName);
	void setGender(string argGender);
	void setDateOfBirth(string argDOB);

	string getID();
	string getName();
	string getGender();
	string getDateOfBirth();

protected:
	string m_ID;
	string m_Password;
	string m_Name;
	string m_Gender;
	string m_DateOfBirth;
};
