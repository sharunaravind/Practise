package PS6;

public class q1 {
    public static void main(String[] args) {
        Cube cube1 = new Cube("red",12);
        Circle circle1 = new Circle("blue",5);
        Cube cube2 = new Cube("green",150,125,5);
        Circle[] array = new Circle[5];
        for(int i =0;i<5;i++)
        {
            array[i] = new Circle("orange",i+3);
        }
        cube2.dispAll();
        cube1.dispAll();
        cube2.dispVolume();
        circle1.dispAll();
        array[3].Calculate();
        array[3].dispArea();
        array[2].Calculate();
        array[2].dispPerimeter();
    }
}

class Shape{
    private static int count = 0;
    private String color;
    protected double area;
    Shape(String color,double area)
    {
        count++;
        this.color = color;
        this.area = area;
    }
    Shape(String color)
    {
        count++;
        this.color = color;
    }
    void dispArea()
    {
        System.out.printf("The area of this %s is %f\n\n\n",this.getClass().getSimpleName(),this.area);
    }
    void dispInfo()
    {
        System.out.printf("The Colour of this %s is %s \n the area of this shape is %f \n",this.getClass().getSimpleName(),this.color,this.area);
    }
}

class TwoDshapes extends Shape{
    protected double perimeter;
    TwoDshapes(String color, double area, double perimeter) {
        super(color, area);
        this.perimeter=perimeter;
    }

    TwoDshapes(String color){
        super(color);
    }
    void dispPerimeter()
    {
        System.out.printf("The perimeter of this %s is %f\n\n\n",this.getClass().getSimpleName(),this.perimeter);
    }
}

class ThreeDshapes extends Shape{
    protected double volume;
    ThreeDshapes(String color, double area,double volume) {
        super(color, area);
        this.volume = volume;
    }
    ThreeDshapes(String color)
    {
        super(color);
    }
    void dispVolume()
    {
        System.out.printf("The volume of this %s is %f\n\n\n",this.getClass().getSimpleName(),this.volume);
    }
}

class Circle extends TwoDshapes{
    private int radius;
    Circle(String color, double area, double perimeter,int radius) {
        super(color, area, perimeter);
        this.radius = radius;
    }
    Circle(String color,int radius)
    {
        super(color);
        this.radius = radius;
    }
    void getArea()
    {
        this.area = Math.PI*this.radius*this.radius;
    }
    void getPerimeter()
    {
        this.perimeter = Math.PI*this.radius*2;
    }
    void Calculate()
    {
        getArea();
        getPerimeter();
    }
    void dispAll()
    {
        Calculate();
        dispInfo();
        System.out.printf("The perimieter of this shape is %f\n\n\n",this.perimeter);
    }
}

class Cube extends ThreeDshapes{
    private int side;
    Cube(String color, double area, double volume,int side) {
        super(color, area,volume);
        this.side = side;
    }
    Cube(String color,int side)
    {
        super(color);
        this.side = side;
    }
    void getArea()
    {
        this.area = 6*this.side*this.side;
    }
    void volume()
    {
        this.volume = this.side*this.side*this.side;
    }
    void calculate()
    {
        getArea();
        volume();
    }
    void dispAll()
    {
        calculate();
        dispInfo();
        System.out.printf("The Volumen of this shape is %f\n\n\n",this.volume);
    }
}