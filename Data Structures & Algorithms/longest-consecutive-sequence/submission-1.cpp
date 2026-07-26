class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> hashSet;

        for(int ele:nums)
            hashSet.insert(ele);

        for(auto ele:hashSet)
        {
            int num = ele;
            if(hashSet.find(ele-1) == hashSet.end())
                while(hashSet.find(num) != hashSet.end())
                    num++;
            maxLen = max(maxLen,num-ele);
        }
        return maxLen;
    }
};
