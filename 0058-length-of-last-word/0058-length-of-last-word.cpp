class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;

        // End ke spaces skip karo
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        // Last word ki length count karo
        int count = 0;

        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};