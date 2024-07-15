class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for (int i = 0; i<n; i++) mp[nums[i]] = i;

        vector<vector<int>> result;
        for (int i = 0; i<nums.size()-2; i++) {
            for (int j = i+1; j<nums.size()-1; j++) {
                int sum = -1*(nums[i] + nums[j]);
                if (mp.count(sum) && mp[sum] > j) {
                    result.push_back({nums[i], nums[j], sum});
                }
                j = mp[nums[j]];
            }
            i = mp[nums[i]];
        }
        return result;
    }
};
