#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{
private:
    static void _Print(clsBankUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind User Screen");

        string UserName = "";

        cout << "\nPlease Enter an User Name : ";
        UserName = clsInputValidate::ReadString();
        while (!clsBankUser::IsUserExist(UserName))
        {
            cout << "\nUser Name not found ,Please Enter an existed one : ";
            UserName = clsInputValidate::ReadString();
        }

        clsBankUser User = clsBankUser::Find(UserName);
        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser was not Found :-(\n";
        }
        _Print(User);
    }
};

