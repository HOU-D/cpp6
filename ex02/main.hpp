#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo> 
#define MAUVE "\033[35m"
#define RESET "\033[0m"

class Base
{
    public:
        virtual ~Base();
};

class A : public Base
{
    public:
        ~A();
};

class B : public Base
{
    public:
        ~B();
};

class C : public Base
{
    public:
        ~C();
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif