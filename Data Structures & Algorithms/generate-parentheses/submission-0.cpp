class Solution {
public:
    void backTrack(vector<string>& res, string curString, int openCount, int closeCount, int n) {
        if(openCount == closeCount && openCount == n)
        {
            res.push_back(curString);
            return;
        }
        if(openCount < n)
        {
            curString.push_back('(');
            backTrack(res, curString, openCount+1, closeCount, n);
            curString.pop_back();
        }
        if(closeCount < openCount)
        {
            curString.push_back(')');
            backTrack(res, curString, openCount, closeCount+1, n);
            curString.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curString;
        backTrack(res, curString, 0, 0, n);
        return res;
    }
};
