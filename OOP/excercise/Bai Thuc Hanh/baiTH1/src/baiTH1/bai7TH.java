package baiTH1;
import java.util.Scanner;

public class bai7TH {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap vao ho ten cua ban: ");
		String s = sc.nextLine().trim();
		
		int pos = s.lastIndexOf(" ");
		System.out.println("Ten cua ban la: " + s.substring(pos + 1));
	}

}
