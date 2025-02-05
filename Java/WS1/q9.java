import java.util.Arrays;
public class q9 {
    public static void main(String[] args) {
        String[] Signs = {"Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius","Capricorn"};
        int[] ends = {0,19,17,19,19,20,20,22,22,22,22,21,21};
        if(Integer.parseInt(args[1])<ends[Integer.parseInt(args[0])])
            System.out.println(Signs[Integer.parseInt(args[0])-1]);
        else System.out.println(Signs[Integer.parseInt(args[0])]);

    }
}
