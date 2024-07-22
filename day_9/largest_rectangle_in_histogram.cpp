class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMin(n, 0), rightMin(n, n-1);

        stack<int> st;
        for (int i = 0; i<n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) leftMin[i] = st.top() + 1;
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = n-1; i>=0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) rightMin[i] = st.top() - 1;
            st.push(i);
        }

        int result = 0;
        for (int i = 0; i<n; i++) {
            result = max(result, heights[i]*(rightMin[i] - leftMin[i] + 1));
        }
        return result;
    }
};
