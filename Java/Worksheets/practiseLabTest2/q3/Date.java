package practiseLabTest2.q3;

public class Date {
    private int year;
    private int month;
    private int day;
    public Date(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }
    public Date(String date) {
        this.day=Integer.parseInt(date.substring(0,2));
        this.month=Integer.parseInt(date.substring(2,4));
        this.year=Integer.parseInt(date.substring(4,8));
    }

    public int getYear() {
        return year;
    }
    public int getMonth() {
        return month;
    }
    public int getDay() {
        return day;
    }
    public void setYear(int year) {
        this.year = year;
    }
    public void setMonth(int month) {
        this.month = month;
    }
    public void setDay(int day) {
        this.day = day;
    }
    public String toString() {
        return year+"/"+month+"/"+day;
    }
}
