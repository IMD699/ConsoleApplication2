#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "Global.h"
class clsLoginRegister {
    static string _DateToDateLine(string Sep = "/##/") {
        clsDate _Date;
        string Date = clsDate::GetSystemDateTimeString();
        string DateLine = Date + Sep + CurrentUser.UserName + Sep + CurrentUser.Password + Sep + to_string(CurrentUser.Permissions);
        return DateLine;
    }
public:
	static void LoginRegister() {
		 
            fstream MyFile;
            string DateLine = _DateToDateLine();
            MyFile.open("LoginRegister.txt", ios::out | ios::app);//read Mode

            if (MyFile.is_open())
            {
                        MyFile << DateLine << endl;
               
                MyFile.close();

            }
		
	}
};