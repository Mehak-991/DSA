class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 == 1)
            return false;

        // Maximum possible balance is the path length
        int maxBalance = m + n - 1;
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(maxBalance + 1, false)
            )
        );

        // First character must be '('
        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                // Maximum balance possible at this cell
                int maxPossible = i + j + 1;

                for (int balance = 0;
                     balance <= maxPossible;
                     balance++) {

                    int previousBalance;

                    if (grid[i][j] == '(')
                        previousBalance = balance - 1;
                    else
                        previousBalance = balance + 1;

                    // Balance cannot be negative
                    if (previousBalance < 0)
                        continue;

                    // Previous balance cannot exceed the array
                    if (previousBalance > maxBalance)
                        continue;

                    // Come from top
                    if (i > 0 && dp[i - 1][j][previousBalance])
                        dp[i][j][balance] = true;

                    // Come from left
                    if (j > 0 && dp[i][j - 1][previousBalance])
                        dp[i][j][balance] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};