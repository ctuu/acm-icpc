import java.io.*;
import java.math.*;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        BigInteger[] dp = new BigInteger[103];
        for(int i = 0; i < 103; ++i)
            dp[i] = BigInteger.ZERO;
        dp[0] = BigInteger.ONE;
        dp[1] = BigInteger.ONE;
        dp[2] = new BigInteger("2");
        for(int i = 3; i < 103; ++i)
            for(int j = 0; j < i; ++j)
                dp[i] = dp[i].add(dp[j].multiply(dp[i-j-1]));
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            int n = cin.nextInt();
            System.out.println(dp[n]);
        }
    }
    
}