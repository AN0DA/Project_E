#pragma once
class Stat
{
public:
	Stat(unsigned short _max = 100, unsigned short _current = 100);

	//setters
	void set_current(unsigned short _current);
	void set_max(unsigned short _max);

	void modify(int _val);

	//getters
	unsigned short get_max();
	unsigned short get_current();

private:
	unsigned short current;
	unsigned short max;
};