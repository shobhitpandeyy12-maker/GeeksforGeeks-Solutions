class Solution {
  public:
    bool binarySearch(vector<int>& arr, int k) {
        // code here
        int start=0, end=arr.size()-1;
    
            
        
        while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==k)
            return 1;
        if(arr[mid]<k)
            start=mid+1; 
        
        if(arr[mid]>k)
        
            end=mid-1;
        }
        
        return 0;
    }
};