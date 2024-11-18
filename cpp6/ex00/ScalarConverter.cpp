#include "ScalarConverter.hpp"

// Orthodox Canonical Form inutile mais obligatoire donc bon
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

// Recuperer les types
bool ScalarConverter::isChar(const std::string &literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal) {
    char *end;
    std::strtol(literal.c_str(), &end, 10);
    return (*end == '\0');
}

bool ScalarConverter::isFloat(const std::string &literal) {
    char *end;
    std::strtof(literal.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

bool ScalarConverter::isDouble(const std::string &literal) {
    char *end;
    std::strtod(literal.c_str(), &end);
    return (*end == '\0');
}

bool ScalarConverter::isSpecialLiteral(const std::string &literal) {
    return (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
            literal == "-inf" || literal == "+inf" || literal == "nan");
}

void ScalarConverter::convert(const std::string &literal) {
    if (isSpecialLiteral(literal)) 
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (literal == "nan" || literal == "nanf") 
        {
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        } 
        else 
        {
            std::cout << "float: " << literal << "\n";
            std::cout << "double: " << literal.substr(0, literal.length() - 1) << "\n";
        }
    }
    // Si c'est un char
    else if (isChar(literal)) 
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
    }
    // Si c'est un int
    else if (isInt(literal)) 
    {
        char *end;
        long value = std::strtol(literal.c_str(), &end, 10);

        std::cout << "char: ";
        if (value < 0 || value > 255 || !std::isprint(static_cast<int>(value)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(value) << "'\n";
        std::cout << "int: " << value << "\n";
        std::cout << "float: ";
        if (value == 0)
            std::cout << "0.0f\n";
        else
            std::cout << static_cast<float>(value) << "f\n";
        std::cout << "double: ";
        if (value == 0)
            std::cout << "0.0\n";
        else
            std::cout << static_cast<double>(value) << "\n";
    }
    // Si c'est un float
    else if (isFloat(literal)) 
    {
        char *end;
        float value = std::strtof(literal.c_str(), &end);

        std::cout << "char: ";
        if (value < 0 || value > 255 || !std::isprint(static_cast<int>(value)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(value) << "'\n";
        std::cout << "int: ";
        if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<int>(value) << "\n";
        std::cout << "float: ";
        if (value == 0.0f)
            std::cout << "0.0f\n";
        else
            std::cout << std::fixed << std::setprecision(1) << value << "f\n";
        std::cout << "double: ";
        std::cout << static_cast<double>(value) << "\n";
    }
    // Si c'est un double
    else if (isDouble(literal)) 
    {
        char *end;
        double value = std::strtod(literal.c_str(), &end);

        std::cout << "char: ";
        if (value < 0 || value > 255 || !std::isprint(static_cast<int>(value)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(value) << "'\n";
        std::cout << "int: ";
        if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<int>(value) << "\n";
        std::cout << "float: ";
        if (std::isinf(value) || std::isnan(value))
            std::cout << literal + "f\n";
        else 
        {
            if (value == 0.0f)
                std::cout << "0.0f\n";
            else
                std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n"; 
        }
        std::cout << "double: ";
        if (value == 0.0)
            std::cout << "0.0\n";
        else
            std::cout << std::fixed << std::setprecision(1) << value << "\n"; 
    }
    else 
    {
        std::cout << "Conversion impossible\n";
    }
}
