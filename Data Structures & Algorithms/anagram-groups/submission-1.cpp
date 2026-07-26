class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashMap;

        for(string str:strs)
        {
            vector<int> vecstring(26,0);
            for(char ch:str)
            {
                vecstring[ch - 'a']++;
            }
            string s;
            for(int i=0;i<26;i++)
                s += to_string(vecstring[i]) + ',';
            hashMap[s].push_back(str);
        }

        vector<vector<string>> result;

        for(auto itr:hashMap)
        {
            result.push_back(itr.second);
        }
        return result;
    }
};
