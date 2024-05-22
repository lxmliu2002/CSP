#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n;
    cin >> n;
    stack<long long> st;
    long long num;
    long long sum = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> num;
        while (!st.empty() && num >= st.top())
        {
            st.pop();
        }
        sum += st.size();
        st.push(num);
    }
    cout << sum;
    return 0;
}