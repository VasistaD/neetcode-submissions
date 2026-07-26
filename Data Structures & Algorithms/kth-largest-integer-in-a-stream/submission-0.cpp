class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int psize;
    KthLargest(int k, vector<int>& nums) {
        psize = k;
        for(int ele:nums)
            add(ele);
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > psize)
            pq.pop();
        return pq.top();
    }
};
