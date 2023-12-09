#pragma once

#include <stdexcept>
#include <string>

class Exception : std::exception
{
public:
    template<typename String>
    explicit Exception(String&& str)
        : _what(std::forward<String>(str)) {}

    const char* what() const noexcept override
    {
        return _what.c_str();
    }

private:
    std::string _what;
};