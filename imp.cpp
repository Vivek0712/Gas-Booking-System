#include"head.h"

void delay(int n)
{
  for(int i=0;i<n;i++)
  { }
}

void Agency::operator +(int x )
{

  tot_nc+=x;
  ofstream fout;
  fout.open("Stock.txt");
  fout<<tot_nc;
  fout.close();
}
void Agency::operator -(int x)
{

      int check;
      check= tot_nc - x;
      if( check<0)
      {
        cout<<"\n Insufficient stock . \n Please place order from company and proceed. ";
        delay(2000);
      }
      else
    {
      tot_nc=check;
      ofstream fout;
      fout.open("Stock.txt");
      fout<<tot_nc;
      fout.close();
     }
}
/*struct dosdate_t
{
  unsigned char day;
  unsigned char month;
  unsigned int year;
}date;

_dos_getdate(& date);
*/

/*ifstream filein("Company.txt");
int x;
filein>>x;
*/
int Agency:: menu()
{
  int choice;
  // clrscr();
   cout<<"\n\n\n\n";
   cout<<"\n\n\n\n+--------------------------------------------------------------------------+";
   cout<<"\n                            GAS AGENCY                           ";
   cout<<"\n+--------------------------------------------------------------------------+";
   cout<<"\n\n 1. PLACE ORDER TO THE COMPANY ";
   cout<<"\n 2. CUSTOMER GAS BOOKING       ";
   cout<<"\n 3. CUSTOMER NEW GAS CONNECTION  ";
   cout<<"\n 4. VIEW SUMMARY ";
   cout<<"\n 5. EXIT ";
   cout<<"\n Enter choice ";
   cin>>choice;
   return choice;
}

