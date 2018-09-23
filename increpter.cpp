#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
 using namespace std;
 int i;
 char confirm[30],		addr[30],		key[30],	a=176;
 COORD coord={0,0};

 void password(char[],char);
 void gotoxy(int,int);
 void reverse(char[]);
 void transform(char[],char);
 void incript();
 void dicript();
 void choice_page();
 void change_pass();
 void log_on();
 void login();
class name
{
	protected:
		char first_name[15];
		char last_name[15];
	public:
		char name[45];
		void f_name()
		{
			cin>>first_name;
		}
		void l_name()
		{
			cin>>last_name;
		}
};


class profile:public name
{
	private:
		char pass[30];
	public:
		int checkpass(char code[30])
		{
			if(strcmp(pass,code)==0)
			return(1);
			else
			return(0);
		}
		void gen_name()
		{
			name[0]='\0';
			strcat(name,first_name);
			strcat(name," ");
			strcat(name,last_name);
		}
		void enter_pass()
		{
			password(pass,'*');
		}
		string give_name()
		{
			return(name);
		}
}person;


 int main()
{
	login();
}

 void gotoxy(int x,int y)						//function to move pointer on console screen
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

 void reverse(char key[])							//function to reverse the required string
{
	char temp;
	int j=strlen(key)-1;
	for(int i=0;i<j;++i,--j)
	{
		temp=key[i];
		key[i]=key[j];
		key[j]=temp;
	}
}


  void transform(char add[30],char key)			//function used to transform given file in unknown form
{
	FILE *fp,*gp;
	char ch,en;
	fp=fopen(add,"r");
		if(fp==NULL)
			printf("File not Found");
	gp=fopen("temp.txt","w");
		while(!feof(fp))
		{
			ch=fgetc(fp);
			en=ch^key;
				if((int)en==26)
					en=en^key;
		 	fputc(en,gp);
		}
	fclose(fp);
	fclose(gp);
	remove(add);
	rename("temp.txt",add);
}

 void incript()									//function to increpte the file
{
	system("cls");
	gotoxy(5,1);
	cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<" Welcome "<<person.give_name()<<" in INCREPTING Software "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
	gotoxy(5,3);
	cout<<"Enter File address to be Encript.:";
	gotoxy(5,5);
	cout<<"Enter Encrepting Passward.:";
	gotoxy(40,3);
	cin>>addr;
	gotoxy(40,5);
	password(key,'*');
	for(i=0;key[i]!='\0';++i)
	transform(addr,key[i]);
}
 void dicript()									//function to decrept the file
{
	system("cls");
	gotoxy(5,1);
	cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<" Welcome "<<person.give_name()<<" in INCREPTING Software "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
	gotoxy(5,3);
	cout<<"Enter File address to be Decript.:";
	gotoxy(5,5);
	cout<<"Enter Dicripting Passward.:";
	gotoxy(40,3);
	cin>>addr;
	gotoxy(40,5);
	password(key,'*');
	reverse(key);
	for(i=0;key[i]!='\0';++i)
	transform(addr,key[i]);
}

 void change_pass()								//function to change the password
{
	FILE *pass;
	x:
	system("cls");
	cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<" FILE INCREPTER "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
	pass=fopen("passcode.dat","wb");
			gotoxy(1,3);
			cout<<"New Password.:";
			gotoxy(1,5);
			cout<<"Confirm Password.:";
			gotoxy(30,3);
			person.enter_pass();
			gotoxy(30,5);
			password(confirm,'*');
			if(person.checkpass(confirm))
			{
				fwrite(&person,sizeof(person),1,pass);
				fclose(pass);
				choice_page();
			}
			else
			{
				fclose(pass);
				goto x;
			}
}
 void choice_page()						//function to make choices in the front page
{
	int choice;
	while(1)
	{
		system("cls");
		gotoxy(5,1);
		cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<" Welcome "<<person.give_name()<<" in INCREPTING Software "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
		gotoxy(5,3);
		cout<<"1.Increpting File";
		gotoxy(5,5);
		cout<<"2.Decrepting File";
		gotoxy(5,7);
		cout<<"3.Change Password";
		gotoxy(5,9);
		cout<<"4.Exit";
		gotoxy(5,11);
		cout<<"Make Your Choice.:";
		gotoxy(30,11);
		cin>>choice;
		switch(choice)
		{
			case 1:incript();											break;
			case 2:dicript();											break;
			case 3:change_pass();										break;
			case 4:exit(0);
			default:cout<<"\n\n!!!!Wrong Choice Selection!!!!";			break;
		}
	}
}

 void log_on()							//function used in logon time
{
	FILE *entry;
	char pass[30];
	entry=fopen("passcode.dat","rb");
	fread(&person,sizeof(person),1,entry);
	system("cls");
	gotoxy(5,1);
	cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<" Welcome "<<person.give_name()<<" in INCREPTING Software "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
	gotoxy(5,3);
	cout<<"Enter Your Passward.:";
	gotoxy(30,3);
	password(pass,'*');
	if(person.checkpass(pass))
	{
		choice_page();
	}
}
 void login()					//functio run first time
{
	FILE *pass;
	x:
	system("cls");
	gotoxy(18,1);
	cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<" FILE INCREPTER "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
	pass=fopen("passcode.dat","rb");
		if(pass==NULL)
		{
			gotoxy(19,3);
			cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<" SIGN UP "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
			gotoxy(1,5);
			cout<<"First Name.:";
			gotoxy(1,7);
			cout<<"Last Name.:";
			gotoxy(1,9);
			cout<<"New Password.:";
			gotoxy(1,11);
			cout<<"Confirm Password.:";
			gotoxy(30,5);
			person.f_name();
			gotoxy(30,7);
			person.l_name();
			gotoxy(30,9);
			person.enter_pass();
			gotoxy(30,11);
			cin>>confirm;
			if(person.checkpass(confirm))
			{
				person.gen_name();
				pass=fopen("passcode.dat","wb");
				fwrite(&person,sizeof(person),1,pass);
				choice_page();
			}
			else
			{
				fclose(pass);
				remove("passcode.dat");
				goto x;
			}
		}
		else
		{
			log_on();
		}
}
void password(char pass[],char x)
{
    int i=0;
    pass[0]=getch();
    cout<<x;
    while((int)pass[i]!=13)
    {
        pass[++i]=getch();
        if((int)pass[i]==8)
        {
            pass[--i]='\0';
            --i;
            cout<<"\b \b";
            continue;
        }
        if((int)pass[i]!=13)
        cout<<x;
    }
    pass[i]='\0';
}
