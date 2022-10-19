class Solution {
public:
    int countSubArrays(int limit, vector<int> &v) {
        int c=1,s=0;
        for(int i=0;i<v.size();i++) {
            if(s+v[i]<=limit) s+=v[i];
            else c++, s=v[i];
        }
        return c;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0, r=0;
        for(auto x:nums) { l=max(l,x); r+=x; }
        while(l<=r) {
            int mid = (l+r)/2;
            if(countSubArrays(mid,nums)<=m) r = mid-1;
            else l=mid +1;
        }
        return r+1;
    }
};