void Agency:: UpdateMaster()
{
   ofstream fout;
   fout.open("Master.txt",ios::out);
   fout<< comp_order_id<<"\n";
   fout<<cust_order_id<<"\n";
   fout<<availablecylinders<<"\n";
   fout<<consumer_id<<"\n";
   fout<<cylinders_ordered<<"\n";
   fout.close();
}
void Agency:: GetMasterValues()
{
   fstream fin;
   fin.open("Master.txt",ios::in);
   if(fin.fail())
   {
    comp_order_id=0;
    cust_order_id=0;
    availablecylinders=0;
    consumer_id=0;
    cylinders_ordered=0;
   }
   else
   {
    fin>> comp_order_id;
    fin>>cust_order_id;
    fin>>availablecylinders;
    tot_nc=availablecylinders;
    fin>>consumer_id;
    fin>>cylinders_ordered;
   }
   fin.close();
}
int Agency::login()
{
  int log=0,count=0;
  do
  {
   //clrscr();
   cout<<"\n\n\n\n";
   ifstream fin;
   fin.open("Login.txt");
   int check;
   fin>>check;
   cout<<"\n\n\n\n+--------------------------------------------------------------------------+";
   cout<<"\n                            GAS AGENCY                           ";
   cout<<"\n+--------------------------------------------------------------------------+";
   cout<<"\n Enter your registration number ";
   cin>>reg_no;
   if( check==reg_no)
   {
     cout<<"\n Enter the password ";
     cin>>password;
     fin>>check;
     if(check==password)
     {
       cout<<"\n Access Granted ";
//       GetMasterValues();
       delay(2000);
      // clrscr();
       cout<<"\n\n\n\n";
       log=1;
       return 1;
      }
    else
     {
      cout<<"\n Enter correct password";
      delay(2000);
     //clrscr();
      cout<<"\n\n\n\n";
      count++;
    }
   }
   else
   {
     cout<<"\n Enter valid registration number ";
     delay(2000);
     //clrscr();
     cout<<"\n\n\n\n";
     count++;
   }
 return 0;
 }
 while( log!=1&& count<5);
if(count==5)
 {
   //clrscr();
   cout<<"\n\n\n\n";
   cout<<"\n\n\n\n+--------------------------------------------------------------------------+";
   cout<<"\n                            GAS AGENCY                           ";
   cout<<"\n+--------------------------------------------------------------------------+";
   cout<<"\n You have made five unsuccessful attempts to login ";
   cout<<"\n The application will terminate ";
   delay(3000);
   exit(0);
  }
return 0;
}
void Agency::summary()
{
   ifstream fin;
   int orderid,customerid,cylinder;
   float cost;
   //clrscr();
   cout<<"\n\n\n\n";
  int reportchoice,d;
   do
   {
   //clrscr();
   cout<<"\n\n\n\n";
   cout<<"\n\n\n\n+--------------------------------------------------------------------------+";
   cout<<"\n                      SUMMARY AND RECORD MAINTAINCE                          ";
   cout<<"\n+--------------------------------------------------------------------------+";
   cout<<"\n\n 1. STOCK REPORT ";
   cout<<"\n 2. VIEW COMPANY RELATED RECORDS AND SUMMARY";
   cout<<"\n 3. VIEW CUSTOMER RELATED RECORDS AND SUMMARY";
   cout<<"\n 4. EXIT TO MAINMENU";
   cout<<"\n ENTER CHOICE : ";
   cin>>reportchoice;
 switch (reportchoice)
   {
     case 1 :   //clrscr();
    cout<<"\n\n\n\n";
    cout<<"\n\n\n\n+--------------------------------------------------------------------------+";
    cout<<"\n                      STOCK REPORT                          ";
    cout<<"\n+--------------------------------------------------------------------------+";
    cout<<"\n\n"<<endl;
    cout<<"\n#of Cylinders Ordered to Company     : "<<cylinders_ordered<<endl;
    cout<<"\n#of Cylinders Delivered to Customers : "<<cylinders_ordered - availablecylinders<<endl;
    cout<<"\n#of Cylinders in stock               : "<<availablecylinders<<endl;
    delay(5000);
    break;
   case 2 :
         fin.open("Company.txt");
         if(fin.fail())
         {
          cout<<"No orders!!!!"<<endl;
          delay(3000);
          break;
          }
         //clrscr();
         cout<<"\n\n\n\n";
         cout<<"\n\n\n\n+--------------------------------------------------------------------------+";
         cout<<"\n                      ORDER PLACED TO COMPANY                          ";
         cout<<"\n+--------------------------------------------------------------------------+";
         cout<<"\nOrder #"<<"\t"<<"# of Cylinders"<<"\t"<<"Cost"<<endl;
         while(!fin.eof())
         {
           fin>>orderid;
           fin>>cylinder;
           fin>>cost;
           if (!fin.eof())
           cout<<orderid<<"\t"<<cylinder<<"\t"<<cost<<endl;
         }
         cout<<"\n\n "<<endl;
         cout<<"\n Total Number of cylinders ordered to company : "<<cylinders_ordered<<endl;
         fin.close();
         delay(5000);
         break;
 case 3 :
         //cout<<"Cylinders Delivered to Customers "<<endl;
         fin.open("Orders.txt",ios::in);
         if (fin.fail())
         {
          cout<<"No orders!!!!"<<endl;
          delay(3000);
          break;
         }
         //clrscr();
         cout<<"\n\n\n\n";
         cout<<"\n\n\n\n+--------------------------------------------------------------------------+";
         cout<<"\n                      CUSTOMER ORDER DETAILS                          ";
         cout<<"\n+--------------------------------------------------------------------------+";
         cout<<"\nOrder #"<<"\t"<<"Customer ID"<<"\t"<<"Cost"<<endl;
         while(!fin.eof())
         {
           fin>>customerid;
           fin>>orderid;
           fin>>cost;
           if (!fin.eof())
           cout<<orderid<<"\t"<<customerid<<"\t\t"<<cost<<endl;
         }
         fin.close();
         cout<<"\n\n "<<endl;
         cout<<"\n Total Number of Cylinders Delivered : "<<cylinders_ordered-availablecylinders;
         delay(5000);
         break;
    case 4 :
      break;
   }
   }
   while(reportchoice<4);
}
int Company::get_order()
{
  char choice;
  //clrscr();
   cout<<"\n\n\n\n";
  // _strdate(date);
  cout<<"\n+--------------------------------------------------------------------------+";
  cout<<"\n                     PLACE ORDER TO THE COMPANY                             ";
  cout<<"\n+--------------------------------------------------------------------------+";
  cout<<"\n Place 50 cylinders default order ? ";
  cout<<"\n Press 'y' to to finalize order and 'n' to enter the number of cylinders ";
  cin>>choice;
  if(choice=='y' || choice=='Y')
  {
   cost = ordercost(50);
   cout<<" \nCost : "<<cost;
   place_order();
   return 50;
  }
  else
  {
   cout<<"\n Enter the number of cylinders ";
   cin>>cylinders;
   cost = ordercost(cylinders);
   cout<<" \nCost : "<<cost;
   cout<<"\n\n Press 'y' to finalize the order and 'n' to abort ";
   cin>>choice;
   if(choice=='y' || choice=='Y')
   {
     place_order(cylinders);
     return cylinders;
   }

   else
   {
    cout<<" Order has not been placed ";
    delay(2000);
    return 0;
   }
 }
}
void Company :: place_order(int cylinders)
{
    ofstream outfile;
    outfile.open("Company.txt",ios::app);
    comp_order_id++;
    outfile<<comp_order_id<<"\n";
    //char sep='|';
    //comp_cyc+=cylinders;
    outfile<<cylinders<<"\n";
    cout<<"\n\n+---------------------------------------------------------------------------+";
    cout <<"\n                                BILL                                        ";
    cout<<"\n+---------------------------------------------------------------------------+";
    cout<<"\n\nOrder No : "<<comp_order_id;
    cout<<"\nNumber of cylinders ordered : "<<cylinders;
    cout<<"\nCost : "<<cost<<"\n";
    outfile<<cost<<"\n";
    cout<<"+---------------------------------------------------------------------------+";
    availablecylinders+=cylinders;
    cylinders_ordered+=cylinders;
    delay(3000);
    outfile.close();
 }

