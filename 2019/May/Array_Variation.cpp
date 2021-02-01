/*
    Md Elias Hassan Naim
    Codeforces: enaim
    Bangladesh University of Business & Technology (BUBT)
*/

#include<stdio.h>
#include<stdlib.h>


int main()
{
///Array Declaration:

///Variant 1:
	int ar1[10];

///Variant 2:
    int ar2[10] = {0};

///Variant 3:
    int ar3[] = {1,2,3,4,5,6,7,8,9,0};

///Variant 4:
    int ar4[10] = {1,2,3,4,5,6,7,8,9,0};

///Variant 5:
    int *ar5;
    ar5 = (int*)malloc(sizeof(int)*10);

/// For all variations of assigning value,input-output:
    int ar[10];
    int i,*p;
    p = ar;


///Assigning Value in Array:

///Variant 1:
	for(i=0;i<10;i++)
        ar[i] = i;

///Variant 2:
	for(i=0;i<10;i++)
        *(ar+i) = i;

///Variant 3:
    p = ar;
    for(i=0;i<10;i++)
        *p = i , p++;

///Variant 4:
    p = ar;
    for(i=0;i<10;i++)
        *(p+i) = i;

///Variant 5:
    p = ar;
    for(i=0;i<10;i++)
        p[i] = i;


///Input values in Array:

///Variant 1:
    for(i=0;i<10;i++)
        scanf("%d",&ar[i]);

///Variant 2:
    for(i=0;i<10;i++)
        scanf("%d",ar+i);

///Variant 3:
    p = ar;
    for(i=0;i<10;i++)
        scanf("%d",p),p++;

///Variant 4.1:
    p = ar;
    for(i=0;i<10;i++)
        scanf("%d",p+i);

///Variant 4.2:
    p = ar;
    for(i=0;i<10;i++)
        scanf("%d",&(*(p+i)));      /// &*(p+i) also right

///Variant 5:
    p = ar;
    for(i=0;i<10;i++)
        scanf("%d",&p[i]);


///Print values from an Array:

///Variant 1:
    for(i=0;i<10;i++)
        printf("%d ",ar[i]);
    printf("\n");

///Variant 2:
    for(i=0;i<10;i++)
        printf("%d ",*(ar+i));
    printf("\n");

///Variant 3:
    p = ar;
    for(i=0;i<10;i++)
        printf("%d ",*p),p++;
    printf("\n");

///Variant 4:
    p = ar;
    for(i=0;i<10;i++)
        printf("%d ",*(p+i));
    printf("\n");

///Variant 5:
    p = ar;
    for(i=0;i<10;i++)
        printf("%d ",p[i]);
    printf("\n");

    return 0;
}
