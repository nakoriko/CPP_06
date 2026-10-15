/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:46:37 by nakoriko          #+#    #+#             */
/*   Updated: 2026/02/21 18:27:17 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "TypeIdent.hpp"

int main () {

    std::cout << "TEST 1. MANUAL TYPE CREATION" << std::endl;
    A a;
    B b;
    C c;

    Base *pa = &a;
    Base *pb = &b;
    Base *pc = &c;
    std::cout << "A as a pointer: " ; identify(pa);
    std::cout << "B as a pointer: " ; identify(pb);
    std::cout << "C as a pointer: " ; identify(pc);
    std::cout << std::endl;

    Base &ra = a;
    Base &rb = b;
    Base &rc = c;
    std::cout << "A as a refernce: " ; identify(ra);
    std::cout << "B as a refernce: " ; identify(rb);
    std::cout << "C as a refernce: " ; identify(rc);


    std::cout << " TEST 2. RANDOM GENERATE" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base *p = generate();
        std::cout << "Pointer: "; identify(p);
        std::cout << "Reference: "; identify(*p);
        delete p;
        std::cout << std::endl;
    }

    std::cout << "TEST 3. NULL POINTER TEST" << std::endl;
    Base *p = NULL;
    identify(p);
    std::cout << std::endl;

    std::cout << "TEST 4. UNKNOWN TYPE TEST" << std::endl;
    Base some_type;
    std::cout << "Pointer: "; identify(&some_type);
    std::cout << "Reference: "; identify(some_type);
    std::cout << std::endl;
    
    return 0;

}

