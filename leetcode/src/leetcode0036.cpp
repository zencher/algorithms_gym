// leetcode036.cpp
//
//Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//Each row must contain the digits 1-9 without repetition.
//Each column must contain the digits 1-9 without repetition.
//Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//A partially filled sudoku which is valid.
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

#include <vector>
#include <map>
using namespace std;

/*class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int y = 0; y < 9; ++y) {
            Begin();
            for (int x = 0; x < 9; ++x) {
                if (Insert(board[y][x]) != true)
                {
                    return false;
                }
            }
        }
        
        for (int x = 0; x < 9; ++x) {
            Begin();
            for (int y = 0; y < 9; ++y) {
                if (Insert(board[y][x]) != true)
                {
                    return false;
                }
            }
        }
        
        for (int x = 0; x < 9; x += 3) {
            for (int y = 0; y < 9; y += 3) {
                Begin();
                for (int xi = 0; xi < 3; ++xi) {
                    for (int yi = 0; yi < 3; ++yi) {
                        if (Insert(board[x+xi][y+yi]) != true)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
private:
    void Begin()
    {
        map_.clear();
    }
    
    bool Insert(char c)
    {
        if (c >= '0' && c <= '9')
        {
            int i = int(c - '0');
            auto it = map_.find(i);
            if (it != map_.end())
            {
                return false;
            }else{
                map_[i] = true;
            }
        }
        return true;
    }
    map<int,bool> map_;
};*/

class Solution1
{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool colChecker[9][9] = {false};
        bool boxChecker[9][9] = {false};
        
        for (size_t row = 0; row < 9; ++row) {
            bool rowChecker[9] = {false};
            for (size_t col = 0; col < 9; ++col) {
                if (board[row][col] != '.') {
                    char check = board[row][col];
                    size_t index = (size_t)check-'1';
                    size_t boxIndex = mapToBox(row, col);
                    if (colChecker[col][index] || rowChecker[index] || boxChecker[boxIndex][index]) {
                        return false;
                    }
                    colChecker[col][index] = true;
                    rowChecker[index] = true;
                    boxChecker[boxIndex][index] = true;
                }
            }
        }
        return true;
    }
    
    size_t mapToBox(size_t row, size_t col) {
        return col/3 + 3 * (row/3);
    }
};


int main()
{
    vector<vector<char>> sudoku;
    vector<char> line;
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('5');
    line.push_back('.');
    line.push_back('.');
    line.push_back('1');
    line.push_back('.');
    sudoku.push_back(line);
    
    line.clear();
    line.push_back('.');
    line.push_back('4');
    line.push_back('.');
    line.push_back('3');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    sudoku.push_back(line);
    
    line.clear();
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('3');
    line.push_back('.');
    line.push_back('.');
    line.push_back('1');
    sudoku.push_back(line);
    
    line.clear();
    line.push_back('8');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('2');
    line.push_back('.');
    sudoku.push_back(line);
    
    line.clear();
    line.push_back('.');
    line.push_back('.');
    line.push_back('2');
    line.push_back('.');
    line.push_back('7');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    sudoku.push_back(line);
    
    line.clear();
    line.push_back('.');
    line.push_back('1');
    line.push_back('5');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    sudoku.push_back(line);
    
    line.clear();
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('2');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    sudoku.push_back(line);
    
    line.clear();
    line.push_back('.');
    line.push_back('2');
    line.push_back('.');
    line.push_back('9');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    sudoku.push_back(line);
    
    line.clear();
    line.push_back('.');
    line.push_back('.');
    line.push_back('4');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    line.push_back('.');
    sudoku.push_back(line);
    
    Solution1 s;
    
    bool bRet = s.isValidSudoku(sudoku);
    
    return 0;
}
