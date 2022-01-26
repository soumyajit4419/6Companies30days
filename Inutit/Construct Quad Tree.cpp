#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *createTree(vector<vector<int>> &grid, int xStart, int xEnd, int yStart, int yEnd, int size)
    {

        int oneCount = 0;
        int zeroCount = 0;

        for (int i = xStart; i < xEnd; i++)
        {
            for (int j = yStart; j < yEnd; j++)
            {

                if (grid[i][j] == 1)
                {
                    oneCount++;
                }
                else
                {
                    zeroCount++;
                }
            }
        }

        if (oneCount == 0 || zeroCount == 0)
        {
            if (oneCount == 0)
            {
                return new Node(0, true);
            }

            return new Node(1, true);
        }

        Node *t = new Node(1, false);
        size = size / 2;
        t->topLeft = createTree(grid, xStart, xStart + size, yStart, yStart + size, size);
        t->topRight = createTree(grid, xStart, xStart + size, yStart + size, yEnd, size);
        t->bottomLeft = createTree(grid, xStart + size, xEnd, yStart, yStart + size, size);
        t->bottomRight = createTree(grid, xStart + size, xEnd, yStart + size, yEnd, size);
        return t;
    }

    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return createTree(grid, 0, n, 0, n, n);
    }
};