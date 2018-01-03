#include <conio.h>

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

	int s_to_i(char *s, const int max_size)
	{
		// scan to start point
		char *p = s;
		for (; *p >= '0' && *p <= '9'; p++);
		p--;

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