using System;
using System.Linq;
using System.Collections;

namespace OnlyRepeatElement
{
    public class GFG
    {
        static int binarySearch(int[] A, int start, int end, int n)
        {
            if(start > end) return -1;

            if(start == end) {
                if(start == 0) {
                    if(A[start] == A[start+1]) return A[start];
                }
                else if(A[end-1] == A[end]) return A[end];

                return -1;
            }

            int mid = start + (end - start)/2;

            if(A[mid] == mid+1) {
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
                
                if(A.Length == 1) {
                    Console.WriteLine("-1");
                }
                else {
                    Console.WriteLine("" + binarySearch(A, 0, A.Length-1, A.Length));
                }
            }
        }
    }
}