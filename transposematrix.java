package condition;
import java.util.*;

public class transposeofmatrix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i,j;
		int input[][]=new int[4][4];
		int transpose[][]=new int[4][4];
		Scanner sc=new Scanner(System.in);
		System.out.println("enter 4*4 matrix");
		for(i=0;i<4;i++) {
			for(j=0;j<4;j++) {
				input[i][j]=sc.nextInt();
			}
		}
		for(i=0;i<4;i++) {
			for(j=0;j<4;j++) {
				transpose[j][i]=input[i][j];
			}
		}
		System.out.println("transpose matrix");
		for(i=0;i<4;i++) {
			for(j=0;j<4;j++) {
				System.out.print(transpose[i][j]+"");
			}
			System.out.print("\n");
		}

	}

}
