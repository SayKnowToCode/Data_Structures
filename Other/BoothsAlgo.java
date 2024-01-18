import java.util.*;

public class BoothsAlgo
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
   
    static int[] DecimalBinary(int k,int size)
    {
        int n = Math.abs(k);
        int i=size;
        int[] binaryNum = new int[size+1];
        while (n > 0)  
        {
            // storing remainder in binary array
            binaryNum[size] = n % 2;
            n = n / 2;
            size--;
        }
       
        if(k<0)
        {
            while(i>=0)
            {
                if(binaryNum[i] == 1)
                {
                    for(int j=i-1;j>=0;j--)
                    {
                        if(binaryNum[j] == 0)
                            binaryNum[j] = 1;
                        else
                            binaryNum[j] = 0;
                           
                    }
                    break;
                }
               
                else
                    i--;
            }
        }
        return binaryNum;
    }
   
    static void printArray(int A[],int size)
    {
        for(int i=0;i<=size;i++)
        {
            System.out.print(A[i]);
        }
    }
   
    static int[] add(int a[],int b[],int size)
    {
        int c=0;
        int sum[] = new int[size+1];
        for(int i=size;i>=0;i--)
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
   
    static int[] rightShift(int arr[],int size)
    {
        int newArr[] = new int[size+1];
        int k = arr[0];
       
        for(int i=0;i<size;i++)
        {
            int j=i+1;
            
            if(j>size)
                break;
            newArr[j] = arr[i];
        }
       
        newArr[0] = k;
        return newArr;
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
   
public static void main(String[] args)
{
   Scanner sc = new Scanner(System.in);
   System.out.println("Enter two numbers in decimal format");
   int q,m;
   q = sc.nextInt();
   m = sc.nextInt();
   int size = Size(Math.max(Math.abs(q),Math.abs(m)));
   
   int A[] = new int[size+1];
   int Q[] = new int[size+1];
   int M[] = new int[size+1];
   
   A = DecimalBinary(0,size);
   
   Q = DecimalBinary(Math.abs(q),size);
   int [] Q_2C = DecimalBinary(q,size);
   
   M = DecimalBinary(m,size);
   int [] M_2C = DecimalBinary(-m,size);
   
   System.out.println();
   System.out.println();
   printArray(M,size);
   System.out.print(" ");
   printArray(M_2C,size);
   System.out.println();
   
   int Qm = 0;
   
   printArray(A,size);
   System.out.print("  ");
   printArray(Q_2C,size);
   System.out.print("  ");
   System.out.print(Qm);
   System.out.println();

   for(int i=1;i<=size+1;i++)
   {
       int flag = 0;
       
       if(Q_2C[size] == 0 && Qm == 1)
       {
            A = add(A,M,size);
       }
       
       else if (Q_2C[size] == 1 && Qm == 0)
       {
            A = add(A,M_2C,size);
       }
       
       if(flag > 0)
       {
           printArray(A,size);
           System.out.print("  ");
           printArray(Q_2C,size);
           System.out.print("  ");
           System.out.print(Qm);
           System.out.println();
       }
       
       int temp = A[size];
       Qm = Q_2C[size];
       A = rightShift(A,size);
       Q_2C = rightShift(Q_2C,size);
       Q_2C[0] = temp;
       
       printArray(A,size);
       System.out.print("  ");
       printArray(Q_2C,size);
       System.out.print("  ");
       System.out.print(Qm);
       System.out.println();
   }
   
   int[] last = new int[A.length + Q.length];
   
   int counter = 0;
   for(int i=0 ; i<=size ; i++)
   {
       last[counter] = A[i];
       counter++;
   }
   for(int i=0 ; i<=size ; i++)
   {
       last[counter] = Q_2C[i];
       counter++;
   }
   
   int negFlag = 0;
   if(last[0] == 1)
   {
       int i = last.length - 1;
       negFlag = 1;
       while(i>=0)
       {
           if(last[i] == 1)
           {
               for(int j=i-1;j>=0;j--)
               {
                   if(last[j] == 1)
                    last[j] = 0;
                    
                   else
                    last[j] = 1;
               }
               break;
           }
           
           i--;
       }
   }
   
   if(negFlag == 0)
    System.out.println("\n\nThe answer is "+answer(last,last.length-1));
   else
    System.out.println("\n\nThe answer is -"+answer(last,last.length-1));
}
}




