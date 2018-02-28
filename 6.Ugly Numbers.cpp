#include <bits/stdc++.h>
using namespace std;

#define mx 1000

// Find Minimum among three numbers
long int minimum(long int x, long int y, long int z)
{
    return min(x,min(y,z));
}

// Actual Method that computes all Ugly Numbers till the required range
long int uglyNumber(int cnt)
{

    long int arr[mx], val;

    // index of last multiple of 2 --> i2
    // index of last multiple of 3 --> i3
    // index of last multiple of 5 --> i5
    int i2, i3, i5, lastIndex;

    arr[0] = 1;
    i2 = i3 = i5 = 0;
    lastIndex = 1;


    while(lastIndex<=cnt-1)
    {

        val = minimum(2*arr[i2], 3*arr[i3], 5*arr[i5]);

        arr[lastIndex] = val;
        lastIndex++;

        if(val == 2*arr[i2])    i2++;
        if(val == 3*arr[i3])    i3++;
        if(val == 5*arr[i5])    i5++;
    }

    return arr[lastIndex-1];

}

int main()
{

    long int num;
    int cnt;

    cout<<"Which Ugly Number : ";
    cin>>cnt;

    num = uglyNumber(cnt);

    cout<<num<<endl;

    return 0;
}
