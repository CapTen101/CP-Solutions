#include <bits/stdc++.h>
using namespace std;

void DuplicateArray(int input1, int input2[])
{
    int n = input1;
    vector<int> arr(input2, input2 + n);

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    vector<int> ans;
    for (auto it = s.begin(); it != s.end(); it++)
        ans.push_back(*it);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 300, 4, 5, 5, 5, 6, 6};
    DuplicateArray(5, arr);
    cout << endl;
    return 0;
}