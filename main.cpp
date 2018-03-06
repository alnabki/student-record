#include <iostream>
#include <iomanip>
#include <windows.h>
#include <mysql.h>
#include<stdlib.h>
using namespace std;

class student {
  public:
       string name;
       string age;
       string id;

     student addstudent (student &s){


     cout <<"enter the student name some you need to add it :"<<endl;
     cin >>s.name;

     cout <<"enter the age :"<<endl;
     cin >>s.age;
     return s;

     }
     //~student(){
     //delete name;
     //delete age;
     //}
     void print(student s){
         //student s;
     cout <<setw(25)<<"Students'name"<<setw(20)<<"the age"<<endl;
     cout <<setw(25)<<s.name<<setw(20)<<s.age<<endl;
     }


    };
void print_menu(){
cout <<"************select you option*****************"<<endl;
cout<<"select 1 if you want to add student "<<endl;
cout<<"select 2 if you want to select  student by Id"<<endl;
cout<<"select 3 if you want to Modify students information "<<endl;
cout<<"select 4 if you want to delete student from record "<<endl;
cout <<"************************************************"<<endl;
}

int  main()
{

    char i;
    bool j=false;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;
    int menu_choice;
     bool check=false;
    student st,s;
    print_menu();


  do {
      conn = mysql_init(0);
      conn = mysql_real_connect(conn,"localhost","root","","school",0,NULL,0);

      // check connection:

      if(conn)
         {
           cout<<"connection object ok, conn="<<conn<<endl;
         }
      else
           cout<<"conn object problem: "<<mysql_error(conn);
  //menu choice:
     cout << "Enter a menu choice: ";
     cin >> menu_choice;
	 cout << '\n';

  switch(menu_choice)
{
    //insert Data ( insert student in table):
case 1:
     // insert Data :

    st.addstudent (st);
        cout <<st.name<<endl;
        cout<<st.age<<endl;
    // print Data:
      st.print(st);

    if(conn)
     {
        cout<<"connected to database Students names"<<endl;

        string query="insert into elever (name,age) values('"+st.name+"','"+st.age+"')";

        const char* q = query.c_str();

        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);

            if(!qstate)
              cout<<"record inserted successfully..."<<endl;
            else
              cout<<"query problem: "<<mysql_error(conn)<<endl;

           qstate = mysql_query(conn,"select * from elever");

            if(!qstate)
               {
                res = mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                      {
                        cout<<"id: "<<row[0]<< " "
                         <<"name: "<<row[1]<< " "
                         <<"age: "<<row[2]<<endl;
                      }
               }
            else
               {
                 cout<<"query error: "<<mysql_error(conn)<<endl;
               }
 }
    else
         cout<<"connection problem: "<<mysql_error(conn)<<endl;
         break;

case 2:

    // select student :
          cout << "enter the id of student that you need select him>"<<endl;
          cin>> s.id;
          mysql_query(conn,"select * from  elever ");
          res = mysql_use_result(conn);
                while(row=mysql_fetch_row(res))
                      {
                         if ( s.id == row[0])
                          {
                            cout<<"id: "<<row[0]<< " "
                            <<"name: "<<row[1]<< " "
                            <<"age: "<<row[2]<<endl;
                            check=true;
                          }
                      }
                       if (check==false)
                            cout <<"this Id"<<s.id<<"\t\dosn't exist"<<endl;


          // enter y for continue:


          break;
  default:
        cout << "You have entered an invalid menu choice.\n"
             << "Please try again.\n\n";
          break;
   }

         cout << "if you want to continue press y or any key to exit"<<endl;
        cin >> i;

           if (i=='y' || i=='Y')
           {
           j= true;
           system("cls");
            print_menu();
           }
          else
            j = false;

  }while(j==true);

    mysql_close(conn);

      return 0;
      }

