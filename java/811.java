// 811. Subdomain Visit Count
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> counts = new HashMap();
        for(String domain: cpdomains){
            String[] countNamePair = domain.split("\\s+");
            int count = Integer.valueOf(countNamePair[0]);
            String[] domainFrag = countNamePair[1].split("\\.");
            
            String cur = domainFrag[domainFrag.length-1];
            for(int i = domainFrag.length - 2; i >= 0; i--){
                counts.put( cur, counts.getOrDefault(cur, 0) + count );
                cur =  domainFrag[i] + "." + cur;
            }
            counts.put( cur, counts.getOrDefault(cur, 0) + count );
        }
        
        List<String> ans = new ArrayList();
        for(String dom: counts.keySet()){
            ans.add("" + counts.get(dom) + " " + dom);
        }
        
        return ans;
    }
}
