#include <bits/stdc++.h>
using namespace std;

int numeric(vector<string> v)
{
    int n = v.size();
    vector<vector<int>> answer;

    for (int i = 0; i < n; i++)
    {
        // getting all words from the sentence
        stringstream ss(v[i]);
        string temp;
        unordered_map<string, int> um;
        vector<string> words;
        while (getline(ss, temp, ' '))
        {
            um[temp]++;
            words.push_back(temp);
        }

        for (int j = 0; j < words.size(); j++)
        {

            // float num_val =
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char a[100];
    cin >> a;

    cout << a << endl;

    return 0;
}