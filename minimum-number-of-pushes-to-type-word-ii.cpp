class Solution {
public:
    int minimumPushes(string word) {

        vector<int> freq(26, 0);

        int maxFreq = 0;

        // Count the frequency of every letter
        for (char ch : word) {
            freq[ch - 'a']++;
            maxFreq = max(maxFreq, freq[ch - 'a']);
        }

        // Bucket sort frequencies
        vector<int> bucket(maxFreq + 1, 0);

        for (int f : freq) {
            if (f > 0) {
                bucket[f]++;
            }
        }

        int ans = 0;
        int rank = 0;   // Position among the used letters

        // Process frequencies from highest to lowest
        for (int f = maxFreq; f >= 1; f--) {

            while (bucket[f]--) {

                // Every group of 8 letters requires one extra key press
                int press = (rank / 8) + 1;

                ans += press * f;

                rank++;
            }
        }

        return ans;
    }
};
