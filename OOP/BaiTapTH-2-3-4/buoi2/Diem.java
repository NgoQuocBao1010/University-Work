package ptcang.buoi2;

import java.util.Scanner;

public class Diem {
	private int x;
	private int y;
	
	public Diem(){
		this.x=this.y=0;
		//System.out.println("Goi ham xay dung 1");
	}
	
	public Diem(int x, int y){
		this.x=x;
		this.y=y;
		//System.out.println("Goi ham xay dung 2");
	}
	
	// copy constructor
	public Diem(Diem d){
		x=d.x;
		y=d.y;
	}
	
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap x=");
		x= sc.nextInt();
		System.out.print("Nhap y=");
		y= sc.nextInt();		
	}
	
	public void in(){
		System.out.printf("(%d,%d)", x, y);
	}

	public void gan(int x, int y){
		this.x=x;
		this.y=y;
	}
	
	public void tinhtien(int dx, int dy){
		this.x += dx;
		this.y += dy;
	}
	
	public double kcach(){
		return Math.sqrt(Math.pow(x,2) + Math.pow(y,2));
	}
	
	public double kcach(Diem d){
		return Math.sqrt(Math.pow(x-d.x,2) + Math.pow(y - d.y,2));
	}
	
	private static void test(){
		
	}
	
    boolean equals(Diem d){
		return x==d.x && y==d.y;
	}

	public static void main(String[] args) {	
		Diem a,b, c;
		
		System.out.println("Tao doi tuong \n");
		a = new Diem();
		b = new Diem(5,3);
		/*
		System.out.println("\nNhap Toa do a: ");
		a.nhap();
		
		System.out.println("Toa do a: ");
		a.in();
		
		System.out.println("Toa do b: ");
		b.in();
		
		System.out.println("Khoang cach a: "  + a.kcach());*/
		
		c = new Diem(5,3);
		
		if(c.compareTo(b)) System.out.println("Hai diem bang nhau: ");
		else System.out.println("Hai diem khac nhau: ");

	}

}
