class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0,r=0;
        unordered_map<char,int> charCount;
        int maxCount = 0, maxFreq = 0;
        while(r < n)
        {
            charCount[s[r]]++;
            maxFreq = max(maxFreq, charCount[s[r]]);
            while(r - l + 1 > maxFreq + k)
            {
                charCount[s[l]]--;
                if(charCount[s[l]] == 0)
                    charCount.erase(s[l]);
                l++;
            }
            r++;
            maxCount = max(maxCount,r-l);
        }
        return maxCount;
    }
};
