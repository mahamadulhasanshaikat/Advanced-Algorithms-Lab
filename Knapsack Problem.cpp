#include <bits/stdc++.h>
using namespace std;

// Function to solve 0/1 Knapsack problem using DP
int knapSack(int W, vector<int> wt, vector<int> val, int n) {
    // DP table: dp[i][w] = max profit using first i items with capacity w
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<=n; i++){           // loop over items
        for(int w=1; w<=W; w++){       // loop over capacities
            if(wt[i-1] <= w) // If item can fit
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w]; // Otherwise, exclude it
        }
    }
    return dp[n][W]; // Final answer
}

int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    cout << "Max value = " << knapSack(W, wt, val, val.size()) << endl;
}
