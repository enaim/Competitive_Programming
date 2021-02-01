class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& inputMatrix) {
        int rowLength = inputMatrix.size();
          int colLength = inputMatrix[0].size();
          int countElements = 0;
          int totalElements = rowLength*colLength;
          int firstRow = 0;
          int lastRow = rowLength-1;
          int firstColumn = 0;
          int lastColumn = colLength-1;
          int step = 0;
          vector<int>result;

          // I can see you typing but I can't hear you
          // Are you still wathing?
          // Yes!
          // Okay. I will continue.
          // Sounds good. I can type here.
          // Okay!
          // I am finished my code almost. I need to give an overview over my code.
          // Ok. Do you have Zoom? We could try using Skype or Zoom.
          // Okay. I have skype.
          // Great, my Skype name is ********

          while(countElements<totalElements)
          {
            if(step == 0)
            {
                for(int i=firstColumn; i<=lastColumn; i++)
                {
                  result.push_back(inputMatrix[firstRow][i]);
                  countElements++;
                }
                firstRow++;
            }
            if(step == 1)
            {
                for(int i=firstRow; i<=lastRow; i++)
                {
                    result.push_back(inputMatrix[i][lastColumn]);
                    countElements++;
                }
                lastColumn--;
            }
            if(step == 2)
            {
                  for(int i=lastColumn; i>=firstColumn; i--)
                  {
                      result.push_back(inputMatrix[lastRow][i]);
                      countElements++;
                  }
                  lastRow--;
            }
            if(step == 3)
            {
                  for(int i=lastRow; i>=firstRow; i--)
                  {
                      result.push_back(inputMatrix[i][firstColumn]);
                      countElements++;
                  }
                  firstColumn++;
            }
            step++;
            step = step % 4;
          }
          return result;
    }
};
