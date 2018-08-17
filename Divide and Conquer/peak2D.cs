using System;
using System.Linq;
using System.Collections;

namespace Peak2D
{
    public class GFG
    {
        int maxim;

        static int binarySearch(int[,] A, int i, int start, int end, int n)
        {
            if(start > end) return -1;

            // two elements
            if(end == start+1) {

                if(start == 0 && A[i][start] > A[i][start+1]) {
                    return A[start];
                }
                else if(n == end+1 && A[i][end-1] < A[i][end]) {
                        return A[end];
                }
                else {
                    if(A[i][start] > A[i][end]) return A[i][start];
                    return A[end];
                }
            }

            int mid = start + (end - start)/2;

            if(A[i][mid-1] < A[i][mid] && A[i][mid] > A[i][mid+1]) {
                if(i == 0 && A[i+1][mid] < A[i][mid]) {
                    maxim = Math.Max(maxim, A[i][mid]);
                }
                else if(i == n-1 && A[i-1][mid] < A[i][mid]) {
                    maxim = Math.Max(maxim, A[i][mid]);
                }
                else {
                    if(A[i-1][mid] < A[i][mid] && A[i][mid] > A[i+1][mid]) {
                        maxim = Math.Max(maxim, A[i][mid]);
                    }
                }
            }

            if(A[i][mid-1] <= A[i][mid]) {
                binarySearch(A, i, mid, end, n);
                return;
            }

            binarySearch(A, i, start, mid, n);
            return;
        }
        public static void Main(String[] args)
        {
            int t;
            int n, m;

            t = Int32.Parse(Console.ReadLine());

            while(t-- > 0) {
                int[] nums = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                
                n = nums[0];
                m = nums[1];

                int A[,] = new int[n, m];

                maxim = A[0][0];
                for (int i = 0; i < n; i++) {
                    binarySearch(A, i, 0, m-1, n);
                }

                Console.WriteLine(maxim);
            }
        }
    }
}