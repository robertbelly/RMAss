//
//  main.cpp
//  RMAss
//
//  Created by Robert Bell on 6/16/16.
//  Copyright © 2016 Robert Bell. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int NUMBER_OF_ASSIGNMENTS;
int NUMBER_OF_DAYS;
int arrayAssignmentMarker = 0;
const int MODE = 0;
ifstream in_file;
void swap (string *a, string *b)
{
    string temp = *a;
    *a = *b;
    *b = temp;
}
void randomize ( string arr[], int n )
{
    srand (time(NULL));
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}


int main() {
    int more;
    if (MODE == 0) {
        in_file.open("DXnameslist.txt", ios::in);
        if (in_file.fail()) {
            cout << "Could not open input file.  Program terminating.\n\nEnter an integer to quit.";
            cin >> more;
            return 0;
        }
    }
    cout << "Total number of assignments: ";
    cin >> NUMBER_OF_ASSIGNMENTS;
    string *mainArray;
    mainArray = new string[NUMBER_OF_ASSIGNMENTS];
    string *dateArray;
    dateArray = new string[NUMBER_OF_DAYS];
    int NUMBER_OF_NAMES;
    NUMBER_OF_NAMES = 0;
    string val;
    int classorind;

    cout << "Do you want to assign individually or by class? (1 for ind, 2 for class)" << endl;
    cin >> classorind;

    if (classorind == 1) {
        while (in_file >> ws) //fills in the names array with people's names and the # of possible assignments
        {
            getline(in_file, val);
            cout << val << endl;

            int personalASS;
            cout << "Assignments: ";
            cin >> personalASS;
            for (int j = 0; j < personalASS; j++) {
                mainArray[arrayAssignmentMarker] = val;
                arrayAssignmentMarker++;
            }
        }
    }
    else {
        int pc1;
        int pc2;
        int pc3;

        cout << "Pledge Class (1) Assignments: " << endl;
        cin >> pc1;
        cout << "Pledge Class (2) Assignments: " << endl;
        cin >> pc2;
        cout << "Pledge Class (3) Assignments: " << endl;
        cin >> pc3;

        while (in_file >> ws)
        {
            getline(in_file, val);
            if (val[0] == '1')
            {
                for (int j = pc1; j > 0; j-- )
                {
                    mainArray[arrayAssignmentMarker] = val;
                    arrayAssignmentMarker++;
                }
            }
            else if (val[0] == '2')
            {
                for (int j = pc2; j > 0; j-- )
                {
                    mainArray[arrayAssignmentMarker] = val;
                    arrayAssignmentMarker++;
                }
            }
            else if (val[0] == '3')
            {
                for (int j = pc3; j > 0; j-- )
                {
                    mainArray[arrayAssignmentMarker] = val;
                    arrayAssignmentMarker++;
                }
            }
            else {
                cout << "fix the names list!";
                return 0;
            }

        }
    }

    /*
    while (in_file >> ws) //fills in the names array with people's names and the # of possible assignments
    {
        int assignmentmarker;
        int classmarker;
        cout << "Do you want to assign individually for everyone or by class? (1 for ind, 2 for class)" << endl;
        cin >> classmarker;

        if (classmarker == 1)
        {
            int personalASS;
            getline(in_file, val);
            cout << val << endl;
            cout << "Assignments: ";
            cin >> personalASS;
            // assignmentmarker = personalASS;
            for (int j = 0; j < personalASS; j++) {
                mainArray[arrayAssignmentMarker] = val;
                arrayAssignmentMarker++;
            }
        }
        else
        {
            int classmarker1;
            cout << "Class 1: Individually or for the class? (1 for ind, 2 for class)" << endl;
            cin >> classmarker1;
            if (classmarker1 == 1)
            {
                int personalASS;
                cout << "Assignments: ";
                cin >> personalASS;
                // assignmentmarker = personalASS;
                for (int j = 0; j < personalASS; j++) {
                    mainArray[arrayAssignmentMarker] = val;
                    arrayAssignmentMarker++;
                }
            }
            else
            {
                int classASS;
                cout << "Assignments: ";
                cin >> classASS;
                for (int j = classASS; j > 0; j--)
                {
                    mainArray[arrayAssignmentMarker] = val;
                    arrayAssignmentMarker++;
                }

            }
        }

    }*/

    randomize (mainArray, NUMBER_OF_ASSIGNMENTS); //randomizes the names list

    cout << "Total number of dates for assignment: ";
    cin >> NUMBER_OF_DAYS;
    
    for (int m = 0; m < NUMBER_OF_DAYS; m++) //inputs the dates for assignment
    {
        cout << "Date? ";
        cin >> dateArray[m];
    }
    int place = 0;
    int programType;
    cout << "1 for RM, 2 for Setup/Cleanup: ";
    cin >> programType;
    if (programType == 1)
    {
        int assignmentspDay;
        cout << "Assignments per day: ";
        cin >> assignmentspDay;
        for (int i = 0; i < NUMBER_OF_DAYS; i++) //prints the dates and people assigned to that date
        {
            cout << dateArray[i] << endl;
            cout << "-------------" << endl << endl;
            for (int j = 0; j < assignmentspDay; j++)
            {
                cout << mainArray[place] << endl;
                place++;
            }
            cout << endl;
        }
    }
    else if (programType == 2)
    {
        int setuppDay;
        cout << "Set-Up per day: ";
        cin >> setuppDay;
        int cleanuppDay;
        cout << "Clean-Up per day: ";
        cin >> cleanuppDay;
        for (int i = 0; i < NUMBER_OF_DAYS; i++) //prints the dates and people assigned to that date
        {
            cout << endl;
            cout << dateArray[i] << endl;
            cout << "-------------" << endl << endl;
            cout << "Set-Up" << endl;
            cout << "--------" << endl;
            for (int j = 0; j < setuppDay; j++)
            {
                cout << mainArray[place] << endl;
                place++;
            }
            cout << endl;
            cout << "Clean-Up" << endl;
            cout << "---------" << endl;
            for (int k = 0; k < cleanuppDay; k++)
            {
                cout << mainArray[place] << endl;
                place++;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "you fucker" << endl;
    }
    delete[] dateArray;
    delete[] mainArray;
    return 0;
}
