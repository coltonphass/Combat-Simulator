/*
Author:         Colton Phass
Description:    Fighting Simulator
*/

// Allowed Warnings
#pragma warning (disable:6031) // getch

//Library
#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;

// Combat H
#include "CIS115-P02S - Menu Driven Combat Simulator.h"

// Define Min Health
#define MINIMUM_HEALTH 0

// Prototypes
void mainPrompt();
void clearScreenUi();
void errorMessageOne();
void displayHealth(int playerHealth, int enemyHealth, int firstColumnWidth);
void playerAttack(int& enemyHealth);
void enemyAttack(int& playerHealth);
void playerHeal(int& playerHealth);

int main() {
	SeedRNGToSystemClock();
	// Declare vars
	int continueGame = 1;
	int playerHealth = 100;
	int enemyHealth = 100;
	int choice = 0;
	int firstColumnWidth = 5;


	// game loop
	while (playerHealth >= MINIMUM_HEALTH && enemyHealth >= MINIMUM_HEALTH) {
		displayHealth(playerHealth, enemyHealth, firstColumnWidth);
		mainPrompt();
		cin >> choice;

		// input validation
		while (cin.fail() || choice < 1 || choice > 2) {
			errorMessageOne();
			cin.clear();
			rewind(stdin);
			cin >> choice;
		}

		// Turn
		if (choice == 1) {
			playerAttack(enemyHealth);
		}

		// Player Heal
		else if (choice == 2) {
			playerHeal(playerHealth);
		}


		// Enemy Attacks
		enemyAttack(playerHealth);
		clearScreenUi();
	}


	// Win & Lose Conditions I added max health so that way there is no negative value displayed.
	if (playerHealth <= MINIMUM_HEALTH) {
		playerHealth = max(playerHealth, MINIMUM_HEALTH);
		displayHealth(playerHealth, enemyHealth, firstColumnWidth);
		mainPrompt();
		cout << "You have died.   Better luck next time." << endl << endl;
		continueGame = 0;
	}
	else {
		enemyHealth = max(enemyHealth, MINIMUM_HEALTH);
		displayHealth(playerHealth, enemyHealth, firstColumnWidth);
		mainPrompt();
		cout << "You have defeated the enemy. Gratz." << endl << endl;
		continueGame = 0;
	}

	cout << "GAME OVER!";
	// Exit to OS
	_getch();
	return 0;
}

// Functions
void displayHealth(int playerHealth, int enemyHealth, int firstColumnWidth) {
	cout << "Player HP:" << setw(firstColumnWidth) << playerHealth << endl;
	cout << "Enemy HP :" << setw(firstColumnWidth) << enemyHealth << endl;
}

void mainPrompt() {
	cout << "Select an action..." << endl;
	cout << "1.) Attack" << endl;
	cout << "2.) Heal" << endl;
	cout << " : ";
}

void errorMessageOne() {
	cout << "this isn't a valid menu option.  Please try again..." << endl;
}

void playerAttack(int& enemyHealth) {
	int missChance = generateRandomValue(1, 10);
	if (missChance <= 2) {
		cout << "You ATTACK and MISS" << endl;
	}
	else {
		int attack = generateRandomValue(1, 10);

		// Player Crit Check
		int critChance = generateRandomValue(1, 10);
		if (critChance <= 2) {
			int critDMG = attack * 2.5 + 5;
			enemyHealth -= critDMG;
			cout << "You ATTACK and score a CRIT on the enemy for " << critDMG << "HP." << endl;
		}
		else {
			enemyHealth -= attack;
			cout << "You ATTACK and score a HIT on the enemy for " << attack << "HP." << endl;
		}
	}
}

void playerHeal(int& playerHealth) {
	int heal = generateRandomValue(3, 25);
	playerHealth += heal;
	cout << "You heal yourself for " << heal << "HP" << endl;
}

void enemyAttack(int& playerHealth) {
	int enemyMiss = generateRandomValue(1, 10);
	if (enemyMiss <= 2) {
		cout << "The enemy ATTACKS and MISSES";
	}
	else {
		int enemyAttack = generateRandomValue(1, 10);

		// Enemy Crit Check
		int enemyCritChance = generateRandomValue(1, 10);
		if (enemyCritChance <= 2) {
			int critDMG = enemyAttack * 2.5 + 5;
			playerHealth -= critDMG;
			cout << "The enemy ATTACKS and scores a CRIT on you for " << critDMG << "HP." << endl;
		}
		else {
			playerHealth -= enemyAttack;
			cout << "The enemy ATTACKS and scores a HIT on you for " << enemyAttack << "HP." << endl;
		}
	}
}

void clearScreenUi() {
	_getch();
	ClearScreen();
}