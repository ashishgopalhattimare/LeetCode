using System;
using System.Linq;
using System.Collections;

namespace Peak1D
{
    public class GFG
    {
        static int binarySearch(int[] A, int start, int end, int n)
        {
            if(start > end) return -1;

            // two elements
            if(end == start+1) {
                if(start == 0 && A[start] > A[start+1]) {
                    return A[start];
                }
                else if(n == end+1 && A[end-1] < A[end]) {
                        return A[end];
                }
                else {
                    if(A[start] > A[end]) return A[start];
                    return A[end];
                }
            }

            int mid = start + (end - start)/2; // more than 2 elements in the range

            if(A[mid-1] < A[mid] && A[mid] > A[mid+1]) {
                return A[mid];
            }

            if(A[mid-1] <= A[mid]) {
                return binarySearch(A, mid, end, n);
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
                    Console.WriteLine("" + A[0]);
                }
                else {
                    Console.WriteLine("" + binarySearch(A, 0, A.Length-1, A.Length));
                }
            }
        }
    }
}