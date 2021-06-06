// The idea is to use Doubly Linked List(DLL).We can delete middle element in O(1) time by maintaining mid pointer.We can move mid pointer in both directions using previous and next pointers.int findMiddle(myStack *ms)
{
    if (ms->count == 0)
    {
        cout << "Stack is empty now\n";
        return -1;
    }

    return ms->mid->data;
}