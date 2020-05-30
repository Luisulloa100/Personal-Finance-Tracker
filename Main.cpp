#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

const time_t t = time(0);
const tm *ltm = localtime(&t);

struct entry
{
  string name;
  string date;
  float amount;

  entry(string n, string d, float amnt);
};

entry::entry(string n, string d, float amnt)
{
  name = n;
  date = d;
  amount = amnt;
}

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

void initFile(string name)
{
  ofstream fout;
  fout.open(name);
  fout<<name;
  cout<<"\t\t"<<name;

  int currMonth = 1 + ltm->tm_mon;//current month
  for(int i = 1; i <= 12; i++)//print empty months to the file
  {
    string month = getMonth(i);
    fout<<"\n"<<month;
    if(i == currMonth)//when we reach curent month then ask for values to input
    {
      string name,date;
      float income;
      cout<<"\n\n\t\tLogging this months entries.\nEnter the name (MAX ONE WORD), date, and amount then move on to the next.\nWhen done enter a dash \"-\" as the name and press enter."<<endl;
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
    //readFile(income);
  }
  else//initialize file
  {
    cout<<"\nIncome file does not exist, lets initialize your income file\n";
    initFile(fileName);
  }
  fin.close();
  cin.ignore(10000,'\n');
  cout<<"\nWhat is the name of your expense file? ";
  getline(cin,fileName);
  //hard code file name for testing
  //fileName = "expense.txt";
  fin.open(fileName);
  if(getline(fin,fileStart))//if file was opened then read
  {
    cout<<fileStart<<" opened"<<endl;
    //readFile();
  }
  else//initialize file
  {
    cout<<"\nExpense file does not exist, lets initialize your expense file\n";
    initFile(fileName);
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
