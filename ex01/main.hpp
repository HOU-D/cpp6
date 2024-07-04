#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#define MAUVE "\033[35m"
#define RESET "\033[0m"

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdint.h>

typedef struct s_data
{
	std::string name;
	short	sh;
	int		i;
	
}Data;

class Serializer
{
	private:

		Serializer();
		~Serializer();
		Serializer(Serializer &other);
		Serializer &operator = (Serializer &other);

	public:

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};


#endif