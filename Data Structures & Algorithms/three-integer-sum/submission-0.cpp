class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n =nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int j=i+1,k=n-1;
            int target = (-1) * nums[i];
            while(j < k)
            {
                if(nums[j] + nums[k] == target)
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                }
                else if(nums[j] + nums[k] < target)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};
