#include <conio.h>
#include <fstream>


namespace chili
{
	void print(const char* s)
	{
		// Loop through the string and print each character until we hit a null terminator
		for (; *s != 0; s++)
		{
			_putch(*s);
		}
	}

	void print_i(const int i)
	{
		_putch(i);
	}

	void read(char * buf, const int max_size)
	{
		const char * const end = buf + max_size;
		for (char c = _getch(); c != 13 && buf + 1 < end; c = _getch(), buf++)
		{
			*buf = c;
			_putch(c);
		}
		*buf = 0;
	}

	void strrev(char * s, const int max_size)
	{
		char *p = s;
		for (; *p != 0; p++);
		p--;

		for (; p > s; s++, p--)
		{
			const char temp = *p;
			*p = *s;
			*s = temp;
		}
	}

	const char *scan_to_end(const char *buf, const int max_size)
	{
		// return a pointer to the furthest element in the buffer
		// up to the first invalid character.

		const char *p = buf;
		for (; *p >= '0' && *p <= '9'; p++);
		p--;

		return p;
	}

	int s_to_i(char *s, const int max_size)
	{
		// scan to start point
		const char *p = scan_to_end(s, max_size);

		int val = 0;
		int place = 1;

		for (; p >= s; p--)
		{
			val += (*p - '0') * place;
			place *= 10;
		}

		return val;
	}

	void i_to_s(char *buffer, int n, const int max_size)
	{
		char * const p_start = buffer;

		for (; n > 0; n /= 10, buffer++)
		{
			*buffer = (n % 10) + '0';
		}
		*buffer = 0;
		strrev(p_start, max_size);
	}

	int strlen(const char* buffer)
	{
		int len = 0;
		for (; *buffer != 0; buffer++, len++);
		return len;
	}	

	char *scan_to_end(char *buf, const int max_size)
	{
		// return a pointer to the furthest element in the buffer
		// up to the first invalid character.

		char *p = buf;
		for (; *p >= '0' && *p <= '9'; p++);
		p--;

		return p;
	}

	char *strcpy(char *d, const char *s)
	{
		char *saved = d;
		while (*s)
		{
			*d++ = *s++;
		}
		*d = 0;
		return saved;
	}
}

void print_header()
{
	const int center = 59;
	chili::print("\n");
	for(int i = 0; i < center - 9; i++)
	{
		chili::print(" ");
	}
	chili::print("Beautiful Sexy Chart\n");
	for(int i = 0; i < center - 3; i++)
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
}

class row
{
public:
	char name[15];
	int value;

};
void print_padded(const char* s, const int width, const int size)
{
	for (int i = 0; i <= width; i++)
	{
		chili::print(" ");
	}
	chili::print(s);
}
void print_chart(row* db)
{
	chili::print("\n\n\n");
	
	for (int i = 0; i < 50; i++)
	{
		chili::print(db[i].name);
		chili::print("\n");
	}
}

void add_row(row* db)
{
	char buffer[15];
	chili::print("\nEnter a name: ");
	chili::read(buffer, sizeof(buffer));
	chili::strcpy(db->name, buffer);
	chili::print("\nEnter a value: ");
	chili::read(buffer, sizeof(buffer));
	db->value = chili::s_to_i(buffer, sizeof(buffer));
}

void save(row* db)
{
	std::ofstream out("data.dat", std::ios_base::binary);
	out.write(reinterpret_cast<char*> (db), sizeof(row) * 50);
}
void load(row* db)
{
	std::ifstream in("data.dat", std::ios_base::binary);
	in.read(reinterpret_cast<char*> (db), sizeof(row) * 50);
}
int main()
{
	bool quit = false;
	row db[50];
	row *row = db;
	
	while (!quit)
	{
		
		chili::print("(A)dd\t\t(S)ave\t\t(L)oad\t\t(P)rint\n");
		chili::print(">");
		char input[2];
		chili::read(input, 2);
		chili::print("\n");

		
		switch (input[0])
		{
		case 'a':
		case 'A':
			add_row(row);
			row++;
			break;
		case 's':
		case 'S':
			save(row);
			break;
		case 'l':
		case 'L':
			load(row);
			break;

		case 'p':
		case 'P':
			print_header();
			print_chart(row);
			break;
		default:
			quit = true;;
			break;
		}
		chili::print("\n\n\n");
	}
}
