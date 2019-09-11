#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int mycompare(string x,string y)
{
    string xy=x+y;
    string yx=y+x;
    return (xy>yx)?1:0;
    
}
int largestno(vector<string> arr)
{
    sort(arr.begin(),arr.end(),mycompare);
    for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i];
        }
}
int main()
{
    std::vector<string> arr;

    //output should be 6054854654
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    largestno(arr);

    return 0;
}