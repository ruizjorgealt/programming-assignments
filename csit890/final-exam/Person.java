
package main;

public abstract class Person {
    private String name;
    
    public Person(){
        name = "";
    }
    
    public Person(String n){
        name = n;
    }
    
    public String getName(){
        return name;
    }
    public void setName(String n){
        name = n;
    }
}
