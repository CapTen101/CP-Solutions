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

// First Solution: With STL
vector<vector<int>> rotate(vector<vector<int>> image)
{
    // STEPS:
    // - reverse each row
    // - take the transpose of the matrix

    int rows = image.size();
    int col = image[0].size();

    // reversing the rows:
    for (int i = 0; i < rows; i++)
    {
        int start_col = 0;
        int end_col = col - 1;

        while (start_col < end_col)
        {
            swap(image[i][start_col], image[i][end_col]);
            start_col++;
            end_col--;
        }
    }

    // Now, take Transpose
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < j)
                swap(image[i][j], image[j][i]);
        }
    }

    return image;
}

// Second Solution: Without STL
vector<vector<int>> rotate_stl(vector<vector<int>> v)
{
    int rows = v.size();
    int col = v[0].size();

    // Same thing using the STL Reverse(start_container, end_container) method

    // Reversing the rows through reverse() function
    for (int i = 0; i < rows; i++)
        reverse(v[i].begin(), v[i].end()); // a[i] is the starting pointer of the vector

    // Now, take Transpose
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < j)
                swap(v[i][j], v[j][i]);
        }
    }

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
        v[i].resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    // auto res = rotate(v);
    auto res = rotate_stl(v);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}