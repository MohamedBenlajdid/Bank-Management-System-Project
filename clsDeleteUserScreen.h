#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
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

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t Delete User Screen");
        string UserName = "";

        cout << "\nEnter an User Name : ";
        UserName = clsInputValidate::ReadString();
        while (!clsBankUser::IsUserExist(UserName))
        {
            cout << "\nUser Name Not Exist , Enter Another one : ";
            UserName = clsInputValidate::ReadString();
        }

        clsBankUser User = clsBankUser::Find(UserName);
        _Print(User);

        cout << "\nYou're sure you want delete this User ? : ";
        char Ansr = 'n';
        cin >> Ansr;
        if (toupper(Ansr) == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";

                _Print(User);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }

    }
};

