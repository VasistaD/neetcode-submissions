class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hashMap;

        for(char s_char:s)
            hashMap[s_char]++;

        for(char t_char:t)
        {
            if(hashMap[t_char] == 0)
                return false;
            hashMap[t_char]--;
            if(hashMap[t_char] == 0)
                hashMap.erase(t_char);
        }
        return hashMap.empty();
    }
};
