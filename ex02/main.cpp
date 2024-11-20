#include "includes/Base.hpp"
#include <cstdlib>

int main()
{
	std::srand(std::time(0));

	Base *a = generate();
	Base *b = generate();
	Base *c = generate();


	identify(a);
	identify(b);
	identify(c);

	A a2;
	B b2;
	C c2;

	identify(a2);
	identify(b2);
	identify(c2);
	

	delete a,  delete b,  delete c;
}