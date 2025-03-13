package Math.Product;
import Math.add;

public class product {
    int operand1;
    int operant2;
    public product()
    {
        this.operand1=0;
        this.operant2=0;
    }
    public product(int a,int b)
    {
        this.operand1=a;
        this.operant2=b;
    }
    public int prod(int x,int y)
    {
        int sum=0;
        for(int i=0;i<x;i++)
        {
            sum=add.getSum(sum,y);
        }
        return sum;
    }
}
