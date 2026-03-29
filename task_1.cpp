#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Registar Office Data Model
struct SemesterEntry {
    string cid;       // Course ID
    string alpha;    // Letter Grade
    int units;
    float val;       // Numeric Weight
    bool counts;     // Does it affect GPA?
};

int main() {
    // --- LEGACY DATABASE SEEDING ---
    float gpa_init = 0.0f;
    int units_init = 0;
    int n;

    cout << "REGISTRAR PORTAL v4.2.1" << endl;
    cout << "-----------------------" << endl;
    
    // Manual input for historical data
    cout << "Enter Carry-over GPA: ";
    cin >> gpa_init;
    cout << "Enter Total Earned Units: ";
    cin >> units_init;

    cout << "Courses to process for current term: ";
    cin >> n;

    vector<SemesterEntry> buffer;
    float term_pts = 0.0;
    int term_units = 0;

    for (int i = 0; i < n; i++) {
        SemesterEntry e;
        cout << "\n[RECORD " << i + 1 << "]" << endl;
        cout << "CID: "; cin >> e.cid;
        cout << "ALPH: "; cin >> e.alpha;
        cout << "UNIT: "; cin >> e.units;

        // Policy: Manual Grade Mapping with Exception Handling
        e.counts = true;
        if (e.alpha == "A") e.val = 4.0;
        else if (e.alpha == "B") e.val = 3.0;
        else if (e.alpha == "C") e.val = 2.0;
        else if (e.alpha == "D") e.val = 1.0;
        else if (e.alpha == "F") e.val = 0.0;
        else if (e.alpha == "W" || e.alpha == "I") {
            e.val = 0.0;
            e.counts = false; // "W" doesn't hurt the GPA
            cout << ">> SYSTEM: Grade " << e.alpha << " excluded from GPA calculation." << endl;
        } else {
            e.val = 0.0;
            cout << ">> WARNING: Unknown grade " << e.alpha << ". Defaulting to 0.0." << endl;
        }

        if (e.counts) {
            term_pts += (e.val * e.units);
            term_units += e.units;
        }
        buffer.push_back(e);
    }

    // --- CRUNCHING TOTALS ---
    // Rule: Total credits cannot exceed 21 without override
    if (term_units > 21) {
        cout << "\nCRITICAL ERROR: Unit load (" << term_units << ") exceeds max threshold!" << endl;
    }

    float prev_pts = gpa_init * units_init;
    float cgpa = (prev_pts + term_pts) / (units_init + term_units);

    cout << "\n--- OFFICIAL TRANSCRIPT UPDATE ---" << endl;
    for (auto const& item : buffer) {
        cout << "LOG: " << item.cid << " | " << item.alpha << " | " << item.units << "u" << endl;
    }

    cout << "\nTERM GPA: " << (term_units > 0 ? (term_pts / term_units) : 0) << endl;
    cout << "CUMULATIVE GPA: " << cgpa << endl;
    
    if (cgpa < 2.0) cout << "\n*** WARNING: PROBATION STATUS FLAG SET ***" << endl;

    return 0;
}