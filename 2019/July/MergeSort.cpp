#include<stdio.h>

int ar[100010];
int left[100010];
int right[100010];

void Merge(int l, int mid, int r)
{
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = r - mid;

	k = 0;
	for(i = l; i <= mid; i++)
		left[k++] = ar[i];
	k = 0;
	for(i = mid + 1; i <= r; i++)
		right[k++] = ar[i];

	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2)
	{
		if (left[i] < right[j])
			ar[k++] = left[i], i++;
		else
			ar[k++] = right[j], j++;
	}

	while(i < n1)
		ar[k++] = left[i], i++;
	while(j < n2)
		ar[k++] = right[j], j++;
}

void MergeSort(int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		MergeSort(l, mid);
		MergeSort(mid + 1, r);
		Merge(l, mid, r);
	}
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int i, n;
	while(scanf("%d", &n) == 1)
	{
		for(i = 0; i < n; i++)
			scanf("%d", &ar[i]);
		MergeSort(0, n - 1);
		for(i = 0; i < n; i++)
			printf("%d ", ar[i]);
		printf("\n");
	}

	return 0;
}
