/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:50:08 by hoakoumi          #+#    #+#             */
/*   Updated: 2024/06/29 14:37:03 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: check the number of  parameter " << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
}