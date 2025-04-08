package TryCatch;
import java.util.*;
public class SeriesSum {
    public static <exception> void main(String[] args) {
        double x=0,y=0;
        String temp1,temp2;
        double sum=0;
        Scanner sc = new Scanner(System.in);
        int checkx=0,checky=0;
        System.out.println("Enter '/' when you are done");
        outer:
        while(x!='/' && y!='/')
        {
            checkx=0;
            checky=0;
            while(checkx==0)
            {
                System.out.print("x: ");
                temp1=sc.nextLine();
                if(temp1.charAt(0)=='/') break outer;
                try{
                    x=Double.parseDouble(temp1);
                    checkx=1;
                }
                catch (Exception e)
                {
                    System.out.println("WHoops looks like u didnt enter a number please try again");
                }
            }
            while(checky==0)
            {
                System.out.print("y: ");
                temp2=sc.nextLine();
                if(temp2.charAt(0)=='/') break outer;
                try{
                    y=Double.parseDouble(temp2);
                    checky=1;
                }
                catch (Exception e)
                {
                    System.out.println("Whoops looks like u didnt enter a number. No worries Please try again");
                }
            }
            try{
                if(y==0) throw new ArithmeticException();
                sum+=(x)/(y);
            }
            catch (Exception e)
            {
                System.out.println("Whoops looks like you entered a zero there. No worries keep continuining");
            }
        }
        System.out.println(sum);
    }
}
