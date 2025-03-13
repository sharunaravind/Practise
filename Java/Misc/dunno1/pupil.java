package dunno1;

public class pupil {
    Ddate bday ;
    String name;
    pupil(String name,Ddate birthday)
    {
        this.name = name;
        this.bday = birthday;
    }
    public String toString()
    {
        return String.format("  %s  born on  %s ", name, bday);
//      return "This is a string or whaaaaat";
    }
}
