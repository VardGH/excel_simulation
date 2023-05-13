#include <iostream>
#include <vector>
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

///////

class SpreadSheet
{
public:

    SpreadSheet(int row = 2, int col = 2)
        : m_cells(row, std::vector<Cell>(col))
    {
    }

    ~SpreadSheet() = default;

public:
    //set
    void setCellAt(const int row, const int col, const std::string& val);
    void setCellAt(const int row, const int cal, const Cell cell);

    //get
    const Cell& getCellAt(const int row, const int col) const;

    int getRow() const;
    int getCol() const;

    //
    void addRow(int);
    void addCol(int);

private:
    std::vector<std::vector<Cell>> m_cells;
};

void SpreadSheet::setCellAt(const int row, const int col, const std::string& val)
{
    if (row < 0 || row >= m_cells.size() || col < 0 || col >= m_cells[0].size()) {
        throw std::out_of_range("Row or column index out of range");
    }
    m_cells[row][col].setValue(val);
}

void SpreadSheet::setCellAt(const int row, const int col, const Cell cell)
{
    if (row < 0 || row >= m_cells.size() || col < 0 || col >= m_cells[0].size()) {
        throw std::out_of_range("Row or column index out of range");
    }
    m_cells[row][col] = cell;
}

const Cell& SpreadSheet::getCellAt(const int row, const int col) const
{
    if (row < 0 || row >= m_cells.size() || col < 0 || col >= m_cells[0].size()) {
        throw std::out_of_range("Row or column index out of range");
    }
    return m_cells[row][col];
}

void SpreadSheet::addRow(const int row)
{
    if(row < 0) {
        throw std::out_of_range("Row index is negative");
    }
    int col = m_cells[0].size();
    m_cells.resize(m_cells.size() + row, std::vector<Cell>(col));
}

void SpreadSheet::addCol(const int col)
{
    if(col < 0) {
        throw std::out_of_range("Column index is negative");
    }
    for (auto& row : m_cells) {
        row.resize(row.size() + col, Cell());
    }
}

int SpreadSheet::getRow() const
{
    return m_cells.size();
}

int SpreadSheet::getCol() const
{
    return m_cells[0].size();
}

void test()
{
    Cell c;
    c.setValue(24);

    std::cout << "c val == "<< c.toInt() <<std::endl;

    SpreadSheet s1(2,2);
    s1.setCellAt(0,1,"10");

    std::cout << "s1(0,1) == "<< s1.getCellAt(0,1).toInt() << std::endl;
    std::cout << "s1 row " << s1.getRow() << std::endl;
    s1.addRow(3);
    std::cout << "s1 row " << s1.getRow() << std::endl;

    s1.addRow(3);
    std::cout << "s1 row " << s1.getRow() << std::endl;

    s1.addCol(5);
    std::cout << "s1 col " << s1.getCol() << std::endl;

    SpreadSheet s2;
    std::cout << "s2 col " << s2.getCol() << std::endl;
    std::cout << "s2 row " << s2.getRow() << std::endl;
}

int main()
{
    test();
}
