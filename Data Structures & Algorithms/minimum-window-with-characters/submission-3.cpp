class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> charCountt,window;
        int n=s.size();
        if(t.empty())
            return t;
        for(char ch:t)
            charCountt[ch]++;
        int have=0,need = charCountt.size();
        int l=0,r=0;
        int maxLen=INT_MAX;
        vector<int> posi(2,-1);
        while(r < n)
        {
            window[s[r]]++;
            if(charCountt.count(s[r]) && window[s[r]] == charCountt[s[r]] && have < need)
            {
                have++;
            }
            while(need == have)
            {
                if(r-l+1 < maxLen)
                {
                    posi[0] = l;
                    posi[1] = r;
                    maxLen = r-l+1;
                }
                window[s[l]]--;
                if(charCountt.count(s[l]) && window[s[l]] < charCountt[s[l]])
                {
                    have--;
                }
                l++;
            }
            r++;
        }
        // cout<<"Len:"<<maxLen;
        if(maxLen == INT_MAX)
            return "";
        string res = s.substr(posi[0],maxLen); 
        return res;
    }
};
