#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include<fstream>

using namespace std;
int main(void)
{
    ofstream myfile;
    cout<<"please enter the path of the file you wish to print the output in"<<endl;
    cout<<"please make sure that your path contains no spaces to avoid any issues"<<endl;
    string file_path;
    cin>>file_path;
    myfile.open (file_path);
    myfile << "Writing this to a file.\n";
    myfile.close();

    cout<<"please Entre the path to file to read"<<endl;
    cout<<"please make sure that your path does not contain any spaces to avoid any issues"<<endl;
    cin>>file_path;
    ifstream myfile1(file_path);
    if(myfile1.is_open()){
        while(getline(myfile1,file_path))
            cout<<file_path<<endl;
    }
    else
        cout<<"theres some error occured try again"<<endl;
    return 0;
}