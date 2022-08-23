#include "headers/profile.h"
#include "headers/helper.h"

void Profile::Authentication()
{
	m:
	int choice;
	
	std::vector<std::string> options = {"Login", "Sign Up", "Exit"};
	
	Helper::drawMenu("Welcome to Password Manager.", options);
	choice = Helper::getIntInput("Please Select an option");
	
	switch(choice)
	{
		case 1:
		{
			Login();
			break;
		}
		case 2:
		{
			Register();
			break;
		}
		case 3:
		{
			exit(0);
		}
		default:
		{
			std::cout << "Please select from the given options. \n"; 
			goto m;
		}
	}
}

void Profile::Login()
{
	m:
	std::string username = Helper::getStringInput("Enter Username");
	std::string password = Helper::getStringInput("Enter Password");
	
	std::string u, p;
	std::fstream database;
	
	database.open("database.txt", std::ios::in);
	
	if(!database){
		std::cout << "User does not exist. Try again\n"; 
		goto m;
	}
	
	database >> u >> p;
	while(!database.eof())
	{
		if(username == u)
		{
			if(password == p)
			{
				this->username = username;
				this->password = password;
				this->fileName = username + "_db.txt";
				database.close();
				return ;
			}
			else
			{
				std::cout << "Wrong Password. Try again\n";
				database.close();
				goto m;
			}
			
		}
		database >> username >> password;
	}
	
	std::cout << "User does not exist. Try again\n"; 
	database.close();
	goto m;
}

void Profile::Register()
{
	m:
	std::string username = Helper::getStringInput("Enter username");
	std::string password = Helper::getStringInput("Enter password");
	
	this->username = username;
	this->password = password;
	this->fileName = username + "_db.txt";
	
	AddUserToDatabase();
}

void Profile::AddUserToDatabase()
{
	m:
	std::fstream database;
	int token = 0;
	std::string p;
	std::string u;
	
	database.open("database.txt", std::ios::in);

	if(!database)
	{
		database.open("database.txt", std::ios::app|std::ios::out);
		database  << this->username << " " << this->password << "\n";
		database.close();
	}
	else
	{
		database >> u >> p;
		while(!database.eof())
		{
			if(u == this->username)
			{
				token ++;
			}
			database >> u >> p;
		}
		
		database.close();
	}
	if(token == 1)
	{
		std::cout << "Username Already exist. Try again";
		goto m;
	}
	else
	{
		database.open("database.txt", std::ios::app|std::ios::out);
		database << this->username << " " << this->password << "\n";
		database.close();
	}
	
	CreateUserDatabase();
}


void Profile::CreateUserDatabase()
{
	std::fstream user_database;
	user_database.open(this->fileName, std::ios::app|std::ios::out);
	user_database.close();
}

