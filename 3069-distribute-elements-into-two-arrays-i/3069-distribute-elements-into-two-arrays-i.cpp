class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
           vector<int> arr1, arr2;

        // First two elements go directly into arr1 and arr2
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Decide where each remaining element should go
        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Combine arr1 and arr2
        for (int x : arr2) {
            arr1.push_back(x);
        }

        return arr1;
    }
};