package ex10;

import java.util.Scanner;

interface THEORY {
    double CGPAtheory(double[] score, int[] credits);
    default String print(double nn, String xx) {
        return String.format("%s has scored %.2f CGPA in theory courses", xx, nn);
    }
}

interface LAB {
    double CGPAlab(double[] score, int[] credits);
    default String print(double nn, String xx) {
        return String.format("%s has scored %.2f CGPA in Lab course", xx, nn);
    }
}

class Sem1 implements THEORY, LAB {
    String name, rollNo;
    double[] score;
    int[] credits;
    double[] labScore;
    int[] labCredits;

    public Sem1(String name, String rollNo, double[] score, int[] credits, double[] labScore, int[] labCredits) {
        this.name = name;
        this.rollNo = rollNo;
        this.score = score;
        this.credits = credits;
        this.labScore = labScore;
        this.labCredits = labCredits;
    }

    public double CGPAtheory(double[] score, int[] credits) {
        double totalScore = 0, totalCredits = 0;
        for (int i = 0; i < score.length; i++) {
            totalScore += score[i] * credits[i];
            totalCredits += credits[i];
        }
        return totalScore / totalCredits;
    }

    public double CGPAlab(double[] score, int[] credits) {
        double totalScore = 0, totalCredits = 0;
        for (int i = 0; i < score.length; i++) {
            totalScore += score[i] * credits[i];
            totalCredits += credits[i];
        }
        return totalScore / totalCredits;
    }

    public String printTheory(double nn) {
        return THEORY.super.print(nn, name);
    }

    public String printLab(double nn) {
        return LAB.super.print(nn, name);
    }

    public String print(double nn, String xx)
    {
        System.out.println("to stop ambiguity");
        return "hello";
    }
    public String toString() {
        return String.format("Name: %s\nRoll No: %s\nTheory Scores: %s\nTheory Credits: %s\nLab Scores: %s\nLab Credits: %s",
                name, rollNo, java.util.Arrays.toString(score), java.util.Arrays.toString(credits),
                java.util.Arrays.toString(labScore), java.util.Arrays.toString(labCredits));
    }
}

public class LabExercise10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter student name: ");
        String name = sc.nextLine();
        System.out.print("Enter roll number: ");
        String rollNo = sc.nextLine();

        double[] scores = new double[3];
        int[] credits = new int[3];
        double[] labScores = new double[2];
        int[] labCredits = new int[2];

        System.out.println("Enter theory course scores and credits:");
        for (int i = 0; i < 3; i++) {
            System.out.printf("Score for theory subject %d: ", i + 1);
            scores[i] = sc.nextDouble();
            System.out.printf("Credits for theory subject %d: ", i + 1);
            credits[i] = sc.nextInt();
        }

        System.out.println("Enter lab course scores and credits:");
        for (int i = 0; i < 2; i++) {
            System.out.printf("Score for lab subject %d: ", i + 1);
            labScores[i] = sc.nextDouble();
            System.out.printf("Credits for lab subject %d: ", i + 1);
            labCredits[i] = sc.nextInt();
        }

        Sem1 student = new Sem1(name, rollNo, scores, credits, labScores, labCredits);
        double theoryCGPA = student.CGPAtheory(scores, credits);
        double labCGPA = student.CGPAlab(labScores, labCredits);

        System.out.println("Choose an option:");
        System.out.println("1. Print Theory CGPA");
        System.out.println("2. Print Lab CGPA");
        System.out.println("3. Print All Student Details");
        int choice = sc.nextInt();

        if (choice == 1) {
            System.out.println(student.printTheory(theoryCGPA));
        } else if (choice == 2) {
            System.out.println(student.printLab(labCGPA));
        } else if (choice == 3) {
            System.out.println(student);
        } else {
            System.out.println("Invalid choice.");
        }

        sc.close();
    }
}

