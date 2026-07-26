class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(auto ele:nums)
        {
            if(hashSet.find(ele) != hashSet.end())
                return true;
            hashSet.insert(ele);
        }
        return false;
    }
};