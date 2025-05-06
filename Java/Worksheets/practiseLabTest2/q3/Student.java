package practiseLabTest2.q3;

public class Student {
    private String name;
    private String rollNo;
    private String aadhar;
    private Date dateOfBirth;
    public Student(String name, String rollNo, String aadhar, Date dateOfBirth) {
        this.name = name;
        this.rollNo = rollNo;
        this.aadhar = aadhar;
        this.dateOfBirth = dateOfBirth;
    }
    public Student(String full) {
        String[] split = full.split("\\s+");
        this.rollNo = split[0];
        this.name = split[1];
        this.aadhar = split[2];
        this.dateOfBirth = new Date(split[3]);
    }
    public String getName() {
        return name;
    }
    public String getRollNo() {
        return rollNo;
    }
    public String getAadhar() {
        return aadhar;
    }
    public Date getDateOfBirth() {
        return dateOfBirth;
    }

    @Override
    public String toString() {
        return String.format("Name: %s\nRoll Number: %s\nDate of Birth: %s\n", name, rollNo, dateOfBirth);
    }
}

