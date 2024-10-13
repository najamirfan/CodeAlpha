#include <iostream>
using namespace std;

int main() {


    double current_cgpa=0.0;
    int credit_accepted_before;
    cout<<"\n*************PREVIOUSE**************\n";
    cout<<" Enter Current CGPA:";
    cin>>current_cgpa;
    cout<<"Credits Accepted towards degree completion ";
    cin>>credit_accepted_before;

cout<<"\n\n*************CALCULATING GPA FOR THIS SEMESTER*******\n\n";
    int total_Courses;
    cout << "Enter the number of courses: ";
    cin >> total_Courses;


   
    string course_Name[total_Courses];
    double grades_get[total_Courses];
    int credit_hours[total_Courses];


    
    double gpa=0.0;
    int total_credithours=0;
    for (int i = 0; i < total_Courses; i++) {
        cout << "Enter details for course " << (i + 1) << endl;
        cout << "Course Name: ";
        cin >> course_Name[i];
        cout << "Grade (out of 4.0): ";
        cin >> grades_get[i];
        cout << "Credit Hours: ";
        cin >> credit_hours[i];

       
        gpa += grades_get[i] * credit_hours[i];
        total_credithours += credit_hours[i];
    }

    
    double this_semesert_gpa = gpa / total_credithours;


    cout<<"GPA for this Semester:"<<this_semesert_gpa <<endl;
    cout<<"Total Credit Hours:"<< (credit_accepted_before + total_credithours) <<endl;


    double cgpa=0.0;

    cgpa =     ((current_cgpa * credit_accepted_before) + (this_semesert_gpa * total_credithours) ) / (credit_accepted_before + total_credithours) ;


    cout<<"CGPA IS :"<<cgpa<<endl;

return 0;
}