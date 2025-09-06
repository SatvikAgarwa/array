#include <bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    int invCount = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            invCount += (n1 - i);  
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return invCount;
}

int mergeSortAndCount(vector<int> &arr, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);

        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

int main() {
    vector<int> arr = {6, 3, 9, 5, 2, 8, 7};

    cout << "Before Sorting: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int invCount = mergeSortAndCount(arr, 0, arr.size() - 1);

    cout << "After Sorting: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Number of Inversions: " << invCount << endl;

    return 0;
}
