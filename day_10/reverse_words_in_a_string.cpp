class Solution {
public:
    string reverseWords(string s) {
        string result = "";

        stringstream ss(s);
        string word;
        while (ss >> word) {
            result = word + " " + result;
        }
        result.pop_back();
        return result;
    }
};
