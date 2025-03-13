package dunno1;

public class composite {
    public static void main(String[] args) {
        Ddate dob=new Ddate(2,1,2004);
        Ddate dob1=new Ddate(3,4,2002);
//        System.out.println(dob+dob1);
        pupil objA = new pupil("Kumar",dob);
        System.out.println(objA);
    }
}
