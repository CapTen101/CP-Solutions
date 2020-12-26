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

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        int not_int = 0;  // students interested
        int interest = 0; // students not-interested

        while (interest + not_int <= n)
        {
            if (students[0] == sandwiches[0]) // if he likes it
            {
                students.erase(students.begin() + 0);
                sandwiches.erase(sandwiches.begin() + 0);
                interest++;
                if (not_int > 0)
                    not_int--;
            }
            else
            {
                not_int++;
                int stu = students[0];
                students.erase(students.begin() + 0);
                students.push_back(stu);
            }
        }

        return not_int;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    Solution obj;
    vector<int> v1 = {1, 1, 1, 0, 0, 1};
    vector<int> v2 = {1, 0, 0, 0, 1, 1};

    cout << obj.countStudents(v1, v2) << endl;
}