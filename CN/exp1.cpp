#include <iostream>
using namespace std;
string bitStuffing(string &inputString)
{
    int count = 0, n = inputString.length();
    string flag = "11111";
    string ans = "";
    ans += flag;
    for (int i = 0; i < n; i++)
    {
        if (inputString[i] == '1')
            count++;
        else
            count = 0;
        ans.push_back(inputString[i]);
        if (count == 5)
        {
            ans.push_back('0');
            count = 0;
        }
    }
    ans += flag;

    return ans;
};
string characterStuffing(string &inputString)
{
    string stx = "00000010";
    string etx = "00000011";
    string dle = "00010000";
    string ans = "";
    ans += stx;
    int n = inputString.length();
    for (int i = 0; i <= n - 8; i++)
    {
        if (inputString.substr(i, 8) == stx || inputString.substr(i, 8) == etx ||
            inputString.substr(i, 8) == dle)
        {
            ans += dle;
            ans += inputString.substr(i, 8);
            i += 7;
        }
        else
        {
            ans += inputString[i];
        }
    }
    ans += etx;
    return ans;
}
string byteStuffing(string &inputString, string &esc, string &flag)
{
    string ans = "";
    ans += flag;
    int n = inputString.length();
    for (int i = 0; i <= n - 8; i++)
    {
        if (inputString.substr(i, 8) == flag

            || inputString.substr(i, 8) == esc)
        {
            ans += esc;
            ans += inputString.substr(i, 8);
            i += 7;
        }
        else
        {
            ans += inputString[i];
        }
    }
    ans += flag;
    return ans;
}
int main()
{
    string inputString;
    cout << "Enter Input String: ";
    cin >> inputString;
    cout << "Character Stuffing: " << characterStuffing(inputString) << endl;
    cout << "Bit Stuffing: " << bitStuffing(inputString) << endl;
    string esc, flag;
    cout << "Enter Escape Sequence: ";
    cin >> esc;
    cout << "Enter Flag Sequence: ";
    cin >> flag;
    cout << "Byte Stuffing: " << byteStuffing(inputString, esc, flag) << endl;
}