import java.util.*;
public class ArrayTest{
    public static void main(String[]args){
        Scanner kb = new Scanner(System.in);
        int a[] = new int[5];
        for(int i=0;i<5;i++){
            a[i]=kb.nextInt();
        }
        Arrays.sort(a);
         for(int i=0;i<5;i++){
             System.out.println("LARGEST NO IS" +" " +a[4]);
             System.out.println("SMALLEST NO IS" + "  "+a[0]);
         }

    }
}