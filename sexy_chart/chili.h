#pragma once
namespace chili
{
	// I/O
	void print(const char* s);
	void read(char * buf, const int max_size);

	// String Operations
	void strrev(char * s, const int max_size);
	int s_to_i(char *s, const int max_size);
	void i_to_s(char *buffer, int n, const int max_size);
	int strlen(const char* buffer);
	char *strcpy(char *d, const char *s);
}