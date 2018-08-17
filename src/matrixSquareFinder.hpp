//
// Created by toor on 7/18/18.
//

#ifndef GTESTPROJECTTEMPLATE_MATRIXSQUAREFINDER_HPP
#define GTESTPROJECTTEMPLATE_MATRIXSQUAREFINDER_HPP


#include <vector>
#include <iostream>


class MatrixSquareFinder {
public:
    int SquareNumber(std::vector<std::vector<char> > matrix);

protected:
    void MarkSquare(std::vector<std::vector<char> > &field, int row, int column);
};


#endif //GTESTPROJECTTEMPLATE_MATRIXSQUAREFINDER_HPP
