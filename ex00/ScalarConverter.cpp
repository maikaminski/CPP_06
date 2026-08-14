#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

// 0=char, 1=int, 2=float, 3=double
static int detectType(const std::string &literal)
{
    if (literal.length() == 1 && !isdigit(literal[0]))
        return 0;
    if (!literal.empty() && literal[literal.length() - 1] == 'f')
        return 2;
    if (literal.find('.') != std::string::npos)
        return 3;
    return 1;
}

void ScalarConverter::convert(const std::string &literal)
{
    // Pseudo-literals
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    int    type = detectType(literal);
    double d    = 0.0;
    bool   valid = true;

    if (type == 0) {
        d = static_cast<double>(literal[0]);
    }
    else if (type == 1) {
        char *end;
        long l = strtol(literal.c_str(), &end, 10);
        if (*end != '\0')
            valid = false;
        else
            d = static_cast<double>(l);
    }
    else if (type == 2) {
        char *end;
        d = strtod(literal.c_str(), &end);
        if (*end != 'f' && *end != 'F')
            valid = false;
    }
    else {
        char *end;
        d = strtod(literal.c_str(), &end);
        if (*end != '\0')
            valid = false;
    }

    if (!valid) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // char
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (d < 32 || d == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    // int
    if (d < static_cast<double>(std::numeric_limits<int>::min()) ||
        d > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    // float
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

    // double
    std::cout << "double: " << d << std::endl;
}
