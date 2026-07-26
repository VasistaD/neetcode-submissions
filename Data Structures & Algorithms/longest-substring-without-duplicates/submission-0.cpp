class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0,r=0,maxi=0;
        unordered_map<char,int> hashMap;
        while(r < n)
        {
            hashMap[s[r]]++;
            while(hashMap[s[r]] > 1 && l <= r)
            {
                hashMap[s[l]]--;
                if(hashMap[s[l]] == 0)
                    hashMap.erase(s[l]);
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
