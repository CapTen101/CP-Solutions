#include <bits/stdc++.h>
using namespace std;

int findJudge(int N, vector<vector<int>> &trust)
{
    /*
        Slow approach
        
        set<int> people;
        int n = trust.size();
        if(n==0 and N==1)
            return 1;
        if(n==0 and N>1)
            return -1;
        unordered_map<int, int> um; 
        
        
        for(int i=0; i<n; i++)
        {
            people.insert(trust[i][0]);
            people.insert(trust[i][1]);
            um[trust[i][1]]++;
        }
        
        for(int i=0; i<n; i++)
        {
            int guy = trust[i][0];
            if(people.find(guy) != people.end())
            {
                people.erase(guy);
            }
        }
        
        if(people.size() == 1)
        {
            for(int i : people){
                if(um[i] == N-1)
                    return i;
            }
        }
        
        return -1;
        */

    // fast approach
    vector<int> score(N + 1, 0); // trust score value
    int n = trust.size();

    if (n == 0 and N == 1)
        return 1;
    if (n == 0 and N > 1)
        return -1;

    for (int i = 0; i < n; i++)
    {
        score[trust[i][0]]--;
        score[trust[i][1]]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (score[i] == N - 1)
            return i;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}