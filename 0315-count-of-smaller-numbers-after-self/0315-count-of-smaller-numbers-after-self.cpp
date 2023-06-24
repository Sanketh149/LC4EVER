class Solution {
public:
    void merge(int low, int mid, int high, vector<pair<int, int>>& arr,vector<int>& count)
    {
        vector<pair<int, int>> temp;;
        
        int i = low;
        int j = mid + 1;
        
        while(i <= mid && j <= high)
        {
            if(arr[i].first <= arr[j].first)
            {
                temp.push_back(arr[j++]); 
            }
            else
            {
                count[arr[i].second] += (high - j + 1);
                
                temp.push_back(arr[i++]);
            }
        }
        
        while(i <= mid)
        {
            temp.push_back(arr[i++]);
        }
        
        while(j <= high)
        {
            temp.push_back(arr[j++]);
        }
        
        for(int i = low; i <= high; i++)
            arr[i] = temp[i - low];
        
    }
                
    void mergeSort(int left, int right, vector<pair<int, int>>& arr, vector<int>& count)
    {
        if(left >= right)
            return;

        int mid = left + (right - left) / 2;
        
        mergeSort(left, mid, arr, count);
        mergeSort(mid + 1, right, arr, count);
        
        merge(left, mid, right, arr, count);
    }
    
	vector<int> countSmaller(vector<int>& nums) {
	    
        int n=nums.size();
	    vector<pair<int, int>> arr;
        
	    for(int i = 0; i < n; i++)
	        arr.push_back({nums[i], i});
	    
	    vector<int> count(n, 0);
	    
	    mergeSort(0, n - 1, arr, count);
	    
	    return count;
	}
};