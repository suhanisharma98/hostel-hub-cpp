#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Hostel {
private:
    string name;
    int rollNo;
    static int bedCount;
    static vector<Hostel> ve;

public:
    Hostel() {}
    Hostel(string n, int r) {
        name = n;
        rollNo = r;
    }

    static bool bedStatus() {
        return bedCount < 3;
    }

    static void addStudent(string n, int r) {
        if (bedStatus()) {
            Hostel hostel(n, r);
            ve.push_back(hostel);
            bedCount++;
            cout << "\n[+] Bed allocated successfully to " << n << " (Roll No: " << r << ")\n\n";
        } else {
            cout << "\n[-] Sorry, the hostel is currently full.\n\n";
        }
    }

    static void removeStudent() {
        int rn;
        cout << "\n-> Enter Roll No to remove student: ";
        cin >> rn;
        for (int i = 0; i < ve.size(); i++) {
            if (rn == ve[i].rollNo) {
                cout << "\n[-] Removing student: " << ve[i].name << " (Roll No: " << rn << ")\n";
                ve.erase(ve.begin() + i);
                bedCount--;
                cout << "[+] Student removed successfully.\n\n";
                return;
            }
        }
        cout << "\n[!] No student found with Roll No: " << rn << "\n\n";
    }

    static void displayStudents() {
        if (ve.empty()) {
            cout << "\n[!] No students currently in the hostel.\n\n";
            return;
        }

        cout << "\nList of Students in Hostel:\n";
        cout << "+----+------------------------+------------+\n";
        cout << "| No | Name                   | Roll No    |\n";
        cout << "+----+------------------------+------------+\n";
        for (int i = 0; i < ve.size(); i++) {
            cout << "| " << setw(2) << i + 1 << " | ";
            cout << setw(22) << left << ve[i].name << " | ";
            cout << setw(10) << ve[i].rollNo << " |\n";
        }
        cout << "+----+------------------------+------------+\n\n";
    }
};

int Hostel::bedCount = 0;
vector<Hostel> Hostel::ve;

void showMenu() {
    cout << "\n+====================================+\n";
    cout << "|      HOSTEL MANAGEMENT SYSTEM      |\n";
    cout << "+====================================+\n";
    cout << "| 1. Add Student                     |\n";
    cout << "| 2. Remove Student                  |\n";
    cout << "| 3. Display Students                |\n";
    cout << "| 0. Exit                            |\n";
    cout << "+====================================+\n";
    cout << "-> Enter your choice: ";
}

int main() {
    string name;
    int roll;
    int choice;

    while (true) {
        system("cls");
        showMenu();
        cin >> choice;
        cin.ignore(); // for handling leftover newline

        switch (choice) {
        case 1:
            system("cls");
            cout << "\n--- Add New Student ---\n";
            cout << "Enter Full Name : ";
            getline(cin, name); // allows spaces
            cout << "Enter Roll No   : ";
            cin >> roll;
            Hostel::addStudent(name, roll);
            break;

        case 2:
            system("cls");
            Hostel::removeStudent();
            break;

        case 3:
            system("cls");
            Hostel::displayStudents();
            break;

        case 0:
            char confirm;
            cout << "\n-> Are you sure you want to exit? (Y/N): ";
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y') {
                cout << "\n[+] Thank you for using the system. Goodbye!\n\n";
                return 0;
            }
            break;

        default:
            cout << "\n[!] Invalid input. Please enter a number between 0–3.\n\n";
            break;
        }

        system("pause");
    }

    return 0;
}

