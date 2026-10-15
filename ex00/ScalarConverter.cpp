/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:49:01 by nakoriko          #+#    #+#             */
/*   Updated: 2025/11/05 18:49:01 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ConverterUtils.hpp"
#include "PrintUtils.hpp"

 ScalarConverter::ScalarConverter() {}
 ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void) other;
 }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other) {
    (void) other;
    return(*this);
}
ScalarConverter::~ScalarConverter() {}



void ScalarConverter::convert(const std::string& literal) {
    if (isPseudo(literal) == true) 
        convertFromPseudo(literal);
    else if (isInt(literal)) 
        convertFromInt(literal); 
    else if (isFloat(literal)) 
        convertFromFloat(literal);
    else if (isDouble(literal))
        convertFromDouble(literal); 
    else if (literal.length() == 1)
        convertFromChar(literal); 
    else
        std::cout << "Invalid literal" << std::endl;
}