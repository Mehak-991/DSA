class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool hasOdd = false;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 != 0) {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }

        // If all numbers are already even
        if (!hasOdd) {
            return true;
        }
        for (int x : nums1) {
            if (x % 2 == 0 && x <= minOdd) {
                return false;
            }
        }

        return true;
    }
};