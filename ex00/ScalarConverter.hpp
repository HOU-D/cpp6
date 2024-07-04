#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#define MAUVE "\033[35m"
#define RESET "\033[0m"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

class ScalarConverter
{
    private:

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter & operator = (const ScalarConverter &other);
        ~ScalarConverter();

        static int     _int;
        static float   _float;
        static char    _char;
        static double  _double;

        static bool    isfloat(char* charPtr);
        static bool    isint(char* charPtr);
        static bool    isdouble(char* charPtr);
        static int     teel_me_type(char *str);

    public:

        static void    convert(char *av);
};
#endif