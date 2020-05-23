#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

const time_t t = time(0);
const tm *ltm = localtime(&t);

void printDate()
{
  cout<< "Todays date: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" <<1900+ltm->tm_year ;
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
void InitIncomeFile(string name)
{
  ofstream fout;
  fout.open(name);
  fout<<"2020 Income\n";
  cout<<"\t"<<1900+ltm->tm_year<<" Income\n";

int currMonth = 1 + ltm->tm_mon;//current month
  for(int i = 1; i <= 12; i++)//print empty months to the file
  {
    string month = getMonth(i);
    fout<<"\n"<<month;
    if(i == currMonth)//when we reach curent month then ask for values to input
    {
      float income;
cout<<"\n\t\tLogging this months income.\nInput a value and hit the enter key to input the next. When done inputting, enter -1 as the last value and press enter once more to confirm.\n\t"<<month<<"\n - ";
cin >> income;
while(income != -1)//user will enter -1 to move on
{
  fout<<"\n- "<<income;
  cout<<"\n - ";
  cin>>income;
}
    }
    fout<<"\n";
  }
}

void InitExpenseFile(string name)
{
  ofstream fout;
  fout.open(name);
  fout<<"2020 Expenses\n";
  cout<<"\t"<<1900+ltm->tm_year<<" Income/n";

int currMonth = 1 + ltm->tm_mon;//current month
  for(int i = 1; i <= 12; i++)//print empty months to the file
  {
    string month = getMonth(i);
    fout<<"\n"<<month;
    if(i == currMonth)//when we reach curent month then ask for values to input
    {
      float expense;
cout<<"\n\t\tLogging this months expenses.\nInput a value and hit the enter key to input the next. When done inputting, enter -1 as the last value and press enter once more to confirm.\n\t"<<month<<"\n - ";
cin >> expense;
while(expense != -1)//user will enter -1 to move on
{
  fout<<"\n- "<<expense;
  cout<<"\n - ";
  cin>>expense;
}
    }
    fout<<"\n";
  }
}

/********************
Open txt files if they exist and collect informatoin, if not then initialize new files
********************/
void openTextFiles(vector<float> income,vector<float> expense)
{
ifstream fin;
string fileName;//name of file to be opened
string fileStart;

cout<<"What is the name of your income file? ";
getline(cin,fileName);
//hard code file name for testing
//fileName = "income.txt";
fin.open(fileName);
if(getline(fin,fileStart))//if file was opened then read
{
    cout<<fileStart<<" opened"<<endl;
    //read file and extract information
}
else//initialize file
{
  cout<<"Income file does not exist, lets initialize your income file\n";
  InitIncomeFile(fileName);
}
fin.close();

cout<<"\nWhat is the name of your expense file? ";
getline(cin,fileName);
//hard code file name for testing
//fileName = "expense.txt";
fin.open(fileName);
if(getline(fin,fileStart))//if file was opened then read
{
  cout<<fileStart<<" opened"<<endl;
  //read file and extract information
}
else//initialize file
{
  cout<<"Expense file does no exist, lets initialize your expense file\n";
  InitExpenseFile(fileName);
}
fin.close();
}

int main()
{
vector<float> income;//store income values
vector<float> expense;//store expense values

printDate();
cout<<"\nWelcome, lets begin tracking your finances!\n"<<endl;

openTextFiles(income,expense);//open txt files and gather information

return 0;
}
