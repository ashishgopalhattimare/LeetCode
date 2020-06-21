// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/easy-queries-751f9372/
// Easy
// Segment Tree, Binary Search

import java.io.*;
import java.util.*;

class TreeNode
{
    public int value, sIndex;
    public int low, mid, high;
    public boolean isLeaf;

    public int count;

    public TreeNode(int value, int low, int mid, int high, int sIndex) {

        this.low = low; this.mid = mid; this.high = high;
        this.value = value; this.sIndex = sIndex;
        isLeaf = false;

        this.count = value;
    }

    @Override
    public String toString()
    {
        return "(" + count + ")" + sIndex + ":[" + low + "," + high + "] ";
    }
}

class SegmentTree {

    public static final int MAXLEN = 3*5000007;
    public static final int ROOT_INDEX  = 1;

    private final TreeNode[] SEGMENT_TREE;
    private final int[] LAZY_TREE;
    private final int N;

    public SegmentTree(ArrayList<Integer> arrayList)
    {
        SEGMENT_TREE = new TreeNode[MAXLEN];
        LAZY_TREE = new int[MAXLEN];
        N = arrayList.size();

        constructTree(arrayList, ROOT_INDEX, 0, N-1);
    }

    private void lazyBlock(int index)
    {
        if(LAZY_TREE[index] != 0) {

            SEGMENT_TREE[index].value += LAZY_TREE[index];

            if(!SEGMENT_TREE[index].isLeaf) {
                LAZY_TREE[2*index] += LAZY_TREE[index];
                LAZY_TREE[2*index+1] += LAZY_TREE[index];
            }
            LAZY_TREE[index] = 0;
        }
    }

    // Complexity : O(N) space and time
    private int constructTree(ArrayList<Integer> array, int index, int low, int high)
    {
        int mid = low + (high-low)/2;

        if(low == high)
        {
            SEGMENT_TREE[index] = new TreeNode(array.get(low), low, mid, high, index);
            SEGMENT_TREE[index].isLeaf = true;

            return SEGMENT_TREE[index].count;
        }

        int lChild = constructTree(array, 2*index, low, mid);
        int rChild = constructTree(array, 2*index+1, mid+1, high);

        // Traditional Query
        SEGMENT_TREE[index] = new TreeNode(Math.min(lChild,rChild), low, mid, high, index);
        SEGMENT_TREE[index].count = SEGMENT_TREE[2*index].count | SEGMENT_TREE[2*index+1].count;

        return SEGMENT_TREE[index].count; // whether the count of 1 in the subrange is atleast 1
    }

    // Range Query Criteria
    // 1. Partial Range, 2. Total Overlap, 3. No Overlap

    //Complexity : 4 * O(logn)
    private boolean rangeQueryMinimum(int qlow, int qhigh, int low, int high, int index)
    {
        if(low > high || qlow > high || qhigh < low) {
            return false;
        }

        if(SEGMENT_TREE[index].count == 0) return false;

        // If the 1 in the range, return true : there is atleast 1 in the range [low, right]
        if(qlow <= low && qhigh >= high) {
            return SEGMENT_TREE[index].count >= 1;
        }

        int mid = low + (high-low)/2;

        // Explore other regions
        return rangeQueryMinimum(qlow, qhigh, low, mid, 2*index) ||
               rangeQueryMinimum(qlow, qhigh,mid+1, high, 2*index+1);
    }

    private void updateLazy(int qlow, int qhigh, int delta, int low, int high, int index)
    {
        if(low > high || qlow > high || qhigh < low) { // 3. No Overlap (OutOfBound)
            return;
        }

        if(qlow <= low && qhigh >= high) { // 2. Total Overlap
            SEGMENT_TREE[index].count |= delta;
            return;
        }

        int mid = low + (high-low)/2;

        updateLazy(qlow, qhigh, delta, low, mid, 2*index);
        updateLazy(qlow, qhigh, delta, mid+1, high, 2*index+1);

        SEGMENT_TREE[index].count = SEGMENT_TREE[2*index].count | SEGMENT_TREE[2*index+1].count;
    }

    public void update(int qlow, int qhigh, int delta) {
        updateLazy(Math.max(qlow, 0), Math.min(qhigh, N-1), delta, 0, N-1, ROOT_INDEX);
    }
    public boolean query(int qlow, int qhigh) {
        return rangeQueryMinimum(Math.max(qlow, 0), Math.min(qhigh, N-1), 0, N-1, ROOT_INDEX);
    }
}

class Solution
{
    public static int COUNTER = 0;
    public Solution() throws Exception {

        Print print = new Print();
        Scan scan = new Scan();

        int N = scan.scanInt();
        int Q = scan.scanInt();

        ArrayList<Integer> arrayList = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            int data = scan.scanInt();
            arrayList.add(data);
        }

