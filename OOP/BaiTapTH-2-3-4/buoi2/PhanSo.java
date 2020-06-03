package ptcang.buoi2;

import java.util.Scanner;

public class PhanSo {
	private int tuso, mauso;
	
	public PhanSo(){
		tuso = 0;
		mauso = 1;
	}
	public PhanSo(int t, int m){
		tuso = t;
		mauso = m;
	}
	
	public PhanSo(PhanSo p){
		tuso = p.tuso;
		mauso = p.mauso;		
	}
	
	public void nhapphanso(){
		Scanner input = new Scanner(System.in);
		System.out.print("\n nhap tu so : " );
		tuso=input.nextInt();
		System.out.print("\n nhap mau so : " );
		mauso=input.nextInt();
		while(mauso==0){
			System.out.print("\nnhap lai mau so : ");
			mauso=input.nextInt();
		}
			
	}
	
	public void hienthi(){
		
		if(tuso==0) System.out.print("0");
		else if(mauso==1 || tuso==mauso) System.out.print(tuso/mauso);
		     else
		    	  { if(mauso*tuso <0) System.out.print("-");
		    	    System.out.printf(" %d/%d ", (int)Math.abs(tuso), (int)Math.abs(mauso));
		    	  }
					
	}
	
	public int layT(){
		return tuso;
	}
	
	public int layM(){
		return mauso;
	}
	
	public void gan(int t, int m){
		tuso=t;
		mauso=m;
	}
	
	public static int UCLN(int a, int b){
		while(a!= b){
			if(a>b) a= a-b;
			else b= b-a;
		}
		return (a);
	}
	
	public void toiGian(){
		int us = UCLN(tuso, mauso);
		tuso = tuso/us;
		mauso = mauso/us;
	}
	
	public void nghichdao(){
		if(tuso==0) System.out.println("\n Loi do tu so=0, khong ton tai phan so nghich dao"); 
		else {
			int t;
			t=tuso;
			tuso=mauso;
			mauso=t;
		}		
	}
	public float giatringhichdao(){
		return ((float) mauso)/tuso;
		
		
	}
	public float giatrithuc(){
		return ((float) tuso)/ mauso;
	}
	public boolean lonhon(PhanSo a){
		return giatrithuc() > a.giatrithuc();		
	}

	public PhanSo cong(PhanSo a){
		int tu1= (tuso*a.mauso) +(a.tuso*mauso);
		int mau1=a.mauso*mauso;
		return new PhanSo(tu1,mau1);
		
	}
	public PhanSo tru(PhanSo a){
		int tu1= (tuso*a.mauso)  - (a.tuso*mauso);
		int mau1=a.mauso*mauso;
		return new PhanSo(tu1, mau1);		
	}
	public PhanSo nhan(PhanSo a){
		return new PhanSo(tuso*a.tuso, mauso*a.mauso);
	}
	public PhanSo chia(PhanSo a){
		return new PhanSo(tuso*a.mauso, mauso*a.tuso);
	}
	public PhanSo cong(int a){
		int tu1= tuso + a*mauso;
		int mau1=mauso;
		return new PhanSo(tu1,mau1);
	}
	public PhanSo tru(int a){
		int tu1= tuso - a*mauso;
		int mau1=mauso;
		return new PhanSo(tu1,mau1);
	}
	public PhanSo nhan(int a){
		return new PhanSo(tuso*a, mauso);
	}
	public PhanSo chia(int a){
		return new PhanSo(tuso, mauso*a);
	}
	

	 
}
