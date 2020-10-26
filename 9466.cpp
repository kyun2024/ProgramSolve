#include <iostream>
#include <stack>

using namespace std;

bool check[100001];
bool loop[100001];
int link[100001];
stack<int> st,st2;

int main()
{
    int T;
    int n;
    int i, s;
    int loop_node;


    cin >> T;
    while (T--)
    {
        cin >> n;
        fill_n(check + 1, n, false);
        fill_n(loop + 1, n, false);
        while (!st.empty())
            st.pop();

        
        for (i = 1; i <= n; i++)
        {
            cin >> link[i];
        }
        for (i = 1; i <= n; i++)
        {
            //cout << i << " ";
            if (!check[i])
            {
                st.push(i);
                loop_node = 0;
                while (!check[st.top()])
                {
                    check[st.top()]=true;
                    st.push(link[st.top()]);
                }
                loop_node = st.top();
                st2.push(st.top());
                st.pop();
                while(!st.empty()){
                    st2.push(st.top());
                    //cout << st.top() << " ";
                    st.pop();
                    if(st2.top()==loop_node){
                        break;
                    }
                }
                //cout << endl;
                if(st2.top()==loop_node){
                    st2.pop();
                    while(!st2.empty()){
                        loop[st2.top()]=true;
                        st2.pop();
                    }
                }else {while(!st2.empty())st2.pop();}
                while (!st.empty()){
                    //cout << st.top() << " ";
                    st.pop();
                }
                //cout << endl;
            }
            check[i] = true;
            //cout << endl;
        }
        s = 0;
        for (i = 1; i <= n; i++)
        {
            s += loop[i];
        }
        cout << n - s << endl;
    }
}