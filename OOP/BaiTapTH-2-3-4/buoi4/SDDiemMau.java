package ptcang.buoi4;
import ptcang.buoi2.Diem;

public class SDDiemMau {
	public static void main(String args[]){
		DiemMau A= new DiemMau(5,10,"Trang");
		A.in();
		
		DiemMau B= new DiemMau();
		B.nhap();
		
		System.out.print("Diem B da tinh tien 10,8 va doi mau Vang:\n");
		B.tinhtien(10, 8);
		B.ganMau("Vang");
		
		B.in();
		// Khong the goi ham bi de tu cha B.super.in();
		
		System.out.print("\nGoi ham sao chep cho C(B)\n");
		DiemMau C = new DiemMau(B);
		C.in();
		
		
		
		//tham chieu cua cha 
		Diem p;
		p=new Diem();
		p=new DiemMau();
		
		p.test1(); // goi DiemMau::test1 vi nap de
		//p.test2(); // DiemMau::test2 khong nap de phuong thuc cha nen ko goi duoc
		
		//tham chieu cua con 
		DiemMau pm;
		// -> Sai: pm=new Diem();
		pm=new DiemMau();
		
		//Mang
		System.out.print("\n Tao mang Diem bat ky (Diem hay DiemMau) \n");
		Diem a[] = new Diem[2];
		a[0] = new Diem(1,2);
		a[1] = new DiemMau(5,7,"Tim");
		

		a[0].in();
		a[1].in();
		
		p = a[1];		
		p.in();
		
		
		p.test1();
		//p.test2();
		
		
		
		
		
	
	}

}
