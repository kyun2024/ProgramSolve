    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string str;
        int res = 0;
        int parse_int = 0;
        int neg_flag = 1;
        cin >> str;
        for(char c : str)
        {
            if(c == '-')
            {
                res += parse_int * neg_flag;
                parse_int = 0;
                neg_flag = -1;
            }
            else if(c == '+')
            {
                res += parse_int * neg_flag;
                parse_int = 0;
            }
            else
            {
                parse_int = 10 * parse_int + c - '0';
            }
        }
        res += parse_int * neg_flag;
        cout << res << endl;
        return 0;
    }