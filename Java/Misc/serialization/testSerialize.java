package serialization;

// Writing and reading the Object to and from a file.
// object to be written to a file need to be serialized.
import java.io.*;
public class testSerialize {
    public static void main(String[] args) {
        // Create an object to serialize
        MyObject obj = new MyObject("Hello, world!", 42);
        int n=3;
        MyObject[] array = new MyObject[n];

        for(int i=0;i<n;i++)
        {
            array[i]=new MyObject("Hello, world!", i);
        }

        // Serialize the object
        try {
            FileOutputStream fileOut = new FileOutputStream("object.ser");
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            for(int i=0;i<n;i++)
            {
//                array[i]=new MyObject("Hello, world!", i);
                out.writeObject(array[i]);
            }
            out.close();
            fileOut.close();
            System.out.println("Object has been serialized!");
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Object to be deserialized to read back");
        try (
                FileInputStream fileIn = new FileInputStream("object.ser");
                ObjectInputStream in = new ObjectInputStream(fileIn)
        )
        {
            MyObject[] Newarray = new MyObject[n];
            for(int i=0;i<n;i++)
            {
                Newarray[i] = (MyObject) in.readObject();  // cast back
                System.out.println(" Object read from file:");
                System.out.println(Newarray[i]);
            }
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Error reading object: " + e.getMessage());
        }
    }


}
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.ObjectInputStream;

class MyObject implements Serializable {
    private String message;
    private int value;

    public MyObject(String message, int value) {
        this.message = message;
        this.value = value;
    }

    public String getMessage() {
        return message;
    }

    public int getValue() {
        return value;
    }
    public String toString() {
        return "Message: " + message + ", value: " + value;
    }

}


