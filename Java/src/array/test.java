package array;
import stack.Stack;
public class test {
    public static void main(String[] args) {
        Stack s1 = new Stack(2);
        s1.push(5);
        s1.push(10);
        s1.push(20);
        System.out.println(s1.peek());
        System.out.println(s1.pop());
        System.out.println(s1.peek());
        System.out.println(s1.pop());
        System.out.println(s1.pop());
        System.out.println(s1.pop());
        Stack s2 = new Stack(10);
        s2.push(10);
        s2.push(9384);
        System.out.println(s1.isEmpty());

    }
}
