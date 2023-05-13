#ifndef CELL_H
#define CELL_H
#include <string>

class Cell
{
public:
    Cell()
    {
        m_value = "";
    }

    ~Cell() = default;

public:
    //
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

    //get
    int toInt() const;
    double toDouble() const;
    std::string toString() const;

    // set
    void setValue(const std::string&);
    void setValue(const int);
    void setValue(const double);

private:
    std::string m_value;
};

#endif  //CELL_H
