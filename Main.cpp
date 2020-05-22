#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

time_t t = time(0);
tm *ltm = localtime(&t);

void printDate()
{
  cout<< "Todays date: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" <<1900+ltm->tm_year ;
}

string getMonth(int month)
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
void InitIncomeFile(string name)
{
  ofstream fout;
  fout.open(name);
  fout<<"2020 Income\n";

  for(int i = 1; i <= 12; i++)
  {
    fout<<"\n";
    fout<<getMonth(i);
    fout<<"\n";
  }
}

void InitExpenseFile(string name)
{
  ofstream fout;
  fout.open(name);
  fout<<"2020 Expenses\n";

  for(int i = 1; i <= 12; i++)
  {
    fout<<"\n";
    fout<<getMonth(i);
    fout<<"\n";
  }
}

/********************
Read the income and expense files, store information into vectors
********************/
void readTextFiles(vector<float> income,vector<float> expense)
{
ifstream fin;
string fileName;
string fileStart;

cout<<"What is the name of your income file? ";
getline(cin,fileName);
fin.open(fileName);
if(getline(fin,fileStart))
{
    cout<<fileStart<<" opened"<<endl;
}
else
{
  cout<<"Income file does not exist, lets initialize your income file\n";
  InitIncomeFile(fileName);
}
fin.close();

cout<<"What is the name of your expense file? ";
getline(cin,fileName);
fin.open(fileName);
if(getline(fin,fileStart))
{
  cout<<fileStart<<" opened"<<endl;

}
else
{
  cout<<"Expense file does no exist, lets initialize your expense file\n";
  InitExpenseFile(fileName);
}
fin.close();
}

int main()
{
vector<float> income;
vector<float> expense;

printDate();
cout<<"\nWelcome, lets begin tracking your finances!\n"<<endl;

readTextFiles(income,expense);

return 0;
}
