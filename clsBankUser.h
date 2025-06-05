#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

class clsBankUser : public clsPerson
{
private:
	enum enMode {
		eEmptyMode = 1 , eUpdateMode = 2 , eAddNewMode = 3
	};

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;

	static clsBankUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUsersData;
		vUsersData = clsString::Split(Line, Seperator);

		return clsBankUser(enMode::eUpdateMode, vUsersData[0], vUsersData[1], vUsersData[2],
			vUsersData[3], vUsersData[4], vUsersData[5], stod(vUsersData[6]));

	}

	static string _ConvertUserObjectToLine(clsBankUser User, string Seperator = "#//#")
    {

        string stUserRecord = "";
        stUserRecord += User.FirstName + Seperator;
        stUserRecord += User.LastName + Seperator;
        stUserRecord += User.Email + Seperator;
        stUserRecord += User.Phone + Seperator;
        stUserRecord += User.UserName + Seperator;
        stUserRecord += User.Password + Seperator;
        stUserRecord += to_string(User.Permissions);

        return stUserRecord;

    }

	static  vector <clsBankUser> _LoadUsersDataFromFile()
	{

		vector <clsBankUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankUser User = _ConvertLinetoUserObject(Line);

				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}

	static void _SaveUsersDataToFile(vector <clsBankUser> vUsers)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankUser U : vUsers)
			{
				if (U._MarkedForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsBankUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsBankUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

	}

	void _Add()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsBankUser _GetEmptyUserObject()
	{
		return clsBankUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}


public:
	clsBankUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string Password, int Permissions) :clsPerson(FirstName, LastName,
			Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
	};

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}
	_declspec(property( get = GetPassword, put = SetPassword )) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	static clsBankUser Find(string UserName)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsBankUser Find(string UserName ,string Password)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExists = 2 };

	static bool IsUserExist(string UserName)
	{
		clsBankUser User1 = clsBankUser::Find(UserName);
		return (!User1.IsEmpty());
	}

	bool Delete()
	{
		vector<clsBankUser> vUsers;
		vUsers = clsBankUser::_LoadUsersDataFromFile();
		for (clsBankUser& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::eEmptyMode:
		{
			if (IsEmpty())
			{

				return enSaveResults::svFaildEmptyObject;

			}

		}

		case enMode::eUpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::eAddNewMode:
		{
			//This will add new record to file or database
			if (clsBankUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserNameExists;
			}
			else
			{
				_Add();

				//We need to set the mode to update after add new
				_Mode = enMode::eUpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}

		}
	}

	static clsBankUser GetAddNewUser(string UserName)
	{
		return clsBankUser(enMode::eAddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsBankUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;

	}

};

