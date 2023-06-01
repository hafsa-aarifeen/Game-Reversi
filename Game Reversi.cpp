#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<stdio.h>
#include<ctype.h>
#include<fstream>
using namespace std;


char board[8][8],A,B;
char p1[20], p2[20];

void display(char board[8][8]);

int main(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	system("Color 74");

	char pos[2];
	char X,Y,t1,t2,n;
	int c,i,j,k,m,Score_1,Score_2;
	menu:
		Score_1=0;
		Score_2=0;
		srand(time(0));
		system("cls");
		int done;
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				board[i][j]=' ';
				
		cout<<"\t\t\t -----------------------------------------------\n";
		cout<<"\t\t\t -------------       REVERSI       -------------\n";
		cout<<"\t\t\t -----------------------------------------------\n";
		cout<<"\n\n\t\t\t\t           WELCOME!!!!";
		Sleep(2000);
		
		cout<<"\n\nStart New Game Press 1 "<<endl;
		cout<<"View Score Board Press 2 "<<endl;
		cout<<"Exit the Game Press 3 "<<endl;
		cout<<"\nEnter Your Choice : ";
		cin>>c;
		
		if(c==2){
			// Create a text string, which is used to output the text file
			cout<<"\n\n -------- Score Board ---------"<<endl<<endl;
  			string myText;

  			// Read from the text file
  			ifstream Readscore("ScoreBoard.txt");

  			// Use a while loop together with the getline() function to read the file line by line
  			while (getline (Readscore, myText)) {
    		
			// Output the text from the file
    		cout << myText<<endl;
  			}

  			// Close the file
  			Readscore.close();
  			
  			goback: 
			cout<<"\n Enter 0 to Goto Manu : ";
			cin>>n;
			
			if (n=='0'){
				goto menu;
			}
			else
				cout<<"\n Invalid Input..... "; 
				goto goback;
				
  			
		}
		else if (c==1){
	 
			cout<<"\n\nEnter Player 1 Name : ";
			cin>>p1;
			cout<<"\nEnter "<<p1<<"'s Token : ";
			cin>>A;
			
			cout<<"\nEnter Player 2 Name : ";
			cin>>p2;
			cout<<"\nEnter "<<p2<<"'s Token : ";
			cin>>B;
			
			if(A==B){
				cout<<"\n\t!!!Sorry, Both Players token are same!!!";
				Sleep(3000);
				goto menu;
			}
			t1=A;
			t2=B;
			cout<<"\n Player 1's Token is "<<A;
			cout<<"\n Player 2's Token is "<<B;
			cout<<"\n\n\t\t\t All Set";
			Sleep(500);
			cout<<"\n\nStart to Play..........";
			Sleep(1000);
			board[3][3]=A;
			board[3][4]=B;
			board[4][4]=A;
			board[4][3]=B;
			begin:
				done=1;
			player1:		
			display(board);
			A=t1;
			SetConsoleTextAttribute(color, 10);
			cout<<"\n"<<p1<<" ( Player 1 )"<<"  It's Your Turn........."<<endl;
			SetConsoleTextAttribute(color, 11);
			cout<<"Enter The Position ( like A1 , B4 , G8) : ";
			cin>>pos;
		

			pos[0]=toupper(pos[0]);	
			if(pos[0]=='A')
					Y=0;	
				else if(pos[0]=='B')
						Y=1;
			 		else if(pos[0]=='C')
							Y=2;
				 		else if(pos[0]=='D')
								Y=3;
							else if(pos[0]=='E')
									Y=4;
			 				 	else if(pos[0]=='F')
										Y=5;
				  				  	else if(pos[0]=='G')
											Y=6;
										else if(pos[0]=='H')
												Y=7;
											else
											 	goto player1;
		
			if(pos[1]=='1')
					X=0;	
				else if(pos[1]=='2')
						X=1;
			 		else if(pos[1]=='3')
							X=2;
				  		else if(pos[1]=='4')
								X=3;
							else if(pos[1]=='5')
									X=4;
			 				 	else if(pos[1]=='6')
										X=5;
				  				  	else if(pos[1]=='7')
											X=6;
										else if(pos[1]=='8')
												X=7;
											else
											 	goto player1;
		
			if(board[X][Y]!=' '){
				cout<<"Invalid Cell, Enter Again...........";
				Sleep(500);
				goto player1;			
			}

			board[X][Y]=A;
			//Checking for change
			//Left side
			for(j=Y-1;j>=0;j--){
				if(board[X][j]!=B)
					break;
			}
		
			if(board[X][j]==A){
				for(int l=Y-1;l>j;l--){
					board[X][l]=A;
				}
			}
		
			//right side
		
			for(j=Y+1;j<8;j++){
				if(board[X][j]!=B)
					break;
			}
		
			if(board[X][j]==A){
				for(int l=Y+1;l<j;l++){
					board[X][l]=A;
				}
			}
		
			//North side
		
			for(i=X-1;i>=0;i--){
				if(board[i][Y]!=B)
					break;
			}
		
			if(board[i][Y]==A){
				for(int l=X-1;l>i;l--){
					board[l][Y]=A;
				}
			}
		
			//South side
		
			for(i=X+1;i<8;i++){
				if(board[i][Y]!=B)
					break;
			}
		
			if(board[i][Y]==A){
				for(int l=X+1;l<i;l++){
					board[l][Y]=A;
				}
			}
		
			//Northwest check
		
			i=X-1;
			j=Y-1;
			while(i>=0 && j>=0){
				if(board[i][j]!=B)
					break;
				i--;
				j--;	
			}
		
			if(board[i][j]==A){
				k=X-1,m=Y-1;
				while(k>i && m>j){
					board[k][m]=A;
					k--;
					m--;	
				}
			}
		
			//Northeast check
		
			i=X-1;
			j=Y+1;
			while(i>=0 && j<8){
				if(board[i][j]!=B)
					break;
				i--;
				j++;	
			}
		
			if(board[i][j]==A){
				k=X-1,m=Y+1;
				while(k>i && m<j){
					board[k][m]=A;
					k--;
					m++;	
				}
			}
		
			//Southwest check
		
			i=X+1;
			j=Y-1;
			while(i<8 && j>=0){
				if(board[i][j]!=B)
					break;
				i++;
				j--;	
			}
		
			if(board[i][j]==A){
				k=X+1,m=Y-1;
				while(k<i && m>j){
					board[k][m]=A;
					k++;
					m--;	
				}
			}
		
			//Southeast check
		
			i=X+1;
			j=Y+1;
			while(i<8 && j<8){
				if(board[i][j]!=B)
					break;
				i++;
				j++;	
			}
		
			if(board[i][j]==A){
				k=X+1,m=Y+1;
				while(k<i && m<j){
					board[k][m]=A;
					k++;
					m++;	
				}
			}
		
			//PLAYER 2
			player2:

			display(board);
		
			SetConsoleTextAttribute(color, 12);
			cout<<"\n"<<p2<<" ( Player 2 )"<<" It's Your Turn............."<<endl;
			SetConsoleTextAttribute(color, 13);
			cout<<"Enter the Position ( like A1 , B4 , G8) : ";
			cin>>pos;
		
			pos[0]=toupper(pos[0]);	
			if(pos[0]=='A')
					Y=0;	
				else if(pos[0]=='B')
						Y=1;
			 		else if(pos[0]=='C')
							Y=2;
				  		else if(pos[0]=='D')
								Y=3;
							else if(pos[0]=='E')
									Y=4;
			 				 	else if(pos[0]=='F')
										Y=5;
				  				  	else if(pos[0]=='G')
											Y=6;
										else if(pos[0]=='H')
												Y=7;
											else
											 	goto player2;
		
			if(pos[1]=='1')
					X=0;	
				else if(pos[1]=='2')
						X=1;
			 		else if(pos[1]=='3')
							X=2;
				  		else if(pos[1]=='4')
								X=3;
							else if(pos[1]=='5')
									X=4;
			 				 	else if(pos[1]=='6')
										X=5;
				  				  	else if(pos[1]=='7')
											X=6;
										else if(pos[1]=='8')
												X=7;
											else
											 	goto player2;
		
			if(board[X][Y]!=' '){
				cout<<"Invalid Cell, Enter Again......";
				Sleep(500);
				goto player2;			
			}

			board[X][Y]=B;
			//Checking for change
		
			//Left side
			for(j=Y-1;j>=0;j--){
				if(board[X][j]!=A)
					break;
			}
		
			if(board[X][j]==B){
				for(int l=Y-1;l>j;l--){
					board[X][l]=B;
				}
			}
		
			//right side
			for(j=Y+1;j<8;j++){
				if(board[X][j]!=A)
					break;
			}
			
			if(board[X][j]==B){
				for(int l=Y+1;l<j;l++){
					board[X][l]=B;
				}
			}
		
			//North side
			for(i=X-1;i>=0;i--){
				if(board[i][Y]!=A)
					break;
			}
		
			if(board[i][Y]==B){
				for(int l=X-1;l>i;l--){
					board[l][Y]=B;
				}
			}
		
			//South side
			for(i=X+1;i<8;i++){
				if(board[i][Y]!=A)
					break;
			}
		
			if(board[i][Y]==B){
				for(int l=X+1;l<i;l++){
					board[l][Y]=B;
				}
			}
		
			//Northwest check
			i=X-1;
			j=Y-1;
			while(i>=0 && j>=0){
				if(board[i][j]!=A)
					break;
				i--;
				j--;	
			}
		
			if(board[i][j]==B){
				k=X-1,m=Y-1;
				while(k>i && m>j){
					board[k][m]=B;
					k--;
					m--;	
				}
			}
		
		
			//Northeast check
			i=X-1;
			j=Y+1;
			while(i>=0 && j<8){
				if(board[i][j]!=A)
					break;
				i--;
				j++;	
			}
		
			if(board[i][j]==B){
				k=X-1,m=Y+1;
				while(k>i && m<j){
					board[k][m]=B;
					k--;
					m++;	
				}
			}
		
			//Southwest check
			i=X+1;
			j=Y-1;
			while(i<8 && j>=0){
				if(board[i][j]!=A)
					break;
				i++;
				j--;	
			}
		
			if(board[i][j]==B){
				k=X+1,m=Y-1;
				while(k<i && m>j){
					board[k][m]=B;
					k++;
					m--;	
				}	
			}	
		
			//Southeast check
			i=X+1;
			j=Y+1;
			while(i<8 && j<8){
				if(board[i][j]!=A)
					break;
				i++;
				j++;	
			}
		
			if(board[i][j]==B){
				k=X+1,m=Y+1;
				while(k<i && m<j){
					board[k][m]=B;
					k++;
					m++;	
				}
			}
		
			SetConsoleTextAttribute(color, 14);	
			for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					if(board[i][j]==' ')
						done=0;
		
			if(!done)
				goto begin;
		
			display(board);
		
			for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					if(board[i][j]==A)
						Score_1++;
					else
						Score_2++;
	
			if(Score_1==Score_2)
					cout<<"\n\n\t\t\t Match is Draw";
				else if(Score_1>Score_2)
						cout<<"\n\n\t\t\t\t "<< p1 << " has Won By "<<Score_1-Score_2<<" Congragulations!!!";
					else
			 				cout<<"\n\n\t\t\t\t "<< p2 << " has won by "<<Score_2-Score_1<<" Congragulations!!!";
			
			// Create a text file
  			ofstream Writescore("ScoreBoard.txt");

  			// Write to the file
  			if(Score_1==Score_2)
  					cout<<"Match is Draw";
				else if(Score_1>Score_2) 	
  						Writescore << p1 << " has Won By " << Score_1-Score_2 <<endl;
  					else
							Writescore << p2 <<" has won by " << Score_2-Score_1 <<endl;	
 
 			// Close the file
  			Writescore.close();
			
			goup: 
			cout<<"\n Enter 0 to Goto Manu : ";
			cin>>n;
			
			if (n=='0'){
				goto menu;
			}
			else
				cout<<"\n Invalid Input..... "; 
				goto goup;
			
	}
		
		else if (c==3){
			cout<<"\n\nGood Bye";
		}	
		else {
			cout<<"\n\t!!!Sorry, Invalid Input!!!";
			Sleep(3000);
			goto menu;
		}	
  		return 0;
		
}

void display(char board[8][8]){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	system("Color F");
	system("cls");
		
		cout<<"\t\t\t -----------------------------------------------\n";
		cout<<"\t\t\t -------------       REVERSI       -------------\n";
		cout<<"\t\t\t -----------------------------------------------\n"<<endl;
	
	SetConsoleTextAttribute(color, 6);
	for(int a=0;a<8;a++){
		cout<<"\n\t\t\t        ---------------------------------\n";
		SetConsoleTextAttribute(color, 4);
		cout<<"\t\t\t      "<<a+1;
		for(int b=0;b<8;b++){
			SetConsoleTextAttribute(color, 6);
			cout<<" | "<<board[a][b];	
		}
		cout<<" | ";
	}	
		SetConsoleTextAttribute(color, 6);
		cout<<"\n\t\t\t        ---------------------------------\n";
		SetConsoleTextAttribute(color, 4);
		cout<<"\t\t\t          A   B   C   D   E   F   G   H\n";
}