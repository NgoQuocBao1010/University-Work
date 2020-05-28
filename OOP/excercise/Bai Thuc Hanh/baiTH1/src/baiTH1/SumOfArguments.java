package baiTH1;

public class SumOfArguments {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double sum = 0.0;
		double n = 0.0;
		
		for (String x: args) {
			try {
				n = Double.parseDouble(x);
			}
			catch (NumberFormatException e) {
				n = 0;
			}
			sum += n;
		}
		System.out.println(n);
	}

}
