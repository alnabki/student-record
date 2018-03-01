###include <iostream>
#include <iomanip>
using namespace std;
class student {
  string *name;
  int *age;
 public:
     student (){
     name = new string;
     age  = new int;
     cout <<"enter the student name some you need to add it :"<<endl;
     cin >> *name;
     cout <<"enter the age :"<<endl;
     cin >>*age;
     }
     ~student(){
     delete name;
     delete age;
     }
     void print(){
     cout <<setw(25)<<"Students'name"<<setw(20)<<"the age"<<endl;
     cout <<setw(25)<<*name<<setw(20)<<*age<<endl;
     }
    };
     char i;
    bool j=false;
    main()
{

    do {




    student s;
    s.print();
    cout << "if you want to continue press y or not to exit"<<endl;
    cin >> i;

    if (i=='y' || i=='Y')
    j= true;
    else
        j = false;
    }while(j==true);
      return 0;
}
