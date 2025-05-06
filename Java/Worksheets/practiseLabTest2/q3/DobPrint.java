package practiseLabTest2.q3;
import java.io.*;
import java.util.*;
import practiseLabTest2.q3.Student;

public class DobPrint {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> students = new ArrayList<>();
        File file = new File("studentDeets.txt");
        System.out.printf("Do you want \n 1. Make a new Entry 2.Read the entries\n");
        int choice = sc.nextInt();
        if(choice == 1)
        {
            System.out.println("enter details in the format : ROLLNO NAME AADHAR DOB");
            sc.nextLine();
            String input = sc.nextLine();
            input = input + '\n';
            byte[] data = input.getBytes();
            System.out.println("the binary data is this");
            for(int i = 0; i < data.length; i++)
            {
                int temp = data[i] & 0xff;
                String binary = Integer.toBinaryString(temp);
                String paddedBinary = String.format("%8s", binary).replace(' ', '0');
                System.out.print(paddedBinary + " ");
            }
            try(FileOutputStream writer = new FileOutputStream(file, true))
            {
                writer.write(data);
            }
            catch (IOException e) {
                e.printStackTrace();
                System.out.println("error 1");
            }
        }
        if(choice == 2)
        {
            try(FileInputStream reader = new FileInputStream(file))
            {
                String data = new String(reader.readAllBytes());
                String[] lines = data.split("\n");
                for(int i = 0; i < lines.length; i++)
                {
                    Student newStudent = new Student(lines[i]);
                    students.add(newStudent);
                }

            }
            catch (IOException e)
            {
                e.printStackTrace();
                System.out.println("error 2");
            }

            for(int i=0; i<students.size(); i++)
            {
                System.out.println(students.get(i));
            }
        }
        if(choice == 3)
        {
            try(FileInputStream reader = new FileInputStream(file))
            {
                while(reader.available() > 0)
                {
                    int data = reader.read() & 0xff;
                    String binary = Integer.toBinaryString(data);
                    String paddedBinary = String.format("%8s", binary).replace(' ', '0');
                    System.out.print(paddedBinary + " ");
                }
            }
            catch (IOException e)
            {
                e.printStackTrace();
                System.out.println("error 2");
            }
        }
    }
}
