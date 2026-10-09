class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                // If the next character is ')', use it as a pair
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    // Insert one ')' to complete the pair
                    insertions++;
                }

                // If there is no '(' to match this '))', insert '('
                if (open > 0) {
                    open--;
                } 
                else {
                    insertions++;
                }
            }
        }
        insertions += open * 2;

        return insertions;
    }
};