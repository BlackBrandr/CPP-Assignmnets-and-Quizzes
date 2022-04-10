#include "Patient.h"

// Constructor for Patient
Patient::Patient() {
    name = "";
    age = 0;
    numDays = 0;
    ssn = 0;
    dailyCharge = 0;
    discharged = false;
    totalDays = 0;
}
Patient::Patient(string n, int a, int nd, int SSN, double dc) {
    name = n;
    age = a;
    numDays = nd;
    ssn = SSN;
    dailyCharge = dc;
    discharged = false;
    totalDays = nd;

}

// Calculating Total Charge
Patient::~Patient() {
    double totalCharge = numDays * dailyCharge;
}


string Patient::print() {

    // Calculating Current Expense
    double currentExpense = (totalDays-numDays) * dailyCharge;

    // Printing Patient Information
    return "Name: " + name + ", Age: " + to_string(age) +
           ", DailyCharge: " + to_string(dailyCharge) + " SSN: " + to_string(ssn) +
           ", Number of Days Left: " + to_string(numDays) + ", Current expense: " +
           to_string(currentExpense);
}

// Set function for Patients Name
void Patient::setName(string n) {
    name = n;
}

// Set function for Patients Age
void Patient::setAge(int a) {
    age = a;
}

// Set function for Patients SSN
void Patient::setSSN(int SSN) {
    ssn = SSN;
}

// Set function for Patients Number of Days
void Patient::setNumDays(int nd) {
    numDays = nd;
}

// Set function for Patients Daily Charge
void Patient::setDailyCharge(double r) {
    dailyCharge = r;
}

// Get function for Patients Age
int Patient::getAge() {
    return age;
}

// Get function for Patients Name
string Patient::getName() {
    return name;
}

// Get function for Patients SSN
int Patient::getSSN() {
    return ssn;
}

// Get function for Patients Numbers of Days
int Patient::getNumDays() {
    return numDays;
}

// Get function for Patients Total Days
int Patient::getTotalDays() {
    return totalDays;
}

// Get function for Patients Daily Charge
double Patient::getDailyCharge() {
    return dailyCharge;
}

// Set function for Patients Discharged
void Patient::setDischarged() {
    discharged = true;
}

// Get function for Patients Discharged
bool Patient::getDischarged() {
    return discharged;
}

// Function for Calculating Expenses
double calculateExpenses(Patient p) {
    return p.dailyCharge * p.numDays;
}

