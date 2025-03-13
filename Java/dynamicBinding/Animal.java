class Animal {
    void show()
    {
        System.out.println("Animal sounds");
    }
}
class Dog extends Animal{
    int hello = 10;
    void check()
    {
        super.show();
    }
    void show(){
        System.out.println("Dog barks");
    }
}