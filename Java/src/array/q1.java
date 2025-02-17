package array;
import java.util.*;
import stack.Stack;
class q1 {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] array = new int[n];
        for(int i=0;i<n;i++)
        {
            array[i]=sc.nextInt();
        }
        Arrays.sort(array);
        int p = sc.nextInt();
        System.out.println(array[p]);
    }


}

