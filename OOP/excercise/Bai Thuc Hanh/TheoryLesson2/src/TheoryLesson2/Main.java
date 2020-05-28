package TheoryLesson2;
import java.util.Scanner;

public class Main {
	
	public static void baiDiem() {
		Diem a = new Diem(3, 4);
		System.out.print("Toa do cua diem A: ");
		a.hienThi();
		Diem b = new Diem();
		b.nhapDiem();
		System.out.print("\nToa do cua diem B: ");
		b.hienThi();
		
		int cx, cy;
		cx = b.giaTriX() * -1;
		cy = b.giaTriY() * -1;
		Diem c = new Diem(cx, cy);
		System.out.print("\nToa do cua diem C: ");
		c.hienThi();
		
		System.out.println("\nKhoang cach tu diem B den tam O: " + b.khoangCach());
		System.out.println("\nKhoang cach tu diem A den diem B: " + a.khoangCach(b));
		
	}
	
	public static void baiPhanSo() {
		PhanSo a = new PhanSo(3, 7);
		PhanSo b = new PhanSo(4, 9);
		a.hienThi();
		b.hienThi();
		/*
		PhanSo x = new PhanSo();
		PhanSo y = new PhanSo();
		x.nhapGiaTri();
		y.nhapGiaTri();
		x.hienThi();
		y.hienThi();
		
		PhanSo nghichDaox = x.giaTriNghichDao();
		nghichDaox.hienThi();
		
		PhanSo tong = x.cong(y);
		System.out.print("Tong cua x va y: ");
		tong.hienThi(); */
		
		System.out.print("Nhap so phan tu cua danh sach: ");
		Scanner sc = new Scanner(System.in);
		int tongPS = sc.nextInt();
		PhanSo[] arrs = new PhanSo[tongPS];
		
		for (int i = 0; i < arrs.length; ++i) {
			System.out.println("Nhap vao phan so thu " + (i + 1));
			PhanSo moi = new PhanSo();
			moi.nhapGiaTri();
			arrs[i] = moi.copy();
		}
		
		PhanSo max = new PhanSo(-1000, 1);
		
		for (PhanSo ps: arrs) {
			if (ps.giaTriThuc() > max.giaTriThuc()) max = ps.copy();
		}
		System.out.print("Phan so lon nhat la: ");
		max.hienThi();
		
		for (int i = 0; i < arrs.length - 1; ++i) {
			for (int j = i + 1; j < arrs.length; ++j) {
				if ( arrs[i].soSanh(arrs[j]) == 1 ) {
					PhanSo tam = new PhanSo();
					tam = arrs[i].copy();
					arrs[i] = arrs[j].copy();
					arrs[j] = tam.copy();
				}
			}
		}
		
		for (PhanSo ps: arrs) {
			ps.hienThi();
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// baiDiem();
		baiPhanSo();
	}

}
