#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> vec) {
    int i,j;
    int mx = -100000000;
    for(i=1;i<5;i++)
        for(j=1;j<5;j++)
        {
            int sum = vec[i-1][j-1]+vec[i-1][j]+vec[i-1][j+1]+vec[i+1][j-1]+vec[i+1][j]+vec[i+1][j+1]+vec[i][j];
            mx =max(mx,sum);
        }
    return mx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
