#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* Linear time complexity program for the maximum subarray problem */

int main()
{
  /* Take the input and store it in a vector. Ending is indicated by the input -9999 */
  
  vector<int> array;
  int c;
  while(1) {
    cin >> c;
    if (c == -9999)
      break;
    array.push_back(c);
  }

  /*
   * Build a record of a maximum subarray ending at each index.
   * First vector keeps the sum of each such subarray and second stores the left index of each.
   */
  
  vector<int> max_subs(array.size()), l_subs(array.size());
  max_subs[0] = array.at(0);
  l_subs[0] = 0;

  
  int lsum = array.at(0);
  for (int i = 1; i < array.size(); i++) {
    if (lsum <= 0) {
      max_subs[i] = array.at(i);
      lsum = array.at(i);
      l_subs[i] = i;
    }
    else {
      max_subs[i] = array.at(i) + lsum;
      lsum = lsum + array.at(i);
      l_subs[i] = l_subs.at(i-1);
    }
  }


  /* Calculates maximum subarray in A[0..i] from the two possibilities:
   * (A) Maximum subarray of A[0..i] lies in A[0..i-1], or   
   * (B) It is the maximum subarray ending at A[i]
   */
  int left = 0, right = 0;
  int sum = -1000;

  for (int i = 0; i < array.size(); i++) {
    int tsum = max_subs.at(i);

    if (tsum > sum) {
      sum = tsum;
      left = l_subs.at(i);
      right = i;
    }
  }

  cout << "Left: " << left <<", Right: " << right << ", and Sum: " << sum << '\n';
  
return 0;
}
