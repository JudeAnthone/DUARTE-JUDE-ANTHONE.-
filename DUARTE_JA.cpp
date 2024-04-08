#include <iostream>
#include <string>
#include <limits>
using namespace std;

int record = 0;
const int MAX_RECORDS = 70; // is the class record for BSCS - 1A
string data[MAX_RECORDS][4];

// Function prototypes
void showMenu();
void registerStudent();
void logIn();
void logOut();
void clear();

// program execution starts, dito papasok ang choice ng USER sa MENU
int main()
{
    int choice;

    do
    {

        showMenu();
        cin >> choice;

        if (!cin >> choice)
        {
            cout << '\n';
            cout << "ERROR: Please Enter an INTEGER only! \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            registerStudent();
            break;
        case 2:
            logIn();
            break;
        case 3:
            logOut();
            break;
        case 4:
            int exit;

            cout << "Are you Sure you want to Exit?\n";
            cout << "  1.YES\n  ";
            cout << "  2.NO\n  ";
            cin >> exit;

            if (exit == 1)
            {
                cout << "Thank you! Rest assured that your information is well kept.\n";
                return 0;
            }
            else if (exit == 2)
            {
                choice = 1;
            }
            break;

            return 0;
        default:
            cout << '\n';
            cout << "ERROR: Invalid choice. Please try again.\n";
            break;
        }
    } while (true);
    clear();
    return 0;
}

void showMenu()
{
    cout << "\n    BSCS - 1A REGISTRATION SYSTEM\n\n";
    cout << "************************************\n";
    cout << "           SELECT MENU \n";
    cout << "************************************\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Logout\n";
    cout << "4. Exit\n";
}

void registerStudent()
{
    if (record >= MAX_RECORDS)
    {
        cout << "ERROR: Maximum student limit reached for your section.\n";
        return;
    }

    string username, password, name;

    cout << "Enter FULL NAME: \n";
    cin.ignore();
    getline(cin, name);

    cout << "Enter USERNAME: \n";
    getline(cin, username);

    cout << "Enter PASSWORD: \n";
    getline(cin, password);
    // check if the username and password is empty. If true, display the error
    if (username.empty() || password.empty())
    {
        cout << "Error: Username or password cannot be empty.\n";
        return;
    }

    data[record][0] = name;
    data[record][1] = username;
    data[record][2] = password;
    data[record][3] = "LOGGED OUT";
    record++;
    cout << '\n';
    cout << "Registration Successful (Please remember you USERNAME AND PASSWORD\n";
    cout << '\n';
    clear();
}

void logIn()
{
    string username, password;

    cout << "Enter USERNAME: \n";
    cin.ignore();
    getline(cin, username);

    cout << "Enter PASSWORD: \n";
    getline(cin, password);
    // iterates on the whole max record as long as i is less than max record
    //  if the i is already greater that max record, the loop will stop.
    for (int i = 0; i < MAX_RECORDS; ++i)
    {
        // matching username and password (checks if the details is stored within each itteration)
        if (data[i][1] == username && data[i][2] == password)
        {

            // update log in status, this will work if the username and password are valid
            //  the function updates the log in status to "student log in"
            data[i][3] = "LOGGED IN";
            cout << '\n';
            cout << "SUCESS: LOGGED IN!\n";
            cout << '\n';
            clear();
            return;
        }
    }
    cout << '\n';
    cout << "Error: Invalid username or password.\n";
}

void logOut()
{
    string username;

    cout << "Enter Username: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, username);

    for (int i = 0; i < MAX_RECORDS; ++i)
    {
        // matching username (checks if the username is matched in the input of user)
        if (data[i][1] == username)
        {
            data[i][3] = "LOGGED OUT";
            cout << '\n';
            cout << "SUCESS: LOGED OUT!\n";
            clear();
            return;
        }
    }
    cout << '\n';
    cout << "Error: User not found.\n";
}

void clear()
{
    cout << "\nPress Enter key to continue...";
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    system("cls");
}
