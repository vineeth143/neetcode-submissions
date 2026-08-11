class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row, int m, int n) {
        unordered_map<char,int> umap;
        for(int i=0;i<n;i++) {
            if(board[row][i]=='.')
                continue;
            else if(board[row][i]<'1' || board[row][i]>'9') {
                return false;
            }  
            else {
                if(umap.find(board[row][i])!=umap.end())
                    return false;
                umap[board[row][i]]++;
            }
        }
        return true;
    }
    bool isValidCol(vector<vector<char>>& board, int col, int m, int n) {
        unordered_map<int,int> umap;
        for(int i=0;i<m;i++) {
            if(board[i][col]=='.')
                continue;
            else if(board[i][col]<'1' || board[i][col]>'9')
                return false;
            else {
                if(umap.find(board[i][col])!=umap.end())
                    return false;
                umap[board[i][col]]++;
            }
        }
        return true;
    }
    bool isValidBox(vector<vector<char>>& board, int row, int col, int m, int n) {
        unordered_map<int,int> umap;
        for(int i=row;i<row+3;i++) {
            for(int j=col;j<col+3;j++) {
                if(board[i][j]=='.')
                    continue;
                else if(board[i][j]<'1' || board[i][j]>'9')
                    return false;
                else {
                    if(umap.find(board[i][j])!=umap.end())
                        return false;
                    umap[board[i][j]]++;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i=0;i<rows;i++) {
            if(!isValidRow(board, i, rows, cols))
            {
                return false;
            }
                
        }

        for(int i=0;i<cols;i++) {
            if(!isValidCol(board, i, rows, cols))
            {
                return false;
            } 
        }

        for(int i=0;i<9;i+=3) {
            for(int j=0;j<9;j+=3) {
                if(!isValidBox(board, i, j, rows, cols))
                {
                    return false;
                } 
            }
        }
        return true;

    }
};
