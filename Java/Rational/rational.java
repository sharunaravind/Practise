public class rational {
    private int numerator;
    private int denominator;
    public rational(int x,int y)
    {
        this.numerator=x;
        this.denominator=y;
    }
    public rational()
    {
        this.numerator=1;
        this.denominator=1;
    }
    public rational add(rational x)
    {
        int newNum=(this.numerator*x.denominator)+(this.denominator*x.numerator);
        int newDen=this.denominator*x.denominator;
//        return new rational(newNum,newDen);
        this.numerator = newNum;
        this.denominator=newDen;
        return this;
    }
    public rational divide(rational x)
    {
        int newNum=(this.numerator*x.denominator);
        int newDen=this.denominator*x.numerator;
        this.numerator = newNum;
        this.denominator=newDen;
        return this;
    }
    public String toString()
    {
        return String.format("%d/%d",this.numerator,this.denominator);
    }
    public String toStringDecimal(int x)
    {
        double decimal = this.numerator/(double) this.denominator;
        String format = "%."+x+"f";
        return String.format(format,decimal);
    }
}
