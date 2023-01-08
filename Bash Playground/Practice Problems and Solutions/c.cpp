#include<iostream>
using namespace std;
int unit_length_interval(double x[], int n)
{
    int count = 1;
    double flag = x[0];
    for(int i = 1; i < n; i++) {
        if(x[i] - flag > 1.000000) {
            flag = x[i];
            count++;
        }
    }
    return count;
}

int main()
{
    double x[] ={1.4,2.4,2.5,2.6,2.7,2.9,4.8};
    cout<<unit_length_interval(x, sizeof(x)/ sizeof(x[0]));
}
