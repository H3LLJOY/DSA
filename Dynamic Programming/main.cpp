#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int target) {
    vector<vector<int>> dp(coins.size(), vector<int>(target + 1, INT_MAX));

    // Base case: 0 coins needed to make change for 0
    for (int i = 0; i < coins.size(); i++) {
        dp[i][0] = 0;
    }

    for (int i = 0; i < coins.size(); i++) {
        for (int j = 1; j <= target; j++) {
            if (i > 0) {
                dp[i][j] = dp[i - 1][j]; // Use the previous denomination's value as the default
            }
            if (j - coins[i] >= 0) {
                dp[i][j] = std::min(dp[i][j], dp[i][j - coins[i]] + 1); // Check if using current denomination is better
            }
        }
    }

    return dp[coins.size() - 1][target];
}

int main() {
    std::vector<int> coins = {1, 5, 10, 25};
    int target = 11;
    int result = minCoins(coins, target);
    std::cout << "Minimum number of coins needed: " << result << std::endl;
    return 0;
}
