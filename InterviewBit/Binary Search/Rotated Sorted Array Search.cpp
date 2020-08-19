int pivotind(int arr[], int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
    {
        if (arr[0] > arr[1])
            return 1;
        else
            return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[0] < arr[n - 1])
            return 0;
        if (i > 0 && arr[i] < arr[(i + 1) % n] && arr[i] < arr[i - 1])
            return i;
    }

    return -1;
}

int bin_search_ITERATIVE(int A[], int left, int right, int k)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (A[mid] == k)
        {
            return mid;
        }

        else if (k > A[mid])
        {
            left = mid + 1;
        }

        else if (k < A[mid])
        {
            right = mid - 1;
        }
    }

    return -1;
}

int Solution::search(const vector<int> &A, int k)
{
    int arr[A.size()];
    int n = A.size();

    for (int i = 0; i < n; i++)
        arr[i] = A[i]; // converting vector to array

    int minindex = pivotind(arr, n);
    int index = -1;

    if (k < arr[minindex])
    {
        // index = bin_search_ITERATIVE(arr, 0, minindex - 1, k);
        return -1;
    }

    if (k == arr[minindex])
        return minindex;

    int firsthalf = bin_search_ITERATIVE(arr, 0, minindex - 1, k);
    int secondhalf = bin_search_ITERATIVE(arr, minindex + 1, n - 1, k);

    if (firsthalf != -1)
        return firsthalf;
    else if (secondhalf != -1)
        return secondhalf;
    else
        return -1;

    // return index;
}
