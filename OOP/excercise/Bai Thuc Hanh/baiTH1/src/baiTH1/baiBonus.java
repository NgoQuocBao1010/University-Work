package baiTH1;
import java.util.Scanner;

public class baiBonus {
	public static void ThongKe(int[] arrs) {
		for (int i =0; i < arrs.length; ++i) {
			if (arrs[i] != Integer.MIN_VALUE) {
				int count = 1;
				if (i == arrs.length - 1) {
					System.out.println("So " + arrs[i] + " co " + count + " so.");
					return;
				}
				for (int j = i + 1; j < arrs.length; ++j) {
					if (arrs[i] == arrs[j]) {
						arrs[j] = Integer.MIN_VALUE;
						count ++;
					}
				}
				System.out.println("So " + arrs[i] + " co " + count + " so.");
			}
		}
	}

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
		
		ThongKe(arrs);
	}

}
