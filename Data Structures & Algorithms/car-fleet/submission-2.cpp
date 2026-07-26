class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> cars(n);
        
        for(int i=0;i<n;i++)
            cars[i] = {position[i],speed[i]};

        sort(cars.rbegin(),cars.rend());

        stack<double> st;

        for(int i=0;i<n;i++)
        {
            if(!st.empty())
            {
                double curTime = (double)(target - cars[i].first) / cars[i].second;
                if(curTime <= st.top())
                    continue;
            }
            st.push((double)(target - cars[i].first) / cars[i].second);
        }
        return st.size();
    }
};
