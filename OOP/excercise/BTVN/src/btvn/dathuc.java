package btvn;
import java.util.Scanner;

public class dathuc {
	public int bacCaoNhat;
	public int[] danhSachPhanTu = new int[1000];
	private Scanner sc = new Scanner(System.in);
	
	public dathuc() {
		this.bacCaoNhat = 0;
	}
	
	public dathuc(int bac) {
		this.bacCaoNhat = bac;
	}
	
	public void nhap() {
		this.bacCaoNhat = sc.nextInt();
		for (int i=this.bacCaoNhat; i>=0; i--) {
			this.danhSachPhanTu[i] = sc.nextInt();
		}
	}
	
	public void in() {
		String result = "";
		for (int i=this.bacCaoNhat; i>=0; i--) {
			result += this.danhSachPhanTu[i] + "mu" + i + " + ";
		}
		System.out.println(result);
	}
}
