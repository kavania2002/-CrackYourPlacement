class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string current = "";
        for (int i = 0; i<201; i++) {
            if (i < strs[0].size()) {
                char previous = strs[0][i];
                for (string &x: strs) {
                    if (i>=x.size() || x[i] != previous) return current;
                }
                current += previous;
            } else return current;
        }
        return current;
    }
};
