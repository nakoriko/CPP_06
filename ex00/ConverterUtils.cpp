/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:31:17 by nakoriko          #+#    #+#             */
/*   Updated: 2026/02/21 16:48:24 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ConverterUtils.hpp"
#include "PrintUtils.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>
// ======================== BOOLS========================

bool isPseudo(const std::string &literal) {
    if (literal == "-inff" || literal ==  "+inff" || literal == "nanf"
        || literal == "-inf" || literal ==  "+inf" || literal == "nan")
        return true;
    return false;
}



bool isInt (const std::string& literal) {
    size_t start = 0;
    if (literal.empty())
        return false;
    
    if(literal[0] == '+' || literal[0] == '-') {
        start = 1;
        if (literal.size() == 1)
            return false;
    }
    for (size_t i = start; i < literal.size(); i++) {
        if(!isdigit(literal[i]))
            return false;
    }
    long long x = atoll(literal.c_str());
    if ( x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max())
        return false;
    return true;
}

bool isFloat(const std::string& literal) {
    if (literal.empty()  || literal[literal.size() - 1] != 'f')
        return false;
    std::string numberPart = literal.substr(0, literal.size() - 1);
    if (numberPart.empty())
        return false;
    if(literal == "+nan" || literal == "-nan" || literal == "inff" || literal == "inf")
        return false;
    char *end;
    float value = strtof(numberPart.c_str(), &end);
    (void) value;
    if (*end != '\0' || end == numberPart.c_str())
        return false;
    return true;
}

bool isDouble(const std::string& literal) {
    if(literal.empty())
        return false;
    if(literal == "+nan" || literal == "-nan" || literal == "inff" || literal == "inf")
        return false;
    char *end;
    float value = strtod(literal.c_str(), &end);
    (void) value;
    if (*end != '\0' || end == literal.c_str())
        return false;
    return true;
}

// ======================== CONVERTERS ========================

void convertFromPseudo(const std::string& literal) {
    std::cout << "char: impossible" <<std::endl;
    std::cout << "int: impossible" <<std::endl;
    if (literal == "-inf" || literal ==  "+inf" || literal == "nan") {
        std::cout << "float: " << literal << "f" << std::endl;
    }
    else
        std::cout << "float: " << literal << std::endl;
    if (literal == "-inff" || literal ==  "+inff" || literal == "nanf") {
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
    }
    else
        std::cout << "double: " << literal << std::endl;
}

void convertFromChar(const std::string& literal) {
    double d = static_cast<double>(literal[0]);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void convertFromInt(const std::string& literal) {
    int i = std::atoi(literal.c_str());
    double d = static_cast<double>(i);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void convertFromFloat(const std::string& literal) {

    // std::string numberPart = literal.substr(0, literal.size() - 1);
    float f = strtof(literal.c_str(), NULL);
    double d =  static_cast<double>(f);

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void convertFromDouble(const std::string& literal) {
    double d = strtod(literal.c_str(), NULL);

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}




