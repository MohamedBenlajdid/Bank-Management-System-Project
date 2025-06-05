#pragma once
#include<iostream>
#include<iomanip>
#include "clsBankUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
private:
	static void _Login()
	{
		bool FailedLogin = false;
		string UserName, Password;
		do
		{
			if (FailedLogin)
			{
				cout << "\n" << setw(37) << left << "" << "Invalid UserName/Password!\n\n";
			}
			cout << "\n" << setw(37) << left << "" << "Enter Your UserName : ";
			cin >> UserName;
			cout << "\n" << setw(37) << left << "" << "Enter Your Password : ";
			cin >> Password;
			CurrentUser = clsBankUser::Find(UserName, Password);
			FailedLogin = CurrentUser.IsEmpty();
		} while (FailedLogin);
		clsMainScreen::ShowMainMenue();
	}
public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		_Login();
	}
};

