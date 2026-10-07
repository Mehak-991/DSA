class Solution {
public:
        unordered_set<string> result;

        void backtrack(string& s, int index, int leftCount, int rightCount,
                   int leftRemove, int rightRemove, string current) {

        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && leftCount == rightCount) {
                result.insert(current);
            }
            return;
        }

        char ch = s[index];

        // Parentheses
        if (ch == '(') {
            // Remove this '('
            if (leftRemove > 0) {
                backtrack(s, index + 1, leftCount, rightCount,
                          leftRemove - 1, rightRemove, current);
            }

            // Keep this '('
            backtrack(s, index + 1, leftCount + 1, rightCount,
                      leftRemove, rightRemove, current + ch);
        }
        else if (ch == ')') {
            // Remove this ')'
            if (rightRemove > 0) {
                backtrack(s, index + 1, leftCount, rightCount,
                          leftRemove, rightRemove - 1, current);
            }

            // Keep ')' only if it can be matched
            if (leftCount > rightCount) {
                backtrack(s, index + 1, leftCount, rightCount + 1,
                          leftRemove, rightRemove, current + ch);
            }
        }
        else {
            // Letters are always kept
            backtrack(s, index + 1, leftCount, rightCount,
                      leftRemove, rightRemove, current + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        // Find the minimum parentheses that must be removed
        for (char ch : s) {
            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        backtrack(s, 0, 0, 0, leftRemove, rightRemove, "");

        return vector<string>(result.begin(), result.end());
    }
};