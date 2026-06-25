class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

      
        for (int row = 0; row < 9; row++) {
            vector<int> freq(9, 0);

            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') continue;

                int num = board[row][col] - '0';

                if (freq[num - 1])
                    return false;

                freq[num - 1] = 1;
            }
        }

       
        for (int col = 0; col < 9; col++) {
            vector<int> freq(9, 0);

            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.') continue;

                int num = board[row][col] - '0';

                if (freq[num - 1])
                    return false;

                freq[num - 1] = 1;
            }
        }

        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {

                vector<int> freq(9, 0);

                for (int i = boxRow; i < boxRow + 3; i++) {
                    for (int j = boxCol; j < boxCol + 3; j++) {

                        if (board[i][j] == '.') continue;

                        int num = board[i][j] - '0';

                        if (freq[num - 1])
                            return false;

                        freq[num - 1] = 1;
                    }
                }
            }
        }

        return true;
    }
};