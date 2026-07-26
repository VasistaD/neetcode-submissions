class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),l=0,r=n-1;
        int maxL=height[l],maxR=height[r];
        int totArea=0;
        while(l < r)
        {
            if(height[l] < height[r])
            {
                l++;
                maxL = max(maxL,height[l]);
                totArea += maxL - height[l];
            }
            else
            {
                r--;
                maxR = max(maxR,height[r]);
                totArea += maxR - height[r];
            }
        }
        return totArea;
    }
};
