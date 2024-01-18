// Here we have assumed that always q is greater than m and q and m are always positive as unsigned

import java.util.*;

public class RestoreDiv
{
    static int Size(int q)
    {
        int i = 0;
       
        while(q>0)
        {
            q=q/2;
            i++;
        }
        return i;
    }

    static int[] DecimalBinary(int n,int size)
    {
        int[] binaryNum = new int[size];
        while (n > 0)  
        {
            // storing remainder in binary array
            binaryNum[size-1] = n % 2;
            n = n / 2;
            size--;
        }
        return binaryNum;
    }

    static void printArray(int A[],int size)
    {
        for(int i=0;i<size;i++)
        {
            System.out.print(A[i]);
        }
    }
   
    static int[] add(int a[],int b[],int size)
    {
        int c=0;
        int sum[] = new int[size];
        for(int i=size-1;i>=0;i--)
        {
            if(a[i]==0 && b[i]==0)
            {
                sum[i] = 0+c;
                c=0;
            }
               
            else if((a[i]==1 && b[i]==0) || (a[i]==0 && b[i]==1))
            {
                sum[i] = 1+c;
               
                if(c==1)
                {
                    sum[i] = 0;
                    c=1;
                    continue;
                }
                c=0;
            }
           
            else if(a[i]==1 && b[i]==1)
            {
                sum[i] = 0+c;
                c=1;
            }
        }
        return sum;
    }

    static int[] leftShift(int arr[],int size)
    {
        int newArr[] = new int[size];
       
        for(int i=1;i<size;i++)
        {
            int j=i-1;
            newArr[j] = arr[i];
        }

        return newArr;
    }

    static int[] C2(int [] arr,int size)
    {
        int i = size-1;
        int[] binaryNum = new int[size];
        while (i >= 0)
        {
            if (arr[i] == 1)
            {
                binaryNum[i] = arr[i];
                for (int j = i - 1; j >= 0; j--)
                {
                    if (arr[j] == 0)
                        binaryNum[j] = 1;
                    else
                        binaryNum[j] = 0;
                }
                break;
            }
            else
            {
                binaryNum[i] = arr[i];
            }
            i--;
        }
        return binaryNum;
    }

    static int answer(int [] arr, int size)
    {
        int power = 0;
        int sum = 0;

        while(size>=0)
        {
            sum = sum + (arr[size] * (int)(Math.pow(2,power)));
            size--;
            power++;
        }
        return sum;
    }
    
    public static void main (String[]args)
    {
        Scanner sc = new Scanner (System.in);
        int q, m;
        System.out.println ("Enter the dividend ");
        q = sc.nextInt ();
        System.out.println ("Enter the divisor ");
        m = sc.nextInt ();
        int size = Size (q);

        int A[] = new int[size + 1];
        int Q[] = new int[size];
        int M[] = new int[size + 1];

        M = DecimalBinary(m,M.length);
        Q = DecimalBinary(q,Q.length);
        int M_2C[] = C2(M,M.length);

        printArray(A,A.length);
        System.out.print("  ");
        printArray(Q,Q.length);
        System.out.print("  ");
        printArray(M, M.length);
        System.out.println();

        for (int i = 0; i < Q.length; i++)
        {
            int temp = Q[0];
            A = leftShift (A, A.length);
            A[A.length-1] = temp;
            Q = leftShift(Q, Q.length);
            A = add(A,M_2C,A.length);

            if(A[0] == 0)
            {
                Q[Q.length-1] = 1;
            }

            else
            {
                Q[Q.length-1] = 0;
                A = add(A, M, A.length);
            }

            printArray(A,A.length);
            System.out.print("  ");
            printArray(Q,Q.length);
            System.out.print("  ");
            printArray(M, M.length);
            System.out.println();
        }

        System.out.println("The Quotient is : "+answer(Q, Q.length-1));
        System.out.println("The Remainder is : "+ answer(A, A.length-1));

    }
}
