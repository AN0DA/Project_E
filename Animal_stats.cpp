#include "Animal_stats.h"

//Health - - - - - - -  -- - - - -- - - - - -  

Health::Health() {
	current = 100;
	max = 100;
}
Health::Health(unsigned short _max, unsigned short _current) {
	current = _current;
	max = _max;
}

void Health::set_current(unsigned short _current) {
	current = _current;
}
void Health::set_max(unsigned short _max) {
	max = _max;
}

void Health::modify(int _val) {
	if (current + _val > max) current = max;
	else if (current - _val < 0) current = 0;
	else current += _val;
}

unsigned short Health::get_max() {
	return max;
}
unsigned short Health::get_current() {
	return current;
}

//Age - - - -  - - -- - - - - - - - -

Age::Age() {
	current = 0;
	max = 100;
	reproduction = 20;
}
Age::Age(unsigned short _max, unsigned short _reproduction) {
	current = 0;
	max = _max;
	reproduction = _reproduction;
}
void Age::set_current(unsigned short _current) {
	current = _current;
}
void Age::set_max(unsigned short _max) {
	max = _max;
}
void Age::set_reproduction(unsigned short _reproduction) {
	reproduction = _reproduction;
}
void Age::modify(int _val) {
	if (current + _val > max) current = max + 1;
	else if (current - _val < 0) current = 0;
	else current += _val;
}

unsigned short Age::get_max() {
	return max;
}
unsigned short Age::get_current() {
	return current;
}
unsigned short Age::get_reproduction() {
	return reproduction;
}


