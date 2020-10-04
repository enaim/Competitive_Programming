#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10


#include <cmath>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
 *  Complete below function. And make sure to include required headers files.
 *
 */
void ouputRemainderToConsole(vector<int> proportions,vector<int> availableGrams) {
   int mx = 0;
   int n = proportions.size();
   for(int i=0;i<n;i++)
   {
     mx = max(mx, availableGrams[i]/proportions[i]);
   }
   bool f = false;
    for(int i=0;i<n;i++){
        if(f)   cout<<" ";
        cout<<availableGrams[i] - mx*proportions[i];
    }
    cout<<endl;
}

// DO NOT MODIFY anything below this line.
int main() {
    /* Read input from STDIN. Print output to STDOUT */
    vector<int> proportion ;
    vector<int> availableGram;
    string line1,line2;
    getline(cin,line1);
    istringstream iss(line1);
    int i;
    while (iss >> i)
    {
        proportion.push_back(i);
        iss.ignore();
        iss.ignore();
    }
    getline(cin,line2);
    istringstream iss2(line2);
    while (iss2 >> i)
    {
        availableGram.push_back(i);
        iss2.ignore();
        iss2.ignore();
    }
    ouputRemainderToConsole(proportion, availableGram);

    return 0;
}
