#include <iostream>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define get cin >>
#define print cout <<
#define inarr(s, n, arr)        \
    for (int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)       \
    for (int i = s; i < n; i++) \
        cout << arr[i];
#define start \
    int t;    \
    cin >> t; \
    while (t--)

long long binaryexpo(long long a, long b)
{
    if (b == 0)
        return 1;

    long long res = binaryexpo(a, b / 2);

    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float prev_total = 792.042;
    float prev_credits = 101.0;

    float fluid_grade, bm_grade;

    cout << "fluid:" << endl;
    cin >> fluid_grade;
    cout << "bm:" << endl;
    cin >> bm_grade;

    float ibm = 9 * 3;
    float case_study = 10 * 3;
    float mtlab = 10;
    float pdclab = 9;
    float modelling = 10 * 4;
    float bm = bm_grade * 3;
    float fluid = fluid_grade * 4;
    float utility_safety = 10 * 3;

    float current_total = ibm + case_study + mtlab + pdclab + modelling + utility_safety + bm + fluid;
    float current_credits = 22.0;

    if (bm_grade == 0)
    {
        current_credits -= 3;
        cout << "BM grade: S\n";
    }

    if (fluid_grade == 0)
    {
        current_credits -= 4;
        cout << "fluid grade: S\n";
    }

    cout << "current_credits = " << current_credits << endl;
    cout << "current_total = " << current_total << endl;

    float sg = current_total / current_credits;
    cout << "sg = " << sg << endl;

    float cg = (current_total + prev_total) / (current_credits + prev_credits);
    cout << "cg = " << cg << endl;
}