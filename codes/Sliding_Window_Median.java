
public class Solution {
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving.
     */
    public ArrayList<Integer> medianSlidingWindow(int[] nums, int k) {
        ArrayList<Integer> result = new ArrayList<Integer>();

        if (nums.length == 0) return result;

        if (nums.length < k) {
            Arrays.sort(nums);
            result.add(nums[nums.length / 2]);
            return result;
        }

        ArrayList<Integer> init = new ArrayList<Integer>();
        for (int i = 0; i < k; i++)
            init.add(nums[i]);

        Collections.sort(init);
        PriorityQueue<Integer> leftQueue = new PriorityQueue<Integer>(1, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });

        PriorityQueue<Integer> rightQueue = new PriorityQueue<Integer>();

        int midIndx = (k + 1) / 2 - 1;
        int mid = init.get(midIndx);
        result.add(mid);

        for (int i = 0; i < midIndx; i++)
            leftQueue.add(init.get(i));
        for (int i = midIndx + 1; i < k; i++)
            rightQueue.add(init.get(i));

        for (int i = k; i < nums.length; i++) {
            int cur = nums[i];
            int toRemove = nums[i - k];
            if (cur <= mid) {
                leftQueue.add(cur);
                if (toRemove < mid) {
                    leftQueue.remove(toRemove);
                } else if (toRemove > mid) {
                    rightQueue.remove(toRemove);
                    rightQueue.add(mid);
                    mid = leftQueue.poll();
                } else {
                    mid = leftQueue.poll();
                }
            } else {
                rightQueue.add(cur);
                if (toRemove < mid) {
                    leftQueue.remove(toRemove);
                    leftQueue.add(mid);
                    mid = rightQueue.poll();
                } else if (toRemove > mid) {
                    rightQueue.remove(toRemove);
                } else {
                    mid = rightQueue.poll();
                }
            }
            result.add(mid);
        }
        return result;
    }
}