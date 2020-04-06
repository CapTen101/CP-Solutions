long long binaryexpo(long long a, long  b) {
    if (b == 0)
        return 1;
    long long res = binaryexpo(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}