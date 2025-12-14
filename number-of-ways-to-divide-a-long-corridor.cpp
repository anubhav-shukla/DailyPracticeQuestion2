class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1000000007;
        long res = 1;
        int prevSeat = 0;
        int numSeats = 0;

        for (int i = 0; i < corridor.length(); i++) {
            char c = corridor[i];
            if (c == 'S') {
                numSeats += 1;
                if (numSeats > 2 && numSeats % 2 == 1) {
                    res = res * (i - prevSeat) % mod;                    
                }
                prevSeat = i;
            }
        }

        return numSeats > 1 && numSeats % 2 == 0 ? res : 0;        
    }
};
