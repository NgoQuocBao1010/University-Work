package baiTH3;
import java.util.Scanner;

public class danhsachtotien {
	private int soluong;
	private totien[] danhSach;
	private Scanner sc = new Scanner(System.in);
	
	public danhsachtotien() {
		this.nhap();
	}
	
	public void nhap() {
		System.out.print("Nhap so to tien: ");
		soluong = sc.nextInt();
		danhSach = new totien[soluong];
		
		for (int i=0; i<soluong; i++) {
			System.out.println("Nhap menh gia cua to tien thu " + (i + 1) + ": ");
			int tien = sc.nextInt();
			totien moi = new totien(tien);
			danhSach[i] = moi;
		}
	}
	
	public void in() {
		System.out.print("(");
		for (int i=0; i<soluong; i++) {
			danhSach[i].in();
		}
		System.out.println(")");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		danhsachtotien bt = new danhsachtotien();
		bt.in();
	}

}

