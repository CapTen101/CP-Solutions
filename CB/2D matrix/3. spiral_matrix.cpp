#include <bits/stdc++.h>
using namespace std;

#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define start \
    int t;    \
    cin >> t; \
    while (t--)
const ll mod = 1000000007;

void spiral_print(int a[][1000], int m, int n)
{
    // Maintain 4 different pointers for 4 different movements
    int startRow = 0;
    int startCol = 0;
    int endRow = m - 1;
    int endCol = n - 1;

    while (startRow <= endRow and startCol <= endCol)
    {
        // Start Row
        for (int i = startCol; i <= endCol; i++)
            cout << a[startRow][i] << " ";
        startRow++;

        // End Coloumn
        for (int i = startRow; i <= endRow; i++)
            cout << a[i][endCol] << " ";
        endCol--;

        if (endRow > startRow)
        {
            // End Row
            for (int i = endCol; i >= startCol; i--)
                cout << a[endRow][i] << " ";
            endRow--;
        }

        if (endCol > startCol)
        {
            // Start Column
            for (int i = endRow; i >= startRow; i--)
                cout << a[i][startCol] << " ";
            startCol++;
        }
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> m >> n;
    int a[1000][1000] = {0};
    int val = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = val;
            val++;
        }
    }

    spiral_print(a, m, n);
}