#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // int *d = new int[n];
    // int *w = new int[n];
    stack<int> st;
    int re = 0;
    for (int i = 0; i < n; i++)
    {
        int d, w;
        cin>>d>>w;
        while(!st.empty() && w <= st.top())
        {
            if(st.top() == w)
            {
                re ++;
            }
            st.pop();
        }
        st.push(w);
    }
    cout << n - re;
    return 0;
}