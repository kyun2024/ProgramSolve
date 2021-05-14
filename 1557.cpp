#include <iostream>
#include <algorithm>

using namespace std;

constexpr int PN1 = 4317;
constexpr int PN2 = 10037;
constexpr int PN3 = 7963;
constexpr int PN4 = 2491;
constexpr int PN5 = 251;
constexpr int PN6 = 2;

long long primes[PN1];
long long primes2[PN2];
long long primes3[PN3];
long long primes4[PN4];
long long primes5[PN5];
long long primes6[PN6];

int main()
{
    int i1, i2, i3, i4, i5, i6;
    int c{}, c2{}, c3{}, c4{}, c5{}, c6{};
    for (i1 = 2; i1 <= 41231; i1++)
    {
        for (i2 = 2; i2 * i2 <= i1; i2++)
        {
            if (i1 % i2 == 0)
                break;
        }
        if (i2 * i2 > i1)
        {
            //cout << i1 * i1 << " ";
            primes[c++] = i1 * i1;
        }
    }
    for (i1 = 0; i1 < c; i1++)
    {
        for (i2 = i1 + 1; i2 < c; i2++)
        {
            if (primes[i1] * primes[i2] <= 1700000000)
            {
                //cout << primes[i1] * primes[i2] << " ";
                primes2[c2++] = primes[i1] * primes[i2];
            }
            else
                break;
        }
    }
    sort(primes2,primes2+c2);
    for (i1 = 0; i1 < c; i1++)
    {
        for (i2 = i1 + 1; i2 < c; i2++)
        {
            if (primes[i1] * primes[i2] <= 1700000000)
            {
                for (i3 = i2 + 1; i3 < c; i3++)
                {
                    if (primes[i1] * primes[i2] * primes[i3] <= 1700000000)
                    {
                        //cout << primes[i1] * primes[i2] * primes[i3] << " ";
                        primes3[c3++] = primes[i1] * primes[i2] * primes[i3];
                    }
                    else
                        break;
                }
            }
            else
                break;
        }
    }
    sort(primes3,primes3+c3);
    for (i1 = 0; i1 < c; i1++)
    {
        for (i2 = i1 + 1; i2 < c; i2++)
        {
            if (primes[i1] * primes[i2] <= 1700000000)
            {
                for (i3 = i2 + 1; i3 < c; i3++)
                {
                    if (primes[i1] * primes[i2] * primes[i3] <= 1700000000)
                    {
                        for (i4 = i3 + 1; i4 < c; i4++)
                        {
                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] <= 1700000000)
                            {
                                //cout << primes[i1] * primes[i2] * primes[i3] * primes[i4] << " ";
                                primes4[c4++] = primes[i1] * primes[i2] * primes[i3] * primes[i4];
                            }
                            else
                                break;
                        }
                    }
                    else
                        break;
                }
            }
            else
                break;
        }
    }
    sort(primes4,primes4+c4);
    for (i1 = 0; i1 < c; i1++)
    {
        for (i2 = i1 + 1; i2 < c; i2++)
        {
            if (primes[i1] * primes[i2] <= 1700000000)
            {
                for (i3 = i2 + 1; i3 < c; i3++)
                {
                    if (primes[i1] * primes[i2] * primes[i3] <= 1700000000)
                    {
                        for (i4 = i3 + 1; i4 < c; i4++)
                        {
                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] <= 1700000000)
                            {
                                for (i5 = i4 + 1; i5 < c; i5++)
                                {
                                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] <= 1700000000)
                                    {
                                        //cout << primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] << " ";
                                        primes5[c5++] = primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5];
                                    }
                                    else
                                        break;
                                }
                            }
                            else
                                break;
                        }
                    }
                    else
                        break;
                }
            }
            else
                break;
        }
    }
    sort(primes5,primes5+c5);
    for (i1 = 0; i1 < c; i1++)
    {
        for (i2 = i1 + 1; i2 < c; i2++)
        {
            if (primes[i1] * primes[i2] <= 1700000000)
            {
                for (i3 = i2 + 1; i3 < c; i3++)
                {
                    if (primes[i1] * primes[i2] * primes[i3] <= 1700000000)
                    {
                        for (i4 = i3 + 1; i4 < c; i4++)
                        {
                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] <= 1700000000)
                            {
                                for (i5 = i4 + 1; i5 < c; i5++)
                                {
                                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] <= 1700000000)
                                    {
                                        for (i6 = i5 + 1; i6 < c; i6++)
                                        {
                                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] <= 1700000000)
                                            {
                                                //cout << primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6]<< " ";
                                                primes6[c6++] = primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6];
                                            }
                                            else
                                                break;
                                        }
                                    }
                                    else
                                        break;
                                }
                            }
                            else
                                break;
                        }
                    }
                    else
                        break;
                }
            }
            else
                break;
        }
    }
    sort(primes6,primes6+c6);
    //cout << c << " " << c2 << " " << c3 << " " << c4 << " " << c5 << " " << c6 << endl;
    
    int n, i;
    long long res = 0, valid;
    long long s, e, mid;
    cin >> n;
    s = 1;
    e = n*2; // 2000000000; //1644933981;
    while (s < e)
    {
        mid = (s + e) / 2;
        res = mid;
        for (i = 0; i < PN1; i++)
        {
            res -= mid / primes[i];
        }
        for (i = 0; i < PN2; i++)
        {
            res += mid / primes2[i];
        }
        for (i = 0; i < PN3; i++)
        {
            res -= mid / primes3[i];
        }
        for (i = 0; i < PN4; i++)
        {
            res += mid / primes4[i];
        }
        for (i = 0; i < PN5; i++)
        {
            res -= mid / primes5[i];
        }
        for (i = 0; i < PN6; i++)
        {
            res += mid / primes6[i];
        }
        
        if (res >= n)
        {
            e = mid;
        }
        else
            s = mid+1;
    }
    cout << e << endl;
    
    return 0;
