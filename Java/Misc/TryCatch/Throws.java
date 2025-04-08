package TryCatch;

import java.util.Random;

public class Throws {
    public static void main(String[] args) throws Exception {

        whatever();
    }
    static void whatever() throws Exception
    {
        Random rand = new Random();
        int x=rand.nextInt(2);
        if(x==1)
            throw new Exception();
        else System.out.println("You lucky fuck");
    }
}
