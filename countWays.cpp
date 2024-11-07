#include <iostream>

using namespace std;

int countWays_1(int n) {
    int res = 0;

    if (n == 0 || n == 1)
        return 1;

    res = countWays_1(n - 1) + countWays_1(n - 2);

    return res;
}

int countWaysRec(int n, vector<int> memo) {
    
    if (n == 0 || n == 1)
        return 1;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = countWaysRec(n - 1, memo) + countWaysRec(n - 2, memo);

    return memo[n];
}

int countWays_2(int n) {
    int res = 0;
    vector<int> memo(n + 1, -1);

    res = countWaysRec(n, memo);

    return res;
}

int countWays(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

int main() {
    
    cout << countWays(4) << endl;   // 5
    cout << countWays(10) << endl;  // 89
    cout << countWays(3) << endl;   // 3

    return 0;
}