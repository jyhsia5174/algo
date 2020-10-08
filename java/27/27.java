import java.io.*;
import java.util.Scanner;
import java.util.Arrays;

class Solution {
    public int removeElement(int[] nums, int val){
        System.out.println(Arrays.toString(nums));
        System.out.println(val);

        int i = 0;
        int j = nums.length - 1;
        while( i <= j ){
            if( nums[i] == val ){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j--;
            }
            else{
                i++;
            }
        }

        return i;
    }
}

class Input{
    public static void main(String[] args){
        try{
            File inputFile = new File(args[0]);
            Scanner reader = new Scanner(inputFile);
            while( reader.hasNextLine() ){
                int[] arr;
                int val;

                String line = reader.nextLine();
                line = line.replaceAll("\\[|\\]", "");
                String[] tokens = line.split(",");

                arr = new int[tokens.length];
                for(int i = 0; i < tokens.length; i++)
                    arr[i] = Integer.valueOf(tokens[i]);

                line = reader.nextLine();
                val = Integer.valueOf(line);

                Solution s = new Solution();
                s.removeElement(arr, val);
            }
        } catch(FileNotFoundException e){
            e.printStackTrace();
        }
    }
}
