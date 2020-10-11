28. Implement strStr()
class Solution {
    public int strStr(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if( n2 == 0 ) return 0;
        
        int[] lss = longestSubstr(s2);
        
        int j = -1;
        for(int i = 0; i < n1; i++){
            if( s1.charAt(i) == s2.charAt(j+1) ){
                j++;
            }else{
                while( j != -1 ){
                    if( s1.charAt(i) == s2.charAt(j+1) ){
                        j++;
                        break;
                    }
                    j = lss[j];
                }
                
                if( j == -1 && s1.charAt(i) == s2.charAt(j+1) )
                    j = 0;
            }
            
            if( j == n2-1 )
                return i - n2 + 1;
        }
        
        return -1;
    }
    
    private int[] longestSubstr(String s){
        int N = s.length();
        int[] lss = new int[N];
        lss[0] = -1;
        
        int j = lss[0];
        for(int i = 1; i < N; i++){
            while( j != -1 ){
                if( s.charAt(j+1) == s.charAt(i) )
                    break;
                j = lss[j];
            }
            
            if( j != -1 ){
                j = j + 1;
            }
            else if( j == -1 && s.charAt(0) == s.charAt(i) ){
                j = 0;
            }
            else{
                j = -1;
            }
            lss[i] = j;
        }
        
        return lss;
    }
}
