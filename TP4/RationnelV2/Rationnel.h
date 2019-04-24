/**
 *
 * \file    Rationnel.h
 *
 * \authors M. Laporte, D. Mathieu
 *
 * \date    01/02/2008
 *
 * \version V1.0
 *
 * \brief   Declaration de la classe Rationnel (V1)
 *             Ajout des operateurs de relation
 *
 **/
#ifndef __RATIONNEL_H__
#define __RATIONNEL_H__

namespace nsMath
{
    class Rationnel
    {
        int myNum;
        int myDenom;

        void simplify (void);

      public :
        Rationnel (const int num = 0, const int denom = 1);
        Rationnel (const Rationnel & r);

        void display (void) const;

        bool operator <       (const Rationnel & r)  const;
        bool operator ==      (const Rationnel & r)  const;

        Rationnel operator + (const Rationnel & r)  const;
        Rationnel operator - (const Rationnel & r)  const;
        Rationnel operator * (const Rationnel & r)  const;
        Rationnel operator / (const Rationnel & r)  const;

    }; // Rationnel

} // namespace nsMath

#endif /*  __RATIONNEL_H__  */
