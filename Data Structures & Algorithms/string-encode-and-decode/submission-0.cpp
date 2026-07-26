class Solution {
public:

    string encode(vector<string>& strs) {
        string encString;
        for(string str:strs)
            encString += to_string(str.size()) + '#' + str;
        return encString;
    }

    vector<string> decode(string s) {
        vector<string> decString;
        cout<<s<<endl;
        int i = 0;
        while(i < s.size())
        {
            string num;
            int j = i;
            while(s[j] != '#')
                num += s[j++];
            // cout<<"num:"<<num<<endl;
            int siz = stoi(num);
            i = j+1;
            string str = s.substr(i,siz);
            // cout<<"str:"<<str<<endl;
            i += siz;
            decString.push_back(str);
        }
        return decString;
    }
};
