#include <iostream>
#include <iomanip>
#include <windows.h>
#include <mysql.h>
#include<stdlib.h>
using namespace std;
class Student {
 public:
       string name;
       string age;
       string id;
 public:
    void printInf(){
        cout << "id: " <<  id << " name: " << name << "age: " << age << endl;
    }
    void enter(){
        cout<< "Enter name:"; cin>> name ; cout<< endl;
        cout<< "Enter age:"; cin>> age ; cout<< endl;
    }

};
class databasemethode{
        protected:
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES *res;
        int qstate ;
        public:
databasemethode (){
    conn = mysql_init(0);

    if(conn)
    {
        cout<<"connection object ok, conn="<<conn<<endl;
    }
    else
        cout<<"conn object problem: "<<mysql_error(conn);
    conn = mysql_real_connect(conn,"localhost","root","","school",0,NULL,0);
    if(conn)
    {
        cout<<"connected to database school"<<endl;
    }
    else
    {
     cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }
}
Student select(string id)
{
    Student s;
    bool check;
    string query = "select * from  elever where id=" + id;
    const char* q = query.c_str();
    qstate = mysql_query(conn,q);

       if(!qstate)
        {
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
               s.id = row[0];
               s.name = row[1];
               s.age = row[2];
               check=true;
            }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
         if (check==false)
                {
                    cout <<"this Id"<<s.id<<"\t\dosn't exist"<<endl;
                }
        return s;
}

void insertSt(Student s){
        string query="insert into elever(name,age) values('"+s.name+"','"+s.age+"')";


        const char* q = query.c_str();

        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);

        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
       else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
}
void update_inf(Student s){

                string q3 = "update  elever set name='"+s.name+"',age="+s.age+" where id ="+s.id;
                const char* q4 = q3.c_str();
                cout <<q4<<endl;

                qstate = mysql_query(conn,q4);

                if(!qstate)
                        cout<<"record inserted successfully..."<<endl;
                else
                        cout<<"query problem: "<<mysql_error(conn)<<endl;

     }
void delet_rec(string id){

                            string q3 = "delete from elever where id ="+id;
                            const char* q4 = q3.c_str();
                            qstate = mysql_query(conn,q4);

                           if(!qstate)
                                 cout<<"the record delete  successfully..."<<endl;
                            else
                                 cout<<"query problem: "<<mysql_error(conn)<<endl;

                        }

void close(){
    mysql_close(conn);
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

int main(){

    Student st;
    databasemethode db;
    char i;
    bool j = false;
    string id;
    int menu_choice;

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
                   st.enter();
                   db.insertSt(st);
                    break;
              case 2:
                    {

                        cout <<"inter the id"<<endl;
                        cin>> id;
                    st = db.select(id);
                    st.printInf();
                    }
                    break;
              case 3:
                      cout << "enter the id of student that you need update his info>"<<endl;
                      cin>> id;
                      st = db.select(id);
                      st.printInf();
                      st.enter();
                      db.update_inf(st);
                     break;
              case 4:
                         cout << "enter the >ID of student that you need delete it:>"<<endl;
                         cin>> id;
                         db.delet_rec(id);
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
                db.close();
           }


    } while (j==true);



      return 0;
      }

