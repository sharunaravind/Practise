import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        int[] a = {1, -2, 4, -4, 9, -6, 16, -8, 25, -10};
        System.out.println(computeAverage(a)); // Should print 2.5
    }

    static double computeAverage(int[] arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        return (double) sum / arr.length;
    }
}
