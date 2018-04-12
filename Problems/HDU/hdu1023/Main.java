import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        BigInteger[][]  com = new BigInteger[203][203];
        for(int i = 0; i < 203; ++i)
            for(int j = 0; j < 203; ++j)
                com[i][j] = BigInteger.ZERO;
        com[1][0]=new BigInteger("1");
        for(int i = 1; i < 203; ++i)
            for(int j = 1; j < 203; ++j)
                com[j][i] = com[j-1][i-1].add(com[j][i-1]);
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
            int t;
            t = cin.nextInt();
            System.out.println((com[t][2 * t].subtract(com[t+1][2 * t])).abs());
        }
    }    
}       