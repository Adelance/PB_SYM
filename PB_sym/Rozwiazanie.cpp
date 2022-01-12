#include "solution.h"
#include "stdafx.h"

//Nazwy zaworów: Z1, Z2, Z3, GR
//Nazwy czujników: X1, X2, X3, TM

extern char X1, X2, X3, X4, X5, X7, T, Z1, Z2, Z3, Z4, Z5, G;

int stan = 1;
int tim;

int stan1 = 1, stan2 = 1, stan3 = 1;
int tim1, tim2;


void Solution(void) {

	// Zbiornik

	/*
	switch (stan) {
	case 1: Z1 = 1; Z2 = 1; Z3 = 0; GR = 0; M1 = 0;
		if (X2) { stan = 2; tim = 30; }
		break;
	case 2: Z1 = 1; Z2 = 0; Z3 = 0; GR = 0; M1 = 0;
		if (!tim) { stan = 3; tim = 30; }
		else if (X3) { stan = 4; tim = 50; }
		break;
	case 3: Z1 = 0; Z2 = 1; Z3 = 0; GR = 0; M1 = 0;
		if (!tim) { stan = 2; tim = 30; }
		else if (X3) { stan = 4; tim = 50; }
		break;
	case 4: Z1 = 0; Z2 = 0; Z3 = 0; GR = 1; M1 = 1;
		if (!tim && !TM) stan = 5;
		else if (!tim && TM) stan = 6;
		break;
	case 5: Z1 = 0; Z2 = 0; Z3 = 0; GR = 1; M1 = 0;
		if (TM) stan = 6;
		break;
	case 6: Z1 = 0; Z2 = 0; Z3 = 1; GR = 0; M1 = 0;
		if (!X1) stan = 1;
		break;


	}
	if (tim) --tim;
	*/


	/*
	// Kaskada

	//Dolny
	switch (stan1) {
		case 1: Z3 = 1; Z4 = 1; Z5 = 0; GR = 0; M3 = 0;
			if (X6) { stan1 = 2; tim1 = 30; }
			break;
		case 2: Z3 = 1; Z4 = 0; Z5 = 0; GR = 0; M3 = 0;
			if (!tim1) { stan1 = 3; tim1 = 30; }
			else if (X5) { stan1 = 4; tim1 = 50; }
			break;
		case 3: Z3 = 0; Z4 = 1; Z5 = 0; GR = 0; M3 = 0;
			if (!tim1) { stan1 = 2; tim1 = 30; }
			else if (X5) { stan1 = 4; tim1 = 50; }
			break;
		case 4: Z3 = 0; Z4 = 0; Z5 = 0; GR = 1; M3 = 1;
			if (!tim1 && !TM) stan1 = 5;
			else if (!tim1 && TM) stan1 = 6;
			break;
		case 5: Z3 = 0; Z4 = 0; Z5 = 0; GR = 1; M3 = 0;
			if (TM) stan1 = 6;
			break;
		case 6: Z3 = 0; Z4 = 0; Z5 = 1; GR = 0; M3 = 0;
			if (!X7) stan1 = 1;
			break;
	}
	if (tim1) --tim1;

	//Lewy
	switch (stan2) {
		case 1: Z1 = 1; M1 = 0;
			if (X1) stan2 = 2;
			break;
		case 2: Z1 = 0; M1 = 1;
			if (!X2) stan = 1;
			break;
	}

	//Prawy
	switch (stan3) {
		case 1: Z2 = 1; M2 = 0;
			if (X4) { stan3 = 2; tim2 = 30; }
			break;
		case 2: Z2 = 1; M2 = 0;
			if (!tim2) { stan3 = 3; tim2 = 20; }
			else if (X3) stan3 = 4;
			break;
		case 3: Z2 = 0; M2 = 1;
			if (!tim2) { stan3 = 2; tim2 = 30; }
			break;
		case 4: Z2 = 0; M2 = 0;
			if (!X4) stan3 = 1;
			break;
	}
	if (tim2) --tim2;
	*/

	//Wagony
	/*
	switch (stan) {
		case 1: Z1 = 0; Z2 = 0;
			if (X1) stan = 2;
			if (X2) stan = 4;
			break;
		case 2: Z1 = 1; Z2 = 0;
			if (X2) stan = 3;
			break;
		case 3: Z1 = 1; Z2 = 0;
			if (!X2) stan = 1;
			break;
		case 4: Z1 = 0; Z2 = 1;
			if (X1) stan = 5;
			break;
		case 5: Z1 = 0; Z2 = 1;
			if (!X1) stan = 1;
			break;
	}
	*/

	//Linia Produkcyjna
	/*
	switch (stan1) {
		case 1: Z1 = 0; Z2 = 0; Z3 = 0; GR = 0; M1 = 1;
			if (X1) stan1 = 2;
			if (X2) { stan1 = 3; tim1 = 50; }
			if (X3) { stan1 = 4; tim1 = 50; }
			if (X4) { stan1 = 5; tim1 = 50; }
			break;
		case 2: Z1 = 1; Z2 = 0; Z3 = 0; GR = 0; M1 = 0;
			if (TM) stan1 = 1;
			break;
		case 3: Z1 = 0; Z2 = 1; Z3 = 0; GR = 0; M1 = 0;
			if (!tim1) stan1 = 1;
			break;
		case 4: Z1 = 0; Z2 = 0; Z3 = 0; GR = 0; M1 = 0;
			if (!tim1) stan1 = 1;
			break;
		case 5: Z1 = 0; Z2 = 0; Z3 = 0; GR = 1; M1 = 0;
			if (!tim1) stan1 = 1;
			break;
	}
	if (tim1) --tim1;

	//Zbiornik
	switch (stan2) {
		case 1: Z4 = 1; M2 = 0;
			if (X6) stan2 = 2;
			break;
		case 2: Z4 = 0; M2 = 1;
			if (!X7) stan = 1;
			break;
	}
	*/
		
	switch (stan) {
		case 1: Z1 = Z3 = 1; Z2 = Z4 = 0; M1 = M2 = 0;
			if (X2 || X4) { stan = 2; tim = 70; }
			break;
		case 2: Z1 = Z3 = 0; Z2 = Z4 = 0; M1 = M2 = 0;
			if (!tim) { stan = 3; tim = 100; }
			break;



		case 3: Z1 = Z3 = 0; Z2 = Z4 = 1; M1 = M2 = 1;
			if (!tim) { stan = 4; tim = 30; }
			break;
		case 4: Z1 = Z3 = 0; Z2 = Z4 = 1; M1 = M2 = 0;
			if (!tim) stan = 1;
			break;
		case 5: Z1 = Z3 = 1; Z2 = Z4 = 0; M1 = M2 = 0;
			if (TM) stan = 6;
			break;
		case 6: Z1 = Z3 = 1; Z2 = Z4 = 0; M1 = M2 = 0;
			if (!X1) stan = 1;
			break;

	}
	if (tim) --tim;





//TESTOWE

	/*switch (stan) {
	case 1: Z1 = 0; Z2 = 1; Z3 = 0; GR = 1;
		if (TM) stan = 2;
		break;
	case 2: Z1 = 0; Z2 = 1; Z3 = 0; GR = 0;
		if (X3) stan = 3;
		break;
	case 3: Z1 = 0; Z2 = 0; Z3 = 0; GR = 1;
		if (TM) stan = 4;
		break;
	case 4: Z1 = 0; Z2 = 0; Z3 = 1; GR = 0;
		if (!X1) stan = 1;
		break;
	}*/

	//// LEDY
	//L1 = aK1;                // dioda œwieci gdy naciœniemy klawisz

	//switch (stan2) {        // miganie diody
	//case 1: l3 = 1; if (!tim) { stan2 = 2; tim = 5; } break;
	//case 2: l3 = 0; if (!tim) { stan2 = 1; tim = 10; } break;
	//}
	//if (tim) --tim;
	//
	//x1 = ak1; x2 = ak2; x3 = ak3; x4 = ak4; x5 = ak5; x7 = ak6; t = ak7;
	//switch (stan1) { // ------------------------------------- zbiornik 1
	//case 1: Z1 = 1; Z3 = 0; if (X1)stan1 = 2;
	//	  break;
	//case 2: Z1 = 0; Z3 = 1; if (!X2)stan1 = 1;
	//	break;
	//}
	//if (tm1) --tm1;


	//switch (stan2) { // ------------------------------------- zbiornik 2
	//case 1: Z2 = 1; if (X3)stan2 = 2;
	//	break;
	//case 2: Z2 = 0; if (!X4)stan2 = 1;
	//	break;
	//}

	//switch (stan3) { // ------------------------------------- zbiornik 3
	//case 1: Z3 = 1; Z4 = 0; Z5 = 0; GR = 0; M1 = 0, M2 = 0, M3 = 0;
	//	if (X5) stan3 = 2;
	//	break;
	//case 2: Z3 = 0; Z4 = 0; Z5 = 0; GR = 1;
	//	if (X5) { tm3 = 50; stan3 = 4; }
	//	else if (!tm3) { tm3 = 30; stan3 = 3; }
	//	break;
	//}
	//
	//switch (stan) {
	//case 1: Z1 = 0; Z2 = 0;
	//	if (X1) stan = 2;
	//	if (X2) stan = 3;
	//	break;
	//case 2: Z1 = 1; Z2 = 0;
	//	if (X2) stan = 3;
	//	break;
	//case 3: Z1 = 1; Z2 = 1;
	//	if (!X2) stan = 1;
	//	break;
	//}
	/*switch (stan)
	{
		case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; M1 = 1; M2 = 0;
			if (X1) stan = 2;
			break;
		case 2: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; M1 = 0, M2 = 0;
			if (X6) stan = 3;
			break;
		case 3: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; M1 = 0, M2 = 0;
			if (!X7) stan = 4;
			break;
		case 4: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; M1 = 1, M2 = 0;
			if (X2) stan = 5; tm1 = 10;
			break;
		case 5: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; M1 = 0, M2 = 0;
			if (!tm1) stan = 6;
			break;
		case 6: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; M1 = 0, M2 = 0;
			if (X6) stan = 3;
			break;
		case 7: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; M1 = 0, M2 = 0;
			if (X6) stan = 3;
			break;
	}

	if (tm1) --tm1;*/
	//Z4 = 1; Z2 = 1;

	/*switch (stan)
	{
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; M1 = 1; M2 = 0; GR = 1;
		if (X2) stan = 2; tm1 = 100;
		break;
	case 2: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; M1 = 0; M2 = 0; GR = 1;
		if (tm1<0) stan = 3;
		break;
	case 3: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; M1 = 1; M2 = 0; GR = 1;
		if (X3) stan = 4; tm1 = 100;
		break;
	case 4: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; M1 = 0; M2 = 0; GR = 1;
		if (tm1<0) stan = 5;
		break;

	case 5: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; M1 = 1; M2 = 0; GR = 1;
		if (X1) stan = 6;
		break;
	case 6: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; M1 = 0; M2 = 0; GR = 1;
		if (X6) stan = 7;
		break;
	case 7: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; M1 = 0; M2 = 0; GR = 1;
		if (!X7) stan = 1;
		break;
	}

	if (tm1 >= 0) tm1 -= 1;*/


	/*if (tim > 0) {
		Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0;
	}
	else {
		Z1 = 1; Z2 = 1; Z3 = 1; Z4 = 1;
	}
	if(tim)tim--;*/


	/*switch (stan)
	{
	case 1: Z1 = 0; Z2 = 0;
		if (X2) stan = 2;
		break;
	case 2: Z1 = 1; Z2 = 1; M1 = 1;
		break;
	}*/
	//Z1 = 0;
	//Z3 = 0;
	//Z2 = 1;
	//Z4 = 1;
	//M1 = 1;
	//M2 = 1;

	//

	/*Z1 = 1;
	Z3 = 0;
	Z2 = 1;
	Z4 = 0;
	M1 = 0;
	M2 = 0;*/
}

