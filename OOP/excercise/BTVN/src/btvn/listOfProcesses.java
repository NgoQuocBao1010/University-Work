package btvn;
import java.util.*;

public class listOfProcesses {
	public process[] list = new process[1000];
	public String[] result = new String[10000];
	public int numOfProcesses;
	private Scanner sc = new Scanner(System.in);
	PriorityQueue<process> cpuTimeQueue = new PriorityQueue<process>();
	
	public listOfProcesses() {
	}
	
	private void sortList() {
		for (int i=0; i<this.numOfProcesses-1; i++) {
			for (int j=i+1; j<this.numOfProcesses; j++) {
				if (this.list[i].arrivalTime > this.list[j].arrivalTime) {
					process tmp = this.list[i];
					this.list[i] = this.list[j];
					this.list[j] = tmp;
				}
			}
		}
	}
	
	public void nhap() {
		System.out.print("Nhap so tien trinh: ");
		this.numOfProcesses = sc.nextInt();
		
		for (int i=0; i<this.numOfProcesses; i++) {
			System.out.print("Nhap tien trinh thu "+ (i + 1) + ": ");
			String name = sc.next();
			int arrTime = sc.nextInt();
			int cpuTime = sc.nextInt();
			System.out.println("");
			process newPro = new process(name, arrTime, cpuTime);
			list[i] = newPro;
		}
		this.sortList();
	}
	
	public void printList() {
		for (int i=0; i<this.numOfProcesses; i++) {
			System.out.print(list[i] + "\t");
		}
	}
	
	private void print(int seconds) {
		for (int i=0; i<seconds; i++) {
			System.out.print(result[i] + ", " + i + "||  ");
		}
	}
	
	private boolean completed() {
		for (int i=0; i<this.numOfProcesses; i++) {
			if (list[i].cpuTime != 0) return false;
		}
		return true;
	}
	
	public void solve() {
		int second = 0;
		
		while (!this.completed()) {
			for (int i=0; i<this.numOfProcesses; i++) {
				if (list[i].arrivalTime == second)
					this.cpuTimeQueue.add(list[i]);
			}
			
			if (this.cpuTimeQueue.isEmpty()) {
				result[second] = "None";
			}
			else {
				process working = this.cpuTimeQueue.poll();
				result[second] = working.name;
				working.cpuTime--;
				
				if (working.cpuTime > 0) this.cpuTimeQueue.add(working);
			}
//			System.out.println(5);
			second++;
		}
		this.print(second);
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		listOfProcesses bai1 = new listOfProcesses();
		bai1.nhap();
		bai1.solve();
//		System.out.println("");
//		bai1.printList();
	}

}
