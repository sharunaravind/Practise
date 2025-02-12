import java.util.Scanner;

public class q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter three numbers: ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        System.out.println(averageOf3(a, b, c)); // Prints the average
    }

    static double averageOf3(int a, int b, int c) {
        return (a + b + c) / 3.0;
    }
}
