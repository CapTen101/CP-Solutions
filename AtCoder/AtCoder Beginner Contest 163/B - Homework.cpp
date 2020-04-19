#include <iostream>
using namespace std;

int main()
{
    long N;
    int M;
    cin >> N >> M;

    int A[M];
    long long assigndays = 0;

    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
        assigndays += A[i];
    }

    if (assigndays <= N)
        cout << N - assigndays;

    else
        cout << -1;
}
