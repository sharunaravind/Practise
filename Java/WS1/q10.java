public class q10 {
    public static void main(String[] args) {
        int theta = 50 ;
        int intialVelocity = 20;
        double x=0;
        double y=0;
        while(y>=0)
        {
            double temp1 = (x*Math.tan(theta));
            double temp2 = ((9.8*x*x));
            double temp3 = (2*intialVelocity*intialVelocity*Math.cos(2*theta));
            y = temp1 - (temp2/temp3);
            System.out.println(y);
            x+=1;
        }

    }
}
