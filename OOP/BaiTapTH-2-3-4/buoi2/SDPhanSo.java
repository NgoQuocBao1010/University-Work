package ptcang.buoi2;

import java.util.Scanner;

public class SDPhanSo {

	public static void main(String[] args) {
	
		PhanSo a=new PhanSo(3,7);
		PhanSo b=new PhanSo(4,9);
		
		a.hienthi();
		b.hienthi();		
		
		System.out.printf("\ngia tri cua phan so a la : %f ",a.giatrithuc());		
		System.out.printf("\ngia tri cua phan so b la : %f ",b.giatrithuc());
		
		PhanSo x=new PhanSo();
		x.nhapphanso();
		System.out.printf("\ngia tri nghich dao cua phan so x la : %f ",x.giatringhichdao());
		
		PhanSo y=new PhanSo();
		y.nhapphanso();
		System.out.printf("\ngia tri nghich dao cua phan so y la : %f ",y.giatringhichdao());
		System.out.printf("tong cua x + y la : %f",x.cong(y).giatrithuc());
		
		
		
		Scanner sc = new Scanner(System.in);
		System.out.print("\n Nhap so phan so:");
		int n = sc.nextInt();
		
		PhanSo mang[] = new PhanSo[n];
		for (int i=0; i < n ; i++)
			mang[i] = new PhanSo();
		
		for (int i=0; i < n ; i++){
			System.out.printf("\n Nhap phan so thu %d", i+1);			
			mang[i].nhapphanso();			
		}
		
		System.out.println("\n Day phan so da nhap :");
		for (int i=0; i< n; i++){
			mang[i].hienthi();
			System.out.print(" , ");
		}
		
		PhanSo tong= new PhanSo();
		for(int i=0;i<n;i++)
		  tong = tong.cong(mang[i]);
		
		System.out.println("\n Phan so tong la : ");
		tong.toiGian();
		tong.hienthi();


		
	}

}
