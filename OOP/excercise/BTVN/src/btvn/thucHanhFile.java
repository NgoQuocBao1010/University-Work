package btvn;
import java.io.*;
import java.util.*;

public class thucHanhFile {
	
	public static void saveProcessObject(int numOfProcesses) {
		Scanner sc = new Scanner(System.in);
		try {
			FileOutputStream file = new FileOutputStream("D:\\InformationTec\\Java\\BTVN\\src\\btvn\\text.txt");
			ObjectOutputStream obj = new ObjectOutputStream(file);
			
			for (int i=0; i<numOfProcesses; i++) {
				System.out.print("Nhap arrival time va cpu time process thu " + (i+1) + ": ");
				String name = "p" + (i+1);
				int arrTime = sc.nextInt();
				int cpuTime = sc.nextInt();
				process p = new process(name, arrTime, cpuTime);
				obj.writeObject(p);
			}
			
			obj.close();
		} 
		catch (IOException ex) {
			ex.printStackTrace();
		}
	}
	
	public static process[] readProcesses(int numOfProcesses) {
		process[] result = new process[numOfProcesses];
		try {
			FileInputStream file = new FileInputStream("D:\\InformationTec\\Java\\BTVN\\src\\btvn\\text.txt");
			ObjectInputStream obj = new ObjectInputStream(file);
			
			for (int i=0; i<numOfProcesses; i++) {
				process p = (process) obj.readObject();
				result[i] = p;
			}
			obj.close();
		}
		catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		catch (IOException ex) {
			ex.printStackTrace();
		}
		return result;
	}
	
	public static void main(String[] args) {
		saveProcessObject(3);
		process[] result = readProcesses(3);
		
		for (int i=0; i<3; i++) {
			System.out.println(result[i].toString());
		}
	}
}
