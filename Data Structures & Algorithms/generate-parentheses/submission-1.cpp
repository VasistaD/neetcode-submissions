class Solution {
public:
    void backTrack(string curString, vector<string>& res, int openCount, int closeCount, int n) {
        if(openCount == closeCount && openCount == n)
        {
            res.push_back(curString);
            return;
        }
        if(openCount > n || closeCount > n || openCount < closeCount)
            return;
        curString.push_back('(');
        backTrack(curString, res, openCount+1, closeCount, n);
        curString.pop_back();
        curString.push_back(')');
        backTrack(curString, res, openCount, closeCount+1, n);
        curString.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curString;
        backTrack(curString, res, 0, 0, n);
        return res;
    }
};
