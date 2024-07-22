class Solution {
public:
    vector<string> result;
    void helper(string current, int left, int right, int &n) {
        if (left == n && right == n) {
            result.push_back(current);
            return;
        }

        if (left > n || right > n) return;

        if (left > right) helper(current+")", left, right+1, n);
        helper(current + "(", left+1, right, n);
    }

    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return result;
    }
};
