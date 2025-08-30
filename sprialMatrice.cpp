#include<bits/stdc++.h>
using namespace std;

void spiralMat(vector<vector<int>> &arr, int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int count = 1;

    while(top <= bottom && left <= right)  {
        for(int i = left; i <= right; i++) {
            arr[top][i] = count++;
        }
        top++;
        for(int i = top; i <= bottom; i++) {
            arr[i][right] = count++;
        }
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                arr[bottom][i] = count++;
            }
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                arr[i][left] = count++;
            }
            left++;
        }
    }
}

int main() {
    vector <vector<int>> arr(5, vector<int>(5, 0));
    int rows = arr.size();
    int cols = arr[0].size();
    spiralMat(arr, rows, cols);
    for (const auto &row : arr) {
        for (const auto &elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}