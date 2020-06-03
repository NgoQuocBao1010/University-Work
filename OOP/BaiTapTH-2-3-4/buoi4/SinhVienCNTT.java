package ptcang.buoi4;

import java.util.Scanner;

import ptcang.buoi3.SinhVien;

public class SinhVienCNTT extends SinhVien {
	private String tKhoan, mKhau, email;
	
	public SinhVienCNTT(){
		super();
		tKhoan = new String();
		mKhau = new String();
		email = new String();		
	}
	
	public SinhVienCNTT(SinhVienCNTT svcntt){
		super(svcntt);
		tKhoan = new String(svcntt.tKhoan);
		mKhau = new String(svcntt.mKhau);
		email = new String(svcntt.email);		
	}
	
	public void nhap(){
		super.nhap();
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap tKhoan:");
		tKhoan = sc.nextLine();
		System.out.print("Nhap mat khau:");
		mKhau = sc.nextLine();
		System.out.print("Nhap email:");
		email = sc.nextLine();
	}
	
	public String toString(){
		String s = super.toString();
		s += ", " + tKhoan + "," + mKhau + "," + email;
		return s;
	}
	
	

}
