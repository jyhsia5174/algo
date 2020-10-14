// 204. Count Primes
class Solution {
    public int countPrimes(int n) {
        ArrayList<Integer> primes = new ArrayList<Integer>();
        
        boolean isPrime = true;
        for(int i = 2;i < n; i++){
            isPrime = true;
            for(int v: primes){
                if( v > Math.sqrt(i) )
                    break;
                if( i % v == 0 ){
                    isPrime = false;
                    break;
                }
            }
            
            if(isPrime){
                primes.add(i);
            }
        }
        
        return primes.size();
    }
}

class Solution {
    public int countPrimes(int n) {
        boolean[] isPrimes = new boolean[n];
        for(int i = 2; i < n; i++)
            isPrimes[i] = true;
        
        int count = 0;
        for(int i = 2; i < n; i++){
            if( isPrimes[i] ){
                count++;
                
                for(int j = 2*i; j < n; j+=i)
                    isPrimes[j] = false;
            }
        }
        
        return count;
    }
}
