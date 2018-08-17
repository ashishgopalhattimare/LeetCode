using System;
using System.Linq;
using System.Collections;

namespace zeroCount
{
    public class GFG
    {
        static int binarySearch(int[] A, int start, int end, int n)
        {
            if(start > end) return 0;

            if(start == end && A[start] == 0) {
                return n-end;
            }

            int mid = start + (end - start)/2;

            if(A[mid] == 1) {
                return binarySearch(A, mid+1, end, n);
            }
            return binarySearch(A, start, mid, n);
        }

        public static void Main(String[] args)
        {
            int t;

            t = Int32.Parse(Console.ReadLine());
            while(t-- > 0) {
                int[] A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                
                Console.WriteLine("" + binarySearch(A, 0, A.Length-1, A.Length));
            }
        }
    }
}