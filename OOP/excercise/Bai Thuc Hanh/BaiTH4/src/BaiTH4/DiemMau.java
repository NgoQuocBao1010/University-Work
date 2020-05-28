package BaiTH4;

public class DiemMau extends Diem{
	public String mau;
	
	public DiemMau() {
		this.nhapDiem();
	}
	
	public DiemMau(int x, int y, String m) {
		super(x, y);
		this.mau = m;
	}
	
	public void nhapDiem() {
		super.nhapDiem();
		System.out.print("Nhap mau cua diem: ");
		this.mau = sc.next();
	}
	
	public void GanMau(String mau) {
		this.mau = mau;
	}
	
	public void hienThi() {
		super.hienThi();
		System.out.println("Mau cua diem la: " + this.mau);
	}
	
}
