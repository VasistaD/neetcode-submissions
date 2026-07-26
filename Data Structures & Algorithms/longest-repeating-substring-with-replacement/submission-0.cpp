class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> hashMap;
        int l=0,r=0,n=s.size();
        int maxi=0,maxFreq=0;
        while(r < n)
        {
            hashMap[s[r]]++;
            maxFreq = max(maxFreq,hashMap[s[r]]);
            while((r-l+1)-maxFreq > k)
            {
                hashMap[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
