#include <bits/stdc++.h>
using namespace std;

// Function to calculate the nth Fibonacci number using memoization
int maxProfit(vector<int>& in)
{
  vector<int> out;
  int max = 0;
  
  int min = in[0];
  for(int i = 1; i < in.size(); i++)
  {
      int cost = in[i] - min;
      max = (max > cost) ? max : cost;
      min = (min < in[i]) ? min : in[i];
  }
  return max;
}

int main() {
    int n;
    vector<int> in;
    cout << "Enter no of input: ";
    cin >> n ;
    
    for(int i = 0; i < n ; i++)
    {
        int a;
        cin >> a;
        in.push_back(a);
    }
    
    int result = maxProfit(in);
    cout << "Max profit made was: " << result << endl;

    return 0;
}