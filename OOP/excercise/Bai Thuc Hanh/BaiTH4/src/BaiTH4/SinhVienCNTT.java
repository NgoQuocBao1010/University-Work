package BaiTH4;

public class SinhVienCNTT extends SinhVien {
	public String taikhoanElcit, matkhauElcit;
	public String email;
	
	
	public void nhapThongTin() {
		System.out.print("Nhap ten tai khoan elcit: ");
		this.taikhoanElcit = sc.nextLine();
		System.out.print("Nhap mat khau tai khoan elcit");
		this.matkhauElcit = sc.nextLine();
		System.out.print("Nhap tai khoan email: ");
		this.email = sc.nextLine();
	}
	
	
	public SinhVienCNTT() {
		this.nhapThongTin();
	}
	
	public SinhVienCNTT(String mssv, String hoten, Date ngaysinh, String tkelcit, String mkelcit, String em) {
		super(mssv, hoten, ngaysinh);
		this.taikhoanElcit = tkelcit;
		this.matkhauElcit = mkelcit;
		this.email = em;
	}
	
	
	public String toString() {
		String result = super.toString();
		String thongtin;
		thongtin = "\nTai khoan elcit: " + this.taikhoanElcit + "\nMat khau elcit: " + this.matkhauElcit + "\nEmail: " + this.email;
		return result + thongtin;
	}
	
	
	public void doiMatKhau() {
		System.out.print("Nhap mat khau moi: ");
		this.matkhauElcit = sc.nextLine();
	}
	
	
	public String getEmail() {
		return this.email;
	}
}
