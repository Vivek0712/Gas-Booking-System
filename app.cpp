#include"head.h"
int main()
{
  Agency agency;
  Customer consumer;
  Company company;
  int choice;
  int status;
  if (agency.login()==1)
  {
  do
  {
  choice=agency.menu();
  switch ( choice)
   {
     case 1 :

    status=company.get_order();
    if (status>0)
    agency+status; //Operator Overloading
    break;
     case 2 :

    status=consumer.Order();
    if (status>0)
    agency-status; //Operator Overloading

    break;
     case 3 :

    status=consumer.new_connection();
    if (status>0)
    agency-status;

    break;
     case 4 :
    agency.summary();
    break;
     case 5 :   agency.UpdateMaster();
    exit(0);
     default :
    cout<<"\n Invalid Choice ";
    }
    }
    while (1);
  }
  //getch();
  return 0;
}

