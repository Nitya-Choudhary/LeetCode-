#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
     int findconsecutiveones(vector<int>arr){
       int count=0;
       int maxi=0;
       for(int i=0;i<arr.size();i++){
         if(arr[i]==1){
           count++;
          
         }
         else{
           count=0;
         }
          maxi= max(maxi, count);
       }
       return maxi;
     }
}
