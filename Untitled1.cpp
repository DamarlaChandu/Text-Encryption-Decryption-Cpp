#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to encrypt text
string encrypt(string text, int shift) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char((c - base + shift) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

// Function to decrypt text
string decrypt(string text, int shift) {
    return encrypt(text, 26 - (shift % 26));
}

// Function to read text from a file
string readFile(string filename) {
    ifstream file(filename.c_str());
    string content = "", line;
    if (!file) {
        cout << "Error: File not found!" << endl;
        return "";
    }
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}

// Function to write text to a file
void writeFile(string filename, string text) {
    ofstream file(filename.c_str());
    file << text;
    file.close();
    cout << "Output written to " << filename << endl;
}

int main() {
    int choice, shift;
    string text, filename, outputFile;

    do {
        cout << "\n=== Caesar Cipher Menu ===\n";
        cout << "1. Encrypt text\n";
        cout << "2. Decrypt text\n";
        cout << "3. Encrypt from file\n";
        cout << "4. Decrypt from file\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(1000, '\n'); // Clear input buffer

        switch(choice) {
            case 1:
                cout << "Enter message: ";
                getline(cin, text);
                cout << "Enter shift key: ";
                cin >> shift;
                cin.ignore(1000, '\n');
                cout << "Encrypted message: " << encrypt(text, shift) << endl;
                break;

            case 2:
                cout << "Enter message: ";
                getline(cin, text);
                cout << "Enter shift key: ";
                cin >> shift;
                cin.ignore(1000, '\n');
                cout << "Decrypted message: " << decrypt(text, shift) << endl;
                break;

            case 3:
                cout << "Enter input filename: ";
                getline(cin, filename);
                cout << "Enter output filename: ";
                getline(cin, outputFile);
                cout << "Enter shift key: ";
                cin >> shift;
                cin.ignore(1000, '\n');
                text = readFile(filename);
                if (!text.empty()) writeFile(outputFile, encrypt(text, shift));
                break;

            case 4:
                cout << "Enter input filename: ";
                getline(cin, filename);
                cout << "Enter output filename: ";
                getline(cin, outputFile);
                cout << "Enter shift key: ";
                cin >> shift;
                cin.ignore(1000, '\n');
                text = readFile(filename);
                if (!text.empty()) writeFile(outputFile, decrypt(text, shift));
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 5);

    return 0;
}

