// https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/shift-and-replace-d96fc236/
// Set 2
// March Circuit '20

import java.util.*;

class Data
{
    int total, shift;
    int count;
    public Data(int t, int s, int c) {
        total = t; shift = s;
        count = c;
    }
    public int result() {
        return (shift + total-count);
    }
}

// MIN-HEAP
class DataCompare implements Comparator<Data> {
    
    public int compare(Data d1, Data d2)
    {
        int dd1 = d1.shift + (d1.total - d1.count);
        int dd2 = d2.shift + (d2.total - d2.count);
        
        // If the (shift + rotation) are same, then give priority to
        // the smaller shift value (or index)
        if(dd1 == dd2) {
            if(d1.shift < d1.shift) {
                return -1;
            }
            else if(d1.shift > d1.shift) {
                return 1;
            }
            return 0;
        }
        if(dd1 < dd2) return -1;
        return 1;
    }
}

public class ShiftReplace
{
    // How far is the element from the actual position
    public static int rotateLeft(int X, int N, int i) {
        if(X < i) return i-X;
        else if(X > i) return (i-1) + 1 + (N-X);

        return 0;
    }

    // Get the count of each element to be shifted to get into
    // its perfect location if in range [1..N]

    /**
        10
        [    10 4  6  1  2  3  6  8 10 12 ] -> actual arr 
        [ 0  1  2  3  4  5  6  7  8  9 10 ] -> required position

        [ 1  2  0  3  0  0  0  1  1  1  0 ] -> shifts arr

        // Shift Arr : 
        //      Each index signifies how rotateLeft() are required to 
        //      place arr[i] to its required position.
        //      shifts[i] = There are shifts[i] elements which are
        //                  'i' rotationLeft() far from its required position
    **/
    public static void algoShifts(int[] arr, int[] shifts, int N)
    {
        for(int i = 0; i < shifts.length; i++) {
            shifts[i] = 0;
        }
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] <= N) {
                shifts[rotateLeft(arr[i], N, i)]++;
            }
        }
    }

    public static void main(String[] args) throws Exception
    {
        try {
            Scanner scan = new Scanner(System.in);

            int n = scan.nextInt();

            int[] arr = new int[n+1];
            for(int i = 1; i <= n; i++) {
                arr[i] = scan.nextInt();
            }

            int[] shifts = new int[n+1];

            algoShifts(arr, shifts, n); // : O(n)

            PriorityQueue<Data>pq = new PriorityQueue<>(new DataCompare());
            HashMap<Integer, Data>mapi = new HashMap<>();

            for(int i = 0; i < shifts.length; i++) {
                Data data = new Data(n, i, shifts[i]);
                mapi.put(i, data);
                pq.add(data);
            }

            int q = scan.nextInt();
            int x, b;

            Data data;
            while(q-- > 0) // O(Q)
            {
                x = scan.nextInt(); b = scan.nextInt();

                // Decrement the count of the shift of arr[x] by 1 : O(logn)
                if(arr[x] <= n) {
                    int ii = rotateLeft(arr[x], n, x);
                    data = mapi.get(ii);

                    data.count--;
                }
                arr[x] = b;

                // Increment the count of the shift of arr[x] by 1 : O(logn)
                if(arr[x] <= n) {
                    int ii = rotateLeft(arr[x], n, x);
                    data = mapi.get(ii);

                    data.count++;
                }
                
                // Get the minimum (shift+rotations) required to make the Identity Array
                System.out.println(pq.peek().result()); // : O(1)
            }
        }
        catch(Exception e) {}
    }
}