/*
Given an integer array of coins[] of size n representing different types of denominations and an integer sum, the task is to count all combinations of coins to make a given value sum.  
Note: Assume that you have an infinate supply of each type of coin.
*/

#include <iostream>
#include <vector>

using namespace std;

// Returns the count of ways we can
// sum coins[0...n-1] coins to get sum "sum"
int countRecur(vector<int>& coins, int n, int sum) {
  
    // If sum is 0 then there is 1 solution
    // (do not include any coin)
    if (sum == 0) return 1;

    // 0 ways in the following two cases
    if (sum < 0 || n == 0) return 0;

    // count is sum of solutions (i)
    // including coins[n-1] (ii) excluding coins[n-1]
    return countRecur(coins, n, sum - coins[n - 1]) + 
            countRecur(coins, n - 1, sum);
}

int count(vector<int> &coins, int sum) {
    return countRecur(coins, coins.size(), sum);
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    
    cout << count(coins, sum);
    return 0;
}