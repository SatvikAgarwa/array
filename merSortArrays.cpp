#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector <int> &arr1, vector <int> &arr2) {
    vector <int> ans;
    int n = arr1.size(), m = arr2.size();
    int len = n + m;
    int left = 0, right = n;
    while (left < n && right - n < m)
    {
        if(arr1[left] <= arr2[right - n])
            ans.push_back(arr1[left++]);
        else
            ans.push_back(arr2[right++ - n]);
    }

    while(left < n) ans.push_back(arr1[left++]);
    while(right - n < m) ans.push_back(arr2[right++ - n]);

    for(int i = 0; i < n; i++) arr1[i] = ans[i];
    for(int i = 0; i < m; i++) arr2[i] = ans[n + i];
}

void optimalSolution(vector <int> &arr1, vector <int> &arr2) {
    //Gap method
    int n = arr1.size(), m = arr2.size();
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0, right = gap;
        while(right < len) {
            if(left < n && right < n) {
                if(arr1[left] > arr1[right])
                    swap(arr1[left], arr1[right]);
            } else if(left >= n && right >= n) {
                if(arr2[left - n] > arr2[right - n])
                    swap(arr2[left - n], arr2[right - n]);
            } else {
                if(arr1[left] > arr2[right - n])
                    swap(arr1[left], arr2[right - n]);
            }
            left++;
            right++;
        }

        if (gap <= 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main() {
    vector <int> arr1 = {1, 2, 3, 5, 9};
    vector <int> arr2 = {0, 4, 6, 7, 8, 10};
    optimalSolution(arr1, arr2);

    for(auto i: arr1)
        cout << i << " ";
    
    for (auto i: arr2)
        cout << i << " ";
    
    return 0;
}