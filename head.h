
/*
 DESCRIPTION : This system automates the working of a typical Gas Agency 
 AUTHOR      : VIVEK RAJA P S
 VERSION     : 1.0
 DATE        : 25.04.2017

*/






#include<iostream>
#include<string>
#include<iomanip>
//#include<time>
#include<fstream>
//#include<conio>
//#include<dos>
//#include<process>
//#include<stdio>
#define ordercost(x) x*400;
using namespace std;

inline float cost_calculation(int nc)
{
  return nc*500;
}
static int availablecylinders=0;
static int comp_order_id=0;
static int cust_order_id=0;
static int consumer_id=0;
static int cylinders_ordered=0;

class Company
{
  int cylinders;
  float cost;

public :
  int get_order();
  void place_order(int cylinders=50);

};

class Customer
{
  int  date,cons_id, no_cyc,cylinders ;
  char aadhar[16];
  float cost;
public :
  int Order();
  int new_connection();

};
class Agency : public Company, public Customer
{

   int reg_no;
   int password;
   int tot_nc;

  public :
   Agency()
   {
    tot_nc=0;
    GetMasterValues();
   }
   ~Agency()
   {
   UpdateMaster();
   }
   int login();
   int menu();
   void summary();
   void operator+(int x);
   void operator-(int x);
   void UpdateMaster();
   void GetMasterValues();

};

