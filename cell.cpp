#include <iostream>
#include "cell.hpp"

std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    return os << cell.m_value;
}

int Cell::toInt() const
{
    return std::stod(m_value);
}

double Cell::toDouble() const
{
    return std::stod(m_value);
}

std::string Cell::toString() const
{
    return m_value;
}


void Cell::setValue(const std::string& value)
{
    m_value = value;
}


void Cell::setValue(const int value)
{
    m_value = std::to_string(value);
}

void Cell::setValue(const double value)
{
    m_value = std::to_string(value);
}
