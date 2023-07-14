#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
class bankacc
{
	private:unsigned long accno;
		char n[40],typ[40];
	public: float bal;
		void input();
		void display();
		void modify();
		void load();
		void roll()
		{
		int k=500;
		for(int i=0;i<random(k);i++)
		{ cout<<"\\"; delay(100); clrscr();
		 cout<<"|"; delay(100); clrscr();
		 cout<<"/";delay(100);clrscr();
		 cout<<"-";delay(100);clrscr();
		}
		clrscr();
		}
		int getaccno()
		{ return accno; }
		char* getn()
		{ return n; }
};
void bankacc::load()
{
cout<<"\t$$$";delay(50);cout<<"\t\t\t";cout<<"B";delay(500);cout<<"A";delay(400);cout<<"N";delay(700);cout<<"K";delay(100);
cout<<"A";delay(100);cout<<"R";delay(200);cout<<"E";delay(500);cout<<"N";delay(200);
cout<<"A";delay(500);cout<<".";delay(500);cout<<".";delay(500);cout<<".";delay(600);
cout<<".";delay(100);cout<<".";delay(100);cout<<".";delay(600);cout<<" \t\t$$$";getch();
}
void bankacc::input()
{
	cout<<"\n\nEnter Account No.\nName\nType of account (SAVINGS/CURRENT)\nAmount deposited\n\n ";
	cin>>accno;
	gets(n);
	gets(typ);
	cin>>bal;
}
void bankacc::display()
{
	gotoxy(1,7);
	cout<<"Details of CUSTOMER "<<endl;
	cout<<"ACCOUNT NO is  "<<accno<<endl;
	cout<<"NAME is "<<n<<endl;
	cout<<"TYPE OF ACCOUNT is "<<typ<<endl;
	cout<<"BALANCE AMOUNT is "<<bal<<"\n\n\n"<<endl;
}
void bankacc::modify()
{
	char na[60],type[67];
	cout<<"Enter new name\n( * to retain old name)\n";
	gets(na);
	cout<<"Enter new accont type( * to retain old course)\n";
	gets(type);
	if(strcmp(na,"*")!=0)
	strcpy(n,na);
	if(strcmp(type,".")!=0)
	strcpy(typ,type);
}

