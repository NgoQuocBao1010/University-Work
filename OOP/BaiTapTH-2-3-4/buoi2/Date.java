package ptcang.buoi2;

import java.util.Scanner;

public class Date {
	int d,m,y; 
	public Date(){
		d=m=y=0;
	}
	
	public Date(int d1, int m1, int y1){
		d=d1; m = m1; y=y1;
	}
	
	// copy constructor
	public Date(Date a){
		d=a.d; m = a.m; y=a.y;
	}
	
	private static int nhapSo(){
		int n=0; String s; boolean error=false;
		Scanner sc = new Scanner(System.in);

		do{
			s= sc.next();
			try{
				n = Integer.parseInt(s);				
				error=false;
				if(n<0) {
					System.out.print("Nhap lai mot so nguyen duong:");					
					error=true;
				}
			}
			catch(NumberFormatException e){
				System.out.print("Nhap lai mot so nguyen:");
				sc.nextLine();
				error=true;
			}

		}while(error);
		return n;
	}
	
	
	public void nhap(){
		System.out.print("Nhap ngay:");		
		d=nhapSo();
		System.out.print("Nhap thang:");
		m = nhapSo();
		System.out.print("Nhap nam:");
		y=nhapSo();
	}
	
	public void in(){
		System.out.printf("%d/%d/%d", d,m,y);
	}
	
	public String toString(){
		return  d + "/" + m + "/" + y;
	}
	
	public boolean hople(){
		boolean h=false;
		int max[] = {0, 31,28,31,30,31,30,31, 31,30,31,30,31};
		if(y%4==0) max[2] = 29;
		
		if(y>0 && m > 0 && m <13 && d > 0 && d<=max[m])
			h=true;

		return h;
	}
	
	public Date ngaySau(){
		Date a = new Date(d, m, y);
		int max[] = {0, 31,28,31,30,31,30,31, 31,30,31,30,31};
		if(y%4==0) max[2] = 29;
		
		a.d++ ; // tang ngay		
		if(a.d > max[a.m]) { 
			a.d = 1;
			a.m++; // tang thang
			if(a.m > 12){
				a.m = 1;
				a.y++; // tang nam
			}
		}
	
		return a;
	}
	
	
	public Date congNgay(int n){
		Date a = new Date(d, m, y);
		for(int i=0;i<n;i++)
			a=a.ngaySau();
		return a;
	}
	
	
	public static void main(String[] args) {
		Date a = new Date();
		a.nhap();
		a.in();
		
		if(a.hople()) System.out.println(" Ngay hop le");
		else System.out.println(" Ngay khong hop le");
		
		a = a.congNgay(20);
		a.in();

	}

}
