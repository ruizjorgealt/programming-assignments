
public class BrickDepot {
    
    private int bricks;
    private double money;
    
    public BrickDepot(double money01, int bricks01)
    {
        bricks = bricks01;
        money = money01;
    }
    
    public boolean makeBricks(int n)
    {
        if (money >= n * 3.50){
            bricks += n;
            money -= n * 3.50;
        }
        else
            return true;
      
      return false;
    }
    
    public boolean sellBrick(int n){
    
        if(n >= 1 && n <= bricks){
            bricks -= n;
            money += n * 4.50;
        }
        else
            return true;
        
      return false;  
    }
    
    public int getbricks()
    {
        return bricks;
    }
    
    public double getmoney()
    {
       return money;
    }
}
