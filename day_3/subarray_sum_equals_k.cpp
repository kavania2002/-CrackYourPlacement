class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0]++;
        int current = 0;
        int result = 0;
        for (int i = 0; i<n; i++) {
            current += nums[i];
            if (mp.count(current-k)) result+=mp[current-k];
            mp[current]++;
        }

        return result;
    }
};

