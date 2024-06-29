1. Whenever we want to access the string list in C, use Double pointers to access them, First index[idx][0/1/2...] is to access the full string, to access the string individually the second i.e[0/1/2...][idx] we can use.

For Example:
list = {"car", "bike", "cycle"};    //This is the list of string

To Access the string by index we perform
list[0] = "car";
list[1] = "bike";
list[2] = "cycle";

If we want o access the string specifically index-by-index we can use perform
list[0][0] = 'c' 
list[0][1] = 'a' 
list[0][2] = 'r'
 
list[1][0] = 'b'; 
list[1][1] = 'i';
list[1][2] = 'k';
list[1][3] = 'e';

 
list[2][0] = 'c' 
list[2][1] = 'y' 
list[2][2] = 'c' 
list[2][3] = 'l' 
list[2][4] = 'e'

I was missing in starting, firstly comparing list[0] & list[1] then getting the common prefix among them and then with the prefix string compare the next string.

Optimal way:
1. Get the minimum length among all the strings, which maybe redundent but while iterating the strings to get the prefix this len will help in getting the prefix with less cycles.
2. Compare the First string with every string in the list. list[0][0] with list[1/2/3...][0] with this we can get easily the prefix.
    For example:
    list = {"flower", "flow","flight"}
    Firstly I'll compare list[0][0] with list[1/2/3..][0] if everything matches then Store that into a result, then later
    with list[0][1] with list[1/2/3..][1] if everything matches then Store that into a result, so on and so forth follows for every index upto min_len of list[0][min_len].


