void showVector(vector<long long> g)
{
    vector<long long>::iterator it;
    cout << endl;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it;
}