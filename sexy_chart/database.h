#pragma once
class database
{
private:
	class entry
	{
	public:
		char name[15];
		int value;
		bool initialized = false;
	};
private:
	entry entries_[50];
	entry *current_ = entries_;
	
	const char* const datafile_ = "data.dat";
	static constexpr int center = 59;
	static constexpr int max_entries = 50;
	static constexpr int max_name_length = 8;

public:
	void save();
	void load();
	void add();
	void print() const;
private:
	void print_header() const;
};