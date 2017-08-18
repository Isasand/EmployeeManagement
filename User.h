#include <String>

using namespace std;

class User
{
public:
	User();
	User(string argUserName, string argPassword);
	~User();

	void setUserName(string argUserName);
	void setPassword(string argPassword);

	string getUserName();


protected:
	string m_UserName;
	string m_Password;
};
