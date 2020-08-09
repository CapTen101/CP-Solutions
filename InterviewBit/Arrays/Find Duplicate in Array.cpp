int Solution::repeatedNumber(const vector<int> &A)
{
    // set<int> s;

    // for(int i=0; i<A.size(); i++)
    // {
    //     if(s.find(A[i])!=s.end()) // if found
    //     {
    //         return A[i];
    //     }
    //     else // if not found
    //     {
    //         s.insert(A[i]);
    //     }
    // }

    // above is not optimal;

    long n = A.size();
    long total = ((n - 1) * n) / 2;
    long sumarr = 0;

    for (long i = 0; i < n; i++)
    {
        sumarr += A[i];
    }

    if (sumarr - total)
        return sumarr - total;
    else
        return -1;
}
