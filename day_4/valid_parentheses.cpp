class Solution {
public:
    bool isValid(string s) {
        string result = "";
        for (char &c: s) {
            if (result.empty() || c == '(' || c == '[' || c == '{') result += c;
            else if (c == ')') {
                if (result.back() == '(') result.pop_back();
                else return false;
            } else if (c == '}') {
                if (result.back() == '{') result.pop_back();
                else return false;
            } else if (c == ']'){
                if (result.back() == '[') result.pop_back();
                else return false;
            }
        }
        return result.empty();
    }
};
