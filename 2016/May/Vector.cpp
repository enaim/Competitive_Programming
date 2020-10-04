#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include<vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

#define pb push_back

int main()
{
   // create a vector to store int
   vector<int> vec;
   int i;

   // display the original size of vec
   cout << "vector size = " << (int)vec.size() << endl;

   // push 5 values into the vector
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }

   // display extended size of vec
   cout << "extended vector size = " << vec.size() << endl;

   // access 5 values from the vector
   for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }



/**
   sort(vec.begin(),vec.end());
   sort(vec.rbegin(),vec.rend());   ///Reverse order
*/

   vector<int>g[10];
   g[0].pb(23);
   g[3].pb(23);
   g[4].pb(23);
   g[0].clear();


    vector<string>vs;
    vs.pb("Maksud");
    vs.pb("Madfssud");
    vs.pb("Maksusdfsfdfd");

    for(int i=0;i<vs.size();i++)
        cout<<vs[i].size()<<endl;


   return 0;
}
