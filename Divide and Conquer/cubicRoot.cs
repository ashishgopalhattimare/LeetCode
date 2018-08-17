using System;
using System.Linq;
using System.Collections;

namespace CubicRoot
{
    public class GFG
    {
        static double binarySearch(double start, double end, double n)
        {
            double mid = start + (end-start)/2;

            if(n - mid*mid*mid <= 0.0000001 || mid*mid*mid - n <= 0.0000001) {
                return mid;
            }

            if(mid*mid*mid > n) {
                return binarySearch(start, mid, n);
            }
            return binarySearch(mid, end, n);
        }

        public static void Main(String[] args)
        {
            int t;
            double n;
            t = Int32.Parse(Console.ReadLine());
            while(t-- > 0) {
                n = Convert.ToDouble(Console.ReadLine());

                Console.WriteLine("" + binarySearch(0, n, n));
            }
        }
    }
}