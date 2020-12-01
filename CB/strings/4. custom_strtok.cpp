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

char *mystrtok(char *str, char DELIM)
{
    // this is the static pointer pointing to every token
    static char *input = NULL;

    // if input is not empty, assign the traversal variable to the start of the input
    if (str != NULL)
        input = str;

    // Base Case
    // when the input is empty, return input as NULL pointer to exit this function
    if (input == NULL)
        return NULL;

    // this will be the output array
    char *output = new char[strlen(input) + 1];

    int i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != DELIM)
            output[i] = input[i];

        else
        {
            // when token end is reached, transfer the input to the current position
            // and mark this as '\0'.
            output[i] = '\0';
            input = input + i + 1;
            // return the token
            return output;
        }
    }

    // corner cases
    output[i] = '\0';
    input = NULL;
    return output;
}

int main()
{
    ios_base::sync_with_stdio(false);

    char input[] = "Today is a sunny day";
    char *ptr = mystrtok(input, ' ');

    while (ptr != NULL)
    {
        cout << ptr << endl;
        ptr = mystrtok(NULL, ' ');
    }
}