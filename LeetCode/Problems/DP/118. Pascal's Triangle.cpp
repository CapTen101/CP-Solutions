#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pas(numRows);
    pas[0].push_back(1);

    if (numRows == 1)
        return pas;

    pas[1].push_back(1);
    pas[1].push_back(1);

    for (int i = 2; i < numRows; i++)
    {
        vector<int> row(i + 1);
        row[0] = 1;
        row[i] = 1;
        for (int j = 1; j < i; j++)
        {
            row[j] = pas[i - 1][j] + pas[i - 1][j - 1];
        }
        pas[i] = row;
    }

    return pas;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}