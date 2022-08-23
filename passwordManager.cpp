#include "headers/passwordManager.h"

PassWordManager::PassWordManager()
{
	Profile user_profile;
	user_profile.Authentication();
	this->profile = user_profile;
	Menu();
}

void PassWordManager::Menu()
{
	int choice;
	
	std::string key;
	
	std::vector<std::string> options = {"Store Password", "View Password", "View all Password", "Exit"};
	
	Helper::drawMenu("Password Manager Menu", options);
	choice = Helper::getIntInput("Please Select an option");
	

	switch(choice)
	{
		case 1:
		{
			key = Helper::getStringInput("Enter the key/name of the website or account");
			StorePassword(key);
			break;
		}
		case 2:
		{
			key = Helper::getStringInput("Enter the key/name of the website or account");
			ViewPassword(key);
			break;
		}
		case 3:
		{
			ViewAllPasswords();
			break;
		}
		case 4:
		{
			exit(0);
		}
		default:
		{
			std::cout << "Please select from the given options "; 
		}
	}
}

void PassWordManager::StorePassword(std::string key)
{
	m:
	int choice;
	std::string password;
	
	std::vector<std::string> options = {"Input Password", "Generate Password", "Go back to Menu", "Exit"};
	
	Helper::drawMenu("Do you want to input/ generate password", options);
	choice = Helper::getIntInput("Please Select an option");

	switch(choice)
	{
		case 1:
		{
			password = Helper::getStringInput("Enter the password of the website or account");
			AddPasswordToUserDatabase(key, password);
			break;
		}
		case 2:
		{
			std::cout << "\t\t Generating password ... \n";
			password = GeneratePassword();
			AddPasswordToUserDatabase(key, password);
			std::cout << "\t\t  Password generated and saved. \n";
			break;
		}
		case 3:
		{
			Menu();
		}
		case 4:
		{
			exit(0);
		}
		default:
		{
			std::cout << "Please select from the given options "; 
			goto m;
		}
	}
}

void PassWordManager::AddPasswordToUserDatabase(std::string key, std::string password)
{
	std::fstream user_database;
	
	user_database.open(this->profile.fileName, std::ios::app|std::ios::out);
	user_database << key << " " << password << "\n";
	user_database.close();

}

std::string PassWordManager::GeneratePassword()
{
	const char digits[] = "0123456789";
	const char symbols[] = "!@#$%^&*";
	const char lowerCase[] = "abcdefghijklmnopqrstuvwxyz";
	const char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char allCharacters[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	srand(time(0));
	
	std::string password = "";
	password = password + digits[rand() % 10];
	password = password + symbols[rand() % 10];
	password = password + lowerCase[rand() % 10];
	password = password + upperCase[rand() % 10];
	random_shuffle(password.begin(), password.end());
	
	for(int i = 0; i < 8; i++)
		password = password + allCharacters[rand() % 70];
		
	return password;
}

void PassWordManager::ViewPassword(std::string key)
{
	std::fstream user_database;
	std::string k, p;
	bool passwordFound;
	
	user_database.open( this->profile.fileName, std::ios::in);
	
	user_database >> k >> p;
	while(!user_database.eof())
	{
		if(k == key)
		{
			std::cout << key << " ---> " << p << "\n";
			passwordFound = true;
			break;
		}
		user_database >> k >> p;
	}
	user_database.close();
	
	if(!passwordFound)
	{
		std::cout << "Password not found!.\n";
	}
}

void PassWordManager::ViewAllPasswords()
{
	std::fstream user_database;
	std::string k, p;
	user_database.open(this->profile.fileName, std::ios::in);
	
	user_database >> k >> p;
	while(!user_database.eof())
	{
		std::cout << k << " ---> " << p << "\n";
		user_database >> k >> p;
	}
	
	user_database.close();
}
