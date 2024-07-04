/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:50:29 by hoakoumi          #+#    #+#             */
/*   Updated: 2024/07/04 00:41:37 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Base::~Base()
{}

A::~A()
{}

B::~B()
{}

C::~C()
{}

Base*   generate(void)
{
    std::srand(std::time(0));
    int randome = std::rand() % 3;

    if (randome == 0)
    {
        A *a = new A();
        return (a);
    }
    else if (randome == 1)
    {
        B *b = new B();
        return (b);
    }
    else if (randome == 2)
    {
        C *c = new C();
        return (c);
    }
    return (NULL);
}

void identify(Base* p)
{
    if (p == NULL)
    {
        std::cout << "Null pointer passed" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p))
    {
        std::cout << "Pointer points to an object of type A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "Pointer points to an object of type B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "Pointer points to an object of type C" << std::endl;
    }
    else
    {
        std::cout << "Unknown type pointed to by the pointer" << std::endl;
    }
}


void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a; 
        std::cout << "Reference refers to an object of type A" << std::endl;
    }
    catch (const std::bad_cast&)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            (void)b; 
            std::cout << "Reference refers to an object of type B" << std::endl;
        }
        catch (const std::bad_cast&)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                (void)c; 
                std::cout << "Reference refers to an object of type C" << std::endl;
            }
            catch (const std::bad_cast&)
            {
                std::cout << "Unknown type referred to by the reference" << std::endl;
            }
        }
    }
}


int main()
{
    Base *B = generate();
    identify(B);
    identify(*B);
    delete B;
    
}