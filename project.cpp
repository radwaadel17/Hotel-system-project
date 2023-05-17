#include<iostream>
#include<fstream>
#include<string.h>
using namespace std ;
class Hotel_mangement_system{
    public : 
    int id , id_room ;
    char name[20] ,  from_date[50] , to_date[20], phone_number[10];
};
void system_data()
{
 fstream obj("data.txt" , ios::out) ;
   Hotel_mangement_system h ;
   char c; 
   do {
  // user data 
    cout<<"Enter name : "<<"\n";
    cin>>h.name;
    cout<<"Enter your id : "<<"\n";
    cin>>h.id;
    cout<<"Enter your phone_number : "<<"\n";
    cin>>h.phone_number;
  // system data
    cout<<"The id room "<<"\n";
    cin>>h.id_room;
    cout<<"The book date "<<"\n";
    cin>>h.from_date;
    cout<<"the leaving date "<<"\n";
    cin>>h.to_date;
    cout<<"if you want to continue click y or Y , otherwise click any other char";
    obj.write((char *) & h , sizeof(h));
    cin>>c;
   }while(c == 'y' || c == 'Y');
}

void display_data()
{
    Hotel_mangement_system h ;
    ifstream in;
    in.open("data.txt", ios::in);
    if(in.is_open())
    {
      cout<<"ID"<<"\t"<<"NAME"<<"\t"<<"PHONE NUMBER "<<"\t"<<"BOOK_DATE"<<"\t"<<"LEAVING_DATE"<<"\t"<<"ID_ROOM"<<"\n";
        while(in.read((char*) &h, sizeof(h)))
        {
            if(!in.eof())

            cout<<h.id<<"\t"<<h.name<<"\t"<<h.phone_number<<"\t"<<h.from_date<<"\t"<<h.to_date<<"\t"<<h.id_room<<"\n";
        }
        in.close();
    }
    else
    {
        cout << "Can not open the specified file\n";
    }
}

void search(){
   fstream obj("data.txt" , ios::in);
   char s[20];
  Hotel_mangement_system h; 
  cout<<"Enter the student name to search :"<<"\n";
  cin>>s;
  bool ch = 0 ; 
  if(obj.is_open()){
     while( obj.read((char * ) & h, sizeof(h))){
       if(!obj.eof())
       {
         if(strcmp(s , h.name) == 0){
            cout<<"ID"<<"\t"<<"NAME"<<"\t"<<"PHONE NUMBER "<<"\t"<<"BOOK_DATE"<<"\t"<<"LEAVING_DATE"<<"\t"<<"ID_ROOM"<<"\n";
            cout<<h.id<<"\t"<<h.name<<"\t"<<h.phone_number<<"\t"<<h.from_date<<"\t"<<h.to_date<<"\t"<<h.id_room<<"\n";
            ch = 1 ;
            break;
        }
       }
     }
   
     if(!ch) cout<<"Can not find the specified record"<<"\n";
    obj.close();
  }
    else {
        cout<<"The file doesn't exist"<<"\n";
     }
}

void delete_record()
{
 Hotel_mangement_system h1 ;
 ofstream out ("systemtemp.txt" , ios::out);
 ifstream in ("data.txt" , ios::in);
 cout<<"Enter the user record you want to delete "<<"\n";
 char s [20]; cin>>s;
 while(in.read((char * ) & h1 , sizeof(h1)))
 {
   if(strcmp(s , h1.name) != 0)
   {
     out.write((char *) & h1 , sizeof(h1)); 
   }
 }
 in.close();
 out.close();
 remove("data.txt");
 rename("systemtemp.txt" , "data.txt");
}

void update_id()
{
fstream f ("data.txt" , ios::in | ios::out) ;
 Hotel_mangement_system h;
 cout<<"Enter the name_user_record  you want to update its age: " <<"\n";
 char name[20];
 cin>>name;
 bool ch  = 0 ;
 if(f.is_open())
 {
  while(!f.eof())
  {
    f.read((char *) & h , sizeof(h));
    if(strcmp(name , h.name) == 0)
    {
      ch = 1 ;
      cout<<"Enter the id you want to update : "<<"\n";
      cin >> h.id;
      int pos = f.tellg();
      int sz_st = sizeof(h);
      f.seekp(sz_st - pos , ios::beg);
      f.write((char *) & h , sizeof(h));
      break;
    }
  }
  if(!ch) cout<<"Can not find the specified record"<<"\n";
  f.close();
 }
 else 
 {
  cout<<"Can not find the specified file"<<"\n";
 }
}

int main()
{
  //system_data();
  //display_data();
  //search();
 //delete_record();
  //display_data();
  //update_id();
}