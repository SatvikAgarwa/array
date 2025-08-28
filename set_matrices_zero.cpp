#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<vector <int>> &arr, int n, int m) {
    vector <int> col(m, 0);
    vector <int> row(n, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(row[i] == 1 || col[j] == 1) {
                arr[i][j] = 0;
            }
        }
    }
}

void optimalSolution(vector<vector <int>> &arr, int n, int m) {
    int col0 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                arr[i][0] = 0;
                
                if(j != 0)
                    arr[0][j] = 0;
                else
                    col0 = 1;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    if (col0 == 1) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }
}

int main() {
    vector<vector <int>> arr = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    optimalSolution(arr, 3, 3);
    for(auto row : arr) {
        for(auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}