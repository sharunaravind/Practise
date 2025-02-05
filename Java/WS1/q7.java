import java.util.Arrays;
import java.util.Scanner;
public class q7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter first number");
        int p = sc.nextInt();
        System.out.println("enter the next number");
        int q = sc.nextInt();
        int[] arr = new int[100];
        p=(p%q)*10;
        for(int i=0;i<100;i++)
        {
            arr[i]=p/q;

            p=(p%q)*10;
        }
        int[] numbers = new int[10];
        int check=0;
        int[] position = new int[10];
        int pointer1=0,pointer2;
        while(check==0)
        {
            if(numbers[arr[pointer1]]==0)
            {
                numbers[arr[pointer1]] = 1;
                position[arr[pointer1]] = pointer1;
                pointer1++;
            }
            else
            {
                pointer2=position[arr[pointer1]];
                boolean answercheck = checker(pointer2,pointer1,arr);
                if(answercheck)
                {
                    check=1;
                    for(int i=pointer2;i<pointer1;i++)
                    {
                        System.out.print(arr[i]);
                    }
                    return;
                }
                else
                {
                    Arrays.fill(numbers,0);
                    Arrays.fill(position,0);
//                    numbers[arr[pointer2]]=0;
//                    position[arr[pointer2]]=0;
                    pointer2=0;
                }
            }

        }
    }
    public static boolean checker(int pos1,int pos2,int[] arr)
    {
        int temp = pos2;
        while(pos1<temp)
        {
             if(arr[pos1]!=arr[pos2])
             {
                 return false;
             }
             pos1++;
             pos2++;
        }
        return true;
    }
}
