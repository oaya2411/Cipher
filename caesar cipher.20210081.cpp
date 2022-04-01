/* FCAI . CU – Programming 1 – 2022 - Assignment 2.
 Program Name: CAESER CIPHER.cpp.
 Program Description: Cipher and Decipher program.
 Last Modification Date: 25/3/20222.
 Author1 and ID and Group: Aya Osama Mohammed, 20210081.
 Teaching Assistant: NOT BE DETERMINED YET.
 Purpose:How to encrypt or decrypt a message for the user with knowledge of number of shifts which the user wants to be.

 */
#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

int main() {
    int choice, shifts;//we need to know number of shifts and the option that user wants to do.
    string stat, message;//variable for statement which will be encrypted or decrypted.
    char n;//for every letter in the string.
    cout << "Ahlan ya user ya habibi.\n";//welcome statement to know the option user wants.
    cout << "What do you like to do today?\n";
    cout << "1- Cipher a message.\n";
    cout << "2- Decipher a message.\n";
    cout << "3- End\n>>";
    cin >> choice;//so we will take choice
    if (choice == 3) {
        cout << "End";
        //the third choice required not to do anything, so we put it before choice 1 and 2.
    } else {
        cout
                << "please input the statement: ";//if he wants anything except end the program i will take string from him.

        cin.ignore();
        getline(cin,
                message);//the user may input statement with spaces and that is required to use the function of getline().

        transform(message.begin(), message.end(), message.begin(), ::toupper);
        //we use the function of transform to convert all the letters from small to capital or capital to capital.

        stat = message;//we will use stat to express the modified string

        if (choice == 1) {//choice 1 to encrypt.
            cout << "enter number of the shifts please: ";
            cin >> shifts;
            for (int i = 0; i <
                            stat.size(); i++) {//use loop to convert all letters not the first letter or only one part of the statement.
                if (shifts >= 0 && shifts <=
                                   26) {//shifts may be positive or  negative it also can be over 26, so we ought to do all cases.

                    if (char(stat.at(i) + shifts) <= 'Z' && char(stat.at(i) + shifts) >= 'A') {
                        //we check here to convert the letter using the new ascci code for it.
                        n = char(stat.at(i) + shifts);
                        cout << n;
                    } else if (char(stat.at(i) + shifts) > 'Z') {
                        //the operation of shifts can give ASCCi for not required .
                        n = char(stat.at(i) + shifts) -
                            26;//so we subtract of 26.AS: if he input 23 and the ASCCi is 110 so you will be out of the rang of the alphabet letter.
                        cout << n;//then show it and loop again
                    } else if (char(stat.at(i)) == ' ') {
                        //this is for spaces so it doesn't convert to anything
                        n = ' ';
                        cout << n;
                    }


                } else if (shifts > 26) {
                    //here we check the shifts bigger than 26.so we make a loop until number of shifts become less than 26 and pos.
                    for (int j = 1; j < 26; j++) {
                        shifts = shifts - 26 * j;
                        if (shifts <=26)//as soon as it becomes true he will break and with the same way the convertion will done.
                            break;
                        else
                            continue;

                    }

                    if (char(stat.at(i) + shifts) <= 'Z' && char(stat.at(i) + shifts) >= 'A') {
                        n = char(stat.at(i) + shifts);
                        cout << n;
                    } else if (char(stat.at(i) + shifts) > 'Z') {
                        n = char(stat.at(i) + shifts) - 26;
                        cout << n;
                    } else if (char(stat.at(i)) == ' ') {
                        n = ' ';
                        cout << n;
                    }


                } else if (shifts < 0) {
                    for (int x = 1; x <= 26; x++) {
                        shifts = (shifts + 26 * x) +26;//if the shifts<0 we put condition to make it positive with same affect.
                        if (shifts > 0)
                            break;
                        else
                            continue;
                    }
                    if (char(stat.at(i) + shifts) <= 'Z' && char(stat.at(i) + shifts) >= 'A') {
                        n = char(stat.at(i) + shifts);
                        cout << n;
                    } else if (char(stat.at(i) + shifts) > 'Z') {
                        n = char(stat.at(i) + shifts) - 26;
                        cout << n;
                    } else if (char(stat.at(i)) == ' ') {
                        n = ' ';
                        cout << n;
                    }

                }


            }


        } else if (choice ==2) {//choice2 for decrypt so same things are happens but shifts move back not forward so we subtract not add.
            cout << "enter number of the shifts please: ";
            cin >> shifts;
            for (int i = 0; i < stat.size(); i++) {
                if (shifts >= 0 && shifts <= 26) {
                    if (char(stat.at(i) - shifts) <= 'Z' && char(stat.at(i) - shifts) >= 'A') {
                        n = char(stat.at(i)) - shifts;
                        cout << n;
                    } else if (char(stat.at(i) - shifts) < 'A' && char(stat.at(i) - shifts) > ' ') {
                        n = (char(stat.at(i) - shifts)) + 26;
                        cout << n;
                    } else if (char(stat.at(i)) == ' ') {
                        n = ' ';
                        cout << n;
                    }
                } else if (shifts < 0) {
                    for (int x = 1; x <= 26; x++) {
                        shifts = (shifts + 26);
                        if (shifts > 0)
                            break;
                        else
                            continue;
                    }
                    if (char(stat.at(i) - shifts) <= 'Z' && char(stat.at(i) - shifts) >= 'A') {
                        n = char(stat.at(i)) - shifts;
                        cout << n;
                    } else if (char(stat.at(i) - shifts) < 'A' && char(stat.at(i) - shifts) > ' ') {
                        n = (char(stat.at(i) - shifts)) + 26;
                        cout << n;
                    } else if (char(stat.at(i)) == ' ') {
                        n = ' ';
                        cout << n;
                    }

                } else if (shifts > 26) {
                    for (int j = 1; j < 26; j++) {
                        shifts = shifts - 26 * j;
                        if (shifts <= 26)
                            break;
                        else
                            continue;

                    }
                    if (char(stat.at(i) - shifts) <= 'Z' && char(stat.at(i) - shifts) >= 'A') {
                        n = char(stat.at(i)) - shifts;
                        cout << n;
                    } else if (char(stat.at(i) - shifts) < 'A' && char(stat.at(i) - shifts) > ' ') {
                        n = (char(stat.at(i) - shifts)) + 26;
                        cout << n;
                    } else if (char(stat.at(i)) == ' ') {
                        n = ' ';
                        cout << n;
                    }
                }

            }

        }


    }
    return 0;
}
