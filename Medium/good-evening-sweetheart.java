// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/good-evening-sweetheart/
// Medium

// https://visualgo.net/en/segmenttree
// https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/

import java.util.*;

class TreeNode
{
    public int value, sIndex;
    public int low, mid, high;
    public boolean isLeaf;

    int max, min;

    public TreeNode(int value, int low, int mid, int high, int sIndex) {

        this.low = low; this.mid = mid; this.high = high;
        this.value = value; this.sIndex = sIndex;
        isLeaf = false;

        max = value; min = value;
    }
    public void setRange(int max, int min) {
        this.max = max; this.min = min;
    }

    @Override
    public String toString()
    {
        return "(" + value + ")" + sIndex + ":[" + low + "," + high + "] " + max + " " + min;
    }
}

class SegmentTree {

    public static final int MAXLEN = 1000007;
    public static final int ROOT_INDEX  = 1;

    private final TreeNode[] SEGMENT_TREE;
    private final int[] LAZY_TREE;
    private int N;

    public SegmentTree(ArrayList<Integer> arrayList)
    {
        SEGMENT_TREE = new TreeNode[MAXLEN];
        LAZY_TREE = new int[MAXLEN];
        N = arrayList.size();

        constructTree(arrayList, ROOT_INDEX, 0, N-1);
    }

    public void printST() {
        for(TreeNode node : SEGMENT_TREE) {
            if(node != null) System.out.print(node + " ");
        }
        System.out.println();
    }

    // Complexity : O(N) space and time
    private int constructTree(ArrayList<Integer> array, int index, int low, int high)
    {
        int mid = low + (high-low)/2;

        // LEAF TREENODE
        if(low == high)
        {
            SEGMENT_TREE[index] = new TreeNode(array.get(low), low, mid, high, index);
            SEGMENT_TREE[index].isLeaf = true;

            return SEGMENT_TREE[index].value;
        }

        int lChild = constructTree(array, 2*index, low, mid);
        int rChild = constructTree(array, 2*index+1, mid+1, high);

        SEGMENT_TREE[index] = new TreeNode(Math.min(lChild,rChild), low, mid, high, index);
        SEGMENT_TREE[index].setRange(SEGMENT_TREE[2*index].max, SEGMENT_TREE[2*index+1].min);

        return SEGMENT_TREE[index].value;
    }

    // Range Query Criteria
    // 1. Partial Range, 2. Total Overlap, 3. No Overlap

    //Complexity : 4 * O(logn)
    private int rangeQueryMinimum(int qlow, int qhigh, int low, int high, int index)
    {
        if(LAZY_TREE[index] != 0) {

            SEGMENT_TREE[index].max += LAZY_TREE[index]; // Question
            SEGMENT_TREE[index].min += LAZY_TREE[index]; // Question

            SEGMENT_TREE[index].value += LAZY_TREE[index];
            if(!SEGMENT_TREE[index].isLeaf)
            {
                LAZY_TREE[2*index] += LAZY_TREE[index];
                LAZY_TREE[2*index+1] += LAZY_TREE[index];
            }
            LAZY_TREE[index] = 0;
        }

        if(qlow > high || qhigh < low) {
            return Integer.MAX_VALUE;
        }

        if(qlow <= low && qhigh >= high) {
            return SEGMENT_TREE[index].value;
        }

        int mid = low + (high-low)/2;

        int lQuery = rangeQueryMinimum(qlow, qhigh, low, mid, 2*index);
        int rQuery = rangeQueryMinimum(qlow, qhigh,mid+1, high, 2*index+1);

        return Math.min(lQuery, rQuery);
    }

