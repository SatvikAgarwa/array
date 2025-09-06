#include<bits/stdc++.h>
using namespace std;

vector <int> optimalSolution(vector <int> &arr) {
    int n = arr.size();
    int sumN = (n * (n + 1)) / 2;
    int sum2N = (n * (n + 1) * ((2 * n) + 1)) / 6;
    int arrN = 0, arr2N = 0;

    for (int i: arr)
    {
        arrN += i;
        arr2N += i * i;
    }

    int minusxy = sumN - arrN;
    int plusxy = (sum2N - arr2N) / minusxy;

    int x = (minusxy + plusxy) / 2;
    int y = plusxy - x;

    return {x, y};
}

int main() {
    vector <int> arr = {6, 4, 2, 3, 1, 1};
    vector <int> ans = optimalSolution(arr);

    cout << "Repeating Number: " << ans[0] << endl;
    cout << "Missing Value: " << ans[1] << endl;
    return 0;
}