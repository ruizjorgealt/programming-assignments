
package main;

public class Student extends Person{
    private int units;
    public Student(){
        super();
        units=0;
    }
    
    public Student(int u, String name){
        super(name);
        units = u;
    }
    
    public int getUnits(){
        return units;
    }
    
    public void setUnits(int u){
        units = u;
    }
    
    public String toString(){
        String str ="Student name: " + super.getName()+"\nUnits: " + units + "\nTuition: $" + (units * 46);
        return str;
    }
}
