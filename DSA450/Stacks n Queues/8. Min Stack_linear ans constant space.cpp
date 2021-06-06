#include <bits/stdc++.h>
#include <stack>
using namespace std;
void push(stack<int> &s, int a);
bool isFull(stack<int> &s, int n);
bool isEmpty(stack<int> &s);
int pop(stack<int> &s);
int getMin(stack<int> &s);
stack<int> s;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        while (!isEmpty(s))
        {
            pop(s);
        }
        while (!isFull(s, n))
        {
            cin >> a;
            push(s, a);
        }
        cout << getMin(s) << endl;
    }
}

// GFG constant solution:
int min_ele;
void push(stack<int> &s, int a)
{

    if (s.size() == 0)
    {
        min_ele = a;
        s.push(a);
    }
    else
    {
        if (a < min_ele)
        {
            // now here, update min_ele AND don't push 'a' as it is
            // push -> (2*a - min_ele(current))
            // for ex: a is 2 and min_ele till now was 3. so,
            // push -> 2*2 - 3 = 1 -> into the stack
            // and whenver popping the element, check if it is smaller than min_ele or not
            // if it is indeed smaller, that is an anomaly since no element can be smaller than the min_ele
            // thus obtain the previous of min_ele by min_ele(prev) = 2*min_ele(current) - y
            // where y is the anomaly number which is less than current min_ele
            // and min_ele(prev) means element just bigger than the current min_ele, means the next one in the ascending order
            // ALSO, return the min_ele(current) in the popping function
            s.push(2 * a - min_ele);
            min_ele = a;
        }
        else
        {
            s.push(a);
        }
    }
}

bool isFull(stack<int> &s, int n)
{
    if (s.size() >= n)
        return true;
    else
        return false;
}

bool isEmpty(stack<int> &s)
{
    if (s.size())
        return false;
    else
        return true;
}

int pop(stack<int> &s)
{
    if (s.size() == 0)
        return -1;

    int res;
    if (s.top() < min_ele)
    { // anomaly element -> read theory above
        res = min_ele;
        min_ele = 2 * min_ele - s.top();
        s.pop();
    }
    else
    {
        res = s.top();
        s.pop();
    }

    return res;
}

int getMin(stack<int> &s)
{
    if (s.size() == 0)
        return -1;
    return min_ele;
}

// LEETCODE linear space solution
class MinStack
{
public:
    vector<int> stack_arr;
    vector<int> min_ele;
    MinStack()
    {
    }

    void push(int val)
    {
        stack_arr.push_back(val);
        if (stack_arr.size() == 1)
            min_ele.push_back(val);
        else
        {
            if (val <= min_ele[min_ele.size() - 1])
            {
                min_ele.push_back(val);
            }
        }
    }

    void pop()
    {
        if (stack_arr[stack_arr.size() - 1] == min_ele[min_ele.size() - 1])
            min_ele.pop_back();
        stack_arr.pop_back();
    }

    int top()
    {
        return stack_arr[stack_arr.size() - 1];
    }

    int getMin()
    {
        return min_ele[min_ele.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */