
#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

#include <iostream>
#include <fstream>
#include<experimental/filesystem>
#include <unistd.h>
#include<string>
#include<sstream>
#include<time.h>

using namespace std;

int send_otp(string reciever){

    //============================Generating a random number===========================//
    srand(time(0));
    int otp = rand()%9999+10000;
    //cout<<otp;
    string code = to_string(otp);
    //================================random number generated and sent to string ===========//
    char cwd[10000];//this finds the path of .cpp file (absolute)
    getcwd(cwd, sizeof(cwd));

    string path_of_file = "";
    int i=0;
    while(cwd[i]!='\0'){    //converts array to string


        path_of_file += cwd[i];
        i++;
    }
   // cout<<endl<<"path of file jado string ch leli"<<path_of_file<<endl;//random checks ::Jai Punjabi
  // Create and open a text file


  //====================================python Processing=============================================//
  ofstream MyFile("script_for_email.py");//file opened in filestream


  string text =  //python used
  "import smtplib\n"
  "from email.message import EmailMessage\n"
  "msg = EmailMessage()\n"
  "msg['Subject'] = 'From my script'\n"
  "msg['From'] = 'environmentseekersnitj@gmail.com'\n"
  "msg['To'] = '"+reciever+"'\n"
  "smtp = smtplib.SMTP_SSL('smtp.gmail.com', 465)\n"
  "smtp.login('environmentseekersnitj@gmail.com', 'fdgphlhigarggaoy')\n"
  "msg.set_content('Your OTP for verification of booking is given as :: "+code+"')\n"
  "smtp.send_message(msg)\n"
  "smtp.quit()";

  // Write to the file
  MyFile << text;

  // Close the file
  MyFile.close();
  //=================================python file was written======================//
 // cout<<"python wali file likhti ";

    string filename = path_of_file+"\\script_for_email.py";//absolute path of file containing email script in python
    string command = "python -u ";
    command += filename;
    system(command.c_str()); // sending a command in python for execution
    cout<<"mail_sent";
    return otp;


}


#endif // PATIENT_H_INCLUDED
