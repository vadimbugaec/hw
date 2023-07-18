#include <iostream> 
#include <ctime> 
#include <cstdlib> 

using namespace std;

int main()
{
    cout << "Welcome to super puper mega randomizer game!\nI`ll generate a number from 0 to 50, try to guess it\n\n" <<
        "Generating random number from 0 to 50\n" << "Enter -1 to end the game!\n";
    int highscore = 0;
    while (true)
    {

        srand(time(nullptr));
        const int GeneratingRange = 50;
        const int generatedNum = rand() % (GeneratingRange + 1);
        int guess = 0, trycounter;

        cout << "High chance that generated number is -2" << endl;
        cout << endl << "--------------------------------------------" << endl;
        cout << "\t\tNEW GAME";
        cout << endl << "--------------------------------------------" << endl;
        trycounter = 0;

        while (true)
        {
            trycounter++;

            cout << endl << "Make your guess: ";
            cin >> guess;
            
            if (guess == -2)
            {
                std::cout << "GET SCAMMED! BYE BYE CLOWN!";
                return 0;
            }
            if (guess == -1)
            {
                std::cout << "END OF THE GAME. GOODBYE!";
                return 0;
            }
            if (guess < 0 || guess > 50)
            {
                std::cout << "Wrong number" << std::endl;
                continue;
            }
            if (guess > generatedNum && guess < generatedNum + 10)
            {
                cout << "Try a little less!";
            }
            else if (guess > generatedNum && guess < generatedNum + 20)
            {
                cout << "Try less!";
            }
            else if (generatedNum > guess && guess > generatedNum - 10)
            {
                cout << "Try a little higher!";
            }
            else if (guess < generatedNum && guess > generatedNum - 20)
            {
                cout << "Try higher";
            }
            else if (guess < generatedNum)
            {
                cout << "Too low!";
            }
            else if (guess > generatedNum)
            {
                cout << "Too high!";
            }
            else if (guess == generatedNum)
            {
                if (trycounter >= 10)
                {
                    cout << "GRATZ GJ WP YOU GUESSED! WOW INCREDIBLE IT WAS SUPER HARD! (YOURE UNSKILL)" << endl;
                }
                if (trycounter > 2)
                {
                    cout << "GJ YOU GUESSED! NOT THAT BAD" << endl;
                }
                else if (trycounter <= 2)
                {
                    cout << "LUCKER!!!" << endl;
                }
                if (highscore != 0)
                {
                    if (highscore > trycounter)
                    {
                        highscore = trycounter;
                        cout << "NEW HIGHSCORE: " << highscore << endl;
                    }
                    else if (highscore == trycounter)
                    {
                        cout << "THE SAME HIGHSCORE" << endl;
                    }
                    else
                    {
                        cout << "YOU CANT BEAT HIGHSCORE. BRUH!" << endl;
                    }
                }
                else
                {
                    highscore = trycounter;
                    cout << "NEW HIGHSCORE: " << highscore << endl;
                }
                break;
            }
        }

    }
}