#include <bits/stdc++.h>
using namespace std;

vector<int> generate(int numRows)
{
    vector<vector<int>> pas(numRows);
    pas[0].push_back(1);

    if (numRows == 1)
        return pas[0];

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

    return pas[numRows - 1];
}

vector<int> getRow(int idx)
{
    if (idx == 0)
        return {1};
    else if (idx == 1)
        return {1, 1};
    else if (idx == 2)
        return {1, 2, 1};

    return generate(idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}