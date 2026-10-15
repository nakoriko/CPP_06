/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:03:30 by nakoriko          #+#    #+#             */
/*   Updated: 2025/11/06 15:06:22 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ConverterUtils.hpp"


int main ( int ac, char **av) {

    if (ac != 2) {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    std::string literal = av[1];
    ScalarConverter::convert(literal);
    return 0;
}