void main()
{
	textbackground(YELLOW);
	textcolor(RED);
	clrscr();
	bankacc b;
	ofstream ofo;
	ifstream ifo;
	int choice,chh;
	float a;
	char ch,ch1,nam[40];
	b.load();
	clrscr();
	char pass[]="rsvlegend";
	char temp[20];
	char rsv;
	b.roll();
	cout<<"\n\tEnter the password of Bank Management\n";
	for(int i=0;i<strlen(pass);i++)
	{	temp[i]=getch();	cout<<"*";
	}
	temp[i]='\0';
	if(strcmp(pass,temp)==0)
	{
	do
	{
	clrscr();
	cout<<"1.Add a new customer \n";
	cout<<"2.Search for an existing customer's biodata \n";
	cout<<"3.Remove a customer \n";
	cout<<"4.Edit a customer's biodata \n";
	cout<<"5.Deposit on an account"<<endl;
	cout<<"6.Withdraw from an account"<<endl;
	cout<<"7.Display all customer's biodata \n";
	cout<<"8.Exit \n ";
	cout<<"Enter your choice \n";
	cin>>choice;
	switch(choice)
	{
	case 1: ofo.open("bankacc",ios::binary|ios::app);
		do
		{
		clrscr();
		cout<<"Enter details of customer \n"<<endl;
		b.input();
		ofo.write((char*)&b,sizeof(b));
		cout<<"Do you wish to continue \n";
		cin>>ch;
		}while(ch=='Y'||ch=='y');
		ofo.close();
		break;
	  case 2:clrscr();
		int acno;
		do
		{
		ifo.open("bankacc",ios::binary);
		ifo.seekg(0,ios::beg);
		cout<<"\nSEARCH BASED ON \n1ACCOUNT NO.\n2.NAME\n3.EXIT\n ";
		cin>>chh;
		switch(chh)
		{
		case 1: clrscr();
			int flag=0;
			cout<<"Enterthe account no. of customer that you want 2 search \n";
			cin>>acno;
			while(ifo.read((char*)&b,sizeof(b)))
			{
			if(b.getaccno()==acno)
			{
			b.display();
			flag=1;
			}
			}
			ifo.close();
			if(flag!=1)
			cout<<"Required account no. not found\n";
			break;
		case 2: clrscr();
			flag=0;
			cout<<"Enter the name of the customer\n";
			gets(nam);
			while(ifo.read((char*)&b,sizeof(b)))
			{
			if(strcmp(b.getn(),nam)==0)
			{
			b.display();
			flag=1;
			}
			}
			if(!flag)
			cout<<"No customer found under your request\n";
			ifo.close();
			break;
		case 3:exit(0);
		}
		cout<<"Do you wish 2 continue Y/N "<<endl;
		cin>>ch1;
		}while(ch1=='Y'||ch1=='y');
		break;
	case 3: clrscr();
		do
		{
		ofo.open("banka",ios::binary|ios::app);
		ifo.open("bankacc",ios::binary);
		ifo.seekg(0,ios::beg);
		cout<<"Enter ACCOUNT NO that U want 2 DELETE \n";
		cin>>a;
		while(ifo.read((char*)&b,sizeof(b)))
		{
			if(b.getaccno()!=a)
			{
			ofo.write((char*)&b,sizeof(b));
			}
		}
		ifo.close();
		ofo.close();
		remove("bankacc");
		rename("banka","bankacc");
		ifo.open("bankacc",ios::binary);
		while(ifo.read((char*)&b,sizeof(b)))
		{
		b.display();
		}
		ifo.close();
		cout<<"Do you wish to continue \n";
		cin>>ch1;
		}while(ch1=='y'||ch1=='Y');
		break;
	case 4: clrscr();
		fstream fo;
		clrscr();
		do
		{
		fo.open("bankacc",ios::binary|ios::in|ios::out);
		cout<<"Enter the account no. that you want 2 make the modification";
		cout<<endl;
		cin>>a;
		while(fo.read((char*)&b,sizeof(b)))
		{
			if(b.getaccno()==a)
			{
			 b.modify();
			 fo.seekg(fo.tellg()-sizeof(b));
			 fo.write((char*)&b,sizeof(b));
			 }
		}
		cout<<"Do you wish to continue\n";
		cin>>ch1;
		}while(ch1=='Y'||ch1=='y');
		fo.close();
		break;
	case 5: clrscr();
		unsigned long ac;
		float amt;
		cout<<"Enter the account no. to which money need to be deposited\n";
		cin>>ac;
		cout<<"Enter the amount to be depsited\n";
		cin>>amt;
		fo.open("bankacc",ios::binary|ios::in|ios::out);
		while(fo.read((char*)&b,sizeof(b)))
		{
			if(b.getaccno()==ac)
			{
				b.bal+=amt;
			}
		}
		b.display();
		fo.close();
		break;

	case 6: clrscr();
		cout<<"Enter the account from which money need 2 be withdrawn\n";
		cin>>ac;
		cout<<"Enter the amount to be withdrawn\n";
		cin>>amt;
		fo.open("bankacc",ios::binary|ios::in|ios::out);
		while(fo.read((char*)&b,sizeof(b)))
		{
			if(b.getaccno()==ac)
			{
			if(b.bal-amt>0)
			b.bal-=amt;
			else
			cout<<"Not enough money"<<endl;
			}
		 }
		 b.display();
		 fo.close();
		 break;

	case 7: clrscr();
		ifo.open("bankacc",ios::binary);
		while(ifo.read((char*)&b,sizeof(b)))
		{
		b.display();
		}
		ifo.close();
		break;
	case 8: exit(0);
	}
	cout<<"Do you wish to continue the programme \n";
	cin>>rsv;
	clrscr();
	}while(rsv=='Y'||rsv=='y');
	}
	else
	cout<<"\nIncorrect Password\n";
	getch();
}

