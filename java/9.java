// 9. Palindrome Number
class Solution {
    public boolean isPalindrome(int x) {
        if( x < 0 )
            return false;
        
        int head = 1;
        int base = 1;
        while( (x / head) >= 10 ){
            head *= 10;
        }
        
        while(head > base){
            int hDigit = (x / head) % 10;
            int bDigit = (x / base) % 10;
            
            if( hDigit != bDigit )
                return false;
            
            head /= 10;
            base *= 10;
        }
        
        return true;
    }
}
