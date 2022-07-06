#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows) {
    string ret;
    int nextLetterI, firstNext, previousJ = 0;
    int gap = 2 * (numRows - 1);

    for (int i = 0; i < numRows; i++) {
        nextLetterI = (2 * (numRows - 1)) - (2 * i);
        firstNext = nextLetterI;

        if (i == numRows - 1) {
            nextLetterI = 2 * (numRows - 1);
        }

        for (int j = previousJ; j < s.size(); j = j + nextLetterI) {
            if (nextLetterI == firstNext && nextLetterI != gap && j != previousJ) {
                //ret += s[j];
                //cout << ret << endl;
                //if (firstNext < gap) {
                nextLetterI = gap - firstNext;
                //}
            }
            else if (nextLetterI != firstNext && nextLetterI != gap) {
                //ret += s[j];
                nextLetterI = firstNext;

                //cout << ret << endl;
            }

            ret += s[j];

            //cout << ret << endl;

            //if (j + nextLetterI >= s.size()) {
            //    break;
            //}
        }

        if (i < numRows) {
            previousJ = previousJ + 1;
        }
    }

    return ret;
}

int main()
{
    string s = "PAYPALISHIRING";

    cout << convert(s, 4);

    return 0;
}