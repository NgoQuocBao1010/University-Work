package btvn;

import java.util.Scanner;

public class totien {
	public int value;
	private String unit = "VND";
	private int numbers = 0;
	private Scanner sc = new Scanner(System.in);
	
	public totien() {
		value = 0;
		numbers = 0;
	}
	
	public totien(int value) {
		numbers = 0;
		this.value = value;
	}
	
	public void nhap() {
		System.out.print("Nhap menh gia tien: ");
		value = sc.nextInt();
	}
	
	public void in() {
		System.out.println(this.numbers + " to " + this.value + " " + this.unit);
	}
	
	public void setSoTo(int soTo) {
		this.numbers = soTo;
	}
	
	public int getSoTo() {
		return this.numbers;
	}
	
	public int tongSoTien() {
		return numbers * value;
	}
}
