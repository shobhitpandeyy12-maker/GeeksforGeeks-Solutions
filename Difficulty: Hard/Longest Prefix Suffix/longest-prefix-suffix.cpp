class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        
        vector<int>LPS(s.size(),0);
        
        int pre=0 , suf=1 ;
        while(suf < s.size())
        {
            if(s[pre]==s[suf])
            {
                LPS[suf]=pre+1;
                suf++, pre++;
                
            }
            else
            {
                if(pre==0)
                {
                    LPS[suf]=0;
                    suf++;
                }
                else
                {
                    pre=LPS[pre-1];
                }
            }
        }
        
        return LPS[s.size()-1];
            
        
    }
};