package BaiTH4;

import java.util.Scanner;

public class Diem {
	public int x;
	public int y;
	protected Scanner sc = new Scanner(System.in);
	
	public Diem() {
		this.x = 0;
		this.y = 0;
	}
	
	public Diem(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public void nhapDiem() {
		System.out.print("\nNhap toa do x: ");
		this.x = sc.nextInt();
		System.out.print("\nNhap toa do y: ");
		this.y = sc.nextInt();
	}
	
	public void hienThi() {
		System.out.println("(" + this.x + "," + this.y + ")");
	}
	
	public int giaTriX() {
		return this.x;
	}
	
	public int giaTriY() {
		return this.y;
	}
	
	public float khoangCach() {
		float result = (float) Math.sqrt(this.x * this.x + this.y * this.y);
		return result;
	}
	
	public float khoangCach(Diem d) {
		float result = (float) Math.sqrt(((this.x - d.giaTriX()) * (this.x - d.giaTriX())) * ((this.y - d.giaTriY()) * (this.y - d.giaTriY())));
		return result;
	}
}
