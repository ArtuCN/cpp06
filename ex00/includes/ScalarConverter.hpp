#ifndef SCALARCONVERTOR_HPP
#define SCALARCONVERTOR_HPP

#include <iostream>
#include <string.h>
#include <sstream>

#define FLOAT 0
#define DOUBLE 1
#define INT 2
#define CHAR 3


class ScalarConvertor
{
	private:
		ScalarConvertor() {};
	public:
		ScalarConvertor(ScalarConvertor &sc) {(void)sc;};
		ScalarConvertor operator &=(ScalarConvertor &sc) {(void)sc; return  *this;};
		~ScalarConvertor() {};

		static void convert(std::string toConvert);
};

#endif