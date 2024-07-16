class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int n = cardPoints.size();
        int current = 0;
        for (int i = 0; i<n-k; i++) current += cardPoints[i];
        int result = totalSum - current;

        for (int i = n-k; i<n; i++) {
            current += cardPoints[i];
            current -= cardPoints[i-(n-k)];
            result = max(result, totalSum - current);
        }
        return result;
    }
};
