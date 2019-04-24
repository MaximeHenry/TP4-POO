#include <iostream>
#include <string>

#include "CstCodErr.h"
#include "CException.h"

using namespace std;
using namespace nsUtil;

namespace
{
char ChoixException()
{
    cout << "A: exception 'exception'" << endl
         << "B: exception standard spécifique" << endl
         << "C: exception CException" << endl
         << "D: exception inconnue" << endl << endl
         << "Saisissez votre choix" << endl;
    char choix;
    cin >> choix;
    return choix;
}

void TraiterChoix (char choix)
{
    switch (choix)
    {
    case 'A':
        throw exception();
    case 'B':
    {
        string Str;
        cout << Str.at(0);
        break;
    }
    case 'C':
        throw CException("Surprise" , 123);
    case 'D':
        throw 123;
    }
}

void testExceptionsInMain()
{
    TraiterChoix(ChoixException());
}
}

int main()
{
    try {
        testExceptionsInMain();
    }
    catch (const CException &e)
    {
        cerr << "Erreur: " << e.getLibelle() << endl
             << "Code: " << e.getCodErr() <<endl;
        return e.getCodErr();
    }
    catch (const out_of_range &e)
    {
        cerr << "Exception out_of_range: " << e.what() << endl;
        return KExcStd;
    }
    catch (const exception &e)
    {
        cerr <<"Exception standard: " << e.what() << endl;
        return  KExcStd;
    }
    catch (const int &e)
    {
        cerr << "Exception int: " << e << endl;
        return KExcStd;
    }
}
