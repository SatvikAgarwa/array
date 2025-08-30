#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<vector <int>> &arr, int m, int n) {
    vector <vector <int>> ans(n, vector <int> (m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[j][n - i - 1] = arr[i][j];
        }
    }

    arr = ans;
}

void optimalSolution(vector<vector<int>> &arr, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if(i == j) continue;
            else swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int end = arr[0].size() - 1;
        for (int j = 0; j < m / 2; j++)
        {
            swap(arr[i][j], arr[i][end - j]);
        }
    }
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int m = arr.size();
    int n = arr[0].size();

    optimalSolution(arr, m, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}