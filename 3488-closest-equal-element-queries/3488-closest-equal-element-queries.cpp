class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
         int n = nums.size();

        // Step 1: Store indices of each number
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        // Step 2: Process each query
        for (int qIndex : queries) {

            int value = nums[qIndex];
            vector<int>& indices = mp[value];

            // If only one occurrence → no answer
            if (indices.size() == 1) {
                result.push_back(-1);
                continue;
            }

            // Find position of current index in list
            int pos = lower_bound(indices.begin(), indices.end(), qIndex) - indices.begin();

            int size = indices.size();

            // Get previous and next positions (circular)
            int prevIndex = indices[(pos - 1 + size) % size];
            int nextIndex = indices[(pos + 1) % size];

            // Function to calculate circular distance
            auto getDistance = [&](int a, int b) {
                int diff = abs(a - b);
                return min(diff, n - diff);
            };

            int dist1 = getDistance(qIndex, prevIndex);
            int dist2 = getDistance(qIndex, nextIndex);

            // Store minimum distance
            result.push_back(min(dist1, dist2));
        }

        return result;
    }
        
    
};