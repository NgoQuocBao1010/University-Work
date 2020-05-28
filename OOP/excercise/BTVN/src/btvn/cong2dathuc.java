package btvn;
import java.util.Scanner;
public class cong2dathuc {
	public int sodathuc;
	public dathuc[] danhsachdathuc = new dathuc[1000];
	public dathuc result = new dathuc();
	private Scanner sc = new Scanner(System.in);
	
	public cong2dathuc() {
		
	}
	
	public void nhap() {
		System.out.print("Nhap so da thuc muon cong: ");
		this.sodathuc = sc.nextInt();
		int max = -1;
		
		for (int i=0; i<this.sodathuc; i++) {
			System.out.println("Nhap da thuc thu " + (i+1) + ": ");
			dathuc moi = new dathuc();
			moi.nhap();
			
			this.danhsachdathuc[i] = moi;
			if (max < moi.bacCaoNhat) max = moi.bacCaoNhat;
		}
		
		this.result = new dathuc(max);
//		System.out.println(this.result.bacCaoNhat);
	}
	
	public void congDathuc() {
//		System.out.println(this.result.bacCaoNhat);
		this.nhap();
		
		for (int i=0; i<=this.result.bacCaoNhat; i++) {
			for (int j=0; j<this.sodathuc; j++) {
				if (i>this.danhsachdathuc[j].bacCaoNhat) continue;
				result.danhSachPhanTu[i] += this.danhsachdathuc[j].danhSachPhanTu[i];
			}
		}
		this.result.in();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		cong2dathuc a = new cong2dathuc();
		a.congDathuc();
	}

}
