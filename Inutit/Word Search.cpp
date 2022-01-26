#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int pos)
    {
        int n = board.size();
        int m = board[0].size();

        if (pos >= word.length())
        {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '0';

        if (i + 1 < n && word[pos] == board[i + 1][j])
        {
            if (dfs(board, i + 1, j, word, pos + 1))
            {
                return true;
            }
        }

        if (i - 1 >= 0 && word[pos] == board[i - 1][j])
        {
            if (dfs(board, i - 1, j, word, pos + 1))
            {
                return true;
            }
        }

        if (j + 1 < m && word[pos] == board[i][j + 1])
        {
            if (dfs(board, i, j + 1, word, pos + 1))
            {
                return true;
            }
        }

        if (j - 1 >= 0 && word[pos] == board[i][j - 1])
        {
            if (dfs(board, i, j - 1, word, pos + 1))
            {
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool isWordExist(vector<vector<char>> &board, string word)
    {
        // Code here

        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, i, j, word, 1))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};