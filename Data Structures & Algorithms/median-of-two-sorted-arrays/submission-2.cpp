class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            nums1.swap(nums2);

        int n1=nums1.size(), n2=nums2.size();
        int total = n1+n2;
        int half = (total+1)/2;
        int l=0, r=n1, i, j;
        int aleft,aright,bleft,bright;

        while(l <= r)
        {
            i = l + (r-l)/2;
            j = half - i;
            aleft = i > 0 ? nums1[i-1] : INT_MIN;
            aright = i < n1 ? nums1[i] : INT_MAX;
            bleft = j > 0 ? nums2[j-1] : INT_MIN;
            bright = j < n2 ? nums2[j] : INT_MAX;

            if(aleft <= bright && bleft <= aright)
            {
                if(total % 2 == 0)
                {
                    return (max(aleft,bleft) + min(aright,bright))/2.0;
                }
                else
                    return max(aleft,bleft);
            }
            else if(aleft > bright)
                r = i - 1;
            else
                l = i + 1;
        }
        return -1;
    }
};
