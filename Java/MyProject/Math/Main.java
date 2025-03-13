package Math;
import Math.Product.*;

public class Main {
    public static void main(String[] args) {
        product p1 = new product();
        System.out.println(p1.prod(Integer.parseInt(args[0]),Integer.parseInt(args[1])));
    }
}
