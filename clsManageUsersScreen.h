#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4,
		eFindUser = 5, eMainMenue = 6
	};
	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Enter an option between[1-6] : ";
		short Option = clsInputValidate::ReadShortNumberBetween(1, 6,
			"Enter an option between[1-6] : ");
		return Option;
	}
	static void _ShowUsersListScreen()
	{
		/*cout << "\nUsers List Will Be Here ...";*/
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		/*cout << "\nAdd New User Screen Will Be Here ...";*/
		clsAddNewUserScreen::ShowAddNewUser();
	}
	static void _ShowDeleteUserScreen()
	{
		/*cout << "\nDelete User Screen Will Be Here ...";*/
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		/*cout << "\nUpdate User Screen Will Be Here ...";*/
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		/*cout << "\nFind User Screen Will Be Here ...";*/
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _ShowMainMenueScreen()
	{
		/*cout << "\nMain Menue Will Be Here ...";*/
	}
	static void _GoBackToManageUsersMenue()
	{
		cout << "\nPress Any Key To Go Back To Manage Users Menue ...";
		system("pause>0");
		ShowManageUsersScreen();
	}
	static void _PerformeManageUsersMenueOptions(enManageUsersMenueOptions ManageUserOption)
	{
		switch (ManageUserOption)
		{
		case enManageUsersMenueOptions::eListUsers:
			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eMainMenue:
			system("cls");
			_ShowMainMenueScreen(); // It's Optionaly , Because it return automaticly to main menue.
			break;
		}
	}

public:
	static void ShowManageUsersScreen()
	{
		if (!CheckAccessRights(clsBankUser::enPermissions::pManageUsers))
		{
			return;// this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");
		cout << setw(37) << left << "" << "=======================================\n";
		cout << setw(37) << left << "" << "\tManage Users Menue\n";
		cout << setw(37) << left << "" << "=======================================\n";
		cout << setw(37) << left << "" << "\t[1] Users List \n";
		cout << setw(37) << left << "" << "\t[2] Add New User \n";
		cout << setw(37) << left << "" << "\t[3] Delete User \n";
		cout << setw(37) << left << "" << "\t[4] Update User \n";
		cout << setw(37) << left << "" << "\t[5] Find User \n";
		cout << setw(37) << left << "" << "\t[6] Main Menue \n";
		cout << setw(37) << left << "" << "=======================================\n";
		_PerformeManageUsersMenueOptions((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
	}

};

