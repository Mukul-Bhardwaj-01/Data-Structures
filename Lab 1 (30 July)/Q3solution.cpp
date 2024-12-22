//30 July Q3 Solution
/*A ball is dropped with a certain velocity from a certain height.
Its velocity decreases by half after each bounce.
Find the number of bounces(hits) it takes before coming to rest.*/

#include<iostream>
using namespace std;

int count_bounces(int v)
{
    int bounces=0;
    while(v>0)
    {
        bounces++;
        v=v/2;
    }
    return bounces;
}

int main()
{
    int v, bounces;
    cout<<"Enter the velocity with which the ball was dropped : ";
    cin>>v;
    bounces = count_bounces(v);
    cout<<"The number of times the ball with velocity "<< v <<"m/s bounces before coming to rest is : "<<bounces<<endl;
}