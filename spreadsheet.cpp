#include "spreadsheet.hpp"
#include <iostream>
#include "cell.hpp"

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
