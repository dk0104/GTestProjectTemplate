//
// Created by toor on 7/18/18.
//

#include "matrixSquareFinder.hpp"

int MatrixSquareFinder::SquareNumber(vector<vector<char>> matrix) {
    int maxCounter = 0;
    for (int row = 0; row < matrix.size(); row++) {
        for (int column = 0; column < matrix[row].size(); column++) {
            if (row == 0 || column == 0)
            {
                continue;
            }

            if (matrix[row][column] != '0') {

                MarkSquare(matrix, row, column);
            }
        }
    }
    return maxCounter;
}

void MatrixSquareFinder::MarkSquare(vector<vector<char>> &field, int row, int column)
{
    if (field[row][column - 1] != '0' &&
        field[row - 1][column] != '0' &&
        field[row - 1][column - 1] != '0')
    {
        field[row][column] = 'x';
        field[row][column - 1] = 'x';
        field[row - 1][column] = 'x';
        field[row - 1][column - 1] = 'x';
    }

}