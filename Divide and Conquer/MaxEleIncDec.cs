using System;
using System.Linq;
using System.Collections;

namespace MaxElement
{
    class GFK
    {
        static int binarySearch(int[] A, int start, int end)
        {
            if(start > end) return -1;

            if(start == end) return A[end];

            if(end == start+1 && A[end] >= A[start]) return A[end];
            if(end == start+1 && A[end] < A[start]) return A[start];

            int mid = start + (end-start)/2;
            
            if(A[mid-1] <= A[mid] && A[mid] > A[mid+1]) return A[mid];
            else if(A[mid-1] <= A[mid]) {
                return binarySearch(A, mid, end);
            }
            return binarySearch(A, start, mid-1);
        }

        static public void Main(String[] args)
        {
            int t;

            t = Int32.Parse(Console.ReadLine());
            while(t-- > 0) {
                int[] A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                
                Console.WriteLine("" + binarySearch(A, 0, A.Length-1));
            }
        }
    }
}