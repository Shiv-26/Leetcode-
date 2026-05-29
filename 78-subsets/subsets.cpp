class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsetCount = 1 << n; // 2^n total subsets
        vector<vector<int>> result;

        for (int mask = 0; mask < subsetCount; ++mask) {
            vector<int> currentSubset;
            for (int i = 0; i < n; ++i) {
                // Check if the i-th bit of mask is set
                if ((mask & (1 << i)) != 0) {
                    currentSubset.push_back(nums[i]);
                }
            }
            result.push_back(currentSubset);
        }
        
        return result;
    }
};