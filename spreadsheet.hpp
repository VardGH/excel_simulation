#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <vector>
#include <string>
#include "cell.hpp"

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
#endif  //SPREADSHEET_H
