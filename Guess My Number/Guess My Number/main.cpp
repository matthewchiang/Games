#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int solve(int);

int main()
{
	int answer = 0;
	int guess = 0;
	string playAgain = "Yes";

	srand(time(NULL));

	while (playAgain == "Yes" || playAgain == "yes"
		|| playAgain == "Y" || playAgain == "y"
		|| playAgain == "solve")
	{
		answer = rand() % 100 + 1;

		if (playAgain == "solve")
			guess = solve(answer);

		cout << "A random number has been selected from 0 to 100\n";

		cout << "Guess the number:\n";

		do
		{	
			cin >> guess;

			if (guess < answer)
				cout << "The answer is higher\n";
			else if (guess > answer)
				cout << "The answer is lower\n";
			else
				cout << "You guessed the number!\n";

		} while (guess != answer);

		cout << "Play again? (Yes or no) \n";

		cin >> playAgain;
		
	}

	return 0;
}


int solve(int answer)
{
	cout << "Entering solve\n";

	int attemptNum = 0;
	int guess = 50;
	int prevHigh = 100;
	int prevLow = 0;

	do
	{
		cout << "Guess = " << guess << endl;

		attemptNum++;

		if (guess < answer)
		{
			prevLow = guess;
			guess = ((guess + prevHigh) / 2);
		}
		else if (guess > answer)
		{
			prevHigh = guess;
			guess = ((guess + prevLow) / 2);
		}
		

	} while (guess != answer);

	cout << "Found the number in " << attemptNum << " attempts\n";
	cout << "The number is " << guess << endl;

	return guess;
}