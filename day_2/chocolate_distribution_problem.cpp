class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        long long result = INT64_MAX;
        for (int i = m-1; i<n; i++) {
            result = min(result, a[i] - a[i-m+1]);
        }
        return result;
    }   
};