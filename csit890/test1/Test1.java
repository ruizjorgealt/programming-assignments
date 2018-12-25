
package test1;

import java.util.Scanner;
import java.io.*;
import javax.swing.JOptionPane;

public class Test1 {

    
    public static void main(String[] args) throws IOException
    {
        int amount = 100;
        int choice;
        int deposit;
        int withdrawal;
        Scanner keyboard = new Scanner(System.in);
        
        do
        {
          System.out.println("1.Deposit");
          System.out.println("2.Withdrawal");
          System.out.println("3.View");
          System.out.println("4.Exit");
          System.out.print("Enter choice: ");
          choice = keyboard.nextInt();
          
          if (choice == 3)
          {
              System.out.println("Updated balanced: $" + amount);
          }
          else if (choice == 1)
          {
              System.out.print("Deposit amount: $");
              deposit = keyboard.nextInt();
              amount += deposit;
              System.out.println("Updated balanced: $" + amount);

          }
          else if (choice == 2)
          {
              System.out.print("Withdrawal amount: $");
              withdrawal = keyboard.nextInt();
              
              if (withdrawal > amount)
              {
                JOptionPane.showMessageDialog(null, "Insufficient funds");
                //System.out.println("Insufficient funds");
              }
              else
              {
                amount -= withdrawal;
                System.out.println("Updated balanced: $" + amount);   
              }


          }
          
        }while (choice != 4);
    
        PrintWriter outputFile = new PrintWriter("balance.txt");
        outputFile.println("Final balance: $" + amount);
        outputFile.close();
		  keyboard.close();
		  System.exit(0);
        
    }
    
}
