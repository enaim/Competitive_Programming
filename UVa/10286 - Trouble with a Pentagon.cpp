#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    double p_l,s_l;

    while(1==scanf("%lf",&p_l))
    {										///http://www.questtosolve.com/browse.php?pid=10286
        s_l = p_l * 1.067395682;           ///((sin 108)/(sin 63))
        printf("%.10lf\n",s_l);
    }

    return 0;
}


