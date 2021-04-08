#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> prime_n;
vector<int> md, p_fac;
constexpr int prime_count = 9592;

void init()
{
    prime_n.resize(100001, 0);
    md.resize(100001, 0);
    p_fac.resize(100001, 0);
}

template <int s>
void add_p(int n){
    if(n==1)return;
    p_fac[md[n]]+=s;
    add_p<s>(n/md[n]);
}

string process()
{
    int n, x;
    int i;
    string str;
    cin >> n;
    cin >> x;
    if (x == 0)
    {
        return "mint chocolate";
    }
    add_p<1>(abs(x));
    for (i = 1; i < n; i++)
    {
        cin >> str >> x;
        if (x == 0)return "mint chocolate";
        (str=="*")?add_p<1>(abs(x)):add_p<-1>(abs(x));
    }
    for (i = 2; i <= 100000; i++)
    {
        if (p_fac[i] < 0)
        {
            return "toothpaste";
        }
    }
    return "mint chocolate";
}

int main()
{
    init();
    int i, j;

    prime_n[1] = 1;
    md[1] = 1;
    for (i = 2; i <= 100000; i++)
    {
        if (!prime_n[i])
        {
            md[i] = i;
            for (j = 2 * i; j <= 100000; j += i)
            {
                if (md[j] == 0)
                {
                    md[j] = i;
                }
                prime_n[j] = 1;
            }
        }
    }

    cout << process() << endl;
    return 0;
}
