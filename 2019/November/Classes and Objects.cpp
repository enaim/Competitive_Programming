class Student{
    int scores[5];
public:
    void input()
    {
        for(int i=0;i<5;i++)
            scanf("%d",&scores[i]);
    }
    int calculateTotalScore()
    {
        int sum = 0;
        for(int i=0;i<5;i++)
            sum+=scores[i];
        return sum;
    }
};
