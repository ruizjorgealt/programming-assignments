
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;
import java.io.*;

/**
 *
 * @author ruizja8845
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) // throws IOException 
    {
        int bricks, choice, n;
        double money;
        Scanner keyboard = new Scanner (System.in);
        System.out.print("Enter starting number of bricks: ");
        bricks = keyboard.nextInt();
        System.out.print("Enter starting amount of money: ");
        money = keyboard.nextDouble();
        BrickDepot bd = new BrickDepot(money, bricks);
        
        do {
        
        System.out.println("\n1. Make bricks\n" +
                           "2. Sell bricks\n" +
                           "3. Inventory and money report\n" +
                           "4. Exit\n" +
                           "Enter choice:");
        choice = keyboard.nextInt();
        
        if (choice == 1){
            
            System.out.println("How many bricks to make: ");
            n = keyboard.nextInt();
            if(bd.makeBricks(n)){
                System.out.printf("Not enough money to make bricks");
            }
        }
        
        if (choice == 2){
            System.out.print("How many bricks to sell: ");
            n = keyboard.nextInt();
            if (bd.sellBrick(n)){  
            System.out.printf("Not enough bricks to sell");            
            } 
        }
        
        if (choice == 3){
            System.out.print("\nMoney: " + bd.getmoney());
            System.out.print("\nBricks: " + bd.getbricks());
        }
        
        }while (choice != 4);
        
        System.out.print("Money: " + bd.getmoney());
        System.out.print("\nBricks: " + bd.getbricks());
        keyboard.close();
        System.exit(0);
    }
    
}
