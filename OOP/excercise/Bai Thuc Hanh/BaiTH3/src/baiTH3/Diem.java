package baiTH3;

import java.util.Scanner;

public class Diem {
	public int x;
	public int y;
	
	public Diem() {
		this.nhapDiem();
	}
	
	public Diem(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		System.out.print("\nNhap toa do x: ");
		this.x = sc.nextInt();
		System.out.print("\nNhap toa do y: ");
		this.y = sc.nextInt();
	}
	
	public void hienThi() {
		System.out.print("(" + this.x + "," + this.y + ")");
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
	
	public void tinhTien(int dx, int dy) {
		this.x += dx;
		this.y += dy;
	}
	
	public float khoangCach(Diem d) {
		float result = (float) Math.sqrt(((this.x - d.giaTriX()) * (this.x - d.giaTriX())) * ((this.y - d.giaTriY()) * (this.y - d.giaTriY())));
		return result;
	}
}
