public class Main {
	static int a = 10;
	public static void main(String[] args) {
		System.out.println(String.valueOf(a*f(1)+a));
	}
	public static int f(int x){
		a = a + 1;
		return x*a;
	}
}