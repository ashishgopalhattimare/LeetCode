using System;
using System.Linq;
using System.Collections;

namespace RotationCount
{
    public class GFG
    {
        static int binarySearch(int[] A, int start, int end)
        {
            if(start > end) return -1;

            #region **Collapse Section**

            // if(end == start + 1) {
            //     if(A[start] > A[end]) {
            //         Console.WriteLine("Rotation Count : {0}", end);
            //         return A[end];
            //     }
            //     Console.WriteLine("Rotation Count : {0}", start);
            //     return A[start];
            // }

            #endregion

            int mid = start + (end - start)/2;

            // Check the mid three elements
            if(A[mid] > A[mid+1]) {
                Console.WriteLine("Rotation Count : {0}", mid+1);
                return A[mid+1];
            }
            else if(A[mid-1] > A[mid]) {
                Console.WriteLine("Rotation Count : {0}", mid);
                return A[mid];
            }

            if(A[mid] < A[end]) {
                return binarySearch(A, start, mid-1);
            }
            return binarySearch(A, mid+1, end);
        }

        public static void Main(String[] args)
        {
            int t;

            t = Int32.Parse(Console.ReadLine());
            while(t-- > 0) {
                int[] A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

                Console.WriteLine("" + binarySearch(A, 0, A.Length - 1));
            }
        }
    }
}