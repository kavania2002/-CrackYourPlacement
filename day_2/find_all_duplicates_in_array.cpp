class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i<nums.size(); i++) {
            int index = nums[i];
            if (nums[abs(index)-1] < 0) result.push_back(abs(index));
            nums[abs(index)-1] *= -1;
        }
        return result;
    }
};
