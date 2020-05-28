package btvn;
import java.io.*;
public class process implements Comparable<process>, Serializable {
	public String name;
	public int arrivalTime;
	public int cpuTime;
	
	
	public process(String name, int arrTime, int cputime) {
		this.name = name;
		this.arrivalTime = arrTime;
		this.cpuTime = cputime;
	}
	
	public int getCPUTime() {
		return this.cpuTime;
	}
	
	public int compareTo(process other) {
		if (this.cpuTime > other.cpuTime) return 1;
		else if (this.cpuTime < other.cpuTime) return -1;
		return 0;
	}
	
	public String toString() {
		String result = "(" + this.name + ", " + this.arrivalTime + ", " + this.cpuTime + ")";
		return result;
	}
}
