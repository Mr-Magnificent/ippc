import java.util.*;

class NextGreaterElementII {
    public int[] nextGreaterElements(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int ele : nums)
            arr.add(ele);
        Stack<Integer> stk = new Stack<>();
        int[] sol = new int[nums.length];
        Arrays.fill(sol, -1);
        arr.addAll(arr);

        for (int i = 0; i < arr.size(); i++) {
            while (!stk.empty() && arr.get(stk.peek()) < arr.get(i)) {
                sol[stk.peek() % nums.length] = arr.get(i);
                stk.pop();
            }
            stk.push(i);
        }
        return sol;
    }

    public static void main(String[] args) {
        NextGreaterElementII obj = new NextGreaterElementII();
        int[] arr = { 1, 2, 1 };
        int[] sol = obj.nextGreaterElements(arr);
        System.out.println(Arrays.toString(sol));
    }
}