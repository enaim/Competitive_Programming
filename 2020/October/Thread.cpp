#include <set>
#include <mutex>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <iostream>

using namespace std;

mutex mute;
mutex muteSetOperation;
set<string>st;

bool Find(string str)
{
    muteSetOperation.lock();
    bool flag = (st.find(str)!=st.end());
    muteSetOperation.unlock();
    return flag;
}

void Print(string str)
{
    mute.lock();
    cout<<str<<endl;

    muteSetOperation.lock();
    st.insert(str);
    muteSetOperation.unlock();

    mute.unlock();
}

void run(int no)
{
    int cnt = 0;
    while(cnt<10)
    {
        cnt++;
        Print("[Thread Number "+ to_string(no) + "] = " + to_string(cnt));
        this_thread::sleep_for(chrono::microseconds(100));
    }
}

void Ask()
{
    int cnt = 0;
    while(cnt<10)
    {
        cnt++;
        if(Find("[Thread Number "+ to_string(1) + "] = " + to_string(5)))
            Print("[Thread Number "+ to_string(1) + "] = " + to_string(5)+" Found!!!");
        this_thread::sleep_for(chrono::microseconds(100));
    }
}

int main()
{
    thread Thread1(run, 1);
    thread Thread2(run, 2);
    thread Thread3(Ask);

    mute.lock();
    printf("Thread Three Running.......\n");
    mute.unlock();

    Thread1.join();
    Thread2.join();
    Thread3.join();

    printf("END\n");

    return 0;
}
