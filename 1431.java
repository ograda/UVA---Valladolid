//Anderson Zudio de Moraes
//Victor Cracel Messner
//AC em 07/04/2014

import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{

    public static void main(String args[]) throws IOException
    {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] in2;
        String newLine;
        BigInteger n, d, e, k, r, y, x, i, p, q;
        int t, cont = 0;
        Random rnd;

         while(true)
         {
         	newLine = in.readLine();
         	in2 = newLine.split(" ");
        	n = new BigInteger(in2[0]);
        	d = new BigInteger(in2[1]);
        	e = new BigInteger(in2[2]);
        	if(e.equals(BigInteger.ZERO)) break;

        	k = d.multiply(e);
        	k = k.subtract(BigInteger.ONE);

        	y = BigInteger.ZERO;
        //	x = BigInteger.ZERO;
        	x = BigInteger.ONE;
       		x = x.add(BigInteger.ONE);

        	while(y.equals(BigInteger.ZERO))
        	{
        		/*rnd = new Random();
        		do {
						 x = new BigInteger(n.bitLength(), rnd);
				}while (x.compareTo(n) >= 0);
        		if(x.equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)) continue;*/

        		if(k.equals(BigInteger.ONE))
        		{
        			r = BigInteger.ZERO;
        			t = 0;
        		}
        		else
        		{
        			r = k;
        			t = 0;
        			while(r.and(BigInteger.ONE).equals(BigInteger.ZERO))
        			{
        				r = r.shiftRight(1);
        				t += 1;
        			}

        		}

        		y = BigInteger.ZERO;
        		i = x.modPow(r,n);

        		while(!(i.equals(BigInteger.ONE)))
        		{
        			y = i;
        			i = i.multiply(i);
        			i = i.mod(n);
        		}

        		if(y.equals(n.subtract(BigInteger.ONE)))
        			y = BigInteger.ZERO;
        		x = x.add(BigInteger.ONE);
            }


            y = y.subtract(BigInteger.ONE);
            e = n;
            while(!(e.equals(BigInteger.ZERO)))
            {
            	q = e;
            	e = y.mod(e);
            	y = q;
            }
            p = y;
            q = n.divide(p);
            cont++;

         	System.out.println("Case #" + cont + ": " + p.min(q) + " " + p.max(q));
         	in.readLine();
         }


    }
}
