package stack;

public class Stack {

    private int n;
    private int[] stack;
    private int t;

    public Stack(int size)
    {
        this.n = size;
        stack = new int[n];
        t = -1;
    }

    public boolean isEmpty()
    {
        return (this.t == -1);
    }

    public int peek() {
        if(isEmpty())
        {
            throw new RuntimeException("Stack Empty");
        }
        return stack[t];
    }

    public int push(int element){
        if(t==(n-1))
        {
            throw new RuntimeException("Stack overflow");
        }
        stack[++t] = element;
        return t;
    }

    public int pop()
    {
        if(isEmpty())
        {
            throw new RuntimeException("Stack underflow");
        }
        return stack[t--];
    }
}
