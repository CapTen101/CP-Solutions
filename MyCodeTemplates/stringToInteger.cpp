int stringToInteger(string s){
    stringstream geek(s); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    int x; 
    geek >> x;
    return x;
}