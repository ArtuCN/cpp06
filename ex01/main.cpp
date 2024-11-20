#include "includes/Serializer.hpp"
#include <iostream>

int main()
{
	Data *d = new Data();
	uintptr_t x = Serializer::serialize(d);
	std::cout<< x << "\n";
	Data *d2 = Serializer::deserialize(x);
	std::cout<<"NUM: "<<d2->_num << " STR: "<<d2->_str << " INFO: " <<d2->_info<< "\n";
	delete d;
}