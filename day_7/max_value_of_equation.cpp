class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int result = INT_MIN;

        for (auto &x: points) {
            while (!pq.empty() && x[0] - pq.top().second > k) pq.pop();
            if (!pq.empty()) {
                result = max(result, x[0] + x[1] + pq.top().first);
            }
            pq.push({x[1] - x[0], x[0]});
        }

        return result;
    }
};
