class Solution {
public:
    vector<vector<char>> grid;
    int n, m;

    int dirs[5] = {0, -1, 0, 1, 0};

    bool valid(int &r, int &c) {
        if (r < 0 || c < 0 || r == n || c == m) return false;
        return true;
    }

    bool exist(string &word, int index, int r, int c) {
        if (index == word.size()) return true;

        bool result = false;
        for (int i = 0; i<5; i++) {
            int ri = r + dirs[i];
            int ci = c + dirs[i+1];
            if (valid(ri, ci) && grid[ri][ci] == word[index]) {
                grid[ri][ci] = '0';
                result |= exist(word, index+1, ri, ci);
                grid[ri][ci] = word[index];
            }
        }
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        this->grid = board;

        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if (grid[i][j] == word[0]) {
                    grid[i][j] = '0';
                    if (exist(word, 1, i, j)) {
                        return true;
                    }
                    grid[i][j] = word[0];
                }
            }
        }

        return false;
    }
};
