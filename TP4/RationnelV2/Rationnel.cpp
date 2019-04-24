/**
 *
 * \file    Rationnel.cpp
 *
 * \authors M. Laporte, D. Mathieu
 *
 * \date    07/12/2011
 *
 * \version V1.0
 *
 * \brief   Definition des methodes de la classe Rationnel
 *             (version 1)
 *
 **/
#include <iostream>
#include <cmath>    // abs()

#include "Rationnel.h"
#include "CException.h"
#include "CstCodErr.h"

#define RATIONNEL nsMath::Rationnel

using namespace std;
using namespace nsMath;

namespace
{
/*
    unsigned PGDC (const unsigned a, const unsigned b)
    {
        if (a == b) return a;
        if (a < b) return PGDC (a, b - a);
        if (a > b) return PGDC (b, a - b);

    } // PGDC()
*/
    unsigned PGDC (unsigned a, unsigned b)
    {
        for ( ; a != b; )
        {
            if (a < b)
                b -= a;
            else
                a -= b;
        }
        return a;

    } // PGDC()

} // namespace

RATIONNEL::Rationnel (const int num   /* = 0 */,
                      const int denom /* = 1 */) throw (CException)
    : myNum (num), myDenom (denom)
{
    simplify ();

} // Rationnel()

RATIONNEL::Rationnel (const Rationnel & r)
    : myNum (r.myNum), myDenom (r.myDenom) {}

void RATIONNEL::display (void) const
{
    cout << myNum << '/' << myDenom;

} // display()

void RATIONNEL::simplify (void)
{
    if (myDenom == 0) throw CException("Division par 0 impossible");
    if (myDenom < 0)
    {
        myNum   = -myNum;
        myDenom = -myDenom;
    }
    int pgdc = (myNum == 0) ? myDenom
                            : PGDC (abs (myNum), abs (myDenom));

    myNum   /= pgdc;
    myDenom /= pgdc;

} // simplify()

bool RATIONNEL::operator < (const Rationnel & r) const
{
    return myNum * r.myDenom < myDenom * r.myNum;

} // operator <

bool RATIONNEL::operator == (const Rationnel & r) const
{
    return myNum == r.myNum && myDenom == r.myDenom;

} // operator ==

RATIONNEL RATIONNEL::operator + (const Rationnel & r)
    const
{
    return Rationnel (myNum   * r.myDenom + r.myNum * myDenom,
                      myDenom * r.myDenom);

} // operator +

RATIONNEL RATIONNEL::operator - (const Rationnel & r)
    const
{
    return Rationnel (myNum   * r.myDenom - r.myNum * myDenom,
                      myDenom * r.myDenom);

} // operator -

RATIONNEL RATIONNEL::operator * (const Rationnel & r)
    const
{
    return Rationnel (myNum   * r.myNum,
                      myDenom * r.myDenom);

} // operator *

RATIONNEL RATIONNEL::operator / (const Rationnel & r)
    const
{
    return Rationnel (myNum * r.myDenom, myDenom * r.myNum);

} // operator /

#undef RATIONNEL
