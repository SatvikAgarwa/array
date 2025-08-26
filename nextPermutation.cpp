#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums) {
    int index = -1, n = nums.size();

    for (int i = n - 2; i > 0; i--)
        if(nums[i] < nums[i + 1]) { 
            index = i; 
            break;
        }
    
    if(index == -1) { reverse(nums.begin(), nums.end()); return; }

    for(int i = n - 2; i > index; i--)
        if(nums[i] > nums[index]) {
            swap(nums[i], nums[index]);
            break;
        }

    for(int i = index + 1, j = n - 1; i < j; i++, j--)
        swap(nums[i], nums[j]);
}

int main() {
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    nextPermutation(nums);
    for (int i : nums) cout << i << " ";
    return 0;
}