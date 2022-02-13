#include "solution.h"
#include "stdafx.h"

//Nazwy zaworów: Z1, Z2, Z3, GR
//Nazwy czujników: X1, X2, X3, TM

extern char X1, X2, X3, X4, X6, X7;
extern char Z1, Z2, Z3, Z4, GR, M1, M2;
int tim;
int stan1 = 1, stan2 = 1;

void Solution(void) {
	switch (stan1) {
		case 1: Z1 = 0; Z2 = 0; Z3 = 0; GR = 0; M1 = 1;
			if (X1) stan1 = 2;
			if (X2) { stan1 = 3; tim = 50; }
			if (X3) { stan1 = 4; tim = 50; }
			if (X4) { stan1 = 5; tim = 50; }
			break;
		case 2: Z1 = 1; Z2 = 0; Z3 = 0; GR = 0; M1 = 0;
			if (TM) stan1 = 1;
			break;
		case 3: Z1 = 0; Z2 = 1; Z3 = 0; GR = 0; M1 = 0;
			if (!tim) stan1 = 1;
			break;
		case 4: Z1 = 0; Z2 = 0; Z3 = 1; GR = 0; M1 = 0;
			if (!tim) stan1 = 1;
			break;
		case 5: Z1 = 0; Z2 = 0; Z3 = 0; GR = 1; M1 = 0;
			if (!tim) stan1 = 1;
			break;
	}
	if (tim) --tim;

	//Zbiornik
	switch (stan2) {
		case 1: Z4 = 1; M2 = 0;
			if (X6) stan2 = 2;
			break;
		case 2: Z4 = 0; M2 = 1;
			if (!X7) stan2 = 1;
			break;
	}
}

