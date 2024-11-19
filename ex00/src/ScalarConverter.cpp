#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>

int ftNum(const char &i)
{
	if (i <= '9' && i >= '0')
		return (1);
	return (0);
}

void printFloat(float f)
{
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	if (!c)
		std::cout<<"char: Non displayable\n";
	else if (f < 0)
		std::cout<<"char: impossible\n";
	else
	 	std::cout<<"char: '"<< c <<"'\n";
	std::cout<<"int: "<< i <<"\n";
	if (f != i)
	{
		std::cout<<"float: "<< f <<"f\n";
		std::cout<<"double: "<< d <<"\n";
	}
	else
	{
		std::cout<<"float: "<< f <<".0f\n";
		std::cout<<"double: "<< d <<".0\n";
	}
}

void printDouble(double d)
{
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (!c)
		std::cout<<"char: Non displayable\n";
	else if (d < 0)
		std::cout<<"char: impossible\n";
	else
	 	std::cout<<"char: '"<< c <<"'\n";
	std::cout<<"int: "<< i <<"\n";
	if (d != i)
	{
		std::cout<<"float: "<< f <<"f\n";
		std::cout<<"double: "<< d <<"\n";
	}
	else
	{
		std::cout<<"float: "<< f <<".0f\n";
		std::cout<<"double: "<< d <<".0\n";
	}
}

void printInt(int i)
{
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (!c)
		std::cout<<"char: Non displayable\n";
	else if (i < 0)
		std::cout<<"char: impossible\n";
	else
	 	std::cout<<"char: '"<< c <<"'\n";
	std::cout<<"int: "<< i <<"\n";
	std::cout<<"float: "<< f <<".0f\n";
	std::cout<<"double: "<< d <<".0\n";
}

void printChar(char c)
{
	float f = static_cast<float>(c);
	int i = static_cast<int>(c);
	double d = static_cast<double>(c);

	if (!c)
		std::cout<<"char: Non displayable\n";
	else
	 	std::cout<<"char: '"<< c <<"'\n";
	std::cout<<"int: "<< i <<"\n";
	std::cout<<"float: "<< f <<".0f\n";
	std::cout<<"double: "<< d <<".0\n";
}

int validPoint(std::string string, std::string::size_type pos)
{
	if (pos <= 0 || pos >= (string.length() - 1))
		return 0;
	if (ftNum(string[pos - 1]) == 0 || ftNum(string[pos + 1]) == 0)
		return 0;
	return 1;
}

int validInt(std::string string)
{
	for (std::string::size_type i = 0; i < string.length(); i++)
		if (!ftNum(string[i]))
			return 0;
	return 1;
}

void pseudoLiteral(std::string str)
{
	std::cout<<"char: impossible\n";
	std::cout<<"int: impossible\n";
	if (str[str.length() - 1] == 'f')
	{
		std::cout<<"float: "<< str <<"\n";
		str.pop_back();
		std::cout<<"double: " << str <<"\n";
	}
	else {
		std::cout<<"float: "<< str <<"f\n";
		std::cout<<"double: "<< str << "\n";
	}
}

void ScalarConvertor::convert(std::string toConvert)
{
	if (toConvert.empty())
		return;
	std::stringstream ss(toConvert);
	std::string::size_type pos = toConvert.find('.');
	if (toConvert == "nan" || toConvert == "nanf" || toConvert == "-inf" || toConvert == "+inf" || toConvert == "-inff" || toConvert == "+inff")
		pseudoLiteral(toConvert);
	else if (pos != std::string::npos && pos != 0 && toConvert[toConvert.size() - 1] == 'f' && validPoint(toConvert, pos))
	{
		float f;
		ss >> f;
		printFloat(f);
	}
	else if (pos != std::string::npos && toConvert.at(pos) == '.' && validPoint(toConvert, pos))
	{
		double d;
		ss >> d;
		printDouble(d);
	}
	else if (validInt(toConvert))
	{
		int i;
		ss >> i;
		printInt(i);
	}
	else if (toConvert.length() == 1)
	{
		char c;
		ss >> c;
		printChar(c);
	}
	else
	 	std::cout<<"string is something else\n";
}