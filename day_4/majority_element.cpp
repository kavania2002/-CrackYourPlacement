class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, current = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != current) {
                count--;
                if (count == 0) {
                    count = 1;
                    current = nums[i];
                }
            } else {
                count++;
            }
        }

        return current;
    }
};
