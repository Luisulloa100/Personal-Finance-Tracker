#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const time_t t = time(0);
const tm *ltm = localtime(&t);
const int currMonth = 1 + ltm->tm_mon;
void printDate()
{
  cout<< "Todays date: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" <<1900+ltm->tm_year ;
}

struct entry
{
  string name;
  string date;
  float amount;

  entry();
  entry(string entryName, string entryDate, float entryAmnt);
};

struct month
{
  string name;
  int num;
  vector<entry> income;
  vector<entry> expense;

  month();
  month(string monthName, int monthNum, vector<entry> incomeVect, vector<entry> expenseVect);
};

month::month()
{
  name = "n/a";
  num = 0;
}

month::month(string monthName, int monthNum, vector<entry> incomeVect, vector<entry> expenseVect)
{
  name = monthName;
  num = monthNum;
  income = incomeVect;
  expense = expenseVect;
}

entry::entry()
{
  name = "n/a";
  date = "0/0/0";
  amount = 0;
}

entry::entry(string entryName, string entryDate, float entryAmnt)
{
  name = entryName;
  date = entryDate;
  amount = entryAmnt;
}

string getMonth(int month)//given a  number 1-12 return coresponding month name
{
  switch (month)
  {
    case 1:
    return "Jan";
    case 2:
    return "Feb";
    case 3:
    return "Mar";
    case 4:
    return "Apr";
    case 5:
    return "May";
    case 6:
    return "Jun";
    case 7:
    return "Jul";
    case 8:
    return "Aug";
    case 9:
    return "Sep";
    case 10:
    return "Oct";
    case 11:
    return "Nov";
    case 12:
    return "Dec";
    default:
    return "n/a";
  }
}

void initFile(string fName)
{
  cout<<"Initializing "<<fName<<endl;
  ofstream fout;
  fout.open(fName);
  fout<<fName;
  /*
  cout<<"\t\t"<<fName;

  int currMonth = 1 + ltm->tm_mon;//current month
  for(int i = 1; i <= 12; i++)//print empty months to the file
  {
  string month = getMonth(i);
  fout<<"\n"<<month;
  if(i == currMonth)//when we reach curent month then ask for values to input
  {
  string name,date;
  float income;
  cout<<"\n\n\t\tLogging this months entries.\nEnter the name (ONE WORD), date, and amount then move on to the next.\nWhen done enter a dash \"-\" as the name and press enter."<<endl;
  cout<<"\nSample Entries:\nName: myjob\t\tstorename\nDate: 6/15/20\t\t6/15/20\nAmount: 123.456\t\t12.34\n\n\t"<<month;
  int done = 0;
  do{
  cout<<"\nName: ";
  cin>>name;
  if(name == "-")
  {
  done = 1;
  break;
}
cout<<"Date: ";
cin>>date;
cout<<"Amount: ";
cin >> income;

fout<<"\n"<<name<<" "<<date<<" "<<income;
}while(done != 1);
}
fout<<"\n";
}*/
}


void readFile(string fName, vector<month> year)
{
  cout<<"Reading "<<fName;
  /*  ifstream fin;
  fin.open(fname);
  string name;
  string date;
  float amount;
  string lineRead;

  getline(fin,lineRead);//file header


  getline(fin,lineRead);
  int month = 0;
  while(month != 1 + ltm->tm_mon)//get to current month in text file
  {
  getline(fin,lineRead);
  if(lineRead.length() == 3)
  month++;
}
getline(fin,lineRead);
while(lineRead.length() != 0)//read all entries for the month
{//read string into corresponding variables
stringstream ss;
ss<<lineRead;
ss>>name;
ss>>date;
ss>>amount;
entry input(name,date,amount);
vect.push_back(input);
getline(fin,lineRead);
}*/
}

/********************
Open txt file if it exists and collect informatoin, if not initialize new file
********************/
void openTextFile(string fileType, vector<month> monthVect)
{
  ifstream fin;
  string fileName;//name of file to be opened
  string fileStart;

  cout<<"\nWhat is the name of your "<<fileType<<" file? ";
  getline(cin,fileName);
  fileName += ".txt";
  //hard code file name for testing
  //fileName = (fileType +".txt");
  fin.open(fileName);
  if(fin.is_open())//if file was opened then read
  {
    readFile(fileName,monthVect);
    /*
    cout<<"\nIncome Vector\n";
    for(int i = 0;i < income.size();i++)
    {
    cout<<income[i].name<<income[i].date<<income[i].amount<<endl;
  }
  */
  cout<<fileName<<" processed.\n";
}
else//initialize file
{
  cout<<"\nIncome file does not exist, lets initialize an income file\n";
  initFile(fileName);
}
fin.close();
}

void monthMenu(int monthNum)
{
  vector<month> year;

  cin.ignore();
  string txtFileType = "income";
  openTextFile(txtFileType,year);
  txtFileType = "expense";
  openTextFile(txtFileType,year);
}

void progMenu()
{
  int option;

  while(option != 0)
  {
    cout<<"\nWhat would you like to work on?\n";
    cout<<"1. Current Months Budget\n";
    cout<<"2. Specific Months Budget\n";
    cout<<"0. Exit\n";
    cout<<"\nChoice: ";
    cin>>option;

    switch(option)
    {
      case 1:
      monthMenu(currMonth);
      break;
      case 2:
      int month;
      cout<<"What month would you like to edit?";
      cin>> month;
      monthMenu(month);
      break;
      case 0:
      break;
      default:
      cout<<option<<" is not an option please enter a valid option";
      break;
    }
  }
}

int main()
{
  printDate();
  cout<<"\nWelcome, lets begin tracking your finances!"<<endl;

  progMenu();

  return 0;
}
