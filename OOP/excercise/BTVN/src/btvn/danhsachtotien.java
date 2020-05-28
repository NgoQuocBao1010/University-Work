package btvn;

import java.util.Scanner;

public class danhsachtotien {
	private int soluong;
	private totien[] danhSach;
	private Scanner sc = new Scanner(System.in);
	
	public danhsachtotien() {
		this.nhap();
	}
	
	public danhsachtotien(totien a, totien b, totien c) {
		this.soluong = 3;
		this.danhSach = new totien[this.soluong];
		
		this.danhSach[0] = a;
		this.danhSach[1] = b;
		this.danhSach[2] = c;
	}
	
	public void nhap() {
		System.out.print("Nhap so to tien: ");
		soluong = sc.nextInt();
		danhSach = new totien[soluong];
		
		for (int i=0; i<soluong; i++) {
			System.out.println("Nhap menh gia cua to tien thu " + (i + 1) + ": ");
			int tien = sc.nextInt();
			totien moi = new totien(tien);
			danhSach[i] = moi;
		}
	}
	
	public void in() {
		System.out.println("(");
		for (int i=0; i<soluong; i++) {
			danhSach[i].in();
		}
		System.out.println(")");
	}
	
	public void sapXepDanhSach() {
		for (int i=0; i<this.soluong-1; i++) {
			for (int j=i+1; j<this.soluong; j++) {
				if (this.danhSach[i].value < this.danhSach[j].value) {
					totien tmp = this.danhSach[i];
					this.danhSach[i] = this.danhSach[j];
					this.danhSach[j] = tmp;
				}
			}
		}
	}
	
	public void greedyMethod(int tongSoTien) {
		this.sapXepDanhSach();
		
		int i=0;
		int sodu = 0;
		while (true) {
			int menhgia = this.danhSach[i].value;
			
			int soTo = tongSoTien / menhgia;

			this.danhSach[i].setSoTo(soTo);
			
			sodu = tongSoTien % menhgia;
			
			if (i == this.soluong - 1) {
				if (sodu == 0)
					break;
				else {
					
					tongSoTien += this.danhSach[i - 1].tongSoTien();
					this.danhSach[i - 1].setSoTo(0);
					soTo = tongSoTien / menhgia;
					this.danhSach[i].setSoTo(soTo);
//					System.out.println("Con du");
					break;
				}
			}
			tongSoTien = sodu;
			i++;
		}
//		System.out.println(sodu);
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		totien a = new totien(100000);
		totien b = new totien(50000);
		totien c = new totien(20000);
		
		danhsachtotien bt = new danhsachtotien(a, b, c);
//		bt.sapXepDanhSach();
		bt.greedyMethod(430000);
		bt.in();
	}

}
