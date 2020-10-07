import java.io.*;
import java.util.Scanner;
import java.util.Arrays;

class Solution {
    public int removeDuplicates(int[] nums) {
        int head = 0;
        for(int curP = 1; curP < nums.length; curP++){
            if( nums[head] != nums[curP] ){
                head++;
                nums[head] = nums[curP];
            }
        }

        for(int i = head + 1; i < nums.length; i++)
           nums[i] = 0;

        return head + 1;
    }
}

class Input{
   public static void main(String[] args){
       Solution sol = new Solution();

       try{
          File myObj = new File(args[0]);
          Scanner reader = new Scanner(myObj);
          while(reader.hasNextLine()){
            String inputData = reader.nextLine();
            inputData = inputData.replaceAll("\\[|\\]", "");
            String[] tokens = inputData.split(",");
            int[] inputArr = new int[tokens.length];
            for(int i = 0; i < tokens.length; i++)
               inputArr[i] = Integer.valueOf(tokens[i]);

            System.out.println(Arrays.toString(inputArr));
            sol.removeDuplicates(inputArr);
            System.out.println(Arrays.toString(inputArr));
          }
       } catch (FileNotFoundException e){
          System.out.println("An error occurred.");
          e.printStackTrace();
       }
   } 
}
