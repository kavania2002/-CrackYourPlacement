class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i<nums.size(); i++) {
            if (i<=maxIndex) maxIndex = max(maxIndex, nums[i] + i);
            else return false;
        }
        if (maxIndex >= nums.size()-1) return true;
        return false;
    }
};
