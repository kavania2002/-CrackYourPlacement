class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pointer = 1, iterator = 1;
        while (iterator < n) {
            if (nums[iterator] != nums[iterator-1]) {
                nums[pointer++] = nums[iterator];
            }
            iterator++;
        }
        return pointer;
    }
};