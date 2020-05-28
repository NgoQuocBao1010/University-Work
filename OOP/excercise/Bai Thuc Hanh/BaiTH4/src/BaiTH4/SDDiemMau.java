package BaiTH4;

public class SDDiemMau {
	public static void cau1() {
		DiemMau a = new DiemMau(5, 10, "trang");
		a.hienThi();
	}
	
	public static void cau2() {
		DiemMau b = new DiemMau();
		b.GanMau("vang");
		b.x = b.x + 10;
		b.y = b.y + 8;
		b.hienThi();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		cau1();
//		cau2();
	}

}
