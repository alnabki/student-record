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
    //  protected:
        MYSQL* conn;
public:

     student addstudent (student &s){

     cout <<"enter the student name some you need to add it :"<<endl;
     cin >>s.name;

     cout <<"enter the age :"<<endl;
     cin >>s.age;
      return s;
     }
 student connection (student &s){
      s.conn = mysql_init(0);
      s.conn = mysql_real_connect(conn,"localhost","root","","school",0,NULL,0);
    if(s.conn)
         {
           cout<<"connection object ok, conn="<<s.conn<<endl;
         }
      else
           cout<<"conn object problem: "<<mysql_error(conn);

}


     void print(student s){
     cout <<setw(25)<<"Students'name"<<setw(20)<<"the age"<<endl;
     cout <<setw(25)<<s.name<<setw(20)<<s.age<<endl;
     }
friend insert();
friend select();
friend delet_student();
    };
void print_menu(){
cout <<"************select you option*****************"<<endl;
cout<<"select 1 if you want to add student "<<endl;
cout<<"select 2 if you want to select  student by Id"<<endl;
cout<<"select 3 if you want to Modify students information "<<endl;
cout<<"select 4 if you want to delete student from record "<<endl;
cout <<"************************************************"<<endl;
}
void insert (student){
// insert Data :
student st;



    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate ;



               st.addstudent (st);
              cout <<st.name<<endl;
              cout<<st.age<<endl;
            // print Data:
               st.print(st);


      // check connection:

     st.connection(st);

               if(st.conn)
                 {
                   cout<<"connected to database Students names"<<endl;

                   string query="insert into elever (name,age) values('"+st.name+"','"+st.age+"')";

                   const char* q = query.c_str();

                   cout<<"query is: "<<q<<endl;

                   qstate = mysql_query(st.conn,q);

                    if(!qstate)
                          cout<<"record inserted successfully..."<<endl;
                    else
                          cout<<"query problem: "<<mysql_error(st.conn)<<endl;

                    qstate = mysql_query(st.conn,"select * from elever");

                    if(!qstate)
                     {
                         res = mysql_store_result(st.conn);
                         while(row=mysql_fetch_row(res))
                              {
                                cout<<"id: "<<row[0]<< " "
                                <<"name: "<<row[1]<< " "
                                <<"age: "<<row[2]<<endl;
                              }
                     }
                   else
                        cout<<"query error: "<<mysql_error(st.conn)<<endl;

                   }
               else
                      cout<<"connection problem: "<<mysql_error(st.conn)<<endl;
  mysql_close(st.conn);
}
void select(student)
{
    student s;
     MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate ;
    bool check=false;
     // select student :
     conn = mysql_init(0);
      conn = mysql_real_connect(conn,"localhost","root","","school",0,NULL,0);

      // check connection:

      if(conn)
         {
           cout<<"connection object ok, conn="<<conn<<endl;
         }
      else
           cout<<"conn object problem: "<<mysql_error(conn);
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
                             {
                                 cout <<"this Id"<<s.id<<"\t\dosn't exist"<<endl;
                                 check==true;
                             }


  mysql_close(conn);
}
void update ()
{
    student s;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate ;
    bool check=false;
                         conn = mysql_init(0);
                         conn = mysql_real_connect(conn,"localhost","root","","school",0,NULL,0);


                            cout << "enter the id of student that you need update his info>"<<endl;
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


                            cout<<"enter the new info "<<endl;
                            cout <<"the name that you need to update\t";
                            cin >>s.name;
                            cout <<"the age the you need to correct:\t";
                            cin >>s.age;
                         conn = mysql_init(0);
                         conn = mysql_real_connect(conn,"localhost","root","","school",0,NULL,0);

                            string q3 = "update  elever set name='"+s.name+"',age="+s.age+" where id ="+s.id;
                            const char* q4 = q3.c_str();
                            qstate = mysql_query(conn,q4);

                           if(!qstate)
                                 cout<<"record inserted successfully..."<<endl;
                            else
                                 cout<<"query problem: "<<mysql_error(conn)<<endl;


                           mysql_query(conn,"select * from  elever ");
                           if(!qstate)
                           {

                           res = mysql_use_result(conn);
                           while(row=mysql_fetch_row(res))
                              {
                                            cout<<"id: "<<row[0]<< " "
                                            <<"name: "<<row[1]<< " "
                                            <<"age: "<<row[2]<<endl;
                              }
                               }
                               }
                               }
                               if (check ==false)
                                cout <<"the records not exist in the table"<<endl;
                  mysql_close(conn);
}

void delet_student(student)
{
    student s;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate ;
    bool check=false;
                         conn = mysql_init(0);
                         conn = mysql_real_connect(conn,"localhost","root","","school",0,NULL,0);


                            cout << "enter the >ID of student that you need delete it:>"<<endl;
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
                                          check=true;
                                 }


                         conn = mysql_init(0);
                         conn = mysql_real_connect(conn,"localhost","root","","school",0,NULL,0);

                            string q3 = "delete from elever where id ="+s.id;
                            const char* q4 = q3.c_str();
                            qstate = mysql_query(conn,q4);

                           if(!qstate)
                                 cout<<"the record delete  successfully..."<<endl;
                            else
                                 cout<<"query problem: "<<mysql_error(conn)<<endl;


                           mysql_query(conn,"select * from  elever ");
                           if(!qstate)
                           {

                           res = mysql_use_result(conn);
                           while(row=mysql_fetch_row(res))
                              {
                                            cout<<"id: "<<row[0]<< " "
                                            <<"name: "<<row[1]<< " "
                                            <<"age: "<<row[2]<<endl;
                              }
                            }

                               if (check ==false)
                                cout <<"the records not exist in the table"<<endl;
                  mysql_close(conn);

}
int  main()
{

    char i;
    bool j = false;

    int menu_choice;
    student st;
    print_menu();


  do {

     //menu choice:
     cout << "Enter a menu choice: ";
     cin >> menu_choice;
	 cout << '\n';

          switch(menu_choice)
             {
               //insert Data ( insert student in table):
              case 1:
                    insert(st);
                    break;
              case 2:
                    select(st);
                    break;
              case 3:
                     update();
                     break;
              case 4:
                     delet_student(st);
                     break;
              default:

                      cout << "You have entered an invalid menu choice.\n"<<endl;
                      cout  << "Please try again.\n\n";
                      break;
                }
     // enter y for continue:
     cout << "if you want to continue press y or any key to exit"<<endl;
     cin >> i;

           if (i=='y' || i=='Y')
            {
               j= true;
               system("cls");
               print_menu();
            }
           else
           {
                j= false;
           }


    } while (j==true);



      return 0;
      }

