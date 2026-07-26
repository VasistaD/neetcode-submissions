class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowList(9);
        vector<unordered_set<char>> colList(9);
        map<pair<int,int>, unordered_set<char>> squareList;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(rowList[i].find(board[i][j]) != rowList[i].end() || colList[j].find(board[i][j]) != colList[j].end() || squareList[{i/3,j/3}].find(board[i][j]) != squareList[{i/3,j/3}].end())
                        return false;
                    rowList[i].insert(board[i][j]);
                    colList[j].insert(board[i][j]);
                    squareList[{i/3,j/3}].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
