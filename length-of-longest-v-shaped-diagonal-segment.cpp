class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        // dp arrays for 4 directions
        vector<vector<int>> dl(n, vector<int>(m, 0)); // ↙
        vector<vector<int>> dr(n, vector<int>(m, 0)); // ↘
        vector<vector<int>> ul(n, vector<int>(m, 0)); // ↖
        vector<vector<int>> ur(n, vector<int>(m, 0)); // ↗
        
        // Down-left (↙) & down-right (↘)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                dl[i][j] = 1;
                dr[i][j] = 1;
                if (i > 0 && j > 0 && grid[i-1][j-1] == grid[i][j])
                    dl[i][j] = dl[i-1][j-1] + 1;
                if (i > 0 && j < m-1 && grid[i-1][j+1] == grid[i][j])
                    dr[i][j] = dr[i-1][j+1] + 1;
            }
        }

        // Up-left (↖) & up-right (↗)
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                ul[i][j] = 1;
                ur[i][j] = 1;
                if (i < n-1 && j > 0 && grid[i+1][j-1] == grid[i][j])
                    ul[i][j] = ul[i+1][j-1] + 1;
                if (i < n-1 && j < m-1 && grid[i+1][j+1] == grid[i][j])
                    ur[i][j] = ur[i+1][j+1] + 1;
            }
        }

        int ans = 0;
        // Combine for V-shapes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                // ↙ then ↗
                if (dl[i][j] > 1 && ur[i][j] > 1)
                    ans = max(ans, dl[i][j] + ur[i][j] - 1);
                // ↘ then ↖
                if (dr[i][j] > 1 && ul[i][j] > 1)
                    ans = max(ans, dr[i][j] + ul[i][j] - 1);
            }
        }
        return ans;
    }
};
