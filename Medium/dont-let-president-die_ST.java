// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/dont-let-president-die/
// Medium
// Segment Tree

import java.util.*;
import java.io.*;
 
class Wrapper
{
    public BitSet bit;
    public int max;
 
    public Wrapper(BitSet bit, int max) {
        this.bit = bit; this.max = max;
    }
    public Wrapper() {
        this.bit = null;
        this.max = 0;
    }
 
    public void combine(Wrapper child) {
 
        if(this.bit == null) this.bit = new BitSet(TreeNode.MAX_BIT);
 
        this.bit.or(child.bit); // perform OR with the given bit
        this.max = Math.max(this.max, child.max);
    }
}
 
class TreeNode
{
    public int value, sIndex;
    public int low, mid, high;
    public boolean isLeaf;
 
    public int max;
    public BitSet bit;
 
    public static final int MAX_BIT = 100007;
 
    public TreeNode(int value, int low, int mid, int high, int sIndex) {
 
        this.low = low; this.mid = mid; this.high = high;
        this.value = value; this.sIndex = sIndex;
        isLeaf = false;
 
        this.bit = new BitSet(MAX_BIT);
        this.max = value;
    }
 
    @Override
    public String toString()
    {
        return "(" + max + ")" + sIndex + ":[" + low + "," + high + "] ";
    }
}
 
class SegmentTree {
 
    public static final int MAXLEN = 500000;
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
 
            SEGMENT_TREE[index].bit.set(array.get(low));
            return SEGMENT_TREE[index].max;
        }
 
        int lChild = constructTree(array, 2*index, low, mid);
        int rChild = constructTree(array, 2*index+1, mid+1, high);
 
        // Traditional Query
        SEGMENT_TREE[index] = new TreeNode(Math.min(lChild,rChild), low, mid, high, index);
        SEGMENT_TREE[index].max = Math.max( SEGMENT_TREE[2*index].max,
                                            SEGMENT_TREE[2*index+1].max);
 
        SEGMENT_TREE[index].bit.or(SEGMENT_TREE[2*index+1].bit);
        SEGMENT_TREE[index].bit.or(SEGMENT_TREE[2*index].bit);
 
        return SEGMENT_TREE[index].max;
    }
 
    // Range Query Criteria
    // 1. Partial Range, 2. Total Overlap, 3. No Overlap
 
    //Complexity : 4 * O(logn)
    private Wrapper rangeQuery(int qlow, int qhigh, int low, int high, int index)
    {
        // OutOfBound
        if(qlow > high || qhigh < low) {
            return new Wrapper();
        }
 
//        System.out.println(SEGMENT_TREE[index]);
        if(qlow <= low && qhigh >= high)  { // Total Overlap
            return new Wrapper(SEGMENT_TREE[index].bit, SEGMENT_TREE[index].max);
        }
 
        int mid = low + (high-low)/2;
 
        Wrapper lChild = rangeQuery(qlow, qhigh, low, mid, 2*index);
        Wrapper rChild = rangeQuery(qlow, qhigh, mid+1, high, 2*index+1);
 
        Wrapper result = new Wrapper();
        if(lChild.bit != null) result.combine(lChild);
        if(rChild.bit != null) result.combine(rChild);
 
        return result;
    }
 
    private void updateLazy(int qlow, int qhigh, int delta, int low, int high, int index)
    {
        if(low > high || qlow > high || qhigh < low) { // 3. No Overlap (OutOfBound)
            return;
        }
 
        if(qlow <= low && qhigh >= high) { // 2. Total Overlap
            return;
        }
 
        int mid = low + (high-low)/2;
 
        updateLazy(qlow, qhigh, delta, low, mid, 2*index);
        updateLazy(qlow, qhigh, delta, mid+1, high, 2*index+1);
 
        SEGMENT_TREE[index].max = Math.max(SEGMENT_TREE[2*index].max, SEGMENT_TREE[2*index+1].max);
    }
 
    public void update(int qlow, int qhigh, int delta) {
        updateLazy(qlow, qhigh, delta, 0, N-1, ROOT_INDEX);
    }
    public Wrapper query(int qlow, int qhigh) {
        return rangeQuery(qlow, qhigh, 0, N-1, ROOT_INDEX);
    }
}
 
class Solution
{
    public Solution() throws Exception {
 
        Scan scan = new Scan();
        Print print = new Print();
 
        int N, M, L, R, data;
 
        N = scan.scanInt();
 
        ArrayList<Integer> arrayList = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            data = scan.scanInt();
            arrayList.add(data);
        }
 
        SegmentTree ST = new SegmentTree(arrayList);
 
        M = scan.scanInt();
        while(M-- > 0)
        {
            L = scan.scanInt();
            R = scan.scanInt();
 
            Wrapper result = ST.query(L, R);
 
            print.println(result.max - result.bit.cardinality());
        }
 
        print.close();
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
 
public class Main {
 
    public static void main(String[] args) throws Exception {
 
        new Solution();
    }
}