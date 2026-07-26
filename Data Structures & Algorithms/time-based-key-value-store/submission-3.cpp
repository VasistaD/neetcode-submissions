class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> timeMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto timeList = timeMap[key];
        int l=0,r=timeList.size()-1;
        int mid;
        string res;
        while(l <= r)
        {
            mid = l + (r-l)/2;
            if(timeList[mid].first <= timestamp)
            {
                res = timeList[mid].second;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        // if(l >= timestamp)
        //     return timeList[l].second;
        // return "";
        return res;
    }
};
