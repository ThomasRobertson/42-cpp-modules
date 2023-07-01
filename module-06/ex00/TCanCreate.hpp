#ifndef TCanCreate_HPP
#define TCanCreate_HPP

#include <sstream>
#include <string>
#include <iostream>

template <class T>
bool TCanCreate(std::string const &input)
{
    std::istringstream iss(input);
    T test_object;

    iss >> test_object;

    return !iss.fail() && (iss.rdbuf()->in_avail() == 0);
}

#endif // TCanCreate_HPP