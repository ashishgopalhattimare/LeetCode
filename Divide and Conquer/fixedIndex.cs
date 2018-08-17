using System;
using System.Linq;
using System.Collections;

namespace BinarySearch
{
    public class fixedIndex {
    
	    static int binarySearch(int[] A, int start, int end)
        {
            if(start > end) return -1;

            int mid = start + (end-start)/2;
            
            if(A[mid] == mid+1) return mid+1;

            if(A[mid] < mid+1) {
                return binarySearch(A, mid+1, end);
            }
            return binarySearch(A, start, mid-1);
        }

        static public void Main(String[] args)
        {
            int t, n;

            t = Int32.Parse(Console.ReadLine());
            while(t-- > 0) {
                n = Int32.Parse(Console.ReadLine());

                int[] arr = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                
                Console.WriteLine("{0}", binarySearch(arr, 0, n-1));
            }
        }
    }
}