#include <iostream>
#include <ctime>
using namespace std;

void printDate(){
  time_t t = time(0);
  tm *ltm = localtime(&t);
  cout<< "Todays date: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" <<1900+ltm->tm_year ;
}

int main(){
printDate();
cout<<"\nWelcome, lets begin tracking your finances!";


return 0;
}
