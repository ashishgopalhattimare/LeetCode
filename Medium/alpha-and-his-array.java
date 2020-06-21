// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/no-name-2/
// Easy-Medium
// Segmented Tree

import java.util.*;

class TreeNode
{
    public long value, sIndex;
    public long low, mid, high;
    public boolean isLeaf;

    public long sum, nodes, max;

    // nodes -> number of node in the subtree
    // sum -> sum of all the nodes
    // max -> maximum value node in the subtre

    public TreeNode(long value, long low, long mid, long high, long sIndex) {

        this.low = low; this.mid = mid; this.high = high;
        this.value = value; this.sIndex = sIndex;
        isLeaf = false;

        this.max = value; this.sum = value; this.nodes = 1;
    }

    @Override
    public String toString()
    {
        return "(" + sum + ")" + sIndex + ":[" + low + "," + high + "] " + max + " " + nodes;
    }
}

class SegmentTree {

    public static final int MAXLEN = 1000007;
    public static final int ROOT_INDEX  = 1;

    private final TreeNode[] SEGMENT_TREE;
    private final long[] LAZY_TREE;
    private final int N;

    public static long SUM_DECREMENT = 0;

    public SegmentTree(ArrayList<Long> arrayList)
    {
        SEGMENT_TREE = new TreeNode[MAXLEN];
        LAZY_TREE = new long[MAXLEN];
        N = arrayList.size();

        constructTree(arrayList, ROOT_INDEX, 0, N-1);
    }

    private void lazyBlock(int index, int len)
    {
        if(LAZY_TREE[index] != 0) {

            SEGMENT_TREE[index].sum = Math.max(0, SEGMENT_TREE[index].sum + len*LAZY_TREE[index]);

            if(!SEGMENT_TREE[index].isLeaf) {
                LAZY_TREE[2*index] += LAZY_TREE[index];
                LAZY_TREE[2*index+1] += LAZY_TREE[index];
            }
            LAZY_TREE[index] = 0;
        }
    }

    private long constructTree(ArrayList<Long> array, int index, int low, int high)
    {
        int mid = low + (high-low)/2;

        if(low == high)
        {
            SEGMENT_TREE[index] = new TreeNode(array.get(low), low, mid, high, index);
            SEGMENT_TREE[index].isLeaf = true;

            return SEGMENT_TREE[index].value;
        }

        long lChild = constructTree(array, 2*index, low, mid);
        long rChild = constructTree(array, 2*index+1, mid+1, high);

        // Traditional Query
        SEGMENT_TREE[index] = new TreeNode(Math.max(lChild,rChild), low, mid, high, index);

        SEGMENT_TREE[index].sum = SEGMENT_TREE[2*index].sum + SEGMENT_TREE[2*index+1].sum;
        SEGMENT_TREE[index].nodes = SEGMENT_TREE[2*index].nodes + SEGMENT_TREE[2*index+1].nodes;
        SEGMENT_TREE[index].max = Math.max(SEGMENT_TREE[2*index].max, SEGMENT_TREE[2*index+1].max);

        return SEGMENT_TREE[index].value;
    }

    private long rangeQueryMinimum(int qlow, int qhigh, int low, int high, int index)
    {
        // Lazy Propagation to lower level
        // lazyBlock(index, high-low+1);

        if(qlow > high || qhigh < low) {
            return Integer.MAX_VALUE;
        }

        if(qlow <= low && qhigh >= high) {
            return SEGMENT_TREE[index].value;
        }

        int mid = low + (high-low)/2;

        long lQuery = rangeQueryMinimum(qlow, qhigh, low, mid, 2*index);
        long rQuery = rangeQueryMinimum(qlow, qhigh,mid+1, high, 2*index+1);

        return Math.min(lQuery, rQuery);
    }

    private void updateLazy(int qlow, int qhigh, long delta, int low, int high, int index)
    {
        if(low > high) return;

        // The subtree is completely 0
        if(SEGMENT_TREE[index].sum == 0) return;

        if(qlow > high || qhigh < low) { // 3. No Overlap (OutOfBound)
            return;
        }

        if(qlow <= low && qhigh >= high) { // 2. Total Overlap

            // If all the values in the subtree are smaller than delta or is leaf node
            if((SEGMENT_TREE[index].sum <= (SEGMENT_TREE[index].nodes)*Math.abs(delta) && SEGMENT_TREE[index].max <= Math.abs(delta)) ||
                    SEGMENT_TREE[index].isLeaf) {

                SEGMENT_TREE[index].max = Math.max(0, SEGMENT_TREE[index].max + delta);

                SegmentTree.SUM_DECREMENT += Math.min(SEGMENT_TREE[index].sum, (SEGMENT_TREE[index].nodes)*Math.abs(delta));
                SEGMENT_TREE[index].sum = Math.max(0, SEGMENT_TREE[index].sum + (SEGMENT_TREE[index].nodes)*delta);

                if(SEGMENT_TREE[index].sum == 0) SEGMENT_TREE[index].nodes = 0;

                return;
            }
        }

        int mid = low + (high-low)/2;

        updateLazy(qlow, qhigh, delta, low, mid, 2*index);
        updateLazy(qlow, qhigh, delta, mid+1, high, 2*index+1);

        SEGMENT_TREE[index].sum = SEGMENT_TREE[2*index].sum + SEGMENT_TREE[2*index+1].sum;
        SEGMENT_TREE[index].nodes = SEGMENT_TREE[2*index].nodes + SEGMENT_TREE[2*index+1].nodes;
        SEGMENT_TREE[index].max = Math.max(SEGMENT_TREE[2*index].max, SEGMENT_TREE[2*index+1].max);
    }

    public void update(int qlow, int qhigh, long delta) {
        updateLazy(Math.max(qlow, 0), Math.min(qhigh, N-1), delta, 0, N-1, ROOT_INDEX);
    }
    public long query(int qlow, int qhigh) {
        return rangeQueryMinimum(Math.max(qlow, 0), Math.min(qhigh, N-1), 0, N-1, ROOT_INDEX);
    }
}


class Solution
{
    public Solution()
    {
        Scanner scan = new Scanner(System.in);
        long N, data;

        N = scan.nextLong();

        ArrayList<Long> arrayList = new ArrayList<>();
        ArrayList<Long> queries = new ArrayList<>();

        for(int i = 0; i < N; i++) {
            data = scan.nextLong();
            arrayList.add(data);
        }
        SegmentTree ST = new SegmentTree(arrayList);

        for(int i = 0; i < N; i++) {
            data = scan.nextLong();
            queries.add(data);
        }

        for(int i = 0; i < N; i++) {
            data = queries.get(i);

            SegmentTree.SUM_DECREMENT = 0;
            ST.update(0, i, -data);
            System.out.print(SegmentTree.SUM_DECREMENT + " ");
        }
        System.out.println();
    }

    private long bruteForce(int start, int end, ArrayList<Long> A, long D) {

        long result = 0;
        for(int i = start; i <= end; i++) {
            result += Math.min(A.get(i), D);
            A.set(i, Math.max(0, A.get(i)-D));
        }
        return result;
    }
}

public class Main {

    public static void main(String[] args) throws Exception {

        new Solution();
    }
}