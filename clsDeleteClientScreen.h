#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{
private:
    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:

    static void ShowDeleteClient()
    {
        if (!CheckAccessRights(clsBankUser::enPermissions::pDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }

        string AccountNumber = "";

        cout << "\nEnter an Account Number : ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Not Exist , Enter Another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);

        cout << "\nYou're sure you want delete this client ? : ";
        char Ansr = 'n';
        cin >> Ansr;
        if (toupper(Ansr) == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _Print(Client);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }

    }
};

