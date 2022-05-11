#include <iostream>
#include<string>
using namespace std;

bool correctPoint (string Address)
{
    if (Address[0] == '.'
        || Address[Address.length() - 1] == '.')
        return false;
    for (int i = 1; i < Address.length() - 1; i++)
        if (Address[i] == '.' && Address[i + 1] == '.')
            return false;
    return true;
}

bool octetValidation(string AddressPart)
{
    int n = AddressPart.length();
    if (n == 1) {
        if (AddressPart[0] >= '0' && AddressPart[0] <= '9')
            return true;
        else
            return false;
    }
    if (n == 2) {
        if (AddressPart[0] >= '1' && AddressPart[0] <= '9'
            && AddressPart[1] >= '0' && AddressPart[1] <= '9')
            return true;
        else
            return false;
    }
    if (n == 3) {
        if (AddressPart[0] == '2') {
            if (AddressPart[1] >= '0' && AddressPart[1] <= '4'
                && AddressPart[2] >= '0' && AddressPart[0] <= '9')
                return true;
            else if (AddressPart[1] == '5' && AddressPart[2] >= '0'
                    && AddressPart[2] <= '5')
                return true;
            else
                return false;
        }
        else if (AddressPart[0] == '1') {
            if (AddressPart[1] >= '0' && AddressPart[1] <= '9'
                && AddressPart[2] >= '0' && AddressPart[2] <= '9')
                return true;
            else
                return false;
        }
        else
            return false;
    }
  return false;
}

string getAddressPart(string Address, int count)
{
    int tempCount = 0;
    string AddressPart = "";
    for (int i = 0; i < Address.length(); i++) {
        if (Address[i] != '.') {
            if (tempCount == count)
                AddressPart += Address[i];
            else if (tempCount > count)
                return AddressPart;
        }
        else
            tempCount++;
    }
  return AddressPart;
}

void ipValidation(string IpAddress)
{
    if (correctPoint(IpAddress)) {
        for (int i = 0; i < 4; i++) {
            string AddressPart = getAddressPart(IpAddress, i);
            if (!octetValidation(AddressPart)) {
                cout << "Invalid" << endl;
                return;
            }
        }
        cout << "Valid" << endl;
    }
    else
        cout << "Invalid" << endl;
}

int main() {
    string IpAddress;
    cout << "Enter ip for verification: " << endl;
    cin >> IpAddress;
    ipValidation(IpAddress);
    return 0;
}