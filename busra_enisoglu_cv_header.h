#ifndef ARRAYHW_H_INCLUDED
#define ARRAYHW_H_INCLUDE

#include <string>
#include <stdio.h>

using namespace std;
#endif // !ARRAYHW_H_INCLUDED

class Candidate
{
private:
    string name;
    int cppDevCapabil;
    int openSystemCapabil;
    int experience;
    int agileSoftwareDev;
    float gpa;
    int degree;
    float average;
    float scores[6] = {-1, -1, -1, -1, -1, -1};
    float total_score;
    

public:
    string get_name();
    void set_name(string n);

    int get_cppDevCapabil();
    void set_cppDevCapabil(int c);

    int get_openSystemCapabil();
    void set_openSystemCapabil(int o);

    int get_experience();
    void set_experience(int e);

    int get_agileSoftwareDev();
    void set_agileSoftwareDev(int a);

    float get_gpa();
    void set_gpa(float g);

    int get_degree();
    void set_degree(int d);

    float* get_scores();
    void set_score(float score);

    float calculateTotalScore();

    void set_average(float average);
    float get_average();

    void printCV(); //output cv's
    
    



};
