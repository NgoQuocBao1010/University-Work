package ptcang.buoi2;

public class SDDiem {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

Diem a,b;
		
		System.out.println("Tao doi tuong \n");
		a = new Diem();
		b = new Diem(5,3);
		
		System.out.println("\nNhap Toa do a: ");
		a.nhap();
		
		System.out.println("Toa do a: ");
		a.in();
		
		System.out.println("Toa do b: ");
		b.in();
		
		System.out.println("Khoang cach a: "  + a.kcach());
	}

}
