class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> cars(n);
        for(int i=0;i<n;i++)
            cars[i] = {position[i],speed[i]};

        sort(cars.begin(), cars.end());

        stack<double> st;

        for(int i=n-1;i>=0;i--)
        {
            // cout<<cars[i].first<<":"<<cars[i].second<<endl;
            if(!st.empty())
            {
                double curTime = (double)(target - cars[i].first) / cars[i].second * 1.0;
                // cout<<"curTime:"<<curTime<<endl;
                // cout<<"st.top:"<<st.top()<<endl;
                if(curTime <= st.top())
                    continue;
            }
            // cout<<"pushed:"<<(double)(target - cars[i].first) / cars[i].second<<endl;
            st.push((double)(target - cars[i].first) / cars[i].second * 1.0);
        }
        return st.size(); 
    }
};
