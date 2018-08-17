using System;
using System.Dynamic;
using System.Linq;

namespace Template
{ 
  public class GFG
  {
    public static void Main(String[] args)
    {
      int t;
      int k;
      
      t = Int32.Parse(Console.ReadLine());

      while (t-- > 0)
      {
        int[] A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        k = Int32.Parse(Console.ReadLine()); 
        
        Console.WriteLine(binarySearch(A, 0, A.Length-1, k));
      }
    }

    private static int binarySearch(int[] A, int start, int end, int k)
    {
      if (start > end) return -1;

      if (start == end)
      {
        if (A[start] == k) return start;
        else return -1;
      }

      int mid = start + (end - start) / 2;

      if (A[mid] == k) return mid;

      // left half is sorted
      if (A[start] <= A[mid])
      {
        if (k >= A[start] && k < A[mid])
        {
          return binarySearch(A, start, mid-1, k);
        }
        return binarySearch(A, mid+1, end, k);
      }
      else if (k > A[mid] && k <= A[end])
      {
        return binarySearch(A, mid+1, end, k);
      }
      return binarySearch(A, start, mid - 1, k);
    }
  }
}