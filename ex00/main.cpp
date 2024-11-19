#include "includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout<<"Wrong input\n";
		return 0;
	}
	ScalarConvertor::convert(av[1]);
	return (1);	
}