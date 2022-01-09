#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
void animator(char *txt){
	while (*txt){
	if(*txt==' ')
	cout<<' ';
	else{
	
		cout<<*txt;
		Sleep(45);
		}
	*txt++;}
};

void menu(){
	cout<<"                     Which Operation you want to apply";Sleep(230);cout<<endl;
	cout<<"                        -> For ADDITION        Press 1";Sleep(230);cout<<endl;
	cout<<"                        -> For SUBTRACTION     Press 2";Sleep(230);cout<<endl;
	cout<<"                        -> For MULTIPLICATION  Press 3";Sleep(230);cout<<endl;
	cout<<"                        -> For DETERMINANT     Press 4";Sleep(230);cout<<endl;
	cout<<"                        -> For TRANSPOSE       Press 5";Sleep(230);cout<<endl;
	cout<<"                        -> For Adjoint         Press 6";Sleep(230);cout<<endl;
	cout<<"                        -> For Exit            Press 7";Sleep(230);cout<<endl;
	cout<<"                           You Pressed  :  ";
	
};
void direct_menu(){
	cout<<"                     Which Operation you want to apply\n"<<endl;
	cout<<"                         For ADDITION        Press 1"<<endl;
	cout<<"                         For SUBTRACTION     Press 2"<<endl;
	cout<<"                         For MULTIPLICATION  Press 3"<<endl;
	cout<<"                         For DETERMINANT     Press 4"<<endl;
	cout<<"                         For TRANSPOSE       Press 5"<<endl;
	cout<<"                         For Adjoint         Press 6"<<endl;
	cout<<"                         For Exit            Press 7"<<endl;
	cout<<"       \n                You Pressed  :  ";
	
};
int main(){
	system("color 0A");
	int num;
	char ch = 'n';
	
	cout<<"________________________________________________________________________________"<<endl;
	animator("                         *****WELCOME TO MATRIX CALCULATOR*****     ");cout<<endl;
	cout<<"________________________________________________________________________________"<<endl;
	menu();
	do
	{
	if(ch!='n')
	{
	system("cls");
	direct_menu();
	}
	cin>>num;
	cout<<endl;
int A[10][10],B[10][10],C[10][10],matrix[10][10],transpose[10][10],i,j,k,m,n,r1,c1,r2,c2,adj[10][10];
		switch (num){
		case (1):
		
		cout<<"\t\t You Selected ADDITION OPERATION \n"<<endl;
cout<<"Enter Order of Matrices"<<endl;
cout<<"Enter Number of Rows   : ";
cin>>m;
cout<<"Enter Number of Column : ";
cin>>n;
cout<<"\nEnter Matrix A : "<<endl;
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
{   
    cin>>A[i][j];
	}
	  }	
cout<<"\nEnter Matrix B : "<<endl;
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)   {   
 cin>>B[i][j];}  }	
for(i=0;i<m;i++){  
for(j=0;j<n;j++) {
C[i][j]=A[i][j]+B[i][j];  
}
}
cout<<"\n\nMatrix A ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<A[i][j];
cout<<"\t";}
cout<<endl;}

cout<<"\nMatrix B ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<B[i][j];
cout<<"\t";}
cout<<endl;}

cout<<"\n\nSum of Matrix A & B ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<C[i][j];
cout<<"\t";}
cout<<endl;}
break;
case (2):
	cout<<"\t\t You Selected SUBRACTION OPERATION"<<endl;
	cout<<"\nEnter Order of Matrices"<<endl;
cout<<"Enter Number of Rows   : ";
cin>>m;
cout<<"Enter Number of Column : ";
cin>>n;

cout<<"\nEnter Matrix A : "<<endl;
for(i=0;i<m;i++){ 
  for(j=0;j<n;j++)  { 
   cin>>A[i][j];
}
}	
cout<<"\nEnter Matrix B : "<<endl;
for(i=0;i<m;i++){  
for(j=0;j<n;j++) {
    cin>>B[i][j];
}
}	

for(i=0;i<m;i++){
for(j=0;j<n;j++) {
C[i][j]=A[i][j]-B[i][j];  
}
}
cout<<"\n\nMatrix A ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<A[i][j];
cout<<"\t";}
cout<<endl;}

cout<<"\nMatrix B ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<B[i][j];
cout<<"\t";}
cout<<endl;
}
cout<<"\n\nDifference of Matrix A & B ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<C[i][j];
cout<<"\t";}
cout<<endl;}
break;
case (3):
	cout<<"\t\t You Selected MULTIPLICATION OPERATION\n"<<endl;
	cout<<"\nEnter Order of Matrix A"<<endl;
cout<<"Enter Number of Rows   : ";
cin>>r1;
cout<<"Enter Number of Column : ";
cin>>c1;

cout<<"\nEnter Order of Matrix B"<<endl;
cout<<"Enter Number of Rows   : ";
cin>>r2;
cout<<"Enter Number of Column : ";
cin>>c2;

