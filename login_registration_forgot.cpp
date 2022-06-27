#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
	int c;
	std::cout << "\t\t\t______________________________________________________________________\n\n\n";
	std::cout << "\t\t\t                     Welcome to the Login page                        \n\n\n";
	std::cout << "\t\t\t_______________________________ MENU  ________ _______________________\n\n\n";
	std::cout << "                                                                              \n\n";
	std::cout << "\t| Press 1 to LOGIN                                 |" <<endl; 
	std::cout << "\t| Press 2 to REGISTER                              |" <<endl;
	std::cout << "\t| Press 3 If you forgot your password              |" <<endl;
	std::cout << "\t| Press 4 to EXIT                                  |" <<endl;
	std::cout << "\n\t\t\t Please enter your choice  :" ;
	std::cin >>c;
	std::cout <<endl;
	
	switch(c)
	{
		case 1:
			login();
			break;
		
		case 2:
			registration();
			break;
			
		case 3:
			forgot();
			break;
			
		case 4:
			std::cout << "\t\t\t Thank you! \n\n\n";
			break;
			
		default:
			system("cls");
			std::cout << "\t\t\t Please select from the options given above \n\n\n";
			main();	
	}
	
}

	void login()
	{
		int count;
		string userid, password, id, pass;
		system("cls");
		std::cout << "\t\t\t Please enter the username and password : " <<endl;
		std::cout << "\t\t\t USERNAME " ;
		std::cin >> userid;
		std::cout << "\t\t\t PASSWORD" ;
		std::cin >> password;
		
		ifstream input("records.txt");
		
		while(input>>id>>pass)
		{
			if(id==userid && pass==password)
			{
				count = 1;
				system("cls");
			}
		}
		input.close();
		
		if(count==1)
		{
			std::cout << userid << "\n Your LOGIN is successful \n Thanks for logging in ! \n" ;
			main();
		}
		else{
			std::cout << "\n LOGIN ERROR \n please check your username and password" ;
		}
}
 void registration()
 {
 	string ruserid,rpassword,rid,rpass;
 	system("cls");
 	std::cout << "\t\t\t Enter the username :" ;
 	std::cin >>ruserid;
 	std::cout << "\t\t\t Enter the password :" ;
 	std::cin >>rpassword;
 	
 	ofstream f1("records.txt",ios::app);
 	f1<<ruserid<<' ' <<rpassword<<endl;
 	system("cls");
 	std::cout << "\n\t\t\t Registration is successful ! \n";
 	main();
 	
 	}
 	void forgot()
 	{
 		int option;
 		system("cls");
 		std::cout << "\t\t\t You forgot the password !! No worries \n";
 		std::cout << "Press 1 to search your userid by username" <<endl;
 		std::cout << "Press 2 to go back to the maain menu" <<endl;
 		std::cout<< "\t\t\t Enter your choice :";
 		std::cin >>option;
 		switch(option)
 		{
 			
 			case 1 :
 			{
 				int count=0;
 				string suserId,sId,spass;
 				std::cout << "\n\t\t Enter the username which you remembered :";
 				std::cin >>suserId;
 				
 				ifstream f2("records.txt");
 				while(f2>>sId>>spass)
 				{
 					if(sId==suserId)
 					{
 						count=1;
					 }
				 }
				 f2.close();
				 if(count==1)
				 {
				 	std::cout<< "\n\n Your account is found! \n";
				 	std::cout << "\n\n Your password is : " <<spass;
				 	main();
				 }
				 else{
				 	std::cout<<"\n\t Sorry! Your account is not found! \n";
				 	main();
				 }
				 break;
			 }
			 case 2 :
			 	{
			 		main();
				 }
				 default:
				 std::cout << "\t\t\t wrong choice ! pleaes try again" <<endl;
				 forgot();
				 
			
		 }
	 }