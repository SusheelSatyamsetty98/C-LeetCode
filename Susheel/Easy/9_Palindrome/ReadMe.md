In Palindrome, 
1. If we check the number(input) / 10 is not zero then perform the action(modulus, adding to res, divide further with 10) is a correct, but there are some corner case if the number(input) contain 0 in between then the number(input) /10 will be zero and that case will fail even if the number is palindrome it returns false. So to handle this case if we copy the input into char buffer and reduce the len until it become zero then only all the number get validated and then only we get determine whether it is palindrome or not. This is exaplined below with an example

For Example:
User Input : 1001

After copying the number into buffer will get the len as 4.

For len = 4;
  (len > 0)
    temp1 = (num % 10) = (1001 % 10) = 1
    res = (res * 10) + temp1 = (0 * 10) + 1 = 1
    temp = temp/10 = (1001/10) = 100
    len-- = 3

For len = 3;
  (len > 0)
    temp1 = (num % 10) = (100 % 10) = 0
    res = (res * 10) + temp1 = (1 * 10) + 0 = 10
    temp = temp/10 = (100/10) = 10
    len-- = 2

For len = 2;
  (len > 0)
    temp1 = (num % 10) = (10 % 10) = 0
    res = (res * 10) + temp1 = (10 * 10) + 0 = 100
    temp = temp/10 = (10/10) = 1
    len-- = 1

For len = 1;
  (len > 0)
    temp1 = (num % 10) = (1 % 10) = 1
    res = (res * 10) + temp1 = (100 * 10) + 1 = 1001
    temp = temp/10 = (1/10) = 0
    len-- = 0

