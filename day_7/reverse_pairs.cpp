class Solution {
public:
    int result = 0;

    void countPairs(vector<int> &nums, int l, int m, int r) {
        int i = l, j = m+1, fromRight = 0;
        vector<int> temp;
        while (i <= m && j <= r) {
            if (nums[i] > 2LL*nums[j]) fromRight++, j++;
            else result += fromRight, i++;
        }

        while (i<=m) result += fromRight, i++;
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        int i = l, j = m+1, fromRight = 0;
        vector<int> temp;
        while (i <= m && j <= r) {
            if (nums[i] > nums[j]) temp.push_back(nums[j++]);
            else temp.push_back(nums[i++]);
        }

        while (i<=m) temp.push_back(nums[i++]);
        while (j<=r) temp.push_back(nums[j++]);

        for (int k = l; k<=r; k++) nums[k] = temp[k-l];
    }

    void partition(vector<int>& nums, int l, int r) {
        if (l>=r) return;

        int mid = l + (r-l)/2;
        partition(nums, l, mid);
        partition(nums, mid+1, r);
        countPairs(nums, l, mid, r);
        merge(nums, l, mid , r);
    }

    int reversePairs(vector<int>& nums) {
        partition(nums, 0, nums.size()-1);
        return result;
    }
};
