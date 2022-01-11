class Solution
{
public:
    //Function to count number of ways to reach the nth stair
    //when order does not matter.
    long long countWays(int n)
    {
        // your code here
        long long int count = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                count++;
            }
        }

        return count;
    }
};
