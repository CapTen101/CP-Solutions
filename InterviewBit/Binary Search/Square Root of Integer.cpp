int Solution::sqrt(int n)
{
    long long l = 1;
    long long r = n;
    long long ans = 0;

    if (n == 0)
        return 0;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;

        if (mid == (n / mid))
            return mid;
        else if (mid < (n / mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else if (mid > (n / mid))
        {
            r = mid - 1;
            ans = r;
        }
    }
    return int(ans);
}
