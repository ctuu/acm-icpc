import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
public class Main 
{
    public static void main(String[] args) 
    {
        Scanner cin=new Scanner (System.in);
        BigInteger dp[]=new BigInteger[105];
        dp[1]=BigInteger.valueOf(1);
        dp[2]=BigInteger.valueOf(3);
        for(int i=3;i<=100;i++)
            dp[i]=dp[i-1].multiply(new BigInteger("3")).subtract(dp[i-2]);
        while(cin.hasNext())
        {
            int id = cin.nextInt();
            System.out.println(dp[id]);
        }
        System.exit(0);
    }
}