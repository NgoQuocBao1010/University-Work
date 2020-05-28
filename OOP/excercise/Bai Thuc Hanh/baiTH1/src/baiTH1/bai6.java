package baiTH1;
import java.util.Scanner;

public class bai6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap so: ");
		int n = sc.nextInt();
		
		if (n <= 0 || n == 1) {
			System.out.println(n + " khong phai so nguyen to!!");
			return;
		}
		
		if (n == 2) {
			System.out.println(n + " la so nguyen to!!");
			return;
		}
		if (n % 2 == 0) {
			System.out.println(n + " khong phai so nguyen to!!");
			return;
		}
		
		for (int i = 3; i < (int) Math.sqrt(n); ++i) {
			if (n % i == 0) {
				System.out.println(n + " khong phai so nguyen to!!");
				return;
			}
		}
		
		System.out.println(n + " la so nguyen to!!");
	}

}