if(c1==r2)
{
cout<<"\nEnter Matrix A : "<<endl;
for(i=0;i<r1;i++){   
for(j=0;j<c1;j++){
    cin>>A[i][j];
}
}	

cout<<"\nEnter Matrix B : "<<endl;
for(i=0;i<r2;i++){ 
for(j=0;j<c2;j++){
cin>>B[i][j];
} 
}	

for(i=0;i<r1;i++){
	for(j=0;j<c2;j++){
		C[i][j]=0;
	}
	}
for(i=0;i<r1;i++){
	for(j=0;j<c2;j++){
		for(k=0;k<c1;k++){
			C[i][j]+=(A[i][k]*B[k][j]);
		}
	}
}
cout<<"\n\nMatrix A="<<endl;
for(i=0;i<r1;i++){
for(j=0;j<c1;j++){ 
cout<<A[i][j];
cout<<"\t";}
cout<<endl;}

cout<<"\n\nMatrix B="<<endl;
for(i=0;i<r2;i++){
for(j=0;j<c2;j++){ 
cout<<B[i][j];
cout<<"\t";}
cout<<endl;}
cout<<"\n\nMultiplication of Matrix A & B ="<<endl;
for(i=0;i<r1;i++){
for(j=0;j<c2;j++){ 
cout<<C[i][j];
cout<<"\t";}
cout<<endl;}

}
else{
	cout<<"\n\nMultiplication is not possible\n"<<endl;
}
break;
case (4):
	cout<<"\t\t You Selected DETERMINANT OPERATION \n"<<endl;
	cout<<"\nFor Determinant Please Input Square Matrix of Type 2*2 or 3*3 only \n "<<endl;
	cout<<"Enter the number of Rows   : ";
	cin>>m;
	cout<<"Enter the number of Column : ";
	cin>>n;
	if(m==n){
	if(m==2 && n==2){
	cout<<"\nEnter the Matrix"<<endl;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>A[i][j];
		}
    }
	cout<<"\n\nMatrix ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<A[i][j];
cout<<"\t";}
cout<<endl;}
			cout<<"\nDeterminant ="<<(A[0][0]*A[1][1]-A[0][1]*A[1][0])<<endl;
			 
		}
			else if(m==3 && n==3){
		cout<<"Enter the Matrix"<<endl;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>A[i][j];
		}
	}
	cout<<"\n\nMatrix ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<A[i][j];
cout<<"\t";}
cout<<endl;}
			float b=((A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]))-(A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]))+(A[0][2])*(A[1][0]*A[2][1]-A[1][1]*A[2][0]));
			cout<<"\nDeterminant = "<<b;}
			}
			else cout<<"\n\nSORRY ENTERED MATRIX IS NOT OF TYPE SQUARE MATRIX"<<endl;
break;
case(5):
	cout<<"\t\t You have selected TRANSPOSE OPERATION"<<endl;
		cout<<"\nEnter the number of rows:";
	cin>>m;
	cout<<"Enter the number of coloums:";
	cin>>n;
	cout<<"\nEnter the Matrix:\n";
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++){
			cin>>matrix[i][j] ;
		}		
}
for(i=0; i<m; i++) {
	for(j=0; j<n; j++) 
{
	transpose[j][i]=matrix[i][j]; 
}
}
cout<<"\n\nMatrix ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<matrix[i][j];
cout<<"\t";}
cout<<endl;}
cout<<"\nTranspose of matrix ="<<endl;
for(i=0; i<n; i++){
		
		for(j=0; j<m; j++){
	
		cout<<transpose[i][j]<<"\t";	
	}
	cout<<endl;
	}
break;
case (6):
	cout<<"\t\t You have selected ADJOINT OPERATION\n"<<endl;
cout<<"Enter the matrix of order 2*2 0nly: "<<endl;
	cout<<"\nEnter number of rows     : ";
	cin>>m;
	cout<<"Enter number of coloumns   : ";
	cin>>n;
if(m==2 && n==2){
	cout<<"\nEnter the Matrix = \n"<<endl;
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			cin>>matrix[i][j];
		}
	}
cout<<"\n\nMatrix ="<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++){ 
cout<<matrix[i][j];
cout<<"\t";}
cout<<endl;}
	cout<<"\nAdjoint="<<endl;
for(i=0; i<m; i++){
	for(j=0; j<i; j++){
		cout<<matrix[1][1]<<"\t";
		cout<<-matrix[0][1]<<endl;
		cout<<-matrix[1][0]<<"\t";
		cout<<matrix[0][0]<<endl;
			}
}	
}
else
cout<<"\n\nSorry in this program ADJOINT OPERATION is only for 2*2 ordered matrix"<<endl;
break;
case (7):
	exit(0);
	cout<<"\n\tYou Exit From Matrix Calculator"<<endl;
break;
default:
	cout<<"\n\n You select invalid option"<<endl;
	cout<<"\n Please select valid option \n"<<endl;
}
cout<<"\nThank you for using Matrix Calculator::\n"<<endl;
cout<<"If you want to continue more press any letter other than (n): ";
cin>>ch;
cout<<"\n"<<endl;
}while(ch!='n');
}
