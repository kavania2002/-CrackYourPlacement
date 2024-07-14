class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, iterator = 0, two = n-1;

        while (iterator <= two) {
            if (nums[iterator] == 0) {
                swap(nums[iterator++], nums[zero++]);
            } else if (nums[iterator] == 2) {
                swap(nums[iterator], nums[two--]);
            } else if (nums[iterator] == 1) {
                iterator++;
            }
        }
    }
};