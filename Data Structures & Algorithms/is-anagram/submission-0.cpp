class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hashMap;

        for(char ch:s)
            hashMap[ch]++;

        for(char ch:t)
        {
            if(hashMap[ch] == 0)
                return false;

            hashMap[ch]--;
            if(hashMap[ch] == 0)
                hashMap.erase(ch);
        }
        return hashMap.empty();
    }
};
