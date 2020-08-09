vector<int> findPerm(const string A, int n)
{
    vector<int> arr(n);

    int l = 1;
    int r = n;

    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == 'I')
        {
            arr[i] = l;
            l++;
        }
        else
        {
            arr[i] = r;
            r--;
        }
    }

    arr[n - 1] = l;

    return arr;
}
