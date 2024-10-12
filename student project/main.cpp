#include <iostream>

using namespace std;


class student
{
private:

    int ID;
    string name;
    float marks[3];

public:
    student(int ID , string name , float *marks)
    {
        this->ID = ID;
        this->name = name;
        this->marks[0] = marks[0];
        this->marks[1] = marks[1];
        this->marks[2] = marks[2];
    }

    int getID()
    {
        return ID;
    }

    string getname()
    {
        return name;
    }

    float * getmarks()
    {
        return marks;
    }


    float total_marks();
    char grade();

};


float student::total_marks()
{
    return marks[0] + marks[1] + marks[2];
}

char student::grade()
{
    float average = (marks[0] + marks[1] + marks[2]) / 3;
    if(average > 60)
        return 'A';
    else if(average >= 40 && average < 60)
        return 'B';
    else
        return 'C';
}



int main()
{
    int ID;

    string name;

    float marks[3];

    cout<<"please enter the Student ID: ";
    cin>>ID;

    cout<<"please enter student first name: ";
    cin>>name;


    for (int i = 0 ; i < 3 ; i++)
    {
        cout<<"Please enter the mark of subject number "<<i+1<<": ";
        cin>>marks[i];
    }


    student s1(ID, name, marks);

    cout<<"Total Marks: "<<s1.total_marks()<<endl;
    cout<<"Grade of Student: "<<s1.grade()<<endl;

    // Student marks accessing
/*
    float *m = s1.getmarks();

    for(int i = 0 ; i < 3 ; i++)
    {
        cout<<"Mark of subject "<< i+1 <<"= "<<m[i]<<endl;
    }
*/
    return 0;
}
