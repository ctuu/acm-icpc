import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BigInteger dp[] = new BigInteger[103];
        dp[1] = BigInteger.ONE;
        dp[2] = BigInteger.valueOf(3);
        for(int i = 3; i < 103; ++i)
            dp[i] = dp[i-1].multiply(BigInteger.valueOf(3)).subtract(dp[i-2]);
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            int n  = cin.nextInt();
            System.out.println(dp[n]);
        }
    }
}
