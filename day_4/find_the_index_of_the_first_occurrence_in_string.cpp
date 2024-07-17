class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 0, j = 0;
    
        int index = -1;
        while (i<n && j<m) {
            if (haystack[i] == needle[j]) {
                if (j == 0) index = i;
                j++;
                i++;
            } else {
                if (index != -1)
                    i = index+1;
                else
                    i++;
                index = -1;
                j = 0;
            }
        }

        if (j == m) return index;
        return -1;
    }
};
