package Inheritance;

public class example {
    public static void main(String[] args) {
        Circle c1 = new Circle(5,"blue",0);
        c1.showArea();
        c1.display();

    }
}
class Shape{
    int sides;
    String color;

    public Shape(int sides,String color)
    {
        this.sides=sides;
        this.color=color;
    }

    public void display()
    {
        System.out.println("the color of the shape is "+this.color + " and it has "+this.sides+" sides");
    }
}

class Circle extends Shape{

    int radius;
    public Circle(int radius,String color,int sides)
    {
        super(sides,color);
        this.radius=radius;
    }
    public void showArea()
    {
        super.display();
        System.out.println(this.radius*this.radius*Math.PI);
    }
}
