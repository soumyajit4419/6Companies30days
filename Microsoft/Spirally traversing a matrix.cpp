#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        int size = r * c;
        vector<int> arr(size);

        int top = 0, right = c - 1, bottom = r - 1, left = 0;
        int dir = 0;
        int count = 0;

        while (top <= bottom && left <= right)
        {
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    arr[count] = matrix[top][i];
                    count++;
                }
                top++;
                dir = 1;
            }
            else if (dir == 1)
            {
                for (int i = top; i <= bottom; i++)
                {
                    arr[count] = matrix[i][right];
                    count++;
                }
                right--;
                dir = 2;
            }
            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    arr[count] = matrix[bottom][i];
                    count++;
                }
                bottom--;
                dir = 3;
            }
            else if (dir == 3)
            {
                for (int i = bottom; i >= top; i--)
                {
                    arr[count] = matrix[i][left];
                    count++;
                }
                left++;
                dir = 0;
            }
        }

        return arr;
    }
};