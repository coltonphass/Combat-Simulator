// ****************************************************************************
// Author:		Mark Dencler
// Description:	The "Menu Drive Combat Simulator" specification code.  This
//				file contains support for supplied functions that use
//				concepts beyond the student's current scope of understanding.
//				The file provides seeding for the RNG (srand()) based on the
//				BIOS clock.  The "system()" call  is used to clear the screen.
//
// WARNING WARNING WARNING !!! WARNING WARNING WARNING !!! WARNING WARNING !!!
// NOTICE: DO NOT MODIFY THIS FILE WHEN USING IT TO COMPLETE
//          "P02 - MENU DRIVEN COMBAT SIMULATOR".  ONLY INCLUDE
//			THIS FILE DIRECTLY IN IT'S GIVEN FORM.
// WARNING WARNING WARNING !!! WARNING WARNING WARNING !!! WARNING WARNING !!!
// ****************************************************************************

#pragma once			// To protect against multiple definitions (VS ONLY).
#include <time.h>		// for time()
#include <stdlib.h>		// for system()

// Description: Seed rand() to the BIOS system clock count
//   in seconds.  Time value obtained through 'time()'.
void SeedRNGToSystemClock() {
	srand((unsigned int)time(NULL));	// seed the RNG
}

// Description: Clears the console screen using a system() call.
//    this call required <windows.h> to function.
int ClearScreen() {
	system("cls");
	return 0;
}

// Description: Return a 'random' integer value on the mathematical
//   interval [lowerBound, upperBound].
int generateRandomValue(int lowerBound, int upperBound) {
	int range = (upperBound - lowerBound) + 1;	// establash 'window' size
	return rand() % range + lowerBound;			// slide the window
}
