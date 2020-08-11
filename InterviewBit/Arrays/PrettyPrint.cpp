vector<vector<int>> Solution::prettyPrint(int A)
{
    int n = 2 * A - 1;
    vector<vector<int>> a(n);
    int inc;

    for (int i = 0; i < n; i++)
    {
        int num = A;
        a[i].assign(n, num);

        for (int j = 0; j < n; j++)
        {
            if (i < A)
            {
                if (j <= i)
                {
                    a[i][j] = num;
                    num--;
                    if (j == i)
                        num++;
                }
                else if (j <= n - i - 1)
                {
                    a[i][j] = num;
                }
                else if (j > n - i - 1)
                {
                    num++;
                    a[i][j] = num;
                }
            }
            else
            {
                a[i][j] = a[n - i - 1][j];
            }
        }
    }

    return a;
}
