#include "cv_header.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//info about a candidate 
string Candidate::get_name()
{
    return name;
};

void Candidate::set_name(string n)
{
    name = n;
}

int Candidate::get_cppDevCapabil()
{
    return cppDevCapabil;
}

void Candidate::set_cppDevCapabil(int c)
{
    if (c % 1 != 0)  //error
    {
        cout << "please enter an integer!" << endl;
        cin >> c;
        cppDevCapabil = c;
    }
    else if (c > 10 || c < 1)  //error
    {
        cout << "please enter an integer between 1 and 10!" << endl;
        cin >> c;
        cppDevCapabil = c;
    }
    else {
        cppDevCapabil = c;
    }
}

int Candidate::get_openSystemCapabil()
{
    return openSystemCapabil;
}

void Candidate::set_openSystemCapabil(int o)
{
    if (o > 10 || o < 1)  //error
    {
        cout << "please enter an integer between 1 and 10!" << endl;
        cin >> o;
        openSystemCapabil = o;

    }
    else
    {
        openSystemCapabil = o;
    }
}

int Candidate::get_experience()
{
    return experience;
}
void Candidate::set_experience(int e)
{
    experience = e;
}

int Candidate::get_agileSoftwareDev()
{
    return agileSoftwareDev;
}

void Candidate::set_agileSoftwareDev(int a)
{
    if (a % 1 != 0) //error
    {
        cout << "please enter an integer!" << endl;
        cin >> a;
        agileSoftwareDev = a;
    }
    else if (a > 10 || a < 1)  //error
    {
        cout << "please enter an integer between 1 and 10!" << endl;
        cin >> a;
        agileSoftwareDev = a;
    }
    else
    {
        agileSoftwareDev = a;
    }
}

float Candidate::get_gpa()
{
    return gpa;
}

void Candidate::set_gpa(float g)
{
    if (g == static_cast<int>(g) && g != 1 && g != 2 && g != 3) //error
    {
        cout << "please enter a float like 1.00!" << endl;
        cin >> g;
        gpa = g;
    }
    else if (!(g <= 4.00 && g >= 1.00))
    {
        cout << "please enter your GPA between 1.00 and 4.00!" << endl;
        cin >> g;
        gpa = g;
    }
    else
    {
        gpa = g;
    }
};

int Candidate::get_degree()
{
    return degree;
}

void Candidate::set_degree(int d)
{
    if (d % 1 != 0) //error
    {
        cout << "please enter an integer!" << endl;
        cin >> d;
        degree = d;
    }
    else if (!(d <= 3 && d >= 1))  //error
    {
        cout << "please enter 1 or 2 or 3!" << endl;
        cin >> d;
        degree = d;
    }
    else {
        degree = d;
    }
}
void Candidate::set_score(float score)
{
    int i = 0;
    while (scores[i] != -1 && i < 5) {
        i++;
    }
    scores[i] = score;
}
float* Candidate::get_scores()
{
    return scores;
}

float Candidate::calculateTotalScore()
{
    float total_score = 0;
    for (int i = 0; i < 5; i++)
    {
        total_score = total_score + scores[i];
    }
    average = total_score /5;
    return total_score;
}


void Candidate::printCV()
{
    cout << setw(5) << get_name()
        << setw(5) << get_cppDevCapabil()
        << setw(5) << get_openSystemCapabil()
        << setw(5) << get_experience()
        << setw(5) << get_agileSoftwareDev()
        << setw(5) << get_gpa()
        << setw(5) << get_degree()
        << setw(5);
}


void Candidate::set_average(float averages)
{
    average = averages;
}


float Candidate::get_average()
{
    return average;
}