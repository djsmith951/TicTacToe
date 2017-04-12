// CodingChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <vector>

using namespace std;

class Game {
public:
	// The game board and the game status
	char board[9];
	int currentState; // the current state of the game
	char currentPlayer; // the current player
	
	void Banner(){
		cout << "\n=======================================================================";
		cout << "\nTTTTTT IIIIII   CCCC    TTTTTT    AAA     CCCC    TTTTTT  OOOO   EEEEE\n";
		cout << "  TT     II    CC   C     TT     AA AA   CC   C     TT   OO  OO  EE\n";
		cout << "  TT     II    CC     ==  TT    AA   AA  CC     ==  TT   OO  OO  EEEEE\n";
		cout << "  TT     II    CC   C ==  TT    AAAAAAA  CC   C ==  TT   OO  oo  EE\n";
		cout << "  TT   IIIIII   CCCC      TT    AA   AA   CCCC      TT    OOOO   EEEEE\n";
		cout << "=======================================================================";
		
	}
	/** Starts the game */
	void start() {
		// Initialize the game-board and current status
		cout << "\n\n* * * * Your Move First! You are Xs! * * * *";
		initGame();
		printBoard();

		do {
			getHumanSpot();
			if (!gameIsOver() && !tie()) {
				evalBoard();
			}
		} while (!gameIsOver() && !tie()); // repeat if not game-over
		if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O' ||
			board[3] == 'O' && board[4] == 'O' && board[5] == 'O' ||
			board[6] == 'O' && board[7] == 'O' && board[8] == 'O' ||
			board[0] == 'O' && board[3] == 'O' && board[6] == 'O' ||
			board[1] == 'O' && board[4] == 'O' && board[7] == 'O' ||
			board[2] == 'O' && board[5] == 'O' && board[8] == 'O' ||
			board[0] == 'O' && board[4] == 'O' && board[8] == 'O' ||
			board[2] == 'O' && board[4] == 'O' && board[6] == 'O'){
			cout << "\nYou Lost! Maybe Next Time." << endl;
		}
		else{
			cout << "\nIt's A Draw. Nice Try." << endl;
		}
		cout << "\nGame Over!" << endl;
	}

	/** Initializes the game */
	void initGame() {
		// Populate board with available spots
		for (int i = 0; i < 9; i++) {
			board[i] = '0' + i;
		}

		currentState = 0; // "playing" or ready to play
		currentPlayer = 'X'; // cross plays first
	}

	void printBoard() {
		cout << "\n\n\n                              " << board[0] << "     |  " << board[1] << "   |     " << board[2] << "\n                                    |      |\n                                    |      |\n                              ======+======+======\n" << "                                    |      |                                                                  " << board[3] << "     |  " << board[4] << "   |     " << board[5] << "\n                                    |      |\n                              ======+======+======" << "\n                                    |      |\n                                    |      |\n                              " << board[6] << "     |  " << board[7] << "   |     " << board[8] << endl; // print all the board cells
	}
	/** Return true if it is a draw (no more empty cell) */
	// TODO: maybe there is an easeir way to check this
	bool tie() {
		return board[0] != '0' &&
			board[1] != '1' &&
			board[2] != '2' &&
			board[3] != '3' &&
			board[4] != '4' &&
			board[5] != '5' &&
			board[6] != '6' &&
			board[7] != '7' &&
			board[8] != '8';
	}

	char nextPlayer() {
		if (currentPlayer == 'X') {
			return 'O';
		}
		else {
			return 'X';
		}
	};

	void getHumanSpot() {
		bool validInput = false;  // for input validation
		cout << "   Enter [0-8]:\n";
		
			int spot;
			while (!(cin >> spot)){
				cout << "Must be a number between 0-8. Please try again:" << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
			
			
				if (board[spot] != 'X' && board[spot] != 'O') {

					board[spot] = 'X';  // update game-board content
					printBoard();
					validInput = true;  // input okay, exit loop
				}
			
			currentPlayer = nextPlayer();  // cross plays first
		    while (!validInput);  // repeat until input is valid
	}

	bool gameIsOver() {
		return board[0] == board[1] && board[1] == board[2] ||
			board[3] == board[4] && board[4] == board[5] ||
			board[6] == board[7] && board[7] == board[8] ||
			board[0] == board[3] && board[3] == board[6] ||
			board[1] == board[4] && board[4] == board[7] ||
			board[2] == board[5] && board[5] == board[8] ||
			board[0] == board[4] && board[4] == board[8] ||
			board[2] == board[4] && board[4] == board[6];
	}

	void evalBoard() {
		bool foundSpot = false;
		do { //these are hardcoded rules for the game to follow to ensure a win for the computer
			if (board[4] == '4') {
				board[4] = 'O';
				foundSpot = true;
			}

			//***********************************Special Cases Offense**********************************************
			//=====8 Condition Cases======
			else{
				if (board[1] == 'O' && board[4] == 'O' && board[8] == 'O' && board[0] == 'X' && board[2] == 'X' && board[6] == 'X' && board[7] == 'X' && board[3] != 'O'){
					board[3] = 'O';
					foundSpot = true;
				}
				else{
					if (board[2] == 'O' && board[0] == 'O' && board[7] == 'O' && board[4] == 'X' && board[8] == 'X' && board[1] == 'X' && board[6] == 'X' && board[3] != 'O'){
						board[3] = 'O';
						foundSpot = true;
					}
				else{
					if (board[2] == 'O' && board[4] == 'O' && board[7] == 'O' && board[1] == 'X' && board[5] == 'X' && board[8] == 'X' && board[6] == 'X' && board[3] != 'X'){
						board[3] = 'O';
						foundSpot = true;
					}
					else{
						if (board[4] == 'O' && board[0] == 'O' && board[7] == 'O' && board[3] == 'X' && board[6] == 'X' && board[8] == 'X' && board[1] == 'X' && board[5] != 'X'){
							board[5] = 'O';
							foundSpot = true;
						}
						else{
							if (board[0] == 'O' && board[4] == 'O' && board[5] == 'O' && board[1] == 'X' && board[2] == 'X' && board[3] == 'X' && board[8] == 'X' && board[3] == 'X'){
								board[6] = 'O';
								foundSpot = true;
							}
							
							//=====7 Condition Cases======
							else{
								if (board[4] == 'X' && board[1] == 'X' && board[5] == 'X' && board[8] == 'X' && board[7] == 'O' && board[2] == 'O' && board[3] == 'O'){
									board[0] = 'O';
									foundSpot = true;
								}
								else{
									if (board[0] == 'X' && board[1] == 'X' && board[6] == 'X' && board[5] == 'X' && board[2] == 'O' && board[3] == 'O' && board[4] == 'O'){
										board[7] = 'O';
										foundSpot = true;
									}
									else{
										if (board[4] == 'X' && board[6] == 'X' && board[5] == 'X' && board[0] == 'X' && board[2] == 'O' && board[3] == 'O' && board[8] == 'O'){
											board[7] = 'O';
											foundSpot = true;
										}

										else{
											if (board[4] == 'X' && board[1] == 'X' && board[6] == 'X' && board[5] == 'X' && board[2] == 'O' && board[3] == 'O' && board[7] == 'O'){
												board[8] = 'O';
												foundSpot = true;
											}
											else{
												if (board[3] == 'O' && board[2] == 'O' && board[4] == 'O' && board[0] == 'X' && board[1] == 'X' && board[6] == 'X' && board[5] != 'X'){
													board[5] = 'O';
													foundSpot = true;
												}
												else{
													if (board[4] == 'O' && board[8] == 'O' && board[3] == 'O' && board[6] == 'X' && board[7] == 'X' && board[0] == 'X' && board[5] == 'X'){
														board[2] = 'O';
														foundSpot = true;
													}
													else{
														if (board[4] == 'O' && board[8] == 'O' && board[3] == 'O' && board[6] == 'X' && board[7] == 'X' && board[0] == 'X' && board[5] != 'X'){
															board[5] = 'O';
															foundSpot = true;
														}
														else{
															if (board[4] == 'O' && board[5] == 'O' && board[6] == 'O' && board[8] == 'X' && board[7] == 'X' && board[2] == 'X' && board[3] == 'X'){
																board[0] = 'O';
																foundSpot = true;
															}
															else{
																if (board[4] == 'O' && board[5] == 'O' && board[6] == 'O' && board[8] == 'X' && board[7] == 'X' && board[2] == 'X' && board[3] != 'X'){
																	board[3] = 'O';
																	foundSpot = true;
																}

																else{
																	if (board[0] == 'O' && board[4] == 'O' && board[5] == 'O' && board[1] == 'X' && board[2] == 'X' && board[8] == 'X' && board[3] != 'X'){
																		board[3] = 'O';
																		foundSpot = true;
																	}
																	else{
																		if (board[1] == 'O' && board[4] == 'O' && board[8] == 'O' && board[2] == 'X' && board[5] == 'X' && board[0] == 'X' && board[7] == 'X'){
																			board[3] = 'O';
																			foundSpot = true;
																		}
																		else{
																			if (board[1] == 'O' && board[4] == 'O' && board[8] == 'O' && board[2] == 'X' && board[5] == 'X' && board[0] == 'X' && board[7] != 'X'){
																				board[7] = 'O';
																				foundSpot = true;
																			}
																			else{
																				if (board[1] == 'O' && board[4] == 'O' && board[6] == 'O' && board[7] == 'X' && board[0] == 'X' && board[3] == 'X' && board[2] == 'X'){
																					board[5] = 'O';
																					foundSpot = true;
																				}
																				else{
																					if (board[1] == 'O' && board[4] == 'O' && board[6] == 'O' && board[0] == 'X' && board[3] == 'X' && board[2] == 'X' && board[7] != 'X'){
																						board[7] = 'O';
																						foundSpot = true;
																					}
																					else{
																						if (board[4] == 'X' && board[6] == 'X' && board[5] == 'X' && board[7] == 'X' && board[2] == 'O' && board[3] == 'O' && board[8] == 'O'){
																							board[1] = 'O';
																							foundSpot = true;
																						}
																						//=====6 Condition Cases======
																						else{
																							if (board[4] == 'X' && board[5] == 'X' && board[8] == 'X' && board[2] == 'O' && board[3] == 'O' && board[0] != 'X'){
																								board[0] = 'O';
																								foundSpot = true;
																							}
																						else{
																							if (board[4] == 'X' && board[5] == 'X' && board[1] == 'X'&& board[2] == 'O' && board[3] == 'O'){
																								board[7] = 'O';
																								foundSpot = true;
																							}
																							else{
																								if (board[4] == 'X' && board[5] == 'X' && board[7] == 'X'&& board[2] == 'O' && board[3] == 'O'){
																									board[1] = 'O';
																									foundSpot = true;
																								}
																								else{
																									if (board[4] == 'X' && board[5] == 'X' && board[7] == 'X'&& board[2] == 'O' && board[3] == 'O' && board[0] == 'X'){
																										board[8] = 'O';
																										foundSpot = true;
																									}
																									else{
																										if (board[4] == 'X' && board[5] == 'X' && board[7] == 'X'&& board[2] == 'O' && board[3] == 'O' && board[8] == 'X'){
																											board[0] = 'O';
																											foundSpot = true;
																										}
																										else{
																											if (board[4] == 'X' && board[5] == 'X' && board[7] == 'X'&& board[2] == 'O' && board[3] == 'O' && board[6] == 'X'){
																												board[0] = 'O';
																												foundSpot = true;
																											}
																											else{
																												if (board[4] == 'X' && board[5] == 'X' && board[7] == 'X'&& board[2] == 'O' && board[3] == 'O' && board[8] == 'X'){
																													board[0] = 'O';
																													foundSpot = true;
																												}

																												else{
																													if (board[2] == 'X' && board[0] == 'X' && board[7] == 'X' && board[1] == 'O' && board[4] == 'O' && board[5] == 'O' && board[3] == 'X'){
																														board[6] = 'O';
																														foundSpot = true;
																													}
																													else{
																														if (board[1] == 'O' && board[4] == 'O' && board[0] == 'X' && board[2] == 'X' && board[7] == 'X' && board[5] != 'X'){
																															board[5] = 'O';
																															foundSpot = true;
																														}
																														else{
																															if (board[6] == 'O' && board[4] == 'O' && board[8] == 'X' && board[7] == 'X' && board[2] == 'X' && board[5] != 'X'){
																																board[5] = 'O';
																																foundSpot = true;
																															}
																															else{
																																if (board[0] == 'O' && board[3] == 'O' && board[4] == 'X' && board[8] == 'X'&& board[5] == 'X' && board[6] != 'X'){
																																	board[6] = 'O';
																																	foundSpot = true;
																																}
																																else{
																																	if (board[4] == 'X' && board[1] == 'X' && board[0] == 'X' && board[5] == 'X' && board[6] != 'O'){
																																		board[6] = 'O';
																																		foundSpot = true;
																																	}
																																	//=====4 Condition Cases======
																																	else{
																																		if (board[1] == 'O' && board[4] == 'O' && board[5] == 'O' && board[3] == 'X'){
																																			board[6] = 'O';
																																			foundSpot = true;
																																		}
																																		else{
																																			if (board[4] == 'O' && board[2] == 'X' && board[6] == 'X' && board[7] != 'X'){
																																				board[7] = 'O';
																																				foundSpot = true;
																																			}
																																			else{
																																				if (board[1] == 'O' && board[4] == 'O' && board[5] == 'O' && board[3] != 'X'){
																																					board[3] = 'O';
																																					foundSpot = true;
																																				}
																																				else{
																																					if (board[0] == 'O' && board[2] == 'O' && board[4] == 'X' && board[1] != 'X'){
																																						board[1] = 'O';
																																						foundSpot = true;
																																					}
																																					//=====3 Condition Cases=======
																																					else{
																																						if (board[1] == 'O' && board[4] == 'O' && board[7] != 'X'){
																																							board[7] = 'O';
																																							foundSpot = true;
																																						}


																																						else{
																																							if (board[2] == 'O' && board[8] == 'O' && board[5] != 'X'){
																																								board[5] = 'O';
																																								foundSpot = true;
																																							}
																																							else{
																																								if (board[1] == 'O' && board[2] == 'O' && board[0] != 'X'){
																																									board[0] = 'O';
																																									foundSpot = true;
																																								}


																																								//*********************************Special Cases Defense************************************************
																																								//=====8 Condition Cases========
																																								else{
																																									if (board[4] == 'X' && board[8] == 'X' && board[1] == 'X' && board[3] == 'X' && board[2] == 'O' && board[0] == 'O' && board[7] == 'O' && board[5] != 'X'){
																																										board[5] = 'O';
																																										foundSpot = true;
																																									}
																																									//=====7 Condition Cases========
																																									else{
																																										if (board[1] == 'X' && board[4] == 'X' && board[5] == 'X' && board[2] == 'O' && board[7] == 'O' && board[3] == 'O' && board[0] != 'X'){
																																											board[0] = 'O';
																																											foundSpot = true;
																																										}


																																										//======6 Condition Cases=======
																																										else{
																																											if (board[2] == 'X' && board[0] == 'X' && board[7] == 'X' && board[1] == 'O' && board[4] == 'O' && board[5] == 'O'){
																																												board[6] = 'O';
																																												foundSpot = true;
																																											}

																																											
																																												else{
																																													if (board[4] == 'O' && board[8] == 'O' && board[6] == 'X' && board[7] == 'X' && board[0] == 'X' && board[3] != 'X'){
																																														board[3] = 'O';
																																														foundSpot = true;
																																													}
																																													//=======5 Condition Cases=========
																																													else{
																																														if (board[1] == 'X' && board[4] == 'X' && board[5] == 'X' && board[2] == 'O' && board[7] == 'O'){
																																															board[3] = 'O';
																																															foundSpot = true;
																																														}
																																														else{
																																															if (board[2] == 'X' && board[6] == 'X' && board[4] == 'O' && board[7] == 'O' && board[1] != 'X' && board[3] == 'X'){
																																																board[1] = 'O';
																																																foundSpot = true;
																																															}
																																															else{
																																																if (board[2] == 'X' && board[6] == 'X' && board[4] == 'O' && board[7] == 'X' && board[1] == 'X'){
																																																	board[0] = 'O';
																																																	foundSpot = true;
																																																}
																																														//======4 Condition Cases========
																																														else{
																																															if (board[0] == 'X' && board[2] == 'X' && board[7] == 'X' && board[8] == 'X'){
																																																board[5] = 'O';
																																																foundSpot = true;
																																															}

																																															else{
																																																if (board[4] == 'X' && board[7] == 'X' && board[0] == 'X' && board[5] == 'X'){
																																																	board[3] = 'O';
																																																	foundSpot = true;
																																																}
																																																else{
																																																	if (board[4] == 'X' && board[1] == 'X' && board[3] == 'X' && board[8] == 'X'){
																																																		board[0] = 'O';
																																																		foundSpot = true;
																																																	}
																																																	

																																																	//======3 Condition Cases=======
																																																	else{
																																																		if (board[4] == 'X' && board[7] == 'X' && board[0] == 'X'){
																																																			board[8] = 'O';
																																																			foundSpot = true;
																																																		}
																																																		else{
																																																			if (board[4] == 'X' && board[1] == 'X' && board[0] == 'X'){
																																																				board[8] = 'O';
																																																				foundSpot = true;
																																																			}
																																																			else{
																																																				if (board[4] == 'X' && board[1] == 'X' && board[3] == 'X'){
																																																					board[5] = 'O';
																																																					foundSpot = true;
																																																				}
																																																				//======2 Condition Cases=========
																																																				else{
																																																					if (board[4] == 'X' && board[1] == 'X'){
																																																						board[7] = 'O';
																																																						foundSpot = true;
																																																					}
																																																					else{
																																																						if (board[4] == 'X' && board[7] == 'X'){
																																																							board[1] = 'O';
																																																							foundSpot = true;
																																																						}
																																																						else{
																																																							if (board[0] == 'X' && board[2] == 'X'){
																																																								board[1] = 'O';
																																																								foundSpot = true;
																																																							}

																																																							else{
																																																								if (board[4] == 'X' && board[5] == 'X'){
																																																									board[3] = 'O';
																																																									foundSpot = true;
																																																								}






																																																								//Offensive Moves

																																																								else{
																																																									if (board[5] == 'O' && board[4] == 'O' && board[3] != 'X'){
																																																										board[3] = 'O';
																																																										foundSpot = true;
																																																									}
																																																									else{
																																																										if (board[3] == 'O' && board[4] == 'O' && board[5] != 'X'){
																																																											board[5] = 'O';
																																																											foundSpot = true;
																																																										}
																																																										else{
																																																											if (board[4] == 'O' && board[6] == 'O' && board[2] != 'X'){
																																																												board[2] = 'O';
																																																												foundSpot = true;
																																																											}
																																																											else{
																																																												if (board[2] == 'O' && board[1] == 'O' && board[0] != 'X'){
																																																													board[0] = 'O';
																																																													foundSpot = true;
																																																												}
																																																												else{
																																																													if (board[0] == 'O' && board[2] == 'O' && board[1] != 'X'){
																																																														board[1] = 'O';
																																																														foundSpot = true;
																																																													}
																																																													else{
																																																														if (board[0] == 'O' && board[3] == 'O' && board[6] != 'X'){
																																																															board[6] = 'O';
																																																															foundSpot = true;
																																																														}

																																																														else{
																																																															if (board[8] == 'O' && board[7] == 'O' && board[6] != 'X'){
																																																																board[6] = 'O';
																																																																foundSpot = true;
																																																															}
																																																															else{
																																																																if (board[0] == 'O' && board[4] == 'O' && board[8] != 'X'){
																																																																	board[8] = 'O';
																																																																	foundSpot = true;
																																																																}
																																																																else{
																																																																	if (board[7] == 'O' && board[4] == 'O' && board[1] != 'X'){
																																																																		board[1] = 'O';
																																																																		foundSpot = true;
																																																																	}

																																																																	else{
																																																																		if (board[2] == 'O' && board[5] == 'O' && board[8] != 'X'){
																																																																			board[8] = 'O';
																																																																			foundSpot = true;
																																																																		}
																																																																		else{
																																																																			if (board[4] == 'O' && board[8] == 'O' && board[0] != 'X'){
																																																																				board[0] = 'O';
																																																																				foundSpot = true;
																																																																			}

																																																																			//Defensive Moves

																																																																			else{
																																																																				if (board[4] == 'X' && board[7] == 'X' && board[2] == 'O'){
																																																																					board[1] = 'O';
																																																																					foundSpot = true;
																																																																				}

																																																																				else{
																																																																					if (board[0] == 'X' && board[6] == 'X'){
																																																																						board[3] = 'O';
																																																																						foundSpot = true;
																																																																					}
																																																																					else{
																																																																						if (board[6] == 'X' && board[7] == 'X'){
																																																																							board[8] = 'O';
																																																																							foundSpot = true;
																																																																						}
																																																																						else{
																																																																							if (board[0] == 'X' && board[3] == 'X'){
																																																																								board[6] = 'O';
																																																																								foundSpot = true;
																																																																							}
																																																																							else{
																																																																								if (board[2] == 'O' && board[8] == 'O'){
																																																																									board[5] == 'O';
																																																																									foundSpot = true;
																																																																								}
																																																																								else{
																																																																									if (board[7] == 'X' && board[8] == 'X'){
																																																																										board[6] = 'O';
																																																																										foundSpot = true;
																																																																									}
																																																																									else{
																																																																										if (board[8] == 'X' && board[6] == 'X'){
																																																																											board[7] = 'O';
																																																																											foundSpot = true;
																																																																										}
																																																																										else{
																																																																											if (board[3] == 'X' && board[6] == 'X'){
																																																																												board[0] = 'O';
																																																																												foundSpot = true;
																																																																											}
																																																																											else{
																																																																												if (board[0] == 'X' && board[8] == 'X'){
																																																																													board[1] = 'O';
																																																																													foundSpot = true;
																																																																												}


																																																																												else{
																																																																													if (board[4] == 'X' && board[6] == 'X'){
																																																																														board[8] = 'O';
																																																																														foundSpot = true;
																																																																													}

																																																																													else{
																																																																														if (board[2] == '2'){
																																																																															board[2] = 'O';
																																																																															foundSpot = true;
																																																																														}

																																																																														else{
																																																																															int spot = getBestMove();
																																																																															if (board[spot] != 'X' && board[spot] != 'O') {
																																																																																foundSpot = true;
																																																																																board[spot] = 'O';
																																																																															}
																																																																															else{
																																																																																foundSpot = false;
																																																																															}
																																																																														}
																																																																													}
																																																																												}
																																																																											}
																																																																										}
																																																																									}
																																																																								}
																																																																							}
																																																																						}
																																																																					}
																																																																				}
																																																																			}
																																																																		}
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		while (!foundSpot);
		printBoard();
	}

	int getBestMove() {
		std::vector<int> availableSpaces;
		bool foundBestMove = false;
		int spot = 100;

		if (board[2] == 'O' && board[8] == 'O' && board[5] !='X'){
			board[5] = 'O';
			foundBestMove = true;
			return spot;
		}
		else{
			if (board[2] == 'O' && board[5] == 'O' && board [8] !='X'){
				board[8] = 'O';
				foundBestMove = true;
				return spot;
			}
			else{
				for (int i = 0; i < 9; i++) {
					if (board[i] != 'X' && board[i] != 'O') {
						availableSpaces.push_back(i);
					}
				}

				for (int i = 0; i < availableSpaces.size(); i++) {
					spot = availableSpaces[i];
					board[spot] = 'O';
					if (gameIsOver()) {
						foundBestMove = true;
						board[spot] = '0' + spot;
						return spot;
					}
					else {
						board[spot] = 'X';
						if (gameIsOver()) {
							foundBestMove = true;
							board[spot] = '0' + spot;
							return spot;
						}
						else {
							board[spot] = '0' + spot;
						}
					}
				}
				if (foundBestMove) {
					return spot;
				}
				else {
					int n = rand() % availableSpaces.size();
					return availableSpaces[n];
				}
			}
		}
	}
};


/** The entry main method (the program starts here) */
int main() {
	Game game;

	char again = 'y';
	game.Banner(); //heading for the program
	
	while (again == 'y'){
		game.start();
		cout << "\nPlay Again? (y/n)";
		cin >> again; //changes controlled variable 
	}

	cout << "\n\nThanks for playing!\n" << endl;
		system("pause");
		return 0;
}

