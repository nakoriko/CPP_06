/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintUtils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:25:17 by nakoriko          #+#    #+#             */
/*   Updated: 2026/02/21 16:55:12 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PrintUtils.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cmath>

void printChar(double val) {

        if (val < 0 || val > 127 || val != static_cast<int>(val)) 
            std::cout << "char: impossible" << std::endl;
        else {
            char c = static_cast<char>(val);
            if (val < 32 || val == 127)
                 std::cout << "char: Non displayable" << std::endl;
             else
                 std::cout << "char: '" << c << "'" << std::endl;
        }
}

void printInt(double val) {

    if (val < (std::numeric_limits<int>::min()) || 
        val > (std::numeric_limits<int>::max()) ||
        std::isnan(val) || std::isinf(val))
        std::cout << "int: impossible" <<std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

void printFloat(double val) {
    float f = static_cast<float>(val);
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if(std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
    else if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
}

void printDouble(double val) {
    if (std::isnan(val))
        std::cout << "double: nan" << std::endl;
    else if(std::isinf(val))
        std::cout << "double: " << (val > 0 ? "+inf" : "-inf") << std::endl;
    else if (val == static_cast<int>(val))
        std::cout << "double: " << val << ".0" << std::endl;
    else
        std::cout << "double: " << val << std::endl;
}