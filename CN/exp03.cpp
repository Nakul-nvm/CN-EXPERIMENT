#include <iostream>
using namespace std;
string getRemainder(string dividend, string divisor)
{
    int n = dividend.length(), m = divisor.length();
    for (int i = 0; i <= (n - m); i++)
    {
        if (dividend[i] == '0')
            continue;
        for (int j = 0; j < m; j++)
        {
            if (dividend[i + j] == divisor[j])
                dividend[i + j] = '0';
            else
                dividend[i + j] = '1';
        }
    }
    string remainder = dividend.substr(n - m + 1);
    return remainder;
};

string encodeData(string data, string generator)
{
    int m = generator.length();
    string redundant(m - 1, '0');
    string code = data + redundant;
    string remainder = getRemainder(code, generator);
    code = data + remainder;
    return code;
}
bool allzero(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '0')
            return false;
    }
    return true;
}
void decodeData(string code, string generator)
{
    string remainder = getRemainder(code, generator);
    if (allzero(remainder) == false)
    {
        cout << "Error Detected In Code" << endl;
    }
    else
    {
        int n = code.length(), m = generator.length();
        string data = code.substr(0, n - m + 1);
        cout << "Data received successfully: " << data << endl;
    }
}
int main()
{
    string data, generator;
    cout << "Enter data string: ";
    cin >> data;

    cout << "Enter generator string: ";
    cin >> generator;
    string code = encodeData(data, generator);
    cout << "Encoded CRC Code: " << code << endl;
    decodeData(code, generator);
}