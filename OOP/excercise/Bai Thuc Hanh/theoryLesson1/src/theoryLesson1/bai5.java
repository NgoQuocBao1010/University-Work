package theoryLesson1;

public class bai5 {
	private static float x;
	private static float x1;
	private static float x2;
	private static float a;
	private static float c;
	private static float b;
	private static float delta;
	
	public bai5(float a, float b) {
		// ax + b = 0
		bai5.a = a;
		bai5.b = b;
		if (a == 0) {
			return;
		}
		
		bai5.x = (float) - bai5.b / bai5.a;
	}
	
	public bai5 (float a, float b ,float c) {
		// ax binh + bx + c = 0
		bai5.a = a;
		bai5.b = b;
		bai5.c= c;
		
		delta = (float) b * (float) b - 4 * (float) a * (float) c;
		
		if (delta == 0) {
			bai5.x1 = (float) -b / 2 * (float) a;
		}
		
		else if (delta > 0) {
			bai5.x1 = (-b + (float) Math.sqrt(delta)) / 2 * a;
			bai5.x2 = (-b - (float) Math.sqrt(delta)) / 2 * a;
		}
		
		else {
			return;
		}
	}
	
	public static void giaiptbac1() {
		if (a == 0) {
			System.out.println("Phuong trinh vo nghiem!!");
		}
		System.out.println("Ket qua cua phuong trinh la: " + bai5.x);
	}
	
	public static void giaiptbac2() {
		if (delta > 0) {
			System.out.println("Ket qua cua phuong trinh la: x1: " + x1 + " , x2: " + x2);
		}
		else if (delta == 0) {
			System.out.println("Ket qua cua phuong trinh la: x1: " + x1);
		}
		else {
			System.out.println("Phuong trinh vo nghiem!!");
		}
	}
}
