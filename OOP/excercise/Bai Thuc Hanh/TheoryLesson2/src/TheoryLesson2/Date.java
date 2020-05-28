package TheoryLesson2;
import java.util.Scanner;

public class Date {
	private int day, month, year;
	
	public Date() {
		this.collectInfo();
	}
	
	public Date(int d, int m, int y) {
		this.day = d;
		this.month = m;
		this.year = y;
		
		if (!this.hopLe()) {
			System.out.println("Thong tin khong hop le, xin nhap lai!!");
			this.collectInfo();
		}
	}
	
	public void collectInfo() {
		Scanner sc = new Scanner(System.in);
		System.out.print("\nNhap vao thong tin ngay, thang va nam: ");
		this.day = sc.nextInt();
		this.month = sc.nextInt();
		this.year = sc.nextInt();
		
		if (!this.hopLe()) {
			System.out.println("Thong tin khong hop le, xin nhap lai!!");
			this.collectInfo();
		}
	}
	
	public void setDay(int day) {
		this.day = day;
	}
	
	public void setMonth(int month) {
		this.month = month;
	}
	
	public void setYear(int year) {
		this.year = year;
	}
	
	public int getDay() {
		return this.day;
	}
	
	public int getMonth() {
		return this.month;
	}
	
	public int getYear() {
		return this.year;
	}
	
	public void display() {
		System.out.println(this.day + "/" + this.month + "/" + this.year);
	}
	
	private boolean checkForLeapYear() {
		if (this.year % 400 == 0) return true;
		
		if (this.year % 4 == 0 && this.year % 100 != 0) return true;
		
		return false;
	}
	
	private int lastDayInMonth() {
		int[] months30 = {4, 6, 9, 11};
		
		for (int month: months30) {
			if (this.month == month) return 30;
		}
		
		if (this.month == 2) {
			if (this.checkForLeapYear()) return 29;
			else return 28;
		}
		
		return 31;
	}
	
	public boolean hopLe() {
		if (this.day <= 0 || this.month <= 0 || this.year <= 0) return false;
		
		if (this.day > 31 || this.month > 12) return false;
		
		if (this.day > this.lastDayInMonth()) return false;
		return true;
	}
	
	public Date nextDay() {
		Date newDate = new Date(this.day, this.month, this.year);
		
		if (this.day == this.lastDayInMonth()) {
			if (this.month == 12) {
				newDate.setDay(1);
				newDate.setMonth(1);
				newDate.setYear(newDate.getYear() + 1);
			}
			else {
				newDate.setDay(1);
				newDate.setMonth(newDate.getMonth() + 1);
			}
		}
		else {
			newDate.setDay(newDate.getDay() + 1);
		}
		
		return newDate;
	}
	
	public Date plusDays(int days) {
		Date newDate = new Date(this.day, this.month, this.year);
		int daysTotal = this.day + days;
		
		while (daysTotal > newDate.lastDayInMonth()) {
			daysTotal -= newDate.lastDayInMonth();
			if (newDate.getMonth() == 12) {
				newDate.setMonth(1);
				newDate.setYear(newDate.getYear() + 1);
			}
			else {
				newDate.setMonth(newDate.getMonth() + 1);
			}
		}
		newDate.setDay(daysTotal);
		return newDate;
	}
}
