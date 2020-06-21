// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/new-queries/
// Easy-Medium
// Segment Tree

import java.util.*;
import java.io.*;

class TreeNode
{
    public int low, mid, high, sIndex;
    public boolean isLeaf;

    public long value, maxEven, maxOdd;

    public TreeNode(long value, int low, int mid, int high, int sIndex) {

        this.low = low; this.mid = mid; this.high = high;
        this.value = value; this.sIndex = sIndex;
        isLeaf = false;

        maxEven = -1; maxOdd = -1;

        if(value % 2 == 0) maxEven = value;
        else maxOdd = value;
    }

    @Override
    public String toString()
    {
        return "(" + value + ")" + sIndex + ":[" + low + "," + high + "] ";
    }
}

class SegmentTree {

    public static final int MAXLEN = 500000;
    public static final int ROOT_INDEX  = 1;

    private final TreeNode[] SEGT_TREE;
    private final int[] LAZY_TREE;
    private final int N;

    public SegmentTree(ArrayList<Long> arrayList)
    {
        SEGT_TREE = new TreeNode[MAXLEN];
        LAZY_TREE = new int[MAXLEN];
        N = arrayList.size();

        constructTree(arrayList, ROOT_INDEX, 0, N-1);
    }

    private void lazyBlock(int index)
    {
        if(LAZY_TREE[index] != 0) {

            SEGT_TREE[index].value += LAZY_TREE[index];

            if(!SEGT_TREE[index].isLeaf) {
                LAZY_TREE[2*index] += LAZY_TREE[index];
                LAZY_TREE[2*index+1] += LAZY_TREE[index];
            }
            LAZY_TREE[index] = 0;
        }
    }

    // Complexity : O(N) space and time
    private long constructTree(ArrayList<Long> array, int index, int low, int high)
    {
        int mid = low + (high-low)/2;

        if(low == high)
        {
            SEGT_TREE[index] = new TreeNode(array.get(low), low, mid, high, index);
            SEGT_TREE[index].isLeaf = true;

            return SEGT_TREE[index].value;
        }

        long lChild = constructTree(array, 2*index, low, mid);
        long rChild = constructTree(array, 2*index+1, mid+1, high);

        // Traditional Query
        SEGT_TREE[index] = new TreeNode(Math.max(lChild,rChild), low, mid, high, index);

        SEGT_TREE[index].maxEven = Math.max(SEGT_TREE[2*index+1].maxEven, SEGT_TREE[2*index].maxEven);  // maximum even in subarray
        SEGT_TREE[index].maxOdd  = Math.max(SEGT_TREE[2*index+1].maxOdd, SEGT_TREE[2*index].maxOdd);    // maximum odd in subarray

        return SEGT_TREE[index].value;
    }

    // Range Query Criteria
    // 1. Partial Range, 2. Total Overlap, 3. No Overlap

    //Complexity : 4 * O(logn)
    private long rangeQuery(int qlow, int qhigh, int low, int high, int index, int type)
    {
        // OutOfBound
        if(low > high || qlow > high || qhigh < low) {
            return -1;
        }

//        System.out.println(SEGT_TREE[index]);
        if(qlow <= low && qhigh >= high)  { // Total Overlap
            if(type == 2)
                return SEGT_TREE[index].maxEven;
            return SEGT_TREE[index].maxOdd;
        }

        int mid = low + (high-low)/2;

        long lChild = rangeQuery(qlow, qhigh, low, mid, 2*index, type);
        long rChild = rangeQuery(qlow, qhigh, mid+1, high, 2*index+1, type);

        return Math.max(lChild, rChild);
    }

    private void updateLazy(int qlow, int qhigh, long delta, int low, int high, int index)
    {
        if(low > high || qlow > high || qhigh < low) { // 3. No Overlap (OutOfBound)
            return;
        }

        if(qlow <= low && qhigh >= high) { // 2. Total Overlap

            SEGT_TREE[index].maxEven = -1; SEGT_TREE[index].maxOdd = -1;

            if(delta % 2 == 0) SEGT_TREE[index].maxEven = delta;
            else SEGT_TREE[index].maxOdd = delta;

            return;
        }

        int mid = low + (high-low)/2;

        updateLazy(qlow, qhigh, delta, low, mid, 2*index);
        updateLazy(qlow, qhigh, delta, mid+1, high, 2*index+1);

        SEGT_TREE[index].value   = Math.max(SEGT_TREE[2*index].value, SEGT_TREE[2*index+1].value);
        SEGT_TREE[index].maxEven = Math.max(SEGT_TREE[2*index+1].maxEven, SEGT_TREE[2*index].maxEven);  // maximum even in subarray
        SEGT_TREE[index].maxOdd  = Math.max(SEGT_TREE[2*index+1].maxOdd, SEGT_TREE[2*index].maxOdd);    // maximum odd in subarray
    }

    public void update(int qlow, int qhigh, long delta) {
        updateLazy(qlow, qhigh, delta, 0, N-1, ROOT_INDEX);
    }
    public long query(int qlow, int qhigh, int type) {
        return rangeQuery(qlow, qhigh, 0, N-1, ROOT_INDEX, type);
    }
}

class Solution
{
    public Solution() throws Exception {

        Scan scan = new Scan();
        Print print = new Print();

        int N, M;
        long data, type, L, R;

        N = scan.nextInt();
        M = scan.nextInt();

        ArrayList<Long> arrayList = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            data = scan.nextLong();
            arrayList.add(data);
        }

        SegmentTree ST = new SegmentTree(arrayList);

        while(M-- > 0)
        {
            type = scan.nextLong();
            L = scan.nextLong() -1;
            R = scan.nextLong() -1;

            if(type == 1) {
                ST.update((int)L, (int)L, R+1);
            }
            else {
                long result = ST.query((int)L, (int)R, (int)type);

                if(result == -1) System.out.println("DNE");
                else System.out.println(result);
            }
        }

        print.close();
    }
}

class Scan
{
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Scan()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Scan(String file_name) throws IOException
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