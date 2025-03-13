package dunno1;

public class Ddate{
   int day;
   int month;
   int year;
    Ddate( int month, int day, int year ) {
        if ( month > 0 && month <=12 ) {
            this.month=month; this.day = day; this.year = year; }   }
    public String toString()
    {
        return String.format(" %d/%d/%d ", day,month,year);
    }
}