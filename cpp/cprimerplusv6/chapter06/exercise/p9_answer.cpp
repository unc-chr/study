/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p9_answer.cpp
*   Author：leekaihua
*   Date：2023年03月05日
*   Brife：
*



*/
#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>

using namespace std;

struct DonationInfo{
    string name;
    double amount;
};

void donationInfoDisplay(DonationInfo donationInfo[], int num, bool isGrandPatrons)
{
    int countNum = 0;
    for(int i = 0 ; i < num ; i++)
    {
        if(isGrandPatrons)
        {
            if(donationInfo[i].amount > 10000)
            {
                countNum++;
                cout << donationInfo[i].name  << endl;
            }
        }
        else
        {
            if(donationInfo[i].amount <= 10000)
            {
                countNum++;
                cout << donationInfo[i].name  << endl;
            }
        }
    }
    if(countNum == 0)
        cout << "none" << endl;
}

int main()
{
    cout << "Read file content..." << endl;
    ifstream txtDonationInfo;
    txtDonationInfo.open("input_for_p9", ios::in);
    if(!txtDonationInfo.is_open())
    {
        cout << "File failed to open !" << endl;
        exit(EXIT_FAILURE);
    }
    int num = 0;
    (txtDonationInfo >> num).get();
    DonationInfo* donationInfo = new DonationInfo[num];
    for(int i = 0; i < num; i++)
    {
        txtDonationInfo >> donationInfo[i].name;
        txtDonationInfo >> donationInfo[i].amount;
        txtDonationInfo.get();
    }
    cout << "******Grand Partons******" << endl;
    donationInfoDisplay(donationInfo, num, true);
    cout << "******Partons******" << endl;
    donationInfoDisplay(donationInfo, num, false);

    delete[] donationInfo;
    txtDonationInfo.close();
    return 0;
}