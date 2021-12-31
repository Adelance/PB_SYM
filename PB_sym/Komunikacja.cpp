// PB_sym.cpp : main project file.

#include "stdafx.h"
#include "solution.h"
#include <string.h>
#include <stdio.h>

//----------------- definicje zmiennych systemowych  ----------------
//
//------------------ NIE WOLNO TU NIC ZMIENIAC !!! ----------------
//

char X1, X2, X3, X4, X5, X6, X7, TM;           // stany czujnikow obiektu
char Z1, Z2, Z3, Z4, Z5, Z6, GR, M1, M2, M3;           // stany zaworow obiektu

extern char aK1, aK2, aK3, aK4;       // stany klawiszy panelu
extern char L1, L2, L3, L4;           // stany LEDów panelu
extern char line1[80], line2[80];     // bufory dla wyswietlacza LCD

char recv_char();              // znak nades³any z konsoli (0=brak znaków)
void send_char(char cc);       // wyœlij jeden znak ASCII z PB na konsolê
void send_string(char* s);    // wyœlij tekst (string) z PB na konsolê


// ------------------- obs³uga komunikacji ------------------------------

char sym_recv_char(void);
void sym_send_char(char cc);
void sym_send_string(char* s);
void sym_trans_char(char cc);
void sym_trans_string(char* s);


// ----------------- obs³uga komunikatów z obiektu  ---------------------

char stan_s = 1;        // stan grafu dla komunikacji z obiektem
char znak_s = 0;        // odebrany znak komunikatu z obiektu


void int_sym_znak()   // wywo³ywana przerwaniowo gdy odebrano znak z obiektu
{
	znak_s = sym_recv_char();

	// ------------------------ os³uga kolejnych znaków komunikatu ------
	switch (stan_s) {
	case 1: if (znak_s == ':') stan_s = 2; else stan_s = 1;      // znak ':'
		break;
	case 2: if (znak_s == '1') { stan_s = 3; X1 = 1; }
		  else
		if (znak_s == '0') { stan_s = 3; X1 = 0; }
		else
			stan_s = 1;                 // b³ad - szukaj od poczatku
		break;
	case 3: if (znak_s == '1') { stan_s = 4; X2 = 1; }
		  else
		if (znak_s == '0') { stan_s = 4; X2 = 0; }
		else
			stan_s = 1;                 // b³ad - szukaj od poczatku
		break;
	case 4: if (znak_s == '1') { stan_s = 5; X3 = 1; }
		  else
		if (znak_s == '0') { stan_s = 5; X3 = 0; }
		else
			stan_s = 1;                 // b³ad - szukaj od poczatku
		break;

	case 5: if (znak_s == '1') { stan_s = 6; X4 = 1; }
		  else
		if (znak_s == '0') { stan_s = 6; X4 = 0; }
		else
			stan_s = 1;                 // b³ad - szukaj od poczatku
		break;

	case 6: if (znak_s == '1') { stan_s = 7; X5 = 1; }
		  else
		if (znak_s == '0') { stan_s = 7; X5 = 0; }
		else
			stan_s = 1;                 // b³ad - szukaj od poczatku
		break;

	case 7: if (znak_s == '1') { stan_s = 8; X6 = 1; }
		  else
		if (znak_s == '0') { stan_s = 8; X6 = 0; }
		else
			stan_s = 1;                 // b³ad - szukaj od poczatku
		break;

	case 8: if (znak_s == '1') { stan_s = 9; X7 = 1; }
		  else
		if (znak_s == '0') { stan_s = 9; X7 = 0; }
		else
			stan_s = 1;                 // b³ad - szukaj od poczatku
		break;

	case 9: if (znak_s == '1') { stan_s = 1; TM = 1; }
		  else
		if (znak_s == '0') { stan_s = 1; TM = 0; }
		else
			stan_s = 1;                 // b³ad - szukaj od poczatku
		break;
	}
}


void out_sym_val(void)  // wys³anie komunikatu do obiektu (stan zaworów) 
{
	sym_send_char(':');
	sym_send_char(Z1 + '0');
	sym_send_char(Z2 + '0');        // wyslij komunikat o stanie zaworów 
	sym_send_char(Z3 + '0');
	sym_send_char(Z4 + '0');
	sym_send_char(Z5 + '0');
	sym_send_char(GR + '0');
	sym_send_char(M1 + '0');
	sym_send_char(M2 + '0');
	sym_send_char(M3 + '0');

	sym_send_char('\r');          // wyœlij dodatkowo znaki CR, LF
	sym_send_char('\n');
}


// ----------------- obs³uga komunikatów z konsoli  ---------------------

char stan_k = 1;        // stan grafu dla komunikacji z konsol¹
char znak_k = 0;        // odebrany znak komunikatu z konsoli


void int_znak()       // wywo³ywana przerwaniowo gdy odebrano znak z konsoli
{
	znak_k = recv_char();

	// ------------- odbieranie znaków i komunikatów z konsoli -------------
	if (znak_k == '8') L4 = 1;    // przyszed³ znak '0' z konsoli
	if (znak_k == '9') L4 = 0;    // przyszed³ znak '1' z konsoli

	switch (stan_k) {
	case 1: if (znak_k == ':') stan_k = 2; else stan_k = 1;      // znak ':'
		break;
	case 2: if (znak_k == '0') stan_k = 3; else stan_k = 1;      // znak '0'
		break;
	case 3: if (znak_k == '1') { stan_k = 1; L2 = 1; }
		  else
		if (znak_k == '0') { stan_k = 1; L2 = 0; }
		else
			stan_k = 1;                 // b³¹d - szukaj od poczatku
		break;
	}
}

// ------------------------------------------------------------------------

void trans_char(char c);       // wyœlij jeden znak z konsoli do PB  
void trans_string(char* s);   // wyœlij tekst (string) z konsoli do PB  


void klaw_F1(void)      // funkcja wywo³ywana po naciœniêciu F1 na konsoli
{
	trans_char(':');
	trans_char('0');               // wyœlij komunikat ':' '0' '1'
	trans_char('1');
}

void klaw_F2(void)      // funkcja wywo³ywana po naciœniêciu F2 na konsoli
{
	trans_char(':');
	trans_char('0');               // wyœlij komunikat ':' '0' '0'
	trans_char('0');
}

void klaw_F3(void)      // funkcja wywo³ywana po naciœniêciu F3 na konsoli
{
	trans_string(":01");           // wyœlij komunikat ':' '0' '1'
}

void klaw_F4(void)      // funkcja wywo³ywana po naciœniêciu F4 na konsoli
{
}

// ----------------------- inicjowanie zmiennych ------------------------

void inicjuj_kom(void)         // inicjuj zmienne dla komunikacji
{
	stan_k = 1;  stan_s = 1;           // inicjuj zmienne
}


//========================= KONIEC =======================================
//========================================================================

