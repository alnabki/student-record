#include <iostream>
#include <iomanip>
#include <windows.h>
#include <mysql.h>
using namespace std;

class student {
  public:
       string name;
       string age;

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
     ;
int  main()
{
char i;
bool j=false;

MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;
 conn = mysql_init(0);
    if(conn)
    {


        cout<<"connection object ok, conn="<<conn<<endl;
    }
    else
        cout<<"conn object problem: "<<mysql_error(conn);

    conn = mysql_real_connect(conn,"localhost","root","","school",0,NULL,0);
do {
    if(conn)
    {
        cout<<"connected to database Students names"<<endl;

        //string id,name,phone;
        //cout<<"enter name: "<<endl; cin>>name;
        //cout<<"enter phone: "<<endl; cin>>phone;

        student st;
        st.addstudent (st);
cout <<st.name<<endl;
cout<<st.age<<endl;
        st.print(st);
        cout << "if you want to continue press y or not to exit"<<endl;
        cin >> i;

          if (i=='y' || i=='Y')
            j= true;
          else
            j = false;

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

      }while(j==true);

    mysql_close(conn);

      return 0;
}
