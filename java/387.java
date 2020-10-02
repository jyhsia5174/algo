// 387. First Unique Character in a String
// Time : O(n) Space: O(1)
class Solution {
    public int firstUniqChar(String s) {
        int[] first_idx = new int[26];
        int[] count = new int[26];
        
        for(int i = 0; i < 26; i++){
            first_idx[i] = -1;
            count[i] = 0;
        }
        
        for(int i = 0; i < s.length(); i++){
            int hash = s.charAt(i)-'a';
            if( count[hash] == 0 ){
                first_idx[hash] = i;
            }
            
            count[hash]++;
        }
        
        
        int min_idx = Integer.MAX_VALUE;
        for(int i = 0; i < 26; i++){
            if( count[i] == 1 ){
                min_idx = Math.min( min_idx, first_idx[i] );
            }
        }
        
        if( min_idx == Integer.MAX_VALUE )
            return -1;
        return min_idx;
    }
}


class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> count = new HashMap<Character, Integer>();
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            char c = s.charAt(i);
            count.put( c, count.getOrDefault(c, 0) + 1);
        }
        
        for(int i = 0; i < n; i++){
            if( count.get(s.charAt(i)) == 1 )
                return i;
        }
        
        return -1;
    }
}
