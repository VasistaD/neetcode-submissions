class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;

        for(int i:nums)
        {
            freqMap[i]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto itr:freqMap)
        {
            bucket[itr.second].push_back(itr.first);
        }

        vector<int> res;

        for(int i=nums.size(); i > 0; i--)
        {
            for(int j:bucket[i])
            {
                res.push_back(j);
                if(res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
