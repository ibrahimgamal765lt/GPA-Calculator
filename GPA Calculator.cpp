#include <iostream>
using namespace std;

double getGradePoint(string grade) {
    for (auto& c : grade) {
        c = toupper(c);
    }
    if (grade == "A" || grade == "A+") return 4.0;
    else if (grade == "A-") return 3.6;
    else if (grade == "B+") return 3.3;
    else if (grade == "B") return 3.0;
    else if (grade == "B-") return 2.7;
    else if (grade == "C+") return 2.3;
    else if (grade == "C") return 2.0;
    else if (grade == "C-") return 1.7;
    else if (grade == "D+") return 1.3;
    else if (grade == "D") return 1.0;
    else cout<<"invalid grade";
    return 0;
}

int main() {
    int numsubjects;
    double totalcredits = 0, totalpoints = 0;
    double gpa, point;

    cout << "How many subjects? ";
    cin >> numsubjects;

    for (int i = 1; i <= numsubjects; i++) {
        double credit;
        string grade;

        cout << "\nSubject " << i << ":\n";
        cout << "  Credit hours: ";
        cin >> credit;
        cout << "  Letter grade (e.g., A, B+, C): ";
        cin >> grade;

        point = getGradePoint(grade);
        totalcredits += credit;
        totalpoints += credit * point;
    }
    if (totalcredits > 0) {
    gpa = totalpoints / totalcredits;
    cout << "\nTotal GPA: " << gpa << endl;
    }
    else cout << "invalid total credits"<<endl;
    if (gpa <= 4 && gpa >= 3.6) cout << "You got Excellent" << endl;
    else if (gpa < 3.6 && gpa >= 2.7) cout << "You got Very Good" << endl;
    else if (gpa < 2.7 && gpa >= 2) cout << "You got Good" << endl;
    else if (gpa < 2 && gpa >= 1) cout << "You got Acceptable" << endl;
    else if (gpa < 1) cout << "You Failed"<<endl;
    cout << "Press Enter to exit...";
    cin.clear();
    cin.ignore();
    cin.get();

    return 0;
}