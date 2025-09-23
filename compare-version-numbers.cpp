class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1), s2(version2);
        string token1, token2;
        
        while (getline(s1, token1, '.') || getline(s2, token2, '.')) {
            int num1 = token1.empty() ? 0 : stoi(token1);
            int num2 = token2.empty() ? 0 : stoi(token2);
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            token1.clear(); token2.clear();
        }
        return 0;
    }
};
