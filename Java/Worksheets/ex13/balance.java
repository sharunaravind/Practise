package ex13;
import java.util.*;
public class balance {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Stack<Character> stack = new Stack<>();

        String in  = sc.nextLine();
        in = in.replaceAll("\\s","");
        Character[] open  = {'{','(','[','\"','\'','<'};
        Character[] close = {'}',')',']','\"','\'','>'};
        for(int i=0;i<in.length();i++)
        {
            Character cur = in.charAt(i);
            if(present(cur,open)>=0)
            {
                stack.push(cur);
            }
            else if(present(cur,close)>=0)
            {
                if(stack.isEmpty())
                {
                    System.out.println("false");
                    return;
                }
                Character topEle = stack.pop();
                if(present(topEle,open)!=present(cur,close))
                {
                    System.out.println("false");
                    return;
                }
            }
        }
        if(!stack.isEmpty())
        {
            System.out.println("false");
            return;
        }
        System.out.println("True");
    }

    static int present(Character c,Character[] array)
    {
        for(int i=0;i<array.length;i++)
        {
            if(array[i]==c)
            {
                return i;
            }
        }
        return -1;
    }
}
