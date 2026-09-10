class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        // Calculate sums and '?' count in both halves
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        if ((leftQ + rightQ) % 2 == 1)
            return true;

        // Difference between the current sums
        int diff = leftSum - rightSum;

        int questionDiff = (leftQ - rightQ) / 2;

        return diff != -questionDiff * 9;
    }
};