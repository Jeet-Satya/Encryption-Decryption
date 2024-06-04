#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;


int main()
{
    string s,s1;

        cout << "\n ** ENTER YOUR MESSAGE HERE ** \n\n";
        getline(cin, s);

        s1=s;

    long long initial_key, key;

    time_t present_time = time(0);

    tm *ltm = localtime(&present_time);

    auto now = chrono::high_resolution_clock::now();

    auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;

    time_t t = chrono::system_clock::to_time_t(now);

    int YEAR = ltm->tm_year + 1900, MON=ltm->tm_mon + 1, DAY = ltm->tm_mday;
    int HOUR = ltm->tm_hour, MIN = ltm->tm_min, SEC = ltm->tm_sec , MS = ms.count();

    cout << endl
         << "** CURRENT DATE AND TIME INFORMATION OF THIS SYSTEM FOR KEY MAKING ** " << endl;

    cout << endl
         << setw(16) << setiosflags(ios::left) << "YEAR"
         << ":" << YEAR<< endl;

    cout << setw(16) << setiosflags(ios::left) << "MONTH"
         << ":" << MON << endl;

    cout << setw(16) << setiosflags(ios::left) << "DAY"
         << ":" << DAY<< endl;

    cout << setw(16) << setiosflags(ios::left) << "HOUR"
         << ":" << HOUR << endl;

    cout << setw(16) << setiosflags(ios::left) << "MINUTES"
         << ":" << MIN << endl;

    cout << setw(16) << setiosflags(ios::left) << "SECONDS"
         << ":" << SEC << endl;

    cout << setw(16) << setiosflags(ios::left) << "Milliseconds"
         << ":" << MS << endl;

    initial_key = HOUR + SEC + MIN + YEAR + MON + DAY;

    key = initial_key * MS + MS;

    cout << endl
         << "HERE IS THE DESIGNED KEY BY USING ABOVE SYSTEM INFORMATION "
         << ": " << key << endl
         << endl;

         int len = s.length(), sum=0,arrsum[len],revarr[len],final_arr[len];


    int choice;
    while (1)
    {
        cout << endl
             << setw(10) << setiosflags(ios::left) << "1.ENCRYPTION" << endl;
        cout << endl
             << setw(16) << setiosflags(ios::left) << "2.DECRYPTION" << endl;
        cout << endl
             << setw(16) << setiosflags(ios::left) << "3.EXIT" << endl;

        cout << "\nENTER YOUR CHIOCE HERE -> ";
        cin >> choice;

        switch (choice)
        {
        case 1:

             // ** ENCRYPTION BEGINS **

    for(int i=0;i<len;i++)
    {
        sum+=(int)s[i];
        arrsum[i] = sum + YEAR + MS;
         s[i]=arrsum[i];
         final_arr[i]=(int)s[i];
    }
     
     cout<<endl;

     cout<<"MESSAGE ENCRYPTED : ";
    for(int i=0;i<len;i++)
    {
        if(i%2==0)
        {
        std::bitset<10> binary(MS);  
    cout<<binary;
    std::bitset<15> binary_num(final_arr[i]);  
    cout<<binary_num;
    }
    else
        {
        std::bitset<10> binary(SEC);  
    cout<<binary;
    std::bitset<15> binary_num(arrsum[i]);   
    cout<<binary_num;
    }
    }

    cout<<endl<<endl;
                                               
    break;

        case 2:

                // ** DECRYPTION BEGINS **

     if(s1==s)

        cout<<"\n** PLEASE FIRST ENCRYPT THE MESSAGE **\n\n";

        else
        {

      long long pin;

        cout<<"\nPLEASE ENTER KEY  : ";

        cin>>pin;

        if(pin==key)
        {

         cout<<endl<<"MESSAGE DECRYPTED : ";
     revarr[0]=arrsum[0]- YEAR - MS;                                                 
     s[0] = revarr[0];

    cout<<s[0];

    for(int i=1;i<len;i++)
    {
        revarr[i]=arrsum[i]-arrsum[i-1];
        s[i]=(char)revarr[i];
        cout<<s[i];
    }
    cout<<endl<<endl<<endl;
    exit(0);

        }

        else
      cout<<"\nPIN IS NOT VALID\n\n";

        }

    break;

        case 3:
            exit(0);

        default:
            cout << "\n\n** KINDLY ENTER A VALID CHIOCE **\n\n";
        }
    }

    return 0;
}