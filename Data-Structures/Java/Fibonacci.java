public class Fibonacci {
  public static int countFibonacci(int n)
  {
      if (n <= 1) { 
        return n;
      }
      return countFibonacci(n - 1) + countFibonacci(n - 2);
  }

  public static void main(String args[])
  {
      int n = 9;
      System.out.println(countFibonacci(n));
  }
}
