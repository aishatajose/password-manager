#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "headers/helper.h"
#include "headers/profile.h"

class PassWordManager
{
public:
	Profile profile;
	
public:
	PassWordManager();
	void Menu();
	void StorePassword(std::string key);
	void CreatePassword(std::string key);
	std::string GeneratePassword();
	void AddPasswordToUserDatabase(std::string key, std::string password);
	void ViewPassword(std::string key);
	void ViewAllPasswords();
};