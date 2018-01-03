#include <conio.h>
#include <fstream>
#include "chili.h"
#include "database.h"




void print_menu()
{
	chili::print("(A)dd\t\t(S)ave\t\t(L)oad\t\t(P)rint\n");
	chili::print(">");
}

void get_choice(char *input)
{
	chili::read(input, sizeof(input) - 1);
}

int main()
{
	bool quit = false;
	database db;
	
	while (!quit)
	{
		// Print the menu
		print_menu();

		// Get selection
		char input[2];
		get_choice(input);
		chili::print("\n");

		const char choice = input[0];
		
		switch (choice)
		{
		case 'a':
		case 'A':
			db.add();
			break;
		case 's':
		case 'S':
			db.save();
			break;
		case 'l':
		case 'L':
			db.load();
			break;

		case 'p':
		case 'P':
			db.print();
			break;
		default:
			quit = true;;
			break;
		}
		chili::print("\n\n\n");
	}
}
