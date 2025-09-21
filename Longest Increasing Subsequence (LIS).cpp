#include <bits/stdc++.h>
using namespace std;

// Function to find LIS using binary search
int LIS(vector<int>& nums){
    vector<int> dp; // stores increasing subsequence
    for(int x : nums){
        auto it = lower_bound(dp.begin(), dp.end(), x); 
        if(it == dp.end()) dp.push_back(x); // new largest element
        else *it = x; // replace to keep smallest element
    }
    return dp.size();
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "Length of LIS = " << LIS(nums) << endl;
}
