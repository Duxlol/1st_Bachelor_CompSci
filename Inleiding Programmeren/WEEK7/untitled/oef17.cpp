#include <iostream>
#include <vector>
using namespace std;
string to_string(vector<vector<int>> matrix) {
    string str = "{";
    for (int i = 0; i < matrix.size(); i++) {
        str += "{";
        for (int j = 0; j < matrix[i].size(); j++) {
            str += to_string(matrix[i][j]);
            if(j!=matrix[i].size()-1) {
                str += ",";
            }
        }
        str+="}";
        if (i!=matrix.size()-1) {
            str+=",";
        }
    }
    str+="}";
    return str;
}
vector<vector<int>> upper_triangle(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size();++i) {
        for (int j = 0; j < i; ++j) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

int main() {
    vector<vector <int>> matrixA = {{10,11,12},{13,14,15},{-1,17,18}};
    cout<<to_string(upper_triangle(matrixA))<<endl;
    vector<vector <int>> matrixB = {{1,2,3},{4,5,6},{7,8,1}};
    cout<<to_string(upper_triangle(matrixB))<<endl;
    vector<vector <int>> matrixC = {{1,2},{3,4}};
    cout<<to_string(upper_triangle(matrixC))<<endl;
}