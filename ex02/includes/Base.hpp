#ifndef BASE_HPP
#define BASE_HPP

#include <ctime>
#include <cstdlib>
#include <iostream>

class Base
{
	private:

	public:
		virtual ~Base() {};
};

class A: public Base
{

};

class B: public Base
{

};

class C: public Base
{

};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif