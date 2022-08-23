#include <iostream>
#include <vector>

class Helper
{
public:
	static void drawMenu(std::string menuName, std::vector<std::string> options)
	{
		int count = 1;
		
		std::cout << "\t\t\t\t_____________________________\n";
		std::cout << "\t\t\t\t                             \n";
		std::cout << "\t\t\t\t   " << menuName << "\n";
		std::cout << "\t\t\t\t                             \n";
		std::cout << "\t\t\t\t_____________________________\n";
//		
		for(std::string option: options){
			std::cout << "\t\t\t\t                             \n";
			std::cout << "\t\t\t\t    " << count << ")." << option << "\n";
			count++;
		}
		
		std::cout << "\t\t\t\t                             \n";
	}
	
	static int getIntInput(std::string message)
	{
		int choice;
		std::cout << "\n\t\t\t" << message << ":  ";
		std::cin >> choice;
		return choice;
	}
	
	static std::string getStringInput(std::string message)
	{
		std::string choice;
		std::cout << "\n\t\t\t" << message << ":  ";
		std::cin >> choice;
		return choice;
	}
};