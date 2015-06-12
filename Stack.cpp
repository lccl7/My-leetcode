class Stack
{
    public:
        queue<int> q1, q2;
    void push(int x)
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    void pop()
    {
        q1.pop();
    }

    int top()
    {
        q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
}
