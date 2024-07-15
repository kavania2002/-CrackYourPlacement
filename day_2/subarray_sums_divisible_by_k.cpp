class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum = 0, result = 0;
        vector<int> remainders(k, 0);
        remainders[0] = 1;

        for (int &x: nums) {
            prefixSum = (prefixSum + x%k + k)%k;
            result += remainders[prefixSum];
            remainders[prefixSum]++;
        }
        return result;
    }
};

