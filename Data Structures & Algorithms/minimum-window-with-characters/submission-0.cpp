class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hashMaps;
        unordered_map<char,int> hashMapt;
        int need=0,have=0;
        for(char ch:t)
        {
            hashMapt[ch]++;
        }
        // for(char ch:s)
        //     hashMaps[ch]++;
        need= hashMapt.size();
        int n=s.size(),l=0,r=0;
        int resl=0,resr=n-1,resLen=INT_MAX;
        while(r < n)
        {
            hashMaps[s[r]]++;
            if(hashMapt.count(s[r]) && hashMaps[s[r]] == hashMapt[s[r]] && have < need)
                have++;
            while(have == need)
            {
                if(r-l+1 < resLen)
                {
                    resl=l;
                    resr=r;
                    resLen = r-l+1;
                }
                hashMaps[s[l]]--;
                if(hashMapt.count(s[l]) && hashMaps[s[l]] < hashMapt[s[l]])
                    have--;
                l++;
            }
            r++;
        }
        string res = "";
        if(resLen != INT_MAX)
            res = s.substr(resl,resLen);
        return res;
    }
};
