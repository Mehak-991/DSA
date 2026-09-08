class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
          int n = nums.size();

        long long sum = 0;
        long long current = 0;

        // Calculate F(0) and total sum
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            current += 1LL * i * nums[i];
        }

        long long answer = current;

        // Calculate F(1), F(2), ...
        for (int k = 1; k < n; k++) {
            current = current + sum - 1LL * n * nums[n - k];

            answer = max(answer, current);
        }

        return answer;
    }
    
};