package baiTH3;
import java.util.Scanner;

public class DoanThang {
	public Diem d1;
	public Diem d2;
	private float heSoGoc;
	private float bien;
	
	private void taoDuongThang() {
		// y = ax + b
		this.heSoGoc = (float) (this.d1.x - this.d2.x) / (float) (this.d1.y - this.d2.y);
		this.bien = (float) (this.d1.y) - this.heSoGoc * (float) this.d1.x;
	}
	
	
	public DoanThang() {
		this.nhapToaDoDoanThang();
		this.taoDuongThang();
	}
	
	public DoanThang(Diem a, Diem b) {
		this.d1 = a;
		this.d2 = b;
		this.taoDuongThang();
	}
	
	public DoanThang(int ax, int ay, int bx, int by) {
		this.d1 = new Diem(ax, ay);
		this.d2 = new Diem(bx, by);
		this.taoDuongThang();
	}
	
	public void nhapToaDoDoanThang() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap toa do cua diem dau: ");
		this.d1 = new Diem();
		System.out.println("Nhap toa do cua diem cuoi: ");
		this.d2 = new Diem();
	}
	
	public void hienThi() {
		System.out.print("2 diem mut cua doan thang la: ");
		this.d1.hienThi();
		System.out.print("  ,  ");
		this.d2.hienThi();
	}
	
	public void tinhTien(int dx, int dy) {
		this.d1.tinhTien(dx, dy);
		this.d2.tinhTien(dx, dy);
		this.taoDuongThang();
	}
	
	public float doDaiDoanThang() {
		return this.d1.khoangCach(this.d2);
	}
	
	public void gocSoVoiTrucHoanh() {
		System.out.println("Doan thang tao voi truc hoanh 1 goc A sao cho tanA = " + this.heSoGoc);
	}
	
}
