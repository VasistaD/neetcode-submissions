class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())
            return "";
        int n = s.size();
        unordered_map<char,int> charCountt, window;
        for(int i=0;i<t.size();i++)
        {
            charCountt[t[i]]++;
        }
        int l=0,r=0;
        int minSize = INT_MAX;
        int need = charCountt.size(), have = 0;
        pair<int,int> pos = {-1,-1};
        while(r < n)
        {
            window[s[r]]++;
            if(charCountt.count(s[r]) && window[s[r]] == charCountt[s[r]] && have < need)
                have++;
            while(have == need)
            {
                if(r-l+1 < minSize)
                {
                    pos = {l,r};
                    minSize = r-l+1;
                }
                window[s[l]]--;
                if(charCountt.count(s[l]) && window[s[l]] < charCountt[s[l]])
                {
                    // window.erase(s[l]);
                    have--;
                }
                l++;
            }
            r++;
        }
        if(pos.first != -1)
            return s.substr(pos.first,minSize);
        return "";
    }
};
