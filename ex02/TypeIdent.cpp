/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeIdent.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:07:21 by nakoriko          #+#    #+#             */
/*   Updated: 2026/02/21 17:43:34 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "TypeIdent.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {

    static bool init = false;
    if(!init) {
        std::srand(std::time(0)); //устанавливаем в качестве входного значения - текущее время, чтобы был настоящий рандом
        init = true;
    }

    int random = std::rand() % 3; // вызываем рандом, получаем всегда разный рпндомный остатой от 3
    switch(random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return NULL;
}

void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Pointer is NULL" << std::endl;
        return;
    }
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Uknown type" << std::endl;

    // dynamic_cast<A*>(p) - Попробуй преобразовать указатель P в указательно на объект типа А

}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" <<std::endl;
        return;
    } catch (const std::exception& e) {}
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception& e) {}
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unknown type" << std::endl;
    }
}


// dynamic_cast  - может бросить в нулл для указателей, но для ссылок - нте. Поэтому делаем тра кэтч.