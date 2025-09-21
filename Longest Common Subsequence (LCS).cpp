#include <bits/stdc++.h>
using namespace std;

// Function to find length of LCS
int LCS(string X, string Y){
    int n = X.size(), m = Y.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(X[i-1] == Y[j-1]) 
                dp[i][j] = 1 + dp[i-1][j-1]; // match, take diagonal
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // skip one
        }
    }
    return dp[n][m];
}

int main(){
    string X = "AGGTAB", Y = "GXTXAYB";
    cout << "Length of LCS = " << LCS(X, Y) << endl;
}
