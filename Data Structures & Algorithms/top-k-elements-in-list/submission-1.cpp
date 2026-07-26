class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        vector<vector<int>> freqMap(nums.size()+1);
        vector<int> res;
        for(int ele:nums)
            hashMap[ele]++;
        for(auto ele:hashMap)
            freqMap[ele.second].push_back(ele.first);
        
        for(int i=freqMap.size()-1;i>=0;i--)
        {
            for(int ele:freqMap[i])
            {
                res.push_back(ele);
                if(res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
