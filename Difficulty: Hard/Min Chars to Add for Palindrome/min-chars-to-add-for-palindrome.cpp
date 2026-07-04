class Solution {
  public:
    int minChar(string &s) {
        // code here
        
        string rev=s;
        reverse(rev.begin(),rev.end());
        
        int size=s.size();
        s+='$';
        s+=rev;
        
        //to take out the longest prefix
        
        int n=s.size();
        
        vector<int>lps(n,0);
        
        int pre=0 , suf=1;
        
        while(suf<s.size())
        //if matched
        {
            if(s[pre]==s[suf])
            {
                lps[suf]=pre+1;
                pre++, suf++;
            }
            
            //not matched
            
            else
            {
                if(pre==0)
                suf++;
                else
                pre=lps[pre-1];
            }
            
        }
        
        return size-lps[n-1];
    }
};
