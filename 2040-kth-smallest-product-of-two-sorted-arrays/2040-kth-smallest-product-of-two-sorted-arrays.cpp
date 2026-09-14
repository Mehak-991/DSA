class Solution {
public:

    // Count how many products are <= x
    long long countProducts(vector<int>& nums1,
                            vector<int>& nums2,
                            long long x) {

        long long count = 0;

        for (long long a : nums1) {

            // a = 0
            if (a == 0) {
                if (x >= 0)
                    count += nums2.size();
            }

            // a > 0
            else if (a > 0) {

                // a * b <= x
                // b <= floor(x / a)

                long long limit = x / a;

                // Fix C++ division for negative x
                if (x < 0 && x % a != 0)
                    limit--;

                count += upper_bound(nums2.begin(),
                                     nums2.end(),
                                     limit) - nums2.begin();
            }

            // a < 0
            else {

                // a * b <= x
                // b >= ceil(x / a)

                long long limit = x / a;

                // Fix C++ division for negative x
                if (x < 0 && x % a != 0)
                    limit++;

                count += nums2.end()
                       - lower_bound(nums2.begin(),
                                     nums2.end(),
                                     limit);
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1,
                                 vector<int>& nums2,
                                 long long k) {

        long long low = -10000000000LL;
        long long high = 10000000000LL;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            long long count = countProducts(nums1, nums2, mid);

            if (count >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};