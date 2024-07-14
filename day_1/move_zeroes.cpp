class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer = 0, iterator = 0;
        int n = nums.size();

        while (iterator < n) {
            if (nums[iterator]) {
                swap(nums[zeroPointer++], nums[iterator]);
            }
            iterator++;
        }
    }
};