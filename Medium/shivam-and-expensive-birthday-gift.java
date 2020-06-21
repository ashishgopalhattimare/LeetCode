// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/shivam-and-expensive-birthday-gift-da58b2f0/
// Easy
// Segment Tree, Bit Manipulation

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
        this.isLeaf = false;

        this.count = 0;
    }

    @Override
    public String toString()
    {
        return "(" + value + ")" + sIndex + ":[" + low + "," + high + "] ";
    }
}

class SegmentTree {

    public static final int MAXLEN = 3*500007;
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

            return SEGMENT_TREE[index].value;
        }

        int lChild = constructTree(array, 2*index, low, mid);
        int rChild = constructTree(array, 2*index+1, mid+1, high);

        // Traditional Query
        SEGMENT_TREE[index] = new TreeNode(Math.min(lChild,rChild), low, mid, high, index);
        SEGMENT_TREE[index].count = SEGMENT_TREE[2*index].count + SEGMENT_TREE[2*index+1].count;

        return SEGMENT_TREE[index].count;
    }

    // Range Query Criteria
    // 1. Partial Range, 2. Total Overlap, 3. No Overlap

    //Complexity : 4 * O(logn)
    private int rangeQueryMinimum(int qlow, int qhigh, int low, int high, int index)
    {
         // Lazy Propagation to lower level
         // lazyBlock(index);

        if(qlow > high || qhigh < low) {
            return 0;
        }

        if(qlow <= low && qhigh >= high) {
            return SEGMENT_TREE[index].count;
        }

        int mid = low + (high-low)/2;

        int lQuery = rangeQueryMinimum(qlow, qhigh, low, mid, 2*index);
        int rQuery = rangeQueryMinimum(qlow, qhigh,mid+1, high, 2*index+1);

        return lQuery + rQuery;
    }

    private void updateLazy(int qlow, int qhigh, int delta, int low, int high, int index)
    {
        if(low > high) return;

        // lazyBlock(index);

        if(qlow > high || qhigh < low) { // 3. No Overlap (OutOfBound)
            return;
        }

        if(qlow <= low && qhigh >= high) { // 2. Total Overlap

            // type 1 : A[X] = 2*A[X] + 1 .. same as increment 1
            // type 1 : A[X] = A[X]/2     .. same as decrement 1
            SEGMENT_TREE[index].count = Math.max(0, SEGMENT_TREE[index].count+delta);
            return;
        }

        int mid = low + (high-low)/2;

        updateLazy(qlow, qhigh, delta, low, mid, 2*index);
        updateLazy(qlow, qhigh, delta, mid+1, high, 2*index+1);

        SEGMENT_TREE[index].count = SEGMENT_TREE[2*index].count + SEGMENT_TREE[2*index+1].count;
    }

    public void update(int qlow, int qhigh, int delta) {
        updateLazy(Math.max(qlow, 0), Math.min(qhigh, N-1), delta, 0, N-1, ROOT_INDEX);
    }
    public int query(int qlow, int qhigh) {
        return rangeQueryMinimum(Math.max(qlow, 0), Math.min(qhigh, N-1), 0, N-1, ROOT_INDEX);
    }
}

class Solution
{
    public Solution() {
    
        try {
            Reader scan = new Reader();
            Print print = new Print();
            
            int N, M;
            int type, X, Y;

            N = scan.nextInt();
            M = scan.nextInt();

            ArrayList<Integer> arr = new ArrayList<>();
            for(int i = 0; i < N; i++) arr.add(0);

            SegmentTree ST = new SegmentTree(arr);

            for(int i = 0; i < M; i++) {

                type = scan.nextInt();
                X = scan.nextInt();

                if(type == 1) {
                    ST.update(X-1, X-1, 1);
                }
                else if(type == 2) {
                    ST.update(X-1, X-1,-1);
                }

                if(type == 3) {
                    Y = scan.nextInt();
                    print.println(ST.query(X-1, Y-1));
                }
            }
            
            print.close();
        }
        catch (Exception e) {}
    }
}


class Reader
{
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException
    {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException
    {
        byte[] buf = new byte[64]; // line length 
        int cnt = 0, c;
        while ((c = read()) != -1)
        {
            if (c == '\n')
                break;
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException
    {
        int ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do
        {
            ret = ret * 10 + c - '0';
        }  while ((c = read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    public long nextLong() throws IOException
    {
        long ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }

    public double nextDouble() throws IOException
    {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();

        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');

        if (c == '.')
        {
            while ((c = read()) >= '0' && c <= '9')
            {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }

    private void fillBuffer() throws IOException
    {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private byte read() throws IOException
    {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException
    {
        if (din == null)
            return;
        din.close();
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

public class Main {

    public static void main(String[] args) throws Exception {

        new Solution();
    }
}