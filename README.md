# CGPA Management System (Registrar Portal v4.2.1)
## About the Project

This is a C++ based CGPA Management System designed as part of my internship at Apexcify Technology.
It simulates a university registrar system that calculates both Term GPA and Cumulative GPA (CGPA) using grade inputs, credit units, and previous academic records.

## Objective

#### The main objective of this project is to:

- Store and process semester course data
- Convert letter grades into grade points
- Calculate Term GPA
- Calculate CGPA using previous academic record
- Handle special grades like W (Withdraw) and I (Incomplete)
- Validate credit load conditions
  
## Features
- Input carry-over GPA and total earned units
- Input multiple course records dynamically
- Grade mapping system (A, B, C, D, F)
#### Special handling for:
- W (Withdraw) → excluded from GPA
- I (Incomplete) → excluded from GPA
- Term GPA calculation
- CGPA calculation using previous + current performance
#### Warning system for:
- Unknown grades
- Overloaded credit hours (>21 units)
- Probation alert if CGPA < 2.0
## Concepts Used
- C++ Programming
- Structures (struct)
- Vectors (std::vector)
- Loops
- Conditional statements
- Grade mapping logic
- GPA calculation formulas
- Basic simulation of real world registrar system
  
## Sample Interaction
REGISTRAR PORTAL v4.2.1
-----------------------
Enter Carry-over GPA: 3.2<br>
Enter Total Earned Units: 30<br>
Courses to process for current term: 3<br>

[RECORD 1]<br>
CID: CS101<br>
ALPH: A<br>
UNIT: 3<br>

[RECORD 2]<br>
CID: MA101<br>
ALPH: B<br>
UNIT: 4<br>

[RECORD 3]<br>
CID: PHY101<br>
ALPH: W<br>
UNIT: 2<br>
SYSTEM: Grade W excluded from GPA calculation.<br>

CRITICAL ERROR: Unit load (7) exceeds max threshold!<br>

--- OFFICIAL TRANSCRIPT UPDATE ---<br>
LOG: CS101 | A | 3u<br>
LOG: MA101 | B | 4u<br>
LOG: PHY101 | W | 2u<br>

TERM GPA: 3.43<br>
CUMULATIVE GPA: 3.32<br>
## Output Features
- Displays term-wise course logs
- Calculates Term GPA
- Calculates CGPA
#### Shows warnings for:
- Unknown grades
- Credit overload
- Academic probation
## Author

**Name:** Asma Batool <br>
**Internship:** Apexcify Technologys  
**GitHub:** (https://github.com/batoolasma2005-lgtm)  
**Role:** C++ Programing
