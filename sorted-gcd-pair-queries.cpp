class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx=*max_element(nums.begin(),nums.end());

        vector<int> freq(mx+1);

        for(int x:nums) freq[x]++;

        vector<long long> exact(mx+1);

        for(int g=mx;g>=1;g--){
            long long cnt=0;

            for(int m=g;m<=mx;m+=g){
                cnt+=freq[m];
            }

            exact[g]=cnt*(cnt-1)/2;

            for(int m=2*g;m<=mx;m+=g){
                exact[g]-=exact[m];
            }
        }

        vector<long long> pref(mx+1);

        for(int g=1;g<=mx;g++){
            pref[g]=pref[g-1]+exact[g];
        }

        vector<int> ans;

        for(long long x:queries){
            long long q=x+1;

            int l=1,r=mx;

            while(l<r){
                int mid=l+(r-l)/2;

                if(pref[mid]>=q) r=mid;
                else l=mid+1;
            }

            ans.push_back(l);
        }

        return ans;
    }
};
