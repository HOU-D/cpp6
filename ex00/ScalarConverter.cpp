/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:50:18 by hoakoumi          #+#    #+#             */
/*   Updated: 2024/07/04 00:21:39 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int     ScalarConverter::_int = 0;
float   ScalarConverter::_float = 0;
char    ScalarConverter::_char = 0;
double  ScalarConverter::_double = 0;

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

int ScalarConverter::teel_me_type(char *str)
{
    std::string text = str;
    
    if (isint(str))
    {
        _int = std::atoi(str);
        return (1);
    }

    else if (isfloat(str) || text == "-inff" || text == "+inff" || text == "nanf")
    {
        text.erase(std::strlen(str)-1, 1);
        _float = std::strtof(text.c_str(), 0);
        return (2);
    }

    else if (isdouble(str) || text == "-inf" || text == "+inf" || text == "nan")
    {
        _double = std::strtof(str, 0);
        return (3);
    }

    else if (std::strlen(str) == 1)
    {
        _char = str[0];
        return (4);
    }

    return (0);
}

void    ScalarConverter::convert(char *av)
{
    int x = teel_me_type(av); 
    std::string text = av;

    if (x == 1)
    {
        if (_int > 31 && _int < 127)
        {
            _char = static_cast<char>(_int);
            std::cout << "char: '" << _char << "'" << std::endl;
        }
        else
            std::cout << "char: " << "Non displayable" << std::endl;
            
        std::cout << "int: " << _int << std::endl;
        
        _float = static_cast<float>(_int);
        std::cout << "float: " << _float << ".0f" << std::endl;
        
        _double = static_cast<double>(_int);
        std::cout << "double: " << _float << ".0" << std::endl;
    }

    else if (x == 2)
    {
        if (text == "-inff" || text == "+inff" || text == "nanf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << av << std::endl;
            text.erase(std::strlen(av)-1, 1);
            std::cout << "double: " << text << std::endl;
            return ;
        }
        else if (_float > 31 && _float < 127)
        {
            _char = static_cast<char>(_float);
            std::cout << "char: '" << _char << "'" << std::endl;
        }
        else
            std::cout << "char: " << "Non displayable" << std::endl;
            
        _int = static_cast<int>(_float);
        std::cout << "int: " << _int << std::endl;

        _double = static_cast<double>(_float);
        
        if (_float - _int != 0)
        {
            std::cout << "float: " << _double << "f" << std::endl;
            std::cout << "double: " << _float << std::endl;
        }
        else
        {
            std::cout << "float: " << _float << ".0f" << std::endl;
            std::cout << "double: " << _double << ".0" << std::endl;
        }
    }

    else if (x == 3)
    {
        if (text == "-inf" || text == "+inf" || text == "nan")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << av << "f" << std::endl;
            std::cout << "double: " << av << std::endl;
            return ;
        }
        if (_double > 31 && _double < 127)
        {
            _char = static_cast<char>(_double);
            std::cout << "char: '" << _char << "'" << std::endl;
        }
        else
            std::cout << "char: " << "Non displayable" << std::endl;
        
        _int = static_cast<int>(_double);
        std::cout << "int: " << _int << std::endl;
        
        _float = static_cast<float>(_double);
        
        if (_float - _int != 0)
        {
            std::cout << "float: " << _double << "f" << std::endl;
            std::cout << "double: " << _float << std::endl;
        }
        else
        {
            std::cout << "float: " << _float << ".0f" << std::endl;
            std::cout << "double: " << _double << ".0" << std::endl;
        }
    }

    else if (x == 4)
    {
        std::cout << "char: '" << _char << "'" << std::endl;
        
        _int = static_cast<int>(_char);
        std::cout << "int: " << _int << std::endl;

        _float = static_cast<float>(_char);
        _double = static_cast<double>(_char);
        
        if (_float - _int != 0)
        {
            std::cout << "float: " << _double << "f" << std::endl;
            std::cout << "double: " << _float << std::endl;
        }
        else
        {
            std::cout << "float: " << _float << ".0f" << std::endl;
            std::cout << "double: " << _double << ".0" << std::endl;
        }
    }

    else
    {
        std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << "Non displayable" << std::endl;
        std::cout << "float: " << "Non displayable" << std::endl;
        std::cout << "double: " << "Non displayable" << std::endl;
    }
}



bool ScalarConverter::isfloat(char* charPtr)
{
    char* endptr;
    std::string text = charPtr;

    if ((charPtr[0] == '-' || charPtr[0] == '+') && std::isdigit(charPtr[1]))
        charPtr++;

    if (charPtr[std::strlen(charPtr)-1] == 'f')
    {
        text.erase(std::strlen(charPtr)-1, 1);
        std::strtof(text.c_str(), &endptr);

        return (endptr != charPtr) && (*endptr == '\0');
    }

    return (0);
}

bool ScalarConverter::isint(char* charPtr)
{
    char* endptr;

    if ((charPtr[0] == '-' || charPtr[0] == '+') && std::isdigit(charPtr[1]))
        charPtr++;

    std::strtol(charPtr, &endptr, 10);

    return (endptr != charPtr) && (*endptr == '\0');
}

bool ScalarConverter::isdouble(char* charPtr)
{
    char* endptr;

    if ((charPtr[0] == '-' || charPtr[0] == '+') && std::isdigit(charPtr[1]))
        charPtr++;

    std::strtod(charPtr, &endptr);

    return (endptr != charPtr) && (*endptr == '\0');
}

