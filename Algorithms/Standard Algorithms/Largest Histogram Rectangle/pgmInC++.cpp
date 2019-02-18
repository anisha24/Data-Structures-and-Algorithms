#include<iostream>
#include<stack>
using namespace std;

int main() 
{
    long n;
    cin >> n;
    long a[n];
    for (long i = 0; i < n; i++)
        cin >> a[i];
    stack<long> s;
    long top,i=0;
    long area = 0, maxArea = 0;
    while(i<n)
    {
        if (s.empty() || a[s.top()] <= a[i])
            s.push(i++);
        else
        {
            top = s.top();
            s.pop();
            if (s.empty())
                area = a[top] * i;
            else
                area = a[top] * (i - s.top() - 1);
            if (area > maxArea)
                maxArea = area;
        }
    }
    while(s.empty() == false)
    {
        top = s.top();
            s.pop();
            if (s.empty())
                area = a[top] * i;
            else
                area = a[top] * (i - s.top() - 1);
            if (area > maxArea)
                maxArea = area;
    }
    cout<< maxArea << endl;
    return 0;
}
