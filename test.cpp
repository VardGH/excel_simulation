#include <iostream>
#include "cell.hpp"
#include "spreadsheet.hpp"

void testCell()
{
    std::cout << "Test Cell\n";
    Cell c;
    c.setValue(24);

    std::cout << "c == "<< c << std::endl;
    std::cout << "c.toInt() -> " << c.toInt() << std::endl;
    std::cout << "c.toDouble() -> " << c.toDouble() << std::endl;
    std::cout << "c.toString() -> " << c.toString() << std::endl;

    Cell c1;
    c1.setValue("v");

    std::cout << "c == "<< c1 << std::endl;
    //std::cout << "c.toInt() -> " << c1.toInt() << std::endl;
    //std::cout << "c.toDouble() -> " << c1.toDouble() << std::endl;
    std::cout << "c.toString() -> " << c1.toString() << std::endl;
}

void testSpreadSheet()
{
    std::cout << "\nTest SpreadSheet\n";
    SpreadSheet s1(2,2);
    s1.setCellAt(0,1,"10");
    s1.setCellAt(0,0, "k");
    s1.setCellAt(1,1,"j");

    std::cout << "s1(0,1) == "<< s1.getCellAt(0,1).toInt() << std::endl;
    std::cout << "s1 row " << s1.getRow() << std::endl;
    s1.addRow(3);
    std::cout << "s1 row " << s1.getRow() << std::endl;
    s1.setCellAt(2,1,"v");

    s1.addCol(1);
    std::cout << "s1 col " << s1.getCol() << std::endl;

    s1.print();

    s1.removeRow(2);
    s1.print();

    s1.removeCol(1);
    s1.print();

    SpreadSheet s2;
    std::cout << "s2 col " << s2.getCol() << std::endl;
    std::cout << "s2 row " << s2.getRow() << std::endl;

    Cell c;
    c.setValue(50);
    SpreadSheet s3(3, 5);
    s3.setCellAt(1, 2, c);
    std::cout << s3.getCellAt(1,2) << std::endl;
}
