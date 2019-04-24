/**
**
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

#include "CstCodErr.h"
#include "CException.h"

using namespace std;
using namespace nsUtil;

namespace
{
    void testFailure (void)
    {
        cin.exceptions (ios_base::failbit | ios_base::eofbit);
        while (true)
        {
            try
            {
                int nombre;
                cout << "Saisir un nombre: " << endl;
                cin >> nombre;
            }
            catch (exception &e)
            {
                if (cin.eof()) cerr << "Fin de fichier" << endl;
                else if (cin.fail()) cerr << "Erreur de lecture" << endl;
                else cerr << e.what() << endl;
                throw;
            }

        }

    } // TestFailure  ()

} // namespace

int main (void)
{
    try
    {
        testFailure ();

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
