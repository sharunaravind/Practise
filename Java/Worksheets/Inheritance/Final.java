package Inheritance;

public class Final {
    public static void main(String[] args) {
        MX24 student1 = new MX24(2001);
        MX24 student2 = new MX24(2003);
        MX24 student3 = new MX24(2000);
        student2.display();
        student3.display();
        student3.display();

    }
}


class MX24{
    private static final int year = 2024;
    private final int birthYear;

    MX24(int dob) {
        this.birthYear = dob;
    }
    void display()
    {
        System.out.printf("The birth year of this student is %d and their admission year is %d \n",this.birthYear,year);
    }
}
