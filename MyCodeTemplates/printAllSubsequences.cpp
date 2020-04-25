void printSubsequences(vector<int> arr, int index,  
                       vector<int> subarr) 
{ 
    // Print the subsequence when reach 
    // the leaf of recursion tree 
    if (index == arr.size()) 
    { 
        int l = subarr.size(); 
  
        // Condition to avoid printing 
        // empty subsequence 
        if (l != 0) 
            printArray(subarr, l); 
    } 
    else
    { 
        // Subsequence without including 
        // the element at current index 
        printSubsequences(arr, index + 1, subarr); 
  
        subarr.push_back(arr[index]); 
  
        // Subsequence including the element 
        // at current index 
        printSubsequences(arr, index + 1, subarr); 
    } 
    return; 
} 