int Customer::Order()
{
 int flag=0;
 char line[30];
 //clrscr();
 cout<<"\n\n\n\n";
 ifstream fin;
 char choice;
 int id_check;
 cout<<"\n\n+--------------------------------------------------------------------------+";
 cout<<"\n                     CUSTOMER GAS CYLINDER BOOKING                          ";
 cout<<"\n+--------------------------------------------------------------------------+";
 cout<<"\n Enter the consumer Id no ";
 cin>>cons_id;
 if (cons_id !=0)
 {
  fin.open("Customer.txt",ios::in);
  //try
  //{
  if(!fin)
  {
   cout<<"file not open ";
   return 0;
  }
  while(!fin.eof())
  {
    fin>>id_check;
    if(id_check==cons_id)
    {
      flag++;
      break;
    }
  }
  if(flag==0)
  {
       cout<<"\n Invalid consumer Id ";
       delay(2000);
       fin.close();
       return 0;
  }
  else
  {
       cout<<"\n Number of Cylinders :";
       cost=cost_calculation(1);
       cout<<" \nCost : "<<cost;
       cout<<"\n\n Press 'y' to finalize the order and 'n' to abort ";
       cin>>choice;
       if(choice=='y' || choice=='Y')
       {
  //cust_order++;
       // cust_cyc+=cylinders;
  fin>>line;
  cout<<"\n\n+---------------------------------------------------------------------------+";
  cout<<"\n                                BILL                                        ";
  cout<<"\n+---------------------------------------------------------------------------+";
  cust_order_id++;
cout<<"\n\nOrder No : "<<cust_order_id;
  cout<<"\nConsumer Id :"<<cons_id;
  cout<<"\n customer's AADHAR number : ";puts(line);
  cout<<"\nCost : "<<cost<<"\n";
  cout<<"+---------------------------------------------------------------------------+";
  availablecylinders--;
  ofstream forder;
  forder.open("Orders.txt",ios::app);
  forder<<cons_id<<"\n";
  forder<<cust_order_id<<"\n";
  forder<<cost<<"\n";
  forder.close();
  fin.close();
  delay(3000);
  return 1;
     }
     else
     {
      cout<<" Order has not been placed ";
      fin.close();
      delay(2000);
      return 0;
     }
  }
  //}
  /*catch (exception ex)
  {
  cout<<"Invalid file operation"<<endl;
  } */

  }
  return 0;
}
int Customer::new_connection()
{
   aadhar:
   //clrscr();
   cout<<"\n\n\n\n";
   char choice;
   int i,adcopy;
   cout<<"\n\n\n\n+--------------------------------------------------------------------------+";
   cout<<"\n                     CUSTOMER NEW GAS CONNECTION BOOKING                          ";
   cout<<"\n+--------------------------------------------------------------------------+";
   cout<<" \n Enter customer's 16 digit AADHAR Number ";
   gets(aadhar);
   if(strlen(aadhar)!=16)
   {
     cout<<"\n Invalid entry . ";
     delay(2000);
     goto aadhar;
   }
   cout<<" \n NOTE : Your personal details will be linked to agency via AADHAR \n";
   cout<<"\n New connection charges : Rs.1000 ";
   cout<<"\n Press 'y' to confirm the new connection and generate bill or press'n' to abort ";
cin>>choice;
   if ( choice =='y'|| choice=='Y')
   {
    ofstream out;
    out.open("Customer.txt",ios::app);
    fstream forder;
    forder.open("Orders.txt",ios::app);
    if(out.fail())
    {
      cout<<"File cannot be opened ";
      return 0;
    }
    int temp;
    cust_order_id++;
    consumer_id++;
    out<<consumer_id<<"\n";
    cost=cost_calculation(1);
    out<<aadhar<<"\n";
    forder<<consumer_id<<"\n";
    forder<<cust_order_id<<"\n";
    forder<<cost<<"\n";
    forder.close();
    cout<<"\n\n+---------------------------------------------------------------------------+";
    cout<<"\n                                BILL                                        ";
    cout<<"\n+---------------------------------------------------------------------------+";
    cout<<"\n\n Order ID : "<<cust_order_id;
    cout<<"\n AADHAR NUMBER : ";puts(aadhar);
    cout<<"\n Consumer id : "<<consumer_id;
    cout<<"\n Cost : 1000\n";
    cout<<"+---------------------------------------------------------------------------+";
    delay(2000);
    availablecylinders--;
    out.close();
    return 1;
  }
  else
  {
    cout<<" Order has not been placed ";
    delay(2000);
    return 0;
  }
}

