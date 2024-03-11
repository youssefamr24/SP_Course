#include <iostream>
#include <cctype>
using namespace std;

// Function to remove non-alphabetic characters from the string
string removeNonAlphabets(string str) {
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
    cout << "Please enter your text that needs to be ciphered (only alphabets): " << endl;
    getline(cin, to_ciphered); // to read all string

    // Remove non-alphabetic characters from the string
    to_ciphered = removeNonAlphabets(to_ciphered);

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
        // Apply Atbash cipher to first half
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
        // Apply Atbash cipher to second half
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


