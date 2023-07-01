#ifndef TConvertType_HPP
#define TConvertType_HPP

#include <sstream>
#include <string>
#include <iostream>

template <class T>
T TConvertType(std::string const &input)
{
    std::istringstream iss(input);
    T object;

    iss >> object;

    return object;
}

#endif // TConvertType_HPP