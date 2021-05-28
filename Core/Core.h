// CompliantFramework.h: file di inclusione per file di inclusione di sistema standard,
// o file di inclusione specifici del progetto.

#ifdef EXPORT
#ifdef _WIN32
#define API __declspec(dllexport)
#else 
#define API
#endif // _WIN32
#else
#ifdef _WIN32
#define API __declspec(dllimport)
#else 
#define API
#endif // _WIN32
#endif // EXPORT



#pragma once




#include <iostream>

// TODO: Fare riferimento qui alle intestazioni aggiuntive richieste dal programma.

int API Test();
