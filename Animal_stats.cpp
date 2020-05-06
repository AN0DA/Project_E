#include "Animal_stats.h"

//Stat - - - - - - -  -- - - - -- - - - - -  


Stat::Stat(unsigned short _max, unsigned short _current){
	current = _current;
	max = _max;
}

void Stat::set_current(unsigned short _current) {
	current = _current;
}
void Stat::set_max(unsigned short _max) {
	max = _max;
}

void Stat::modify(int _val) {
	if (current + _val > max) current = max;
	else if (current - _val < 0) current = 0;
	else current += _val;
}

unsigned short Stat::get_max() {
	return max;
}
unsigned short Stat::get_current() {
	return current;
}


