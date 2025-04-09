#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int row = 0;
    int column = -1;
    vector<int> res;    
    int m = matrix.size();      
    int n = matrix[0].size();    

    while ((m > 0) && (n > 0))
    {
        for (int i = 0; i < n; i++)   // move right
            res.push_back(matrix[row][++column]);
        m--;
        for (int i = 0; i < m; i++)   // move down
            res.push_back(matrix[++row][column]);
        n--;
        if (m > 0) {
            for (int i = 0; i < n; i++)   // move left
                res.push_back(matrix[row][--column]);
            m--;
        }   
        if (n > 0) {
            for (int i = 0; i < m; i++)   // move up
                res.push_back(matrix[--row][column]);
            n--;
        }
    }
    
    return res;
}

int main() 
{
    vector<vector<int>> matrix;
    int row;
    int column;

    cout << "No of Matrix you want to enter(Row) : ";
    cin >> row;

    cout << "No of max no of elements in each row(Column) : ";
    cin >> column;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            int temp = 0;
            cin >> temp;
            cout << i << "th row enter " << j  << " elements value was : " << temp << endl; 
            matrix[i][j] = row;
        }
    }

    vector res = spiralOrder(matrix);
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ", ";
    }
    return 0;
} 