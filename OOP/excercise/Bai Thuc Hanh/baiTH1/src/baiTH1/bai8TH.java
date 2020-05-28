package baiTH1;
import java.util.Scanner;

public class bai8TH {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Nhap vao so phan tu trong danh sach: ");
		int arrs_lenght = sc.nextInt();
		int[] arrs = new int[arrs_lenght];
		
		for (int i = 0; i < arrs.length; ++i) {
			System.out.print("Nhap vao so thu " + (i + 1) + ": ");
			arrs[i] = sc.nextInt();
		}
		
		System.out.print("Nhap vao 1 so: ");
		int so = sc.nextInt();
		int count = 0;
		
		for (int phantu: arrs) {
			if (phantu == so) count += 1;
		}
		System.out.println("Co " + count + " so " + so + " trong danh sach!");
		
		for (int i = 0; i < arrs.length - 1; ++i) {
			for (int j = i+1; j < arrs.length; ++j) {
				if (arrs[i] > arrs[j]) {
					int temp = arrs[i];
					arrs[i] = arrs[j];
					arrs[j] = temp;
				}
			}
		}
		
		System.out.print("Danh sach sau khi sap xep la: ");
		for (int pt: arrs) {
			System.out.print(pt + " ");
		}
	}

}