    private void updateLazy(int qlow, int qhigh, int delta, int low, int high, int index)
    {
        if(low > high) return;

        if(LAZY_TREE[index] != 0) {

            SEGMENT_TREE[index].max += LAZY_TREE[index]; // Question
            SEGMENT_TREE[index].min += LAZY_TREE[index]; // Question

            SEGMENT_TREE[index].value += LAZY_TREE[index];
            if(!SEGMENT_TREE[index].isLeaf)
            {
                LAZY_TREE[2*index] += LAZY_TREE[index];
                LAZY_TREE[2*index+1] += LAZY_TREE[index];
            }
            LAZY_TREE[index] = 0;
        }

        if(qlow > high || qhigh < low) { // 3. No Overlap (OutOfBound)
            return;
        }

        if(qlow <= low && qhigh >= high) { // 2. Total Overlap

            SEGMENT_TREE[index].max += delta; // Question
            SEGMENT_TREE[index].min += delta; // Question

            SEGMENT_TREE[index].value += delta;
            if(!SEGMENT_TREE[index].isLeaf)
            {
                LAZY_TREE[2*index] += delta;
                LAZY_TREE[2*index+1] += delta;
            }
            return;
        }

        int mid = low + (high-low)/2;

        updateLazy(qlow, qhigh, delta, low, mid, 2*index);
        updateLazy(qlow, qhigh, delta, mid+1, high, 2*index+1);

        SEGMENT_TREE[index].value = Math.min(SEGMENT_TREE[2*index].value, SEGMENT_TREE[2*index+1].value);
        SEGMENT_TREE[index].setRange(SEGMENT_TREE[2*index].max, SEGMENT_TREE[2*index+1].min);
    }

    private int firstIndex(int index, int data)
    {
//        System.out.println(SEGMENT_TREE[index]);
        if(LAZY_TREE[index] != 0) {

            SEGMENT_TREE[index].max += LAZY_TREE[index]; // Question
            SEGMENT_TREE[index].min += LAZY_TREE[index]; // Question

            SEGMENT_TREE[index].value += LAZY_TREE[index];
            if(!SEGMENT_TREE[index].isLeaf)
            {
                LAZY_TREE[2*index] += LAZY_TREE[index];
                LAZY_TREE[2*index+1] += LAZY_TREE[index];
            }
            LAZY_TREE[index] = 0;
        }

//        System.out.println(SEGMENT_TREE[index]);

        if(SEGMENT_TREE[index].isLeaf) {
            if(SEGMENT_TREE[index].max == data) return SEGMENT_TREE[index].mid;
            return -1;
        }
        int max = SEGMENT_TREE[index].max;
        int min = SEGMENT_TREE[index].min;

        if(max >= data && data >= min) {
            int res = firstIndex(2*index, data);
            if(res != -1) return res;

            return firstIndex(2*index+1, data);
        }
        return -1;
    }

    private int lastIndex(int index, int data)
    {
//        System.out.println(SEGMENT_TREE[index]);
        if(LAZY_TREE[index] != 0) {

            SEGMENT_TREE[index].max += LAZY_TREE[index]; // Question
            SEGMENT_TREE[index].min += LAZY_TREE[index]; // Question

            SEGMENT_TREE[index].value += LAZY_TREE[index];
            if(!SEGMENT_TREE[index].isLeaf)
            {
                LAZY_TREE[2*index] += LAZY_TREE[index];
                LAZY_TREE[2*index+1] += LAZY_TREE[index];
            }
            LAZY_TREE[index] = 0;
        }

        if(SEGMENT_TREE[index].isLeaf) {
            if(SEGMENT_TREE[index].max == data) return SEGMENT_TREE[index].mid;
            return -1;
        }
        int max = SEGMENT_TREE[index].max;
        int min = SEGMENT_TREE[index].min;

        if(max >= data && data >= min) {
            int res = lastIndex(2*index+1, data);
            if(res != -1) return res;

            return lastIndex(2*index, data);
        }
        return -1;
    }

    public int getFirstIndex(int data) {
        return firstIndex(ROOT_INDEX, data);
    }
    public int getLastIndex(int data) {
        return lastIndex(ROOT_INDEX, data);
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
    public Solution()
    {
        Scanner scan = new Scanner(System.in);
        int N, M, data;

        N = scan.nextInt();
        M = scan.nextInt();

        ArrayList<Integer> arrayList = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            arrayList.add(scan.nextInt());
        }
        Collections.sort(arrayList, Collections.reverseOrder());
        SegmentTree ST = new SegmentTree(arrayList);

        int candles, fi, li;
        boolean possible = true;
        int days = 0;
        for(int i = 0; i < M; i++) {
            candles = scan.nextInt();

            data = ST.query(candles-1, candles-1);
            if(data == 0) possible = false;

            if(possible)
            {
                fi = ST.getFirstIndex(data);
                li = ST.getLastIndex(data);

                if(fi-1>= 0) {
                    ST.update(0, fi-1, -1);
                    candles -= fi;
                }
                ST.update(li-candles+1, li, -1);
                days++;
            }
        }
        System.out.println(days);
    }
}

class TestClass {
    public static void main(String args[] ) throws Exception {
        
        new Solution();
    }
}
