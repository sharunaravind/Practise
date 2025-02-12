import java.util.Scanner;

public class q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a 9-digit number: ");
        int num = sc.nextInt();

        System.out.println("10-digit ISBN: " + checkSum(num));
    }

    static String checkSum(int num) {
        int[] digits = new int[9];
        for (int i = 8; i >= 0; i--) {
            digits[i] = num % 10;
            num /= 10;
        }

        int sum = 0;
        for (int i = 0; i < 9; i++) {
            sum += (i + 2) * digits[i];
        }

        int checksum = (11 - (sum % 11)) % 11;
        if (checksum == 10) {
            return num + "X";
        } else {
            return num + String.valueOf(checksum);
        }

    }
}
