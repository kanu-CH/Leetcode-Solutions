class Solution {
public:
bool isSafe(char value,vector<vector<char>> &board,int curr_row,int curr_col){
    //row check
    for(int col=0;col<9;col++){
        if(board[curr_row][col] == value)
        return false;
    }
      
    //column check
    for(int row=0;row<9;row++){
        if(board[row][curr_col] == value)
            return false;
    } 

    //3*3 matrix check
    for(int i=0;i<9;i++){
        if(board[3*(curr_row/3)+(i/3)][3*(curr_col/3)+(i%3)] == value)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board){
    int n = board[0].size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            //check empty cell
            if(board[i][j]=='.'){
                for(char value='1';value<='9';value++){
                    //check for safety
                    if(isSafe(value,board,i,j)){
                        //insert
                        board[i][j] = value;
                        //bakki recursion sambhal lega
                        bool aageKaSolution = solve(board);
                        if(aageKaSolution == true)
                            return true;
                        //backtracking
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }  
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
