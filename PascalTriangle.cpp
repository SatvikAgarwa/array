#include<bits/stdc++.h>
using namespace std;

int getElement(int n, int r) {
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    
    return  res - 1;
}

vector <int> printRow(int n) {
    int res = 1;
    vector <int> ans;
    for(int i = 1; i <= n; i++) {
        ans.push_back(res);
        res *= n - i;
        res /= i;
    }
    return ans;
}

void printTriangle(int n) {
    for(int i = 1; i <= n; i++) {
        vector<int> row = printRow(i);
        for (int j : row) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << getElement(6, 5) << endl;
    vector<int> row = printRow(6);
    for (int i : row) {
        cout << i << " ";
    }
    cout << endl;
    printTriangle(6);
}