        SegmentTree ST = new SegmentTree(arrayList);

        int type, index;
        while(Q-- > 0)
        {
            type = scan.scanInt();
            switch(type)
            {
                case 0: // find nearest Left and Right with 1
                    index = scan.scanInt();

                    int left = -1, right = -1;
                    
                    // Use binary Search over the range to find the nearest 1 to the index
                    if(ST.query(0, index-1)) {
                        left = binary_left(0, index-1, ST, arrayList);
                    }
                    
                    if(ST.query(index+1, N-1)) {
                        right = binary_right(index+1, N-1, ST, arrayList);
                    }

                    print.println(left + " " + right);

                    break;

                case 1: // update the value at index to 1

                    index = scan.scanInt();

                    if(arrayList.get(index) == 0) {
                        ST.update(index, index, 1);
                        arrayList.set(index, 1);
                    }

                    break;
            }
        }

        print.close();
    }

    // The element 1 is definitely present between [low, high] range
    public int binary_left(int low, int high, SegmentTree ST, ArrayList<Integer> arr)
    {
        int mid = low + (high-low)/2;

        // If the element is between [mid,high] -> explore that range
        if(ST.query(mid, high)) {
            if(Math.abs(mid-high) <= 2) {
                for(int i = high; i >= mid; i--) {
                    if(arr.get(i) == 1) return i;
                }
                return -1;
            }
            return binary_left(mid, high, ST, arr);
        }

        // else explore the [low,mid] range
        return binary_left(low, mid-1, ST, arr);
    }

    public int binary_right(int low, int high, SegmentTree ST, ArrayList<Integer> arr)
    {
        int mid = low + (high-low)/2;
        if(ST.query(low, mid)) {
            if(Math.abs(low-mid) <= 2) {
                for(int i = low; i <= mid; i++) {
                    if(arr.get(i) == 1) return i;
                }
                return -1;
            }
            return binary_right(low, mid, ST, arr);
        }
        return binary_right(mid+1, high, ST, arr);
    }
}

class Scan
{
    private byte[] buf = new byte[1024];
    private int index, total;
    private InputStream in;

    public Scan()
    {
        in=System.in;
    }
    public int scan()throws IOException
    {
        if(total < 0) throw new InputMismatchException();
        if(index >= total) {
            index=0;
            total=in.read(buf);
            if(total<=0) return -1;
        }
        return buf[index++];
    }
    public int scanInt()throws IOException
    {
        int integer = 0, n=scan();
        while(isWhiteSpace(n)) n=scan();
        int neg=1;
        if(n=='-') {
            neg=-1; n=scan();
        }
        while(!isWhiteSpace(n)) {
            if(n>='0'&&n<='9') {
                integer*=10;
                integer+=n-'0';
                n=scan();
            }
            else throw new InputMismatchException();
        }
        return neg*integer;
    }
    public double scanDouble()throws IOException
    {
        double doub=0;
        int n=scan();
        while(isWhiteSpace(n))
            n=scan();
        int neg=1;
        if(n=='-')
        {
            neg=-1;
            n=scan();
        }
        while(!isWhiteSpace(n)&&n!='.')
        {
            if(n>='0'&&n<='9')
            {
                doub*=10;
                doub+=n-'0';
                n=scan();
            }
            else throw new InputMismatchException();
        }
        if(n=='.')
        {
            n=scan();
            double temp=1;
            while(!isWhiteSpace(n))
            {
                if(n>='0'&&n<='9')
                {
                    temp/=10;
                    doub+=(n-'0')*temp;
                    n=scan();
                }
                else throw new InputMismatchException();
            }
        }
        return doub*neg;
    }
    public String scanString()throws IOException
    {
        StringBuilder sb=new StringBuilder();
        int n=scan();
        while(isWhiteSpace(n))
            n=scan();
        while(!isWhiteSpace(n))
        {
            sb.append((char)n);
            n=scan();
        }
        return sb.toString();
    }
    private boolean isWhiteSpace(int n)
    {
        if(n==' '||n=='\n'||n=='\r'||n=='\t'||n==-1)
            return true;
        return false;
    }
}

class Print
{
    private final BufferedWriter bw;
    public Print()
    {
        this.bw=new BufferedWriter(new OutputStreamWriter(System.out));
    }
    public void print(Object object)throws IOException
    {
        bw.append(""+object);
    }
    public void println(Object object)throws IOException
    {
        print(object);
        bw.append("\n");
    }
    public void close()throws IOException
    {
        bw.close();
    }
}

public class Main 
{
    public static void main(String[] args) throws Exception {
        new Solution();
    }
}