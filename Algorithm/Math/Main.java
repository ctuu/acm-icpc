import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        while(cin.hasNext()) {
            BigInteger x, y;
            x = cin.nextBigInteger();
            y = cin.nextBigInteger();
            x = x.add(BigInteger.ONE); x = x.subtract(BigInteger.TEN);
            x = x.multiply(BigInteger.ZERO);
            x = x.divide(y); x = x.remainder(y); x = x.mod(y);
            x = x.pow(10); x = x.gcd(y); x = x.abs(); x = x.negate();
            x = x.max(y); x = x.min(y);
            if (x.compareTo(y) > 0) { }
            if (x.equals(y)) { }
            x = new BigInteger("123456");
            x = new BigInteger("1010101", 2);
            x.toString();
            System.out.println(x);
            BigDecimal a, b;
            a = cin.nextBigDecimal();
            b = cin.nextBigDecimal();
            Double g = a.doubleValue();
            String str = a.toString();
            String st = Integer.toString(num, base); //把int型num当10进制的数转成base进制数存入st中    (base <= 35).  
            int num = Integer.parseInt(st, base); //把st当做base进制，转成10进制的int  
            BigInter m = new BigInteger(st, base); // st是字符串，base是st的进制.
            a = a.divide(b, 100, RoundingMode.HALF_UP);
            System.out.println(String.format("%.6f", a));
        }
    }
}
/*
RoundingMode是一个枚举类，有一下几个常量：
UP,始终对非零舍弃部分前面的数字加 1
DOWN,截尾
CEILING,向正无限大方向舍入
FLOOR,向负无限大方向舍入的舍入
HALF_UP,四舍五入
HALF_DOWN,五舍六入
HALF_EVEN，向最接近数字方向舍入的舍入模式，如果与两个相邻数字的距离相等，则向相邻的偶数舍入
UNNECESSARY，不需要舍入
*/