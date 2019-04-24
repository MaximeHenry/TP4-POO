/**
 *
 * \file   : SqueletteMain.cpp
 *
 * \author :
 *
 * \date   :
 *
**/

#include <iostream>
#include <exception>
#include <vector>

#include "CstCodErr.h"
#include "CException.h"

using namespace std;
using namespace nsUtil;

namespace
{
float divisionEntiere (int & a, int & b) throw (CException)
{
    if (b == 0) throw CException("Division par 0 impossible");
    return (float)a/ (float)b;
}

void testDivisionParZero (void)
{
    vector <int> num = {1,2,3,4,5,6,7,8,9,10};
    vector <int> denom = {0,1,2,3,4,5,6,7,8,9};
    for (unsigned i= 0; i < num.size();++i)
    {
        try
        {
            cout << "Division de " << num[i] << " par " << denom[i]
                 << " = " << divisionEntiere(num[i],denom[i])<< endl;
        }
        catch (CException & e)
        {
            cerr << "Erreur: " << e.getLibelle() << "de code: "
                 << e.getCodErr() << endl;
        }


    }

} // testDivisionParZero ()

} // namespace

int main (void)
{
    try
    {
        testDivisionParZero ();

        return KNoExc;
    }
    catch (const CException & e)
    {
        cerr << "Erreur        : " << e.getLibelle () << '\n'
             << "Code d'erreur = " << e.getCodErr ()  << '\n';
        return e.getCodErr();
    }
    catch (const exception & e)
    {
        cerr << "Exception standard : " << e.what () << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }

} // main()
