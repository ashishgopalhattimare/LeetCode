using System;
using System.Linq;
using System.Collections;

namespace ExtraElement
{
    public class GFG
    {
        static ref int binarySearch(int[] A, int[] B, int start, int end, ref int index)
        {
            if(start > end) return ref index;

            int mid = start + (end - start)/2;

            if(A[mid] == B[mid]) {
                return ref binarySearch(A, B, mid+1, end, ref index);
            }

            index = mid;
            return ref binarySearch(A, B, start, mid-1, ref index);
        }

        public static void Main(String[] args)
        {
            int t;

            t = Int32.Parse(Console.ReadLine());
            while(t-- > 0) {
                int[] A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                int[] B = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

                int index = 0;
                Console.WriteLine("" + binarySearch(A, B, 0, B.Length-1, ref index));
            }
        }
    }
}