class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n,1);
        vector<int> rightProd(n,1);
        leftProd[0] = 1;
        for(int i=1;i<n;i++)
            leftProd[i] = nums[i-1] * leftProd[i-1];
        rightProd[n-1] = 1;
        for(int i=n-1;i>0;i--)
            rightProd[i-1] = rightProd[i] * nums[i];
        
        // for(int ele:leftProd)
        //     cout<<ele<<" ";
        // cout<<endl;

        // for(int ele:rightProd)
        //     cout<<ele<<" ";
        // cout<<endl;

        vector<int> res(n,1);

        for(int i=0;i<n;i++)
        {
            res[i] = leftProd[i] * rightProd[i];
        }
        return res;
    }
};
