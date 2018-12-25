//JORGE A. RUIZ
package main;
import java.util.Scanner;
import java.util.*;


public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        boolean exception;
        do{
            try{
                exception = false;
                System.out.print("Enter number of persons: ");
                int num = scan.nextInt();        
                Person[] p = new Person[num];
                inputPersons(p, num);
                outputPersons(p,num);
                }catch(NegativeArraySizeException e){
                    System.out.println("Number of persons can't be negative\n");
                    System.out.println("Try again to enter non-negative number\n");
                    exception = true;
                }catch(InputMismatchException e){
                   System.out.println("Number of persons must be whole number\n");
                   System.out.println("Try again to enter a whole number\n");
                   scan.nextLine();
                   exception = true;
                }
        }while(exception);
    } 
    
    public static void inputPersons(Person [] p, int n){
        Scanner kb = new Scanner(System.in);
        for(int i=0; i<n; i++){
            System.out.print("S/s for student, T/t for teacher: ");
            String input = kb.nextLine();
            char ch = input.charAt(0);
            System.out.print("Enter data now (Y/y) or later: ");
            String letter = kb.nextLine();
            char r = letter.charAt(0);
            if(ch=='S' || ch=='s'){
                if(r == 'Y' || r == 'y'){
                    System.out.print("\nEnter name: ");
                    String name = kb.nextLine();
                    System.out.print("\nEnter units: ");
                    int units = kb.nextInt();
                    p[i] = new Student(units, name);
                    kb.nextLine();
                }
                else{
                    String name = "";
                    int units = 0;
                    p[i] = new Student(units, name);
                }
            }
            else{
                if(r == 'Y' || r == 'y'){
                    System.out.print("\nEnter name: ");
                    String name = kb.nextLine();
                    System.out.print("\nEnter hours: ");
                    int hours = kb.nextInt();
                    p[i] = new Teacher(hours, name);
                    kb.nextLine();
                }
                else{
                    String name = "";
                    int hours = 0;
                    p[i] = new Teacher(hours, name);
                }
            }
        }
    }
    
    public static void outputPersons (Person [] p, int n){
        for(int i=0; i<n; i++){
            System.out.print((i+1)+". "+p[i].toString()+"\n");
        }
    }
}

