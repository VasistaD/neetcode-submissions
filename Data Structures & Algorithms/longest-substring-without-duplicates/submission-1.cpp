class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> charCount;
        int l=0,r=0;
        int maxCount=0;
        while(r < n)
        {
            charCount[s[r]]++;
            while(charCount[s[r]] != 1)
            {
                charCount[s[l]]--;
                if(charCount[s[l]] == 0)
                    charCount.erase(s[l]);
                l++;
            }
            maxCount = max(maxCount,(int)charCount.size());
            r++;
        }
        return maxCount;
    }
};
