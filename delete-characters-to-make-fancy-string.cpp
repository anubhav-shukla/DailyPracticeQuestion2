#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        int p1 = 0;
        int cur = 1;
        string fancyString;
        fancyString += s[0];
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[p1]) {
                cur++;
            } else {
                cur = 1;
                p1 = i;
            }
            
            if (cur > 2) continue;
            fancyString += s[i];
        }
        
        return fancyString;
    }
};
