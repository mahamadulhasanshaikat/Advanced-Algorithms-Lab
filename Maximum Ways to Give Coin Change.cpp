#include <bits/stdc++.h>
using namespace std;

// Function to count total ways to make amount
int countWays(vector<int>& coins, int amount){
    vector<int> dp(amount+1, 0);
    dp[0] = 1; // 1 way to make 0 (by choosing nothing)

    for(int c : coins){             // loop over coins
        for(int i=c; i<=amount; i++){ 
            dp[i] += dp[i-c];       // include coin c
        }
    }
    return dp[amount];
}

int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Total ways = " << countWays(coins, amount) << endl;
}
