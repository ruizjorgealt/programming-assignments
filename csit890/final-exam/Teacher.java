
package main;


public class Teacher extends Person {
    private int hours;
    
    public Teacher(){
        super();
        hours = 0;
    }
    
    public Teacher(int h, String name){
        super(name);
        hours = h;
    }
    
    public int getHours(){
        return hours;
    }
    
    public void setHours(int h){
        hours = h;
    }
    
    public String toString(){
        String str = "Teacher name: " + super.getName() +"\nHours: " + hours +"\nPay: $" +(hours*75);
        return str;
    }
}
