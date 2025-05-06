package ex14;

import java.io.*;
import java.util.*;

public class FileStuff {
    public static void main(String[] args) {
        File file = new File("testFile.txt");
        File fileCopy = new File("testFileCopy.txt");
        Scanner sc = new Scanner(System.in);
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(file)))
        {
            writer.write("This is a test file.");
            writer.newLine();
            writer.write("This is another test file.");
            writer.newLine();
            writer.write("THis is the lastest line lessgooooo whoohooo.");
        }
        catch (IOException e)
        {
            e.printStackTrace();
            System.out.println("something wrong with opening file for writing error 1");
        }

        try(BufferedReader reader = new BufferedReader(new FileReader(file)))
        {
            String templine;
            System.out.println("Enter the word u'd like to search for please");
            String word = sc.next();
            String[] tempSplit;
            int wordFrequency = 0;
            while((templine= reader.readLine())!=null)
            {
                tempSplit = templine.split("\\s+");
                for(int i=0; i<tempSplit.length; i++)
                {
                    if(tempSplit[i].equals(word)) wordFrequency++;
                }
                System.out.println(templine);
            }
            System.out.println("Your word's Frequency : "+wordFrequency);
        }
        catch (IOException e)
        {
            e.printStackTrace();
            System.out.println("something wrong with opening file for reading error 2");
        }
        System.out.printf("\n\nNow lets print the deets of the file\n\n");
        try(BufferedReader readerChar = new BufferedReader(new FileReader(file)))
        {
            int tempChar;
            int lines=1,words=2,sentences=0,count=0;
            while((tempChar = readerChar.read()) != -1)
            {
                count++;
                if(tempChar==32) words++;
                else if(tempChar==46) sentences++;
                else if(tempChar==10) lines++;
            }
            System.out.printf("The number of lines: %d\n", lines);
            System.out.printf("The number of words: %d\n", words);
            System.out.printf("The number of sentences: %d\n", sentences);
            System.out.printf("The number of characters: %d\n", count);
        }
        catch (IOException e)
        {
            e.printStackTrace();
            System.out.println("something wrong with opening file for reading error 3");
        }

        try(BufferedInputStream bis = new BufferedInputStream(new FileInputStream(file)))
        {
            try(BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(fileCopy)))
            {
                bos.write(bis.readAllBytes());
            }
            catch (IOException e)
            {
                e.printStackTrace();
                System.out.println("something wrong with writing in the copy thingy");
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
            System.out.println("something wrong with copy");
        }

    }
}
