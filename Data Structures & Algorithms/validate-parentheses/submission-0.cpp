class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch:s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else
            {
                if(st.empty())
                    return false;
                char tp = st.top();
                if((ch == ')' && tp != '(') || (ch == '}' && tp != '{') || (ch == ']' && tp != '['))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
