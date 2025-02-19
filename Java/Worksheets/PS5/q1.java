package PS5;
import java.util.Scanner;
public class q1
{
    public static void main(String[] args) {
        Circle c2 = new Circle(10);
        c2.display();
        Circle[] array = new Circle[5];
        for(int i = 1;i<=5;i++)
        {
            array[i-1] = new Circle(i);
            array[i-1].display();
        }

    }
}
class Circle
{
    static int count;
    private int radius;
    private double area;
    Circle()
    {
        count++;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the area");
        this.radius = sc.nextInt();
    }
    Circle(int r)
    {
        count++;
        this.radius = r;
    }
    private void area()
    {
        this.area = Math.PI*this.radius*this.radius;
    }
    void display()
    {
        area();
        System.out.println("The area of the circle "+count+" of radius " + this.radius+" is : "+this.area);
    }
}