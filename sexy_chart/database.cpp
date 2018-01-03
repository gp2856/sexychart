#include "database.h"
#include <fstream>
#include "chili.h"

void database::save()
{
	std::ofstream out(datafile_, std::ios_base::binary);
	out.write(reinterpret_cast<char*> (entries_), sizeof(entry) * 50);
}

void database::load()
{
	std::ifstream in(datafile_, std::ios_base::binary);
	in.read(reinterpret_cast<char*> (entries_), sizeof(entry) * 50);
}

void database::add()
{
	char buffer[max_name_length];
	chili::print("\nEnter a name: ");
	chili::read(buffer, max_name_length);

	// Copy the input into the name field of the current entry
	chili::strcpy(current_->name, buffer);
	chili::print("\nEnter a value: ");
	chili::read(buffer, max_name_length);

	// Copy the input into the value field of the current entry
	current_->value = chili::s_to_i(buffer, max_name_length);

	// Flag entry as initialized and move to the next entry
	current_->initialized = true;
	current_++;
}

void database::print() const
{
	print_header();

	// Loop up until the number of indexed entries
	for(int i = 0; i < max_entries; i++)
	{
		if (entries_[i].initialized)
		{
			// and print each entry
			// Print the name, followed by padding up until the width of the name field.
			chili::print(entries_[i].name);
			for (int c = 0; c <= 8; c++)
			{
				chili::print(" ");
			}
			chili::print("|");

			// Then print '=' times the value
			for (int y = 0; y <= entries_[i].value; y++)
			{
				chili::print("=");
			}

			// End with a newline
			chili::print("\n");
		}
		else
		{
			break;
		}
	}
}

void database::print_header() const
{
	chili::print("\n");
	for (int i = 0; i < center - 9; i++)
	{
		chili::print(" ");
	}
	chili::print("Beautiful Sexy Chart\n");
	for (int i = 0; i < center - 3; i++)
	{
		chili::print(" ");
	}
	chili::print("Bitches!\n");
	for (int i = 0; i < center - 23; i++)
	{
		chili::print(" ");
	}
	for (int i = 0; i < 48; i++)
	{
		chili::print("=");
	}
	chili::print("\n\n\n");
}

