#ifndef SERIALZER_HPP
#define SERIALZER_HPP
#include <stdint.h>
#include <iostream>


struct Data
{
	public:
		Data() : _num(88), _str("string that is stringing"), _info("info is informing") {};
		int _num;
		std::string _str;
		std::string _info;
};

class Serializer
{
	private:
		Serializer() {};
	public:
		Serializer(const Serializer &s) {(void)s; };
		Serializer &operator=(const Serializer &s) {(void)s; return *this;};
		
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
