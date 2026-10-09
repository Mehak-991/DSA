class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int maxImbalance = 0;

        for (char ch : s) {
            if (ch == '[') {
                balance++;
            } else {
                balance--;
            }

            maxImbalance = max(maxImbalance, -balance);
        }

        return (maxImbalance + 1) / 2;
    }
};