package baiTH3;
import java.util.Scanner;

public class Gach {
	public String maso, mau;
	public int vienTrongHop;
	
	//tinh theo cm
	public int chieuDai, chieuRong;
	public long giaBan;
	
	public Gach() {
		this.nhapThongTin();
	}
	
	public Gach(String maso, String mau, int vienTrongHop, int cd, int cr, int gia) {
		this.maso = maso;
		this.mau = mau;
		this.vienTrongHop = vienTrongHop;
		this.chieuDai = cd;
		this.chieuRong = cr;
		this.giaBan = gia;
	}
	
	public void nhapThongTin() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ma so cua hop: ");
		this.maso = sc.nextLine();
		System.out.print("Nhap mau cua gach: ");
		this.mau = sc.nextLine();
		System.out.print("Nhap so vien trong hop: ");
		this.vienTrongHop = sc.nextInt();
		System.out.print("Nhap chieu dai cua 1 vien gach (cm): ");
		this.chieuDai = sc.nextInt();
		System.out.print("Nhap chieu rong cua 1 vien gach (cm): ");
		this.chieuRong = sc.nextInt();
		System.out.print("Nhap gia tien cua mot hop (VND): ");
		this.giaBan = sc.nextInt();
	}
	
	public void hienThi() {
		System.out.println("- Hop co ma so " + this.maso + " su dung gach mau " + this.mau);
		System.out.println("- Chieu dai va chieu rong cua 1 vien gach lan luot la : " + this.chieuDai + " cm, " + this.chieuRong + " cm");
		System.out.println("- Gia ban cua mot hop la: " + this.giaBan + " VND");
		
		System.out.print("\nBan co muon hien thi them thong tin khong? (yes/no): ");
		Scanner sc = new Scanner(System.in);
		String option = sc.nextLine().toLowerCase();
		
		if (option.equals("no")) return;
		
		System.out.println("- Gia ban le cua moi vien trong hop la: " + this.giaBanle() + " VND");
		System.out.println("- Dien tich nen toi da de su dung hop la: " + this.dienTichNenToiDa() + " cm vuong");
	}
	
	public float giaBanle() {
		float gia1vien = (float) this.giaBan / (float) this.vienTrongHop;
		return (float) gia1vien * (1.2F);
	}
	
	public int dienTichNenToiDa() {
		int dienTich1Vien = this.chieuDai * this.chieuRong;
		return this.vienTrongHop * dienTich1Vien;
	}
	
	public int soLuongHop(int D, int N) {
		int dienTich = D * N;
		float soHopTrungBinh = (float) dienTich / (float) this.dienTichNenToiDa();
		int soHop = (int) soHopTrungBinh;
		
		if (soHop == soHopTrungBinh) return soHop;
		return soHop + 1;
	}
	
	
}
