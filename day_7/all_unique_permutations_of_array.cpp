class Solution {
public:
    map<int, int> counter;
    vector<vector<int>> result;
    int n;
    
    void helper(vector<int> &current) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }

        for (auto &x: counter) {
            if (x.second > 0) {
                x.second--;
                current.push_back(x.first);
                helper(current);
                current.pop_back();
                x.second++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        for (auto &x: nums) counter[x]++;
        vector<int> current;
        helper(current);
        return result;
    }
};
