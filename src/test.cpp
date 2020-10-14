#include<iostream>
#include<string>
using namespace std;

void swapString(string &s, int start, int end)
{
    string tmp;
    while(start<end)
    {
        char tmp = s[start];
        s[start]=s[end];
        s[end]=tmp;
        start++;
        end--;
    }
}

void reverseString(string &str)
{
    // remove duplicate space
    int start = 0;
    int end = str.size();
    swapString(str,start,end);  // str="eman ruoy si tahw"
    int cur = start;
    while(cur<end)
    {
        while(str[cur] !=' ' && cur < end)cur++;
        swapString(str, start, cur-1);
        cur = cur + 1;
        start = cur;
    }
    // Notice, Don't forget !!!
    swapString(str,start,cur-1);
}

int main()
{
    string testString = "what is  your  name";
    reverseString(testString);
    cout<<testString<<endl;
}