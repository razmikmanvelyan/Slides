#pragma once
#include <iostream>
#include <any>
#include <string>

namespace helper{
    namespace conversion{
        std::string anyToString(const std::any& value) {
            if (value.has_value()) {
                try {
                    if (value.type() == typeid(std::string)) {
                        return std::any_cast<std::string>(value);
                    } else if (value.type() == typeid(int)) {
                        return std::to_string(std::any_cast<int>(value));
                    } else if (value.type() == typeid(double)) {
                        return std::to_string(std::any_cast<double>(value));
                    }
                } catch (const std::bad_any_cast& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }

            return "";
        }
    }
}