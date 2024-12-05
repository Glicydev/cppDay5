// Faire un programme qui regarde dans des listes si certaines règles sont repectées (dans rules: {plus petit, plus grand})

#include <iostream>
#include <algorithm>

using namespace std;

int rules[21][2] {
    {47, 53},
    {97, 13},
    {97, 61},
    {97, 47},
    {75, 29},
    {61, 13},
    {75, 53},
    {29, 13},
    {97, 29},
    {53, 29},
    {61, 53},
    {97, 53},
    {61, 29},
    {47, 13},
    {75, 47},
    {97, 75},
    {47, 61},
    {75, 61},
    {47, 29},
    {75, 13},
    {53, 13}
};

int updates[6][5] {
    {75,47,61,53,29},
    {97,61,53,29,13},
    {75,29,13},
    {75,97,47,61,53},
    {61,13,29},
    {97,13,75,29,47}
};

/// <summary>
/// Look if the rules between 2 elements is respected
/// </summary>
/// <param name="nb1">First number to check</param>
/// <param name="nb2">Second number to check</param>
/// <returns> True if it's OK, else false </returns>
bool verifyRule(int& smaller, int& bigger) {

    // Initialisation
    int rightIndex = 0;

    // Traitement
    for (int i = 0; i < 21; i++) {

        int* firstElement = rules[i];
        int* lastElement = rules[i] + 2;

        // Get the rule where nb1 and nb2 are both
        if (find(firstElement, lastElement, smaller) != lastElement && find(firstElement, lastElement, bigger) != lastElement) {
            rightIndex = i;
            break;
        }
    }

    // If the first element in the rule is the smallest, so the rule is right!
    if (rules[rightIndex][0] == smaller) {
        return true;
    }
    return false;
}

/// <summary>
/// Verify if one line is correct
/// </summary>
/// <param name="line">The line</param>
/// <returns> True if it's right, else false </returns>
bool VerifyLine(int (&line)[5]) {

    for (int i = 0; i < 4; i++) {

        for (int testWith = 0; testWith < 5; testWith++) {
                if (testWith > i) {
                    if (!verifyRule(line[i], line[testWith])) {
                        return false;
                    }
                }
                else if (testWith < i){
                    if (!verifyRule(line[testWith], line[i])) {
                        return false;
                    }
                }
        }
    }
    return true;
}

int main()
{
    for (int i = 1; i <= 6; i++) {
        if (VerifyLine(updates[i - 1])) {
            cout << "The line " << i << " is OK." << endl;
        }
        else {
            cout << "The line " << i << " is not OK" << endl;
        }
    }
}