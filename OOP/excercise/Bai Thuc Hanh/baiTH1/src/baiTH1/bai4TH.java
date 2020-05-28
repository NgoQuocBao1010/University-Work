package baiTH1;
import java.util.Scanner;

public class bai4TH {
	public static int nhapSo() {
		String s;
		int n;
		Scanner sc = new Scanner(System.in);
		
		do {
			System.out.print("Nhap 1 con so: ");
			s = sc.nextLine();
			try {
				n = Integer.parseInt(s);
			}
			catch (NumberFormatException e) {
				n = Integer.MAX_VALUE;
				System.out.println("So khong hop le!!");
			}
		}
		while (n == Integer.MAX_VALUE);
		
		return n;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a = nhapSo();
		int b = nhapSo();
		System.out.print("Sum = " + (a + b));
	}

}
