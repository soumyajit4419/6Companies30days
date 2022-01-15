void rotate(int n, int a[][n])
{
    //code here
    for (int i = 0; i < n; i++)
    {
        int k = n - 1;
        for (int j = 0; j < n / 2; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[i][k];
            a[i][k] = temp;
            k--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }
    }

    return;
}
