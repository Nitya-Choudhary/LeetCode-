class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if (m == 0 || n == 0) return false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int start) {
        if (start == word.size()) return true;

        int m = board.size(), n = board[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (board[i][j] != word[start])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        bool found = dfs(board, i + 1, j, word, start + 1) ||
                     dfs(board, i - 1, j, word, start + 1) ||
                     dfs(board, i, j + 1, word, start + 1) ||
                     dfs(board, i, j - 1, word, start + 1);

        board[i][j] = temp; // backtrack

        return found;
    }
};
