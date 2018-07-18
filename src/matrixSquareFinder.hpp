//
// Created by toor on 7/18/18.
//

#ifndef GTESTPROJECTTEMPLATE_MATRIXSQUAREFINDER_HPP
#define GTESTPROJECTTEMPLATE_MATRIXSQUAREFINDER_HPP


#include <vector>
#include <iostream>

using namespace std;

class MatrixSquareFinder {
public:
    int SquareNumber(vector<vector<char>> matrix);

protected:
    void MarkSquare(vector<vector<char>> &field, int row, int column);
};


#endif //GTESTPROJECTTEMPLATE_MATRIXSQUAREFINDER_HPP
