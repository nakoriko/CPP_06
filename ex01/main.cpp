/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:02:39 by nakoriko          #+#    #+#             */
/*   Updated: 2026/02/21 17:23:53 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int main () {

    Data data;
    data._value = 42;
    data._name = "Test";
    Data* original_ptr = &data;

    std::cout << "Before serialization:" << std::endl;
    std::cout << "Data adress: " << original_ptr <<std::endl;
    std::cout << "_value: " << data._value << std::endl;
    std::cout << "_name: " << data._name << std::endl;


    uintptr_t raw = Serializer::serialize(original_ptr);
    std::cout << "\nSirealized pointer in raw: " << raw << std::endl;

    Data *restored_ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized raw in pointer: " << restored_ptr << std::endl;
    if(restored_ptr != original_ptr) 
        std::cout << "Pointers are different!" << std::endl;
    else 
        std::cout << "\nPointers are equal" << std::endl;


    std::cout << "After serialization:" << std::endl;
    std::cout << "Data adress: " << restored_ptr <<std::endl;
    std::cout << "_value: " << restored_ptr->_value << std::endl;
    std::cout << "_name: " << restored_ptr->_name << std::endl;
    return 0;
}