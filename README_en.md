# CPP06 Project

## Overview
CPP06 is a set of C++ exercises about data conversion, type casting, pointers, and dynamic identification of the real type of an object in a program.

### ex00: ScalarConverter
**Task:** Implement the ScalarConverter class, which converts a string to various scalar types (char, int, float, double), correctly handles edge-cases, pseudo-literals (nan, inf), filters invalid values, and prints the result in the required format.
**Goal:** Learn to work with type conversion, input filtering, correct output formatting, and handling special cases.

### ex01: Serializer
**Task:** Implement the Serializer class with two static methods: serialize (converts a Data* pointer to uintptr_t) and deserialize (converts uintptr_t back to Data*). Data is a structure with fields.
**Goal:** Master low-level pointer conversion, serialization/deserialization, and working with the bit representation of data.

### ex02: Identify real type
**Task:** Implement a Base class with a virtual destructor and three derived classes (A, B, C). Implement the functions generate (creates a random object) and identify (determines the real type of the object via pointer and reference, using dynamic_cast, without typeid/typeinfo).
**Goal:** Understand Run-Time Type Information (RTTI), dynamic casting, and learn to determine the real type of an object through a base interface.

## Usage
- Each module contains a Makefile for building.
- Use the provided main.cpp files for testing.
- Check correctness with edge-cases and Valgrind.

## Key Concepts
- Type conversion and data filtering
- Pointer serialization and deserialization
- RTTI (Run-Time Type Information) and dynamic_cast