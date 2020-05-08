#pragma once

/**
* Instance of stats
* represents a statistic of animal that have max and current level and cannot be less than 0
*
*/
class Stat
{
public:
	/**
	* Default constructor
	*
	* @param _max Maximum amount of given statistic
	* @param _current Currnet amount of given statistic
	*/
	Stat(unsigned short _max = 100, unsigned short _current = 100);

	/**
	* Sets current statistic
	* @param _current Value
	*/
	void set_current(unsigned short _current);
	/**
	* Sets max statistic
	* @param _max Value
	*/
	void set_max(unsigned short _max);

	/**
	* Adds or substract given value from current
	*
	* @param _val Value that modifies current value. Positive for addition. Negative for substraction
	*/
	void modify(int _val);

	/**
	* Returns maximum value of statistic
	* @return Maximum statistic
	*/
	unsigned short get_max();
	/**
	* Returns current value of statistic
	* @return Current statistic
	*/
	unsigned short get_current();

private:
	unsigned short current;
	unsigned short max;
};