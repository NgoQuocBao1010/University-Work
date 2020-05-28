package baiTH3;
import java.util.Scanner;


public class SinhVien {
	private String mssv, hvt;
	private Date ngaysinh;
	private int sohocphan;
	private String[] tenhocphan = new String[100];
	private String[] diemhocphan = new String[100];
	private Scanner sc = new Scanner(System.in);
	
	public SinhVien() {
		this.nhapThongTin();
	}
	
	public SinhVien(String ms, String hvten, Date ns) {
		this.mssv = ms;
		this.hvt = hvten;
		this.ngaysinh = ns;
	}
	
	public void nhapThongTin() {
		System.out.println("Nhap thong tin cua sinh vien.");
		
		System.out.print("Ho va ten hoc sinh: ");
		this.hvt = sc.nextLine();
		System.out.print("Ma so sinh vien cua hoc sinh: ");
		this.mssv = sc.nextLine();
		
		Date a = new Date();
		this.ngaysinh = a;
	}
	
	public void nhapDiem() {
		
		System.out.print("Nhap so hoc phan: ");
		this.sohocphan = sc.nextInt();
		
		for (int i=0; i < this.sohocphan; i++) {
			System.out.print("Nhap ten va diem cua hoc phan thu " + (i+1) + ": ");
			this.tenhocphan[i] = sc.next().toLowerCase();
			this.diemhocphan[i] = sc.next().toLowerCase();
		}
	}
	
	// quy doi diem chu sang diem so
	private float doiChuSangSo(String diemChu) {
		switch (diemChu) {
			case "a":
				return 4f;
			case "b+":
				return 3.5f;
			case "b":
				return 3f;
			case "c+":
				return 2.5f;
			case "c":
				return 2f;
			case "d+":
				return 1.5f;
			default:
				return 1f;
		}
	}
	
	//ham tinh diem Trung Binh
	public float diemTB() {
		float total = 0;
		
		for (int i=0; i < this.sohocphan ; ++i) {
			total += this.doiChuSangSo(this.diemhocphan[i]);
		}
		
		return total / (float) this.sohocphan;
	}
	
	public String toString() {
		String a;
		a = "Sinh Vien: " + this.hvt + ", sinh ngay " + this.ngaysinh.toString() + ", ma so sinh vien la " + this.mssv; 
		return a;
	}
	
	public void thongTinHocPhan() {
		String a;
		for (int i= 0; i < this.sohocphan; ++i) {
			a = "";
			a = this.tenhocphan[i] + " : " + this.diemhocphan[i];
			System.out.println(a);
		}
		System.out.println(this.diemTB());
	}
	
	// ham dang ky them 1 hoc phan
	public void dangKyThemHocPhan() {
		System.out.print("Nhap ten va diem cua hoc phan can them: ");
		this.tenhocphan[this.sohocphan] = sc.next().toLowerCase();
		this.diemhocphan[this.sohocphan] = sc.next().toLowerCase();
		this.sohocphan ++;
	}
	
	// ham xoa 1 hoc phan
	public void xoaHocPhan() {
		System.out.print("Nhap ten cua hoc phan can xoa: ");
		
		String tenhp = sc.next().toLowerCase();
		
		for (int i=0; i<this.sohocphan; ++i) {
			if (this.tenhocphan[i].equals(tenhp)) {
				for (int j=i; j<this.sohocphan-1; ++j) {
					this.tenhocphan[j] = this.tenhocphan[j + 1];
					this.diemhocphan[j] = this.diemhocphan[j + 1];
				}
				this.sohocphan --;
				return;
			}
		}
	}
}
