// package leetcode.ashish_gopal;
import java.util.ArrayList;

class FenwickTree
{
    private ArrayList<Integer> fenwick;
    private int[] initial;

    public FenwickTree(int[] arr) {

        // Start the array from index 1 : append 0 at the beginning
        fenwick = new ArrayList<>(arr.length+1);
        fenwick.add(0);
        for(int i = 0; i < arr.length; i++) {
            fenwick.add(arr[i]);
        }

        // copy the given array
        initial = arr;
    }

    /**
     * Display the Initial Tree and
     * Fenwick Tree or Binary Indexed Tree
     */
    public void display()
    {
        System.out.print("\nInitial : 0");
        for(int i : initial) System.out.print(" " + i);
        System.out.print("\nFenwick :");
        for(int i : fenwick) System.out.print(" " + i);
    }

    /**
     * Subtract the resultant value from the given value
     * @param value - Position of Least Significant Bit of this value
     *              - starting at 0
     * @return - return the 2**(LSB bit position
     */
    public int LSB(int value) {
        int bitIndex = 0;
        while(value % 2 != 1) { // Get the Least Significant bit index from LHS
            value = value >> 1;
            bitIndex++; // next position bit index
        }
        return (int) Math.pow(2, bitIndex);
    }

    public void construction()
    {
        // start from index 1
        int prev = 1, curr = 1;

        // loop while prev is less than the length of the array - O(2n) time
        while(prev < fenwick.size())
        {
            // if the prev == curr || curr index to update is greater than
            // size of the array, IGNORE
            // else, update
            if(prev != curr && curr < fenwick.size())
                fenwick.set(curr, fenwick.get(prev) + fenwick.get(curr));

            // If difference between prev and curr index is 0 or 1
            if(Math.abs(prev-curr) <= 1) {
                prev = curr;
                curr += LSB(curr);
            }
            // else, there are some indices between prev and curr, are not updated
            // go back
            else curr = ++prev;
        }
        return;
    }

    private int sumCompute(int index) {

        int sum = 0; // initial prefix sum
        while(index > 0) { // O(logn) : go do to 0
            sum += fenwick.get(index); // add this value to sum
            index -= LSB(index); // next possible index in fenwick array
        }

        return sum; // return sum between [0, index] prefix sum
    }

    public int sumRange(int start, int end)
    {
        int e = sumCompute(end);    // [1, end]
        int s = sumCompute(start-1);// [1, start)

        return e - s; // difference
    }

    public int brute(int start, int end) {
        int sum = 0;
        for(int i = start-1; i < end; i++){
            sum += initial[i];
        }
        return sum;
    }

    public void update(int pos, int value) {

        // Get the value to be added to previous values
        int diff = value - initial[pos-1];
        initial[pos-1] += diff; // Update the initial array

        while(pos < fenwick.size()) { // O(logn) : go up to max
            fenwick.set(pos, fenwick.get(pos) + diff); // update
            pos += LSB(pos); // next possible index in fenwick array
        }
        return;
    }
}

public class Main {

    public static void main(String[] args) {

        FenwickTree ft = new FenwickTree(new int[]{3,4,-2,7,3,11,5,-8,-9,2,4,-8});
        ft.construction();  // construction

        ft.display();       // display fenwick and initial array
        System.out.println("\n" + ft.brute(3,9) + " " + ft.sumRange(3,9));

        ft.update(8,8);
        ft.display();       // display fenwick and initial array
        System.out.println("\n" + ft.brute(3,12) + " " + ft.sumRange(3,12));
    }
}
