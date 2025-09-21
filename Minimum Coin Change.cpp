#include <bits/stdc++.h>
using namespace std;

// Function to find minimum coins needed for given amount
int minCoins(vector<int>& coins, int amount){
    vector<int> dp(amount+1, INT_MAX); 
    dp[0] = 0; // 0 coins needed for 0 amount

    for(int i=1; i<=amount; i++){ // loop over all amounts
        for(int c : coins){       // try each coin
            if(i-c >= 0 && dp[i-c] != INT_MAX){
                dp[i] = min(dp[i], dp[i-c]+1); // take min coins
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount]; // -1 if not possible
}

int main(){
    vector<int> coins = {1, 3, 4};
    int amount = 6;
    cout << "Min coins = " << minCoins(coins, amount) << endl;
}
