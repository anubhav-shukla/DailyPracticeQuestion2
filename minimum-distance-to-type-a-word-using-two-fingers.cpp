class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();

        // Precompute positions
        vector<vector<int>> pos(26, vector<int>(2));
        for(int i = 0; i < 26; i++){
            pos[i][0] = i / 6;
            pos[i][1] = i % 6;
        }

        int total = 0;
        vector<int> dp(26, 0); // max savings

        for(int i = 1; i < n; i++){
            int prev = word[i - 1] - 'A';
            int curr = word[i] - 'A';

            int d = dist(pos, prev, curr);
            total += d;

            vector<int> next(26, 0);

            for(int c = 0; c < 26; c++){
                // case 1: don't use second finger
                next[c] = max(next[c], dp[c]);

                // case 2: use second finger
                int saving = d - dist(pos, c, curr);
                next[prev] = max(next[prev], dp[c] + saving);
            }

            dp = next;
        }

        int maxSave = 0;
        for(int val : dp) maxSave = max(maxSave, val);

        return total - maxSave;
    }

private:
    int dist(vector<vector<int>>& pos, int a, int b){
        return abs(pos[a][0] - pos[b][0]) +
               abs(pos[a][1] - pos[b][1]);
    }
};
