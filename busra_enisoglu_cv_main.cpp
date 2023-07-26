#include "cv_header.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
    string ynAnswer;
    int count = 0;

    cout << "Hello, HR representative." << endl;

    cout << "First, please enter weights of each score" << endl;

    int times[6] = { 1, 1, 1, 1, 1 }; // score agirliklarinin arrayi
    for (int i = 0; i < 6; i++) // score agirliklarini almak icin
    {
        cout << "score " << i + 1 << ":" << endl;
        int j;
        cin >> j;

        if (typeid(j) == typeid(ynAnswer)) //error
        {
            cout << "please put in a integer." << endl;
            cin >> j;
        }

        times[i] = j;
    }

    cout << "Thank you!" << endl;

    cout << "Do you like to enter an applicant? (y/n)" << endl;
    cin >> ynAnswer;

    if (ynAnswer == "y")  //error
    {
        count += 1;
    }
    else if (ynAnswer == "n")
    {
        cout << "you have no cv so have good day!" << endl;
        return 0;
    }
    else  //error
    {
        cout << "please put in y or n" << endl;
        cin >> ynAnswer;
        if (ynAnswer == "y")
        {
            count += 1;
        }
        else if (ynAnswer == "n")
        {
            cout << "you have no cv so have good day!" << endl;
            return 0;
        }
    }

    Candidate myCand[30];
    float avgScrofCand[30];
    
    //to input cv
    for (int i = 0; i <= 30; i++)
    {
        
        cout << "Please enter applicant name: " << endl;
        string name;
        cin >> name;
        myCand[i].set_name(name);


        cout << "Enter C++ development score (1 - 10):" << endl;
        int cppDevCapabil;
        cin >> cppDevCapabil;
        myCand[i].set_cppDevCapabil(cppDevCapabil);
        myCand[i].set_score(cppDevCapabil);

        cout << "Enter OS capability score: "<< endl;
        int openSystemCapabil;
        cin >> openSystemCapabil;
        myCand[i].set_openSystemCapabil(openSystemCapabil);
        myCand[i].set_score(openSystemCapabil);

        cout << "Enter experience in software development in years: " << endl;
        int experience;
        cin >> experience;
        myCand[i].set_experience(experience);
        myCand[i].set_score(experience);

        cout << "Enter agile software development score:" << endl;
        int agile;
        cin >> agile;
        myCand[i].set_agileSoftwareDev(experience);
        myCand[i].set_score(experience);

        cout << "Enter bachelor GPA:" << endl;
        float gpa;
        cin >> gpa;
        myCand[i].set_gpa(gpa);
        myCand[i].set_score(gpa);

        cout << "Enter education status: (1-bachelor, 2-masters, 3-doctorate)" << endl;
        int degree;
        cin >> degree;
        myCand[i].set_degree(degree);
        myCand[i].set_score(degree);


        myCand[i].calculateTotalScore();
        avgScrofCand[i] = myCand[i].get_average();


        cout << "Do you like to enter an applicant? (y/n)" << endl;
        cin >> ynAnswer;

        if (ynAnswer == "y")
        {
            count += 1;
            if (count > 30) //error
            {
                count = count - 1;
                cout << "unfortunately, you cannot new cv." << endl;

                for (int cv = 0; cv < count; cv++) {
                    cout << cv + 1 << "- ";
                    myCand[cv].printCV();
                    cout << " Average: "
                        << myCand[cv].get_average() << endl;
                }

                float maxValue = 0; // the mx value in the array
                int maxInArr = 0; //
                for (int a = 0; a < count; a++) // to find the best averages in object array
                {
                    if (maxValue < myCand[a].get_average())
                    {
                        maxValue = myCand[a].get_average();
                    }
                    maxInArr++;
                }
                cout << "the best is: " << myCand[maxInArr - 1].get_name();
                break;
            }
        }
        else if (ynAnswer == "n") // hr calisaninin en basta girdigi sayidan daha az cv girmesi durumunda burasi calisacak
        {
            cout << "The CVs:" << endl;

            for (int cv = 0; cv < count; cv++) {

                cout << cv + 1 << "- "; //print the cv's and average
                myCand[cv].printCV();
                cout << " Average: "
                    << myCand[cv].get_average() << endl;            
            }

            float maxValue = 0; // the mx value in the array
            int maxInArr = 0; //
            for (int a = 0; a < count; a++) // to find the best averages in object array
            {
                if (maxValue < myCand[a].get_average())
                {
                    maxValue = myCand[a].get_average();
                }
                maxInArr++;
            }
            cout << " the best is: " << myCand[maxInArr-1].get_name();
            return 0;
        }
        else //error
        {
            cout << "please put in y or n" << endl;
            cin >> ynAnswer;
            if (ynAnswer == "y") // hr calisani cv girmeye devam ederse burasi calisacak
            {
                count += 1;
            }
            else if (ynAnswer == "n") // hr calisaninin en basta girdigi sayidan daha az cv girmesi durumunda burasi calisacak
            {
                cout << "The CVs:" << endl;

                for (int cv = 0; cv < count; cv++)
                {
                    cout << cv + 1<< "- ";
                    myCand[cv].printCV();
                    cout << " Average: "
                        << myCand[cv].get_average() << endl;
                }


                float maxValue = 0; // the mx value in the array
                int maxInArr = 0; //
                for (int a = 0; a < count; a++) // to find the best averages in object array
                {
                    if (maxValue < myCand[a].get_average())
                    {
                        maxValue = myCand[a].get_average();
                    }
                    maxInArr++;
                }
                cout << " the best is: " << myCand[maxInArr - 1].get_name();

                return 0;
            }
        }

    }
}