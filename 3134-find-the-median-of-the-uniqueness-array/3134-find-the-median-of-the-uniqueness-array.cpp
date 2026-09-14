class Solution {
public:

    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(100001, 0);

        int left = 0;
        int distinct = 0;
        long long count = 0;

        for (int right = 0; right < n; right++) {

            if (freq[nums[right]] == 0)
                distinct++;

            freq[nums[right]]++;

            while (distinct > k) {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0)
                    distinct--;

                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int medianOfUniquenessArray(vector<int>& nums) {

        int n = nums.size();

        long long totalSubarrays = 1LL * n * (n + 1) / 2;

        // Position of the median (1-indexed)
        long long need = (totalSubarrays + 1) / 2;

        int low = 1;
        int high = n;

        while (low < high) {

            int mid = low + (high - low) / 2;

            long long count = countSubarrays(nums, mid);

            if (count >= need) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};