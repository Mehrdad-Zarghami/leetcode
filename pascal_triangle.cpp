/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]


Example 2:

Input: numRows = 1
Output: [[1]]

*/


#include <iostream>
#include <vector>
#include <format>

using namespace std;



vector<vector<int>> generate(int numRows) {

    vector<vector<int>> outer_vec_1{{1}};
    vector<vector<int>> outer_vec_2{ {1}, {1,1} };
    vector<vector<int>> outer_vec(numRows);

    if (numRows == 1) {
        outer_vec = outer_vec_1;
 
    }
    else if (numRows == 2) {
        outer_vec = outer_vec_2;

    }
    else if (numRows > 2) {
        outer_vec[0] = {1};
        outer_vec[1] = {1, 1};

        for (int i {2}; i < numRows; ++i) { // i specifies the (i+1)th row of the Pascal triangle which is the index of i in the outer_vec
            vector<int> inner_vec(i+1, 1); //  e.g. outer_vec[2] has three elements.
            for (int j{ 1 }; j < i; ++j) {
                inner_vec[j] = outer_vec[i - 1][j - 1] + outer_vec[i - 1][j];
            }

            outer_vec[i] = inner_vec;

        }

    }

    return outer_vec;
};


   

int main()
{
    int numRows = 6;
    vector<vector<int>> pascal_triangle = generate(numRows);

    // Print Pascal's Triangle
    cout << "Pascal's Triangle (" << numRows << " rows):" << endl;
    for (const auto& row : pascal_triangle) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl; // Move to the next row
    }

    return 0;

}

