//=============================================================================
//  SuperCPPCString.cpp
//
//  v1.1.2 - 2016.02.17 by Abe Pralle
//
//  See README.md for instructions.
//=============================================================================
#include "SuperCPPCString.h"

#include <cstring>
using namespace std;

namespace PROJECT_NAMESPACE
{
namespace SuperCPP
{

//=============================================================================
//  CString
//=============================================================================
CString::CString() : characters(0), count(0)
{
}

CString::CString( const char* value ) : characters(0), count(0)
{
  *this = value;
}

CString::CString( const CString& existing ) : characters(0), count(0)
{
  *this = existing;
}

CString::~CString()
{
  if (characters) delete characters;
}

CString& CString::operator=( const char* value )
{
  if (characters) delete characters;
  count = (int) strlen( value );
  characters = new char[ count+1 ];
  strcpy( characters, value );
  return *this;
}

CString& CString::operator=( const CString& other )
{
  if (characters) delete characters;
  count = other.count;
  this->characters = new char[ count+1 ];
  strcpy( this->characters, other.characters );
  return *this;
}

CString::operator char*()
{
  return characters;
}

CString::operator const char*()
{
  return characters;
}


} // namespace SuperCPP
} // namespace PROJECT_NAMESPACE

