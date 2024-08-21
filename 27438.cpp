#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

long long total_count[] = {0, 0, 0, 1LL, 19LL, 280LL, 3700LL, 45991LL, 549739LL, 6394870LL, 72915400LL, 818740081LL,
    9082453159LL, 99766977760LL, 1087013539000LL, 11762766729271LL, 126545925214279LL, 1354561349342950LL, 14435830371578500LL,
    153252438815221561LL, 1621385474825287099LL
};

long long nth_count[21];
long long max_bc;

long long exp_ten[19];

//#define _DEBUG_FLAG
//#define _LOOP_INPUT

string get_shom_number(long long ith, long long bc, int leading_six)
{
    #ifdef _DEBUG_FLAG
    cout << "recr) " << ith << " " << bc << " " << leading_six << endl;
    #endif
    if(ith == 1 && bc == 3 && leading_six == 0)
        return "666";
    if(bc == 3 && leading_six == 1)
        return "66"+to_string(ith-1);
    if(bc ==3 && leading_six == 2)
        return (ith<=10?"60":"6")+to_string(ith-1);
    if(bc < 0)return "-1";
    long long sc = 0, cp_sc = 0;
    int i = 0;
    if(bc == max_bc)
    {
        sc += total_count[bc-1];
        for(i=1;i<=9;++i)
        {
            cp_sc = sc;
            if(i == 6)
            {
                cp_sc += total_count[bc]-9*total_count[bc-1];
            }
            else
            {
                cp_sc += total_count[bc-1];
            }
            if(ith <= cp_sc)break;
            sc = cp_sc;
        }
    }
    else
    {
        for(i=0;i<=9;++i)
        {
            cp_sc = sc;
            if(i==6)
            {
                if(leading_six == 1)
                {
                    cp_sc += (total_count[bc+1] - 9 * total_count[bc] - 9 * total_count[bc-1]);
                    #ifdef _DEBUG_FLAG
                    cout << total_count[bc+1] << " - " << 9*total_count[bc] << " - " << 9*total_count[bc-1] << " = " 
                    << total_count[bc+1]-9*total_count[bc]-9*total_count[bc-1] << endl;
                    #endif
                }
                else if(leading_six == 2)
                {
                    cp_sc += exp_ten[bc-1];
                    if(ith <= cp_sc)
                    {
                        ostringstream oss;
                        oss << 6 << setw(bc-1) << setfill('0') << ith-sc-1;
                        return oss.str();
                    }
                }
                else
                {
                    cp_sc += total_count[bc] - 9*total_count[bc-1];
                }
            }
            else
            {
                cp_sc += total_count[bc-1];
            }
            #ifdef _DEBUG_FLAG
            cout << i << " " << cp_sc << endl;
            #endif
            if(ith <= cp_sc)break;
            sc = cp_sc;
        }
    }
    // cout << "sc : " << sc << ", i : " << i << endl;
    if(i == 6 && leading_six == 2)
    {
        return '6' + to_string(ith);
    }
    return static_cast<char>(i+'0') + get_shom_number(ith-sc, bc-1, (i==6?leading_six+1:0));
}

int main()
{
    long long n, i;
    for(i=1;i<21;++i)
    {
        nth_count[i] = total_count[i]-total_count[i-1];
    }
    exp_ten[0] = 1;
    for(i=1;i<=18;++i)exp_ten[i] = 10LL*exp_ten[i-1];
    #ifdef _LOOP_INPUT
    for(n=1;n<=549739LL;++n)
    {
    #endif
    #ifndef _LOOP_INPUT
        cin >> n;
    #endif
        for(max_bc = 3; max_bc<21 && n > total_count[max_bc];++max_bc);
        cout << get_shom_number(n, max_bc, 0) << endl;
    #ifdef _LOOP_INPUT
    }
    #endif
    return 0;
}