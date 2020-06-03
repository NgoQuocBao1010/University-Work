package ptcang.buoi3;

import java.util.Scanner;

public class SDSinhVien {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SinhVien a = new SinhVien();
		a.nhap();
		a.dKy("LTHDT", "B");
		a.dKy("OS", "A");
		
		System.out.print(a.toString() + ", diem TB " + a.diemTB() );
		
		Scanner sc = new Scanner(System.in);		
		int n;
		System.out.print("\n nhap so sinh vien:");
		n = sc.nextInt();
		SinhVien ds[] = new SinhVien[n];
		for(int i=0; i< n;i++) ds[i] = new SinhVien();
		
		for(int i=0; i< n;i++){
			System.out.printf("\n + Nhap sinh vien thu %d : \n", i+1);
			ds[i].nhap();
			ds[i].nhapDiem();
		}
		
		System.out.println("**Danh sach sinh vien vua nhap:**");
		for(int i=0; i< n;i++)
			System.out.printf("+ Sinh vien thu %d : \n %s , diem TB: %.2f \n", i+1, ds[i].toString(), ds[i].diemTB());	

	}

}
