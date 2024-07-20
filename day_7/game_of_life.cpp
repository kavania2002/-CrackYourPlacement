// 1 -> 0 => 10
// 1 -> 1 => 11
// 0 -> 0 => 12
// 0 -> 1 => 13

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {

                int count = 0;
                for (int a = -1; a<=1; a++) {
                    for (int b = -1; b<=1; b++) {
                        int newi = i + a, newj = j + b;
                        if (!(newi<0 || newj<0 || newi == n || newj == m) && !(a == 0 && b == 0)) {
                            if (board[newi][newj] == 1 || board[newi][newj] == 10 || board[newi][newj] == 11) count++; 
                        }
                    }
                }

                if (board[i][j]) {
                    if (count == 2 || count == 3) board[i][j] = 11;
                    else board[i][j] = 10;
                } else {
                    if (count == 3) board[i][j] = 13;
                    else board[i][j] = 12;
                }

            }
        }

        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if (board[i][j] == 10 || board[i][j] == 12) board[i][j] = 0;
                else board[i][j] = 1;
            }
        }
    }
};
