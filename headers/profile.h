#include <iostream>
#include <vector>
#include <fstream>

class Profile
{
public:
	std::string username;
	std::string password;
	std::string fileName;

public:
	void Authentication();
	void Login();
	void Register();
	void AddUserToDatabase();
	void CreateUserDatabase();
};