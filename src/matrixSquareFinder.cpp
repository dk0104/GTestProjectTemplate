//
// Created by toor on 7/18/18.
//

#include "matrixSquareFinder.hpp"
using namespace std;

int MatrixSquareFinder::SquareNumber(vector<vector<char>> matrix) {
    vector<vector<int>> copyField;
    MarkSquare(matrix,copyField);
    return FindMaxSquare(matrix,copyField);
}

void MatrixSquareFinder::MarkSquare(vector<vector<char>>& field, vector<vector<int>>& copyField)
{

    for(auto& i : field){
        vector<int> tmp;
        for(auto& j : i){
            tmp.push_back(0);
        }
        copyField.push_back(tmp);
    }

    for(int i = 0; i < int (field.size()) ;i++)
    {
        for(int j = 0 ; j < int (field[i].size()); j++)
        {
            if(i == 0 || j == 0)
            {
                if(field[i][j]=='0'){

                    copyField[i][j]=0;
                }
                else{
                    copyField[i][j]=1;
                }
            }
        }
    }
}

int MatrixSquareFinder::FindMaxSquare(vector<vector<char>>& origin,vector<vector<int>>& field)
{
    int max = 0;
    for(int i=1;i<field.size();i++)
    {
        for(int j=1;j<field[i].size();j++)
        {
            if(origin[i][j]=='1')
            {
                field[i][j] = min(field[i-1][j],min(field[i][j-1],field[i-1][j-1]))+1;
                if(field[i][j]>max)
                {
                    max = field[i][j];
                }
            }
        }
    }

    return max*max;
}
