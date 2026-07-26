class Solution {
public:
    int findMin(vector<int> &a) {
        int l=0,r=a.size()-1;
        int mid,res=a[0];

        while(l < r)
        {
            mid = l + (r-l)/2;
            if(a[mid] > a[r])
            {
                l = mid + 1;
            }
            else
            {
                r=mid;
            }
        }
        return a[r];
    }
};
