#include <iostream>
#include <conio.h>

enum mymode_t 
{
	NORMAL_MODE = 0,
	WRITE_MODE,
	COMMAND_MODE
};
mymode_t current = NORMAL_MODE;

uint32_t write_mode_main(char c)
{
	if (c == 27) 
	{
		current = NORMAL_MODE;
		std::cout << "You are in normal mode\n";
	}
	else if (c == '\n' || c == '\r')
	{
		std::cout << "\r\n";
	}
	else
	{
		std::cout << c;
	}
	return 0;
}
uint32_t command_mode_main(char c)
{
	if (c == 27) 
	{
		current = NORMAL_MODE;
		std::cout << "You are in normal mode\n";
	}
	return 0;
}

uint32_t loop(void)
{
	char c = '\0';
	while(true)
	{
		switch(current)
		{
			case NORMAL_MODE:
				c = _getch();
				if (c == 27)
				{
					std::cout << "Exiting MyVim\n";
					return 0;
				}
				else if (c == 'w') 
				{
					std::cout << "You are in write mode\n";
					current = WRITE_MODE;
				}
				else if (c == 'c') 
				{
					std::cout << "You are in command mode\n";
					current = COMMAND_MODE; 
				}
				break;
			case WRITE_MODE: 
				write_mode_main(_getch());
				break;
			case COMMAND_MODE:
				command_mode_main(_getch());
				break;
			default:
				std::cout <<  "Error";
				return 1;
		}
	}
}

int main(int argc, char* argv[])
{
	uint32_t result = 0;
	std::cout << "Welcome to MyVim\n";

	result = loop();

	return result;
}
