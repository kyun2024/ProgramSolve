#include <iostream>

using namespace std;

int Mm[3], mm[3], a[3];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    cin >> a[0] >> a[1] >> a[2];
    Mm[0] = mm[0] = a[0];
    Mm[1] = mm[1] = a[1];
    Mm[2] = mm[2] = a[2];
    while(--n)
    {
        int temp[3];
        cin >> a[0] >> a[1] >> a[2];
        temp[0] = max(Mm[0], Mm[1])+a[0];
        temp[1] = max(Mm[0], max(Mm[1], Mm[2]))+a[1];
        temp[2] = max(Mm[1], Mm[2])+a[2];
        Mm[0] = temp[0]; Mm[1] = temp[1]; Mm[2] = temp[2];

        temp[0] = min(mm[0], mm[1])+a[0];
        temp[1] = min(mm[0], min(mm[1], mm[2]))+a[1];
        temp[2] = min(mm[1], mm[2])+a[2];
        mm[0] = temp[0]; mm[1] = temp[1]; mm[2] = temp[2];
    }

    cout << max(Mm[0], max(Mm[1], Mm[2])) << " " << min(mm[0], min(mm[1], mm[2])) << endl;

    return 0;
}