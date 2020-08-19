int Solution::searchInsert(vector<int> &a, int k)
{
    int l = 0;
    int r = a.size() - 1;
    int n = a.size();
    int ans;

    if (a[n - 1] < k)
        return n;
    if (a[0] > k)
        return 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == k)
            return mid;
        else if (k > a[mid])
        {
            ans = mid + 1;
            l = mid + 1;
        }
        else if (k < a[mid])
        {
            ans = mid - 1;
            r = mid - 1;
        }
    }

    if (ans < 0)
        return 0;

    return ans + 1;
}
