// PB_sym.cpp : main project file.

#include "stdafx.h"
#include "solution.h"

#include <string.h>
#include <stdio.h>

// ========================================================================
//
//-------------------- definicje zmiennych systemowych  -------------------
//
//---------------------- NIE WOLNO TU NIC ZMIENIAC !!! --------------------
//
// ========================================================================

char aK1, aK2, aK3, aK4;       // stany klawiszy panelu
char L1, L2, L3, L4;           // stany LEDów panelu

char line1[80], line2[80];     // bufory dla wyswietlacza LCD

char recv_char();              // znak nades³any z konsoli (0=brak znaków)
void send_char(char cc);       // wyœlij jeden znak ASCII z PB na konsolê
void send_string(char* s);    // wyœlij tekst (string) z PB na konsolê

void out_sym_val(void);        // wyslij do obiektu komunikat o stanie zaworów
void inicjuj_kom(void);        // inicjuj zmienne dla komunikacji

//==========================================================================
//============================= Regulator ==================================
//
//---------------------------  dane robocze  -------------------------------
//
//                  ( tu mozna zmieniac ... )

char buf[60];       // bufor roboczy dla sprintf(...)

// ========================================================================
// ----------------------- pêtla g³ówna regulatora ------------------------
// ========================================================================

void inicjuj(void)         // wywo³ywana JEDNORAZOWO na pocz¹tku
{
	strcpy(line2, "Sterownik v.1.0");   // wypisz na LCD

	inicjuj_kom();         // inicjuj zmienne dla komunikacji
}


void oblicz(void)          // wywo³ywana co cykl (co 0.1 sek )
{
	Solution();

	// ------------ wyswietl stan klawiszy i LEDów -----------------------
	out_sym_val(); // KOMUNIKACJA
	sprintf(buf, "K1=%d K2=%d L1=%d L2=%d", (int)aK1, (int)aK2, (int)L1, (int)L2);
	strcpy(line1, buf);

	// -------------- komunikacja regulatora z konsol¹ -------------------
	// send_char('a');  send_string(":012345\r\n");   // wyœlij znak/komunikat na konsolê
}


//========================================================================
//========================= KONIEC =======================================
//========================================================================
