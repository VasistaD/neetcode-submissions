class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string str:tokens)
        {
            if(str == "+")
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b + a);
            }
            else if(str == "-")
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b - a);
            }
            else if(str == "*")
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b * a);
            }
            else if(str == "/")
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b / a);
            }
            else
                st.push(stoi(str));
        }
        return st.top();
    }
};
