//
// Created by toor on 7/18/18.
//

#include "matrixSquareFinder.hpp"
using namespace std;

int MatrixSquareFinder::SquareNumber(vector<vector<char>> matrix) {
    vector<vector<int>> copyField;
    MarkSquare(matrix,copyField);
    return FindMaxSquare(copyField);
}

void MatrixSquareFinder::MarkSquare(vector<vector<char>>& field, vector<vector<int>>& copyField)
{

    for(int i = 0; i < int (field.size()) ;i++)
    {
        vector<int> row;
        for(int j = 0 ; j < int (field[i].size()); j++)
        {
            if(field[i][j] =='0' || i==0 || j==0)
            {
                row.push_back(0);
            }
            else
            {
                row.push_back(1);
            }
        }
        copyField.push_back(row);
    }
}

int MatrixSquareFinder::FindMaxSquare(vector<vector<int>>& field)
{
    int max = 0;
    for(int i=1;i<field.size();i++)
    {
        for(int j=1;j<field[i].size();j++)
        {
            field[i][j] = min(field[i-1][j],min(field[i][j-i],field[i-1][j-i]))+1;
            if(field[i][j]>max){
                max = field[i][j];
            }
        }
    }
    return max*max;

}
