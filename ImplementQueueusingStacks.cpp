class Queue
{
public:
    void push(int x)
    {
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(x);
    }
    void pop()
    {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.pop();
    }
    int peek()
    {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        return stack2.top();
    }
    bool empty()
    {
        return stack1.empty() && stack2.empty();
    }
private:
    stack<int> stack1, stack2;
}
