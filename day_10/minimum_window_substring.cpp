class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int totalCount = m, start = 0, end = 0, head = 0, current = INT_MAX;

        unordered_map<char, int> counter;
        for (char &c: t) counter[c]++;

        while (end < n) {
            if (counter[s[end++]]-- > 0) totalCount--;
            while (totalCount == 0) {
                if (end-start < current) current = end-(head = start);
                if (counter[s[start++]]++ == 0) totalCount++;
            }
        }
        return current == INT_MAX ? "" : s.substr(head, current);
    }
};
