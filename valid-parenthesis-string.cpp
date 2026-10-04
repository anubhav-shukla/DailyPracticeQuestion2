class Solution {
public:
    bool checkValidString(string s) {
        int l=0;
        int h=0;
        for(char c:s){
            l+=(c=='(' ? 2:0)-1;
            h+=(c!=')' ? 2:0)-1;
            if(h<0){
                return false;   
            }
            l=std::max(l,0);
        }
        return l==0;
    }
};
