class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long totalOperations = 1LL * k1 + k2;
        long long totalDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            totalDiff += diff[i];
        }

        // If we can remove every difference, the answer is 0
        if (totalOperations >= totalDiff)
            return 0;

        // Count how many differences have each value
        vector<int> freq(100001, 0);

        for (int d : diff) {
            freq[d]++;
        }

        // Reduce the largest differences first
        for (int d = 100000; d > 0 && totalOperations > 0; d--) {
            if (freq[d] == 0)
                continue;

            long long operations = min(totalOperations, 1LL * freq[d]);

            freq[d] -= operations;
            freq[d - 1] += operations;

            totalOperations -= operations;
        }

        // Calculate the final sum of squared differences
        long long answer = 0;

        for (int d = 1; d <= 100000; d++) {
            answer += 1LL * d * d * freq[d];
        }

        return answer;
    }
};