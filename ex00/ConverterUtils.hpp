/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:31:21 by nakoriko          #+#    #+#             */
/*   Updated: 2026/02/23 15:11:06 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTERUTILS_HPP
#define CONVERTERUTILS_HPP

#include <string>

bool isPseudo(const std::string &literal);
bool isInt (const std::string& literal);
bool isFloat(const std::string& literal);
bool isDouble(const std::string& literal);

void convertFromPseudo(const std::string& literal);
void convertFromInt(const std::string& literal);
void convertFromChar(const std::string& literal);
void convertFromFloat(const std::string& literal);
void convertFromDouble(const std::string& literal);

#endif