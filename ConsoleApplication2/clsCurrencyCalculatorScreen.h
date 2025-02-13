#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsString.h"
#include "clsCurrenciesListScreen.h"
#include <iomanip>
class clsCurrencyCalculatorScreen : clsScreen
{
    static bool _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
           
            return true;
        }
        else
        {
          
            return false;
        }
    }
    static void _PrintCurrency(clsCurrency Currency)
    {
       
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
    static float _FromCurrency1ToDollar(float Amount , float NewAmount , clsCurrency Currency1    ) {
        clsCurrency Currency2 = clsCurrency::FindByCode("Usd");
        NewAmount = Amount / Currency1.Rate();
        
        return NewAmount;

    }
public:
	static void _ShowCurrencyCalculatorScreen() {
        char Answer = 'y';
        float Amount = 0;
        float NewAmount = 0;

        do {
            system("cls");
            _DrawScreenHeader("Cyrrency Calculator Screen");
            string CurrencyCode1 = "";
            cout << "Please Enter Currency Code no1? ";
            cin >> CurrencyCode1;
            clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode1);
            if (!_ShowResults(Currency1)) {
                break;
            }
            string CurrencyCode2 = "";
            cout << "\nPlease Enter Currency Code no2? ";
            cin >> CurrencyCode2;
            clsCurrency Currency2 = clsCurrency::FindByCode(CurrencyCode2);
            if (!_ShowResults(Currency2)) {
                break;
            }
            
            cout << "\nEnter Exchange Amount ";
            cin >> Amount;
            if (clsString::UpperAllString(CurrencyCode2) == "USD") {
                NewAmount = _FromCurrency1ToDollar(Amount, NewAmount, Currency1);
                _PrintCurrency(Currency1);
                cout << "\n" << Amount << clsString::UpperAllString(" USD")
                    << " = " << NewAmount << " " << clsString::UpperAllString(CurrencyCode2);

                cout << " Do You want to perform another Calculation ? ";
                cin >> Answer;

            }
            else {
                cout << "\n\nConvert From: \n";
                _PrintCurrency(Currency1);
                cout << Amount << clsString::UpperAllString(CurrencyCode1)
                    << " = " << _FromCurrency1ToDollar(Amount , NewAmount ,Currency1) << clsString::UpperAllString("usd");
                Amount = _FromCurrency1ToDollar(Amount, NewAmount, Currency1);
                cout << "\n\nTo: \n";
                _PrintCurrency(Currency2);
                NewAmount = Currency2.Rate() * Amount;
                cout << "\n" << Amount << clsString::UpperAllString(" USD")
                    << " = " << NewAmount << " " << clsString::UpperAllString(CurrencyCode2);
                cout << "\n Do You want to perform another Calculation ? ";
                cin >> Answer;
            }
        } while (Answer == 'y' || Answer == 'Y');
	}
}; 

