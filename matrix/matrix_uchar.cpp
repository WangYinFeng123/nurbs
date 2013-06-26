/*=============================================================================
        File: matrix.cpp
     Purpose:       
    Revision: $Id: matrix_uchar.cpp,v 1.2 2002/05/13 21:07:45 philosophil Exp $
  Created by: Philippe Lavoie          (3 Oct, 1996)
 Modified by: 

 Copyright notice:
          Copyright (C) 1996-1998 Philippe Lavoie
 
	  This library is free software; you can redistribute it and/or
	  modify it under the terms of the GNU Library General Public
	  License as published by the Free Software Foundation; either
	  version 2 of the License, or (at your option) any later version.
 
	  This library is distributed in the hope that it will be useful,
	  but WITHOUT ANY WARRANTY; without even the implied warranty of
	  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	  Library General Public License for more details.
 
	  You should have received a copy of the GNU Library General Public
	  License along with this library; if not, write to the Free
	  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
=============================================================================*/

#include "matrix.cpp"

namespace PLib {

  template <> Matrix<unsigned char>&
    Matrix<unsigned char>::operator*=(double a)
    {
      unsigned char *p1 ;
      p1 = m-1 ;
      const int size = rows()*cols() ;
      for(int i=size; i>0; --i){
	*p1 = (unsigned char)(a*double(*p1)) ;  
	++p1 ; 
      }
      return *this ;
    }
  
  template <> Matrix<unsigned char>&
    Matrix<unsigned char>::operator+=(double a)
    {
      unsigned char *p1 ;
      p1 = m-1 ;
      const int size = rows()*cols() ;
      for(int i=size; i>0; --i)
	*(++p1) += (unsigned char)a ;  
      return *this ;
    }
  
  
  template <> Matrix<unsigned char>&
    Matrix<unsigned char>::operator-=(double a)
    {
      unsigned char *p1 ;
      p1 = m-1 ;
      const int size = rows()*cols() ;
      for(int i=size; i>0; --i)
	*(++p1) -= (unsigned char)a ;  
      return *this ;
    }
  
  
  template <> Matrix<unsigned char>&
    Matrix<unsigned char>::operator/=(double a)
    {
      unsigned char *p1 ;
      p1 = m-1 ;
      const int size = rows()*cols() ;
      for(int i=size; i>0; --i){
	*p1 = (unsigned char)(double(*p1)/a) ;  
	++p1 ; 
      }
      return *this ;
    }
  
  
#ifdef NO_IMPLICIT_TEMPLATES
  
  template class Matrix<unsigned char> ;
  
  template Matrix<unsigned char> operator+(const Matrix<unsigned char>&,const Matrix<unsigned char>&);
  template Matrix<unsigned char> operator-(const Matrix<unsigned char>&,const Matrix<unsigned char>&);
  template Matrix<unsigned char> operator*(const Matrix<unsigned char>&,const Matrix<unsigned char>&);
  template Matrix<unsigned char> operator*(const double,const Matrix<unsigned char>&);
  template Matrix<unsigned char> operator*(const Complex&,const Matrix<unsigned char>&);
  template Vector<unsigned char> operator*(const Matrix<unsigned char>&,const Vector<unsigned char>&);
  template int operator==(const Matrix<unsigned char>&,const Matrix<unsigned char>&);
  // template int operator!=(const Matrix<unsigned char>&,const Matrix<unsigned char>&);
  template Matrix<unsigned char> comm(const Matrix<unsigned char>&,const Matrix<unsigned char>&);

#endif

}
