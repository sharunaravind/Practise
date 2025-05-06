package ex13;
import java.util.*;
public class browsernavigator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<String> back = new Stack<>();
        Stack<String> forward = new Stack<>();
        String current = "";

        while(sc.hasNext()) {
            String in = sc.next();
            if(in.equals("visit")) {
                String url = sc.next();
                if(!current.equals("")) {
                    back.push(current);
                }
                forward.clear();
                current = url;
                System.out.println("navigating to a new webpage");
            }
            else if(in.equals("backward")) {
                if(back.isEmpty()) {
                    System.out.println("no pages to go back");
                }
                else {
                    forward.push(current);
                    current = back.pop();
                    System.out.println("going back one page");
                }
            }
            else if(in.equals("forward")) {
                if(forward.isEmpty()) {
                    System.out.println("no pages to go forward");
                }
                else {
                    back.push(current);
                    current = forward.pop();
                    System.out.println("going forward one page");
                }
            }
            else if(in.equals("current")) {
                System.out.println(current);
            }
            else if(in.equals("exit")) {
                break;
            }
        }
    }
}
