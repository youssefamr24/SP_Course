/*File :CS112_A2_T2_S28_20230502
Purpose: The Atbash cipher is a very common, simple cipher. Basically, when encoded, "A" becomes a
"Z" and "B" turns into"Y", etc.
 Author: Youssef amr mohamed rashad eissa
 id: 20230502
 TA:Asmaa Elsayed Ahmed Mohamed
 Section: S28
 cipher:Atbash
 email:youssefamr.fcai@gmail.com
 Note:I haven't get a team and i emailed Dr.elramly to find a solution to this problem and he told me to work alone until i get team

 */
#include <iostream>
#include <cctype>
using namespace std;

// Function to remove non-alphabetic characters from the string
string remove_non_alphabets(string str) {
    string result;
    for (char c : str) {
        if (isalpha(c) || isspace(c)) {
            result += c;
        }
    }
    return result;
}

// Function to perform Atbash cipher
void Atbash()
{
    char choice;
    string to_ciphered;
    cout << "==== Welcome to Atbash cipher ====" << endl;
    cout << "Please enter your text that needs to be ciphered or diciphered (only alphabets): " << endl;
    getline(cin, to_ciphered); // to read all string

    // Remove non-alphabetic characters from the string
    to_ciphered = remove_non_alphabets(to_ciphered);

    // Divide the string into two halves
    string first_half = to_ciphered.substr(0, to_ciphered.length() / 2);
    string second_half = to_ciphered.substr(to_ciphered.length() / 2);


    do {
        cout << "Please, enter which version do you want." << endl << "A)ciphering the text at one time" << endl <<  "B) dividing the text into two halves and then ciphering each part separately "  << endl;
        cin >> choice;

    if(choice == 'A' || choice == 'a' )
    {
        // Apply Atbash cipher to each character
        for (char c : to_ciphered)
        {
            if (isalpha(c))
            {
                if(islower(c))
                {
                    char base = 'a';
                    char reversed = 'z' - (c - base); // Calculate the reversed letter for lowercase
                    cout << reversed;
                }
                else
                {
                    char base = 'A';
                    char reversed = 'Z' - (c - base); // Calculate the reversed letter for uppercase
                    cout << reversed;
                }
            }
            else if (isspace(c))
            {
                cout << " "  ;
            }
            else
            {
                cout << "Invalid answer.Please type a text of alphabets only." << endl;
                break;
            }
        }

    }
    else if(choice == 'B' || choice == 'b') {
        // Apply Atbash cipher to Second half
        for (char c: second_half) {
            if (isalpha(c))
            {
                if(islower(c))
                {
                    char base = 'a';
                    char reversed = 'z' - (c - base); // Calculate the reversed letter for lowercase
                    cout << reversed;
                }
                else
                {
                    char base = 'A';
                    char reversed = 'Z' - (c - base); // Calculate the reversed letter for uppercase
                    cout << reversed;
                }
            }
            else if (isspace(c))
            {
                cout << " "  ;// Print a space
                break;
            }

            else
            {
                cout << "Invalid answer.Please type a text of alphabets only." << endl;
                continue;
            }
        }
        cout << " "; // Print a space
        // Apply Atbash cipher to first half
        for (char c: first_half) {
            if (isalpha(c))
            {
                if(islower(c))
                {
                    char base = 'a';
                    char reversed = 'z' - (c - base); // Calculate the reversed letter for lowercase
                    cout << reversed;
                }
                else
                {
                    char base = 'A';
                    char reversed = 'Z' - (c - base); // Calculate the reversed letter for uppercase
                    cout << reversed;
                }
            }
            else if (isspace(c))
            {
                cout << " "  ;// Print a space
                continue;
            }

            else
            {
                cout << "Invalid answer.Please type a text of alphabets only." << endl;
                break;
            }
        }
    }
    else
    {
        cout << "Invalid choice.Please select a valid choice (A/B)" << endl;

    }
    } while(choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b');

}

int main() {
    Atbash();
    return 0;
}


