class Solution {
public:
    int findMin(vector<int> &nums) {
        int l,r,mid;
        l=0,r=nums.size()-1;
        int res = r;
        while(l <= r)
        {
            mid = l + (r-l)/2;
            if(nums[mid] < nums[r])
            {
                res = mid;  
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return nums[res];
    }
};
