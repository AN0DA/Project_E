#pragma once
class Health
{
public:
	Health();
	Health(unsigned short _max, unsigned short _current);

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

class Age
{
public:
	Age();
	Age(unsigned short _max, unsigned short _reproduction);

	//setters
	void set_current(unsigned short _current);
	void set_max(unsigned short _max);
	void set_reproduction(unsigned short _reproduction);


	void modify(int _val);


	//getters
	unsigned short get_max();
	unsigned short get_current();
	unsigned short get_reproduction();

private:
	unsigned short current;
	unsigned short max;
	unsigned short reproduction;
};

class Desease
{
public:
	Desease();
	~Desease();

private:

};