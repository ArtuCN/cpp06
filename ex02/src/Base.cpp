#include "../includes/Base.hpp"
#include <exception>
#include <iostream>

Base *generate(void)
{
	int randNbr = (std::rand() % 3 + 1);
	if (randNbr == 1)
		return new A;
	else if (randNbr == 2)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base &p)
{
	try{
		A& a = dynamic_cast<A&>(p);
		std::cout<< "A" << "\n";
		(void)a;
	}
	catch (const std::exception& e)
	{
		try {
			B& b = dynamic_cast<B&>(p);
			std::cout<< "B" << '\n';
			(void)b;
		}
		catch (const std::exception &e)
		{
			std::cout<<"C" <<'\n';
		}
	}
}