
/*          Login and Registration System
In this code, we will read the username and password from the file system. 
If the data matches the username and password entered by the user, 
then the user can log in successfully. If the user is registering for the first time, 
their username and password will be collected through input, stored in the data.txt file, 
and subsequently checked using the same login method described above.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//reading data(username and password) from the file
pair<string, string>  READ_DATA_FROM_FILE() {

    ifstream inputFile("data.txt");
    if (!inputFile) {
        cout << "Unable to open file data.txt";
        
    }
    string stored_username, password;
    getline(inputFile, stored_username);
    getline(inputFile, password);

    inputFile.close();
    return {stored_username, password};

}

//writing in file if user signup then his username and password will save in database file
void writeinfile(string username, string password){
	
	ofstream outputFile("data.txt", ios::app);
    if (!outputFile) {
        cout << "Unable to open file data.txt";
    }
    outputFile<<endl;
    outputFile << username << endl;
    outputFile << password << endl;

    outputFile.close();

}

//registration --> if user is trying to sign up
void registration(){
	
	string username, password;
	cout<<"Enter UserName:";
	cin>>username;
	
	pair<string, string> userInfo = READ_DATA_FROM_FILE();
    string stored_username = userInfo.first;
	
	if(username == stored_username)
	{
		cout<<"username already EXIST,... Try with different username\n";
		registration();
	}
    else{
    cout<<"Enter Password:";
	cin>>password;
	}
	
	writeinfile(username, password );
	cout<<"Registration successful! You can now log in\n";
	
}

//login function --> if user already exist 
void login(){
	string username, password;
	cout<<"UserName:";
	cin>>username;
	cout<<"EnterPassword";
	cin>>password;
    
	
	pair<string, string> userInfo = READ_DATA_FROM_FILE();
    string stored_username = userInfo.first;
    string stored_password = userInfo.second;
    
    if(username == stored_username && password == stored_password)
	{
		cout<<"LOG IN successful!... ";
	 }
	 else{
	 	cout<< "username or password doesn't match please try again:";
	 } 
}

int main() {
	int input=0;
     cout<<"Press 1 for Registration:\nPress 2 for LogIn:\n";
     cin>>input;
     switch(input){
     	case 1:
     		  registration(); 
     		  break; 
     	case 2:
		      login();
		      break;
		default:
			   cout<<"INVALID INPUT\n";
			break;
		     	
	 }
return 0;    
}

