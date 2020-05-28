package TheoryLesson2;

import java.util.Scanner;

public class PhanSo {
	private int tu;
	private int mau;
	
	public PhanSo() {
	}
	
	public PhanSo(int tu, int mau) {
		this.tu = tu;
		this.mau = mau;
		this.rutGonPhanSo();
	}
	
	private void rutGonPhanSo() {
		if (this.mau == 1 || this.tu == 1 || this.mau == -1 || this.tu == -1) return;
		
		int a = UCLN(this.mau, this.tu);
		this.tu /= (int) a;
		this.mau /= (int) a;
	}
	
	public void nhapGiaTri() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap vao tu so: ");
		this.tu = sc.nextInt();
		System.out.print("Nhap vao mau so: ");
		this.mau = sc.nextInt();
		while (true) {
			if (this.mau != 0)
				break;
			System.out.print("Mau so khong hop le!\n Xin hay nhap lai: ");
			this.mau = sc.nextInt();
		}
		this.rutGonPhanSo();
	}
	
	public void hienThi() {
		if (this.tu == 0) {
			System.out.println(0);
			return;
		}
		
		if (this.mau == 1) {
			System.out.println(this.tu);
			return;
		}
		
		if (this.mau < 0) {
			this.tu *= -1;
			this.mau *= -1;
		}
		
		System.out.println(this.tu + "/" + this.mau);
	}
	
	public void nghichDao() {
		int a = this.tu;
		this.tu = this.mau;
		this.mau = a;
	}
	
	public PhanSo giaTriNghichDao() {
		int tuA = this.mau;
		int mauA = this.tu;
		
		PhanSo a = new PhanSo(tuA, mauA);
		return a;
	}
	
	public float giaTriThuc() {
		return (float) this.tu / this.mau;
	}
	
	public static int UCLN(int a, int b) {
		if (b == 0) return a;
		return UCLN(b, a % b);
	}
	
	public static int BCNN(int a, int b) {
		return (a * b) / UCLN(a, b);
	}
	
	public int soSanh(PhanSo a) {
		if (this.giaTriThuc() > a.giaTriThuc())
			return 1;
		
		if (this.giaTriThuc() < a.giaTriThuc())
			return -1;
		
		return 0;
	}
	
	public PhanSo cong(PhanSo a) {
		int boichung = BCNN(this.mau, a.mau);
		
		int kT = boichung / this.mau;
		int kA = boichung / a.mau;
		int tuSoMoi = this.tu * kT + a.tu * kA;
		//System.out.println(this.tu + "," +  kA);
		
		PhanSo moi = new PhanSo(tuSoMoi, boichung);
		return moi;
	}
	
	public PhanSo tru(PhanSo a) {
		int boichung = BCNN(this.mau, a.mau);
		
		int kT = boichung / this.mau;
		int kA = boichung / a.mau;
		int tuSoMoi = this.tu * kT - a.tu * kA;
		
		PhanSo moi = new PhanSo(tuSoMoi, boichung);
		return moi;
	}
	
	public PhanSo nhan(PhanSo a) {
		PhanSo moi = new PhanSo(this.tu * a.tu, this.mau * a.mau);
		return moi;
	}
	
	public PhanSo chia(PhanSo a) {
		PhanSo moi = new PhanSo(this.tu * a.mau, this.mau * a.tu);
		return moi;
	}
	
	public PhanSo cong(int k) {
		PhanSo moi = new PhanSo(this.tu + this.mau * k, this.mau);
		return moi;
	}
	
	public PhanSo tru(int k) {
		PhanSo moi = new PhanSo(this.tu - this.mau * k, this.mau);
		return moi;
	}
	
	public PhanSo nhan(int k) {
		PhanSo moi = new PhanSo(this.tu * k, this.mau);
		return moi;
	}
	
	public PhanSo chia(int k) {
		PhanSo moi = new PhanSo(this.tu, this.mau * k);
		return moi;
	}
	
	public PhanSo copy() {
		PhanSo moi = new PhanSo(this.tu, this.mau);
		return moi;
	}
}
