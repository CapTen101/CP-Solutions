void rotate(vector<vector<int>> &A)
{

    int row = A.size();
    int col = A[0].size();

    for (int i = 0; i < row / 2; i++)
    {
        swap(A[i], A[row - i - 1]);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }
}