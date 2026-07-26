class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashMap;
        for(string str:strs)
        {
            vector<int> vec(26,0);
            for(char ch:str)
                vec[ch - 'a']++;
            string keyStr;
            for(int i=0;i<26;i++)
                keyStr += ',' + to_string(vec[i]);
            hashMap[keyStr].push_back(str);
        }
        vector<vector<string>> res;
        for(auto ele:hashMap)
            res.push_back(ele.second);
        return res;
    }
};
