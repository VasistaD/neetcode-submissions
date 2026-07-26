class Solution {
public:
    bool canKokoEat(vector<int>& piles, int h, int mid) {
        int count = 0;
        for(int pile:piles)
            count += ceil(static_cast<double>(pile) / mid);
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(), piles.end());
        int res = 0;
        int mid;
        while(l <= r)
        {
            mid = l + (r-l)/2;
            if(canKokoEat(piles, h, mid))
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};
