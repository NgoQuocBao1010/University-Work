package ptcang.buoi4;
import java.util.Scanner;

import ptcang.buoi2.Diem;

public class DiemMau extends Diem {
	private String mau;
	
	public DiemMau(){
		super();
		mau = new String(); //<-> mau="";
	}
	
	public DiemMau(int x1, int y1, String mau1){
		super(x1,y1);
		mau = new String(mau1);
	}
	
	public DiemMau(DiemMau dm){
		super((Diem) dm);
		mau = new String(dm.mau);
	}
	
	public void nhap(){		
		super.nhap();
		System.out.print("\n Nhap mau cho diem: ");
		Scanner sc = new Scanner (System.in);
		mau = sc.nextLine();		
	}
	
	public void in(){
		super.in();
		System.out.print(", mau cua diem: " + mau);
	}
	
	public void ganMau(String mau1){
		mau = new String(mau1);
	}
	
	private static void test(){
		
	}
	
	public void test1(){
		System.out.print("Goi DiemMau::test 1 ");	
	}
	
	public void test2(){
		System.out.print("Goi DiemMau::test 2 ");	
	}


}
