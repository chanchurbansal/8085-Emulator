#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define ESC 27

int M[65536];
char A[9];
char B[9];
char C[9];
char D[9];
char E[9];
char H[9];
char L[9];
int carry=0;
int borrow=0;

class instruction
{
protected:
    char code[17];
    char operand[4];
    char register1[2];
    char register2[2];
public:
   // instruction()
   // {
    //}
    void display()
    {

        cout<<code<<" "<<operand<<" "<<register1<<" "<<register2<<endl;
    }
    instruction(char c[17],char op[4],char r1[2],char r2[2])
    {
        strcpy(code,c);
        strcpy(operand,op);
        strcpy(register1,r1);
        strcpy(register2,r2);
    }
    virtual char* gettype()
    {
    }
    char* getoperand()
    {
        return operand;
    }
    char* getcode()
    {
        return code;
    }
    char* getregister1()
    {
        return register1;
    }
    char* getregister2()
    {
        return register2;
    }
};


class byte1:public instruction
{
    char type[7];
public:
    byte1(char c[17],char op[4],char r1[2],char r2[2],char t[7]):instruction(c,op,r1,r2)
    {
            strcpy(type,t);
    }
char* gettype()
{
    return type;
}
};


class byte2:public instruction
{
    char type[7];
public:
    byte2(char c[17],char op[4],char r1[2],char r2[2],char t[7]):instruction(c,op,r1,r2)
    {
            strcpy(type,t);
    }
char* gettype()
{
    return type;
}
};


class byte3:public instruction
{
    char type[7];
public:
    byte3(char c[17],char op[4],char r1[2],char r2[2],char t[7]):instruction(c,op,r1,r2)
    {
            strcpy(type,t);
    }
char* gettype()
{
    return type;
}
};

instruction *ins[250];
int inscount=0;

void initialize()
{   int i,j;
    char code[17];
    char operand[4];
    char register1[2];
    char register2[2];
    char type[7];
    FILE *fp1;
    fp1=fopen("pro1.txt","r");
while(1)
{
    if( feof(fp1) )
      {
         break ;
      }



    fscanf(fp1,"%s %s %s %s %s",code,operand,register1,register2,type);

    if(strcmp("1-BYTE",type)==0)
    {
        byte1 *ty;
        ty=new byte1(code,operand,register1,register2,type);
        ins[inscount++]=ty;

    }
    else if(strcmp("2-BYTE",type)==0)
    {
        byte2 *ty;
        ty=new byte2(code,operand,register1,register2,type);
        ins[inscount++]=ty;

    }
    else if(strcmp("3-BYTE",type)==0)
    {
        byte3 *ty;
        ty=new byte3(code,operand,register1,register2,type);
        ins[inscount++]=ty;
    }
}

    fclose(fp1);

}


int btod(char *bin)
{
    int dec=0;
    int s=strlen(bin)-1;
    for(int i=s;i>=0;i--)
    {
        dec+= ((bin[i]-'0')*(int)pow(2,s-i));
    }
    return dec;
}


char* dtob (int dec)
{
	char bin[9];
	int i=7;
	if(dec<0)
	dec=(-1)*dec;
	dec=dec%256; 
	while(i>=0)
      {
           bin[i]=dec%2+'0';
           i--;
           dec=dec/2;
      }
    bin[8]='\0';
	
    return bin;
}


void addition(int i)
{
	char *r1=ins[i]->getregister1();
	char *r2=ins[i]->getregister2();
	
	if(strcmp(r1,"A")==0)
	{
		int ans=2*btod(A);
		if(ans>255)
		carry=1;
		strcpy(A,dtob(ans));
		
	}
	else if(strcmp(r1,"B")==0)
	{
		int ans=btod(A)+btod(B);
		if(borrow==1&&btod(A)<btod(B))
		{
			int x=btod(B)-btod(A);
			if(x>0)
			borrow=0;
			strcpy(A,dtob(x));	
		}
		else if(ans>255)
		{ 			
			carry=1;
			strcpy(A,dtob(ans));
		}
		else
		strcpy(A,dtob(ans));
	}
	else if(strcmp(r1,"C")==0)
	{
		int ans=btod(A)+btod(C);
		if(borrow==1&&btod(A)<btod(C))
		{
			int x=btod(C)-btod(A);
			if(x>0)
			borrow=0;
			strcpy(A,dtob(x));
		}
		else if(ans>255)
		{
			carry=1;
			strcpy(A,dtob(ans));
		}
		else
		strcpy(A,dtob(ans));
	}
	else if(strcmp(r1,"D")==0)
	{
		int ans;
		
		if(borrow==1&&btod(A)<btod(D))
		{
			int x=btod(D)-btod(A);
			if(x>0)
			borrow=0;
			strcpy(A,dtob(x));
		}
		else if(ans>255)
		{
			carry=1;
			strcpy(A,dtob(ans));
		}
		else
		strcpy(A,dtob(ans));
	}
	else if(strcmp(r1,"E")==0)
	{
		int ans=btod(A)+btod(E);
		if(borrow==1&&btod(A)<btod(E))
		{
			int x=btod(E)-btod(A);
			if(x>0)
			borrow=0;
			strcpy(A,dtob(x));			
		}
		else if(ans>255)
		{
			carry=1;
			strcpy(A,dtob(ans));
		}
		else
		strcpy(A,dtob(ans));
	}
	else if(strcmp(r1,"H")==0)
	{
		int ans=btod(A)+btod(H);
		if(borrow==1&&btod(A)<btod(H))
		{
			int x=btod(H)-btod(A);
			if(x>0)
			borrow=0;
			strcpy(A,dtob(x));			
		}
		else if(ans>255)
		{
			carry=1;
			strcpy(A,dtob(ans));
		}
		else
		strcpy(A,dtob(ans));
	}
	else if(strcmp(r1,"L")==0)
	{
		int ans=btod(A)+btod(L);
		if(borrow==1&&btod(A)<btod(L))
		{
			int x=btod(L)-btod(A);
			if(x>0)
			borrow=0;
			strcpy(A,dtob(x));	
		}
		else if(ans>255)
		{
			carry=1;
			strcpy(A,dtob(ans));
		}
		else
		strcpy(A,dtob(ans));
	}
	else if(strcmp(r1,"M")==0)
    {
        char add[17];
        strcpy(add,H);
        strcat(add,L);
        unsigned int address=btod(add);
        int ans=btod(A)+M[address];
        if(borrow==1&&btod(A)<M[address])
		{
			int x=M[address]-btod(A);
			if(x>0)
			borrow=0;
			strcpy(A,dtob(x));			
		}
		else if(ans>255)
		{
			carry=1;
			strcpy(A,dtob(ans));
		}
		else
		strcpy(A,dtob(ans));
    }
}


void increment(int i)
{
	char *r1=ins[i]->getregister1();
    char *r2=ins[i]->getregister2();
    char *op=ins[i]->getoperand();
    if(strcmp(op,"INR")==0)
    {
    	if(strcmp(r1,"A")==0)
    	{
    		int ans=btod(A)+1;
    		if(ans>255)
			carry=1;
    		strcpy(A,dtob(ans));
		}
		else if(strcmp(r1,"B")==0)
		{
			int ans=btod(B)+1;
			strcpy(B,dtob(ans));
		}
		else if(strcmp(r1,"B")==0)
		{
			int ans=btod(B)+1;
			strcpy(B,dtob(ans));
		}
		else if(strcmp(r1,"C")==0)
		{
			int ans=btod(C)+1;
			strcpy(C,dtob(ans));
		}
		else if(strcmp(r1,"D")==0)
		{
			int ans=btod(D)+1;
			strcpy(D,dtob(ans));
		}
		else if(strcmp(r1,"E")==0)
		{
			int ans=btod(E)+1;
			strcpy(E,dtob(ans));
		}
		else if(strcmp(r1,"H")==0)
		{
			int ans=btod(H)+1;
			strcpy(H,dtob(ans));
			
		}
		else if(strcmp(r1,"L")==0)
		{
			int ans=btod(L)+1;
			strcpy(L,dtob(ans));
		}
		else if(strcmp(r1,"M")==0)
		{
			char add[17];
			strcpy(add,H);
			strcat(add,L);
			unsigned int address=btod(add);
			M[address]=M[address]+1;
		}
}
		else if(strcmp(op,"INX")==0)
		{
			
			if(strcmp(r1,"B")==0)
			{
				int x=btod(C);
				
				if(x==255)
				{
					
					int y=btod(C)+1;
					strcpy(C,dtob(y));
					int ans=btod(B)+1;
					strcpy(B,dtob(ans));
				}
			
				else
				{
					
					int y=btod(C)+1;
					strcpy(C,dtob(y));
				}
			}
			else if(strcmp(r1,"D")==0)
			{
				
				if(btod(E)==255)
				{
					
					int y=btod(E)+1;
					strcpy(E,dtob(y));
					int ans=btod(D)+1;
					strcpy(D,dtob(ans));
				}
				else
				{
					int y=btod(E)+1;
					strcpy(E,dtob(y));
				}	
			}
			else if(strcmp(r1,"H")==0)
			{
				
				if(btod(L)==255)
				{
					int y=btod(L)+1;
					strcpy(L,dtob(y));
					int ans=btod(H)+1;
					strcpy(H,dtob(ans));
				}
				else
				{
					int y=btod(L)+1;
					strcpy(L,dtob(y));
				}
			}
		}
	
}


void subtraction(int i)
{
	char *r1=ins[i]->getregister1();
    char *r2=ins[i]->getregister2();
    char *op=ins[i]->getoperand();
    if(strcmp(r1,"A")==0)
    {
    	int x=0;
    	strcpy(A,dtob(x));
    }
    else if(strcmp(r1,"B")==0)
    {
    	int x=btod(A);
    	int y=btod(B);
    	if(borrow==0)
    	{
    	if(x<y)
    	{
    		x=y-x;
    		borrow=1;
    		strcpy(A,dtob(x));
		}
		else
		{
			x=x-y;
			borrow=0;
			strcpy(A,dtob(x));
		}
		}
		else if(borrow==1)
		{
			x=x+y;
			strcpy(A,dtob(x));	
		}
		
	}
	else if(strcmp(r1,"C")==0)
    {
    	int x=btod(A);
    	int y=btod(C);
    	if(borrow==0)
    	{
    	if(x<y)
    	{
    		x=y-x;
    		borrow=1;
    		strcpy(A,dtob(x));
		}
		else
		{
			x=x-y;
			borrow=0;
			strcpy(A,dtob(x));
		}
		}
		else if(borrow==1)
		{cout<<"aa";
			x=x+y;
			strcpy(A,dtob(x));
		}
	}
	else if(strcmp(r1,"D")==0)
    {
    	int x=btod(A);
    	int y=btod(D);
    	if(borrow==0)
    	{
		if(x<y)
    	{
    		x=y-x;
    		borrow=1;
    		strcpy(A,dtob(x));
		}
		else
		{
			x=x-y;
			borrow=0;
			strcpy(A,dtob(x));
		}
		}
		else if(borrow==1)
		{
			x=x+y;
			strcpy(A,dtob(x));
		}
	}
	else if(strcmp(r1,"E")==0)
    {
    	int x=btod(A);
    	int y=btod(E);
    	if(borrow==0)
    	{
		if(x<y)
    	{
    		x=y-x;
    		borrow=1;
    		strcpy(A,dtob(x));
		}
		else
		{
			x=x-y;
			borrow=0;
			strcpy(A,dtob(x));
		}
		}
		else if(borrow==1)
		{
			x=x+y;
			strcpy(A,dtob(x));
		}
	}
	else if(strcmp(r1,"H")==0)
    {
    	int x=btod(A);
    	int y=btod(H);
    	if(borrow==0)
    	{
		if(x<y)
    	{
    		x=y-x;
    		borrow=1;
    		strcpy(A,dtob(x));
		}
		else
		{
			x=x-y;
			borrow=0;
			strcpy(A,dtob(x));
		}
		}
		else if(borrow==1)
		{
			x=x+y;
			strcpy(A,dtob(x));
		}
		
	}
	else if(strcmp(r1,"L")==0)
    {
    	int x=btod(A);
    	int y=btod(L);
    	if(borrow==0)
    	{
		if(x<y)
    	{
    		x=y-x;
    		borrow=1;
    		strcpy(A,dtob(x));
		}
		else
		{
			x=x-y;
			borrow=0;
			strcpy(A,dtob(x));
		}
		}
		else if(borrow==1)
		{
			x=x+y;
			strcpy(A,dtob(x));
		}
	}
	else if(strcmp(r1,"M")==0)
	{
		int x=btod(A);
		char add[17];
		strcpy(add,H);
		strcat(add,L);
		unsigned int address=btod(add);
		int y=M[address];
		if(borrow==0)
		{
		if(x<y)
		{
			x=y-x;
			borrow=1;
			strcpy(A,dtob(x));
		}
		else
		{
			x=x-y;
			borrow=0;
			strcpy(A,dtob(x));
		}
		}
		else if(borrow==1)
		{
			x=x+y;
			strcpy(A,dtob(x));
		}
	}
}

void decrement(int i)
{
	char *r1=ins[i]->getregister1();
    char *r2=ins[i]->getregister2();
    char *op=ins[i]->getoperand();
    if(strcmp("DCR",op)==0)
    {
    	if(strcmp(r1,"A")==0)
    	{    		
			int ans=btod(A)-1;
			if(borrow==1)
			{
				ans=btod(A)+2;
				strcpy(A,dtob(ans));
			}
			else
			strcpy(A,dtob(ans));    		
		}
		else if(strcmp(r1,"B")==0)
		{
			int ans=btod(B)-1;
			strcpy(B,dtob(ans));
		}
		else if(strcmp(r1,"C")==0)
		{
			int ans=btod(C)-1;
			strcpy(C,dtob(ans));
		}
		else if(strcmp(r1,"D")==0)
		{
			int ans=btod(D)-1;
			strcpy(D,dtob(ans));
		}
		else if(strcmp(r1,"E")==0)
		{
			int ans=btod(E)-1;
			strcpy(E,dtob(ans));
		}
		else if(strcmp(r1,"H")==0)
		{
			int ans=btod(H)-1;
			strcpy(H,dtob(ans));
		}
		else if(strcmp(r1,"L")==0)
		{
			int ans=btod(L)-1;
			strcpy(L,dtob(ans));
		}
		else if(strcmp(r1,"M")==0)
		{
			char add[17];
			strcpy(add,H);
			strcat(add,L);
			int address=btod(add);
			M[address]=M[address]-1;
		}
	}
	else if(strcmp(op,"DCX")==0)
	{
		if(strcmp(r1,"B")==0)
		{
			if(btod(C)==0)
			{
				int ans=btod(C)+255;
				strcpy(C,dtob(ans));
				int x=btod(B)-1;
				strcpy(B,dtob(x));
			}
			else 
			{
				int ans=btod(C)-1;
				strcpy(C,dtob(ans));
			}
			
		}
		else if(strcmp(r1,"D")==0)
		{
			if(btod(E)==0)
			{
				int ans=btod(E)+255;
				strcpy(E,dtob(ans));
				int x=btod(D)-1;
				strcpy(D,dtob(x));
			}
			else 
			{
				int ans=btod(E)-1;
				strcpy(E,dtob(ans));
			}
			
		}
		else if(strcmp(r1,"H")==0)
		{
			if(btod(L)==0)
			{
				int ans=btod(L)+255;
				strcpy(L,dtob(ans));
				int x=btod(H)-1;
				strcpy(H,dtob(x));
			}
			else 
			{
				int ans=btod(L)-1;
				strcpy(L,dtob(ans));
			}
			
		}
	}
}


void mls (int i)
{
    char *r1=ins[i]->getregister1();
    char *r2=ins[i]->getregister2();
    char *op=ins[i]->getoperand();
    if(strcmp("MOV",op)==0)
    {
    if(strcmp(r1,"A")==0)
    {
        if(strcmp(r2,"B")==0)
            strcpy(A,B);
        else if(strcmp(r2,"C")==0)
            strcpy(A,C);
        else if(strcmp(r2,"D")==0)
            strcpy(A,D);
        else if(strcmp(r2,"E")==0)
            strcpy(A,E);
        else if(strcmp(r2,"H")==0)
            strcpy(A,H);
        else if(strcmp(r2,"L")==0)
            strcpy(A,L);
    }
    else if(strcmp(r1,"B")==0)
    {
        if(strcmp(r2,"A")==0)
            strcpy(B,A);
        else if(strcmp(r2,"C")==0)
            strcpy(B,C);
        else if(strcmp(r2,"D")==0)
            strcpy(B,D);
        else if(strcmp(r2,"E")==0)
            strcpy(B,E);
        else if(strcmp(r2,"H")==0)
            strcpy(B,H);
        else if(strcmp(r2,"L")==0)
            strcpy(B,L);
    }

    else if(strcmp(r1,"C")==0)
    {
        if(strcmp(r2,"A")==0)
            strcpy(C,A);
        else if(strcmp(r2,"B")==0)
            strcpy(C,B);
        else if(strcmp(r2,"D")==0)
            strcpy(C,D);
        else if(strcmp(r2,"E")==0)
            strcpy(C,E);
        else if(strcmp(r2,"H")==0)
            strcpy(C,H);
        else if(strcmp(r2,"L")==0)
            strcpy(C,L);
    }

    else if(strcmp(r1,"D")==0)
    {
        if(strcmp(r2,"A")==0)
            strcpy(D,A);
        else if(strcmp(r2,"B")==0)
            strcpy(B,B);
        else if(strcmp(r2,"C")==0)
            strcpy(D,C);
        else if(strcmp(r2,"E")==0)
            strcpy(E,E);
        else if(strcmp(r2,"H")==0)
            strcpy(D,H);
        else if(strcmp(r2,"L")==0)
            strcpy(D,L);
    }

    else if(strcmp(r1,"E")==0)
    {
        if(strcmp(r2,"A")==0)
            strcpy(E,A);
        else if(strcmp(r2,"B")==0)
            strcpy(E,B);
        else if(strcmp(r2,"C")==0)
            strcpy(E,C);
        else if(strcmp(r2,"D")==0)
            strcpy(E,D);
        else if(strcmp(r2,"H")==0)
            strcpy(E,H);
        else if(strcmp(r2,"L")==0)
            strcpy(E,L);
    }

    else if(strcmp(r1,"H")==0)
    {
        if(strcmp(r2,"A")==0)
            strcpy(H,A);
        else if(strcmp(r2,"B")==0)
            strcpy(H,B);
        else if(strcmp(r2,"C")==0)
            strcpy(H,C);
        else if(strcmp(r2,"D")==0)
            strcpy(H,D);
        else if(strcmp(r2,"E")==0)
            strcpy(H,E);
        else if(strcmp(r2,"L")==0)
            strcpy(H,L);
    }

    else if(strcmp(r1,"L")==0)
    {
        if(strcmp(r2,"A")==0)
            strcpy(L,A);
        else if(strcmp(r2,"B")==0)
            strcpy(L,B);
        else if(strcmp(r2,"C")==0)
            strcpy(L,C);
        else if(strcmp(r2,"D")==0)
            strcpy(L,D);
        else if(strcmp(r2,"E")==0)
            strcpy(L,E);
        else if(strcmp(r2,"H")==0)
            strcpy(L,H);
    }

    else if(strcmp(r1,"M")==0)
    {
        char add[17];
        strcpy(add,H);
        strcat(add,L);
        unsigned int address=btod(add);

        if(strcmp(r2,"A")==0)
            M[address]=btod(A);
        else if(strcmp(r2,"B")==0)
            M[address]=btod(B);
        else if(strcmp(r2,"C")==0)
            M[address]=btod(C);
        else if(strcmp(r2,"D")==0)
            M[address]=btod(D);
        else if(strcmp(r2,"E")==0)
            M[address]=btod(E);
        else if(strcmp(r2,"H")==0)
            M[address]=btod(H);
        else if(strcmp(r2,"L")==0)
            M[address]=btod(L);
    }

    if(strcmp(r2,"M")==0)
    {
        char add[17];
        strcpy(add,H);
        strcat(add,L);

        unsigned int address=btod(add);
        char *data=dtob(M[address]);

        if(strcmp(r1,"A")==0)
            strcpy(A,data);
        else if(strcmp(r1,"B")==0)
            strcpy(B,data);
        else if(strcmp(r1,"C")==0)
            strcpy(C,data);
        else if(strcmp(r1,"D")==0)
            strcpy(D,data);
        else if(strcmp(r1,"E")==0)
            strcpy(E,data);
        else if(strcmp(r1,"H")==0)
            strcpy(H,data);
        else if(strcmp(r1,"L")==0)
            strcpy(L,data);
    }
}
	else if(strcmp("LDA",op)==0)
	{
		if(strcmp("B",r1)==0)
			strcpy(A,B);
		else if(strcmp("C",r1)==0)
			strcpy(A,C);
        else if(strcmp("D",r1)==0)
			strcpy(A,D);
		else if(strcmp("E",r1)==0)
			strcpy(A,E);
		else if(strcmp("H",r1)==0)
			strcpy(A,H);
		else if(strcmp("L",r1)==0)
			strcpy(A,L);
		else if(strcmp("M",r1)==0)
			{
				 char add[17];
        		strcpy(add,H);
       			strcat(add,L);
        		unsigned int address=btod(add);
        		char *data=dtob(M[address]);
        		strcpy(A,data);
			}
	}
	else if(strcmp("STA",op)==0)
	{
	
		if(strcmp("B",r1)==0)
			strcpy(B,A);
		else if(strcmp("C",r1)==0)
			strcpy(C,A);
        else if(strcmp("D",r1)==0)
			strcpy(D,A);
		else if(strcmp("E",r1)==0)
			strcpy(E,A);
		else if(strcmp("H",r1)==0)
			strcpy(H,A);
		else if(strcmp("L",r1)==0)
			strcpy(L,A);
		else if(strcmp("M",r1)==0)
			{
				 char add[17];
        		strcpy(add,H);
       			strcat(add,L);
        		unsigned int address=btod(add);
        		M[address]=btod(A);
			}
	}
}


void input()
 {
    char code[17];
    char op[4];

    cout<<"\n\tEnter your 16-bit binary code:- ";
    LOOP:

    cin>>code;
    if(strlen(code)!=16)
    {
        cout<<"\nCode length invalid. Please enter valid instruction : ";
        goto LOOP;
    }
    bool found = false;
    int i;
    for(i=0;i<inscount;i++)
    {
        if(strcmp(ins[i]->getcode(),code)==0)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        ins[i]->display();
        strcpy(op,ins[i]->getoperand());
        if(strcmp(op,"MOV")==0 || strcmp(op,"LDA")==0 || strcmp(op,"STA")==0)
        {
            mls(i);
        }
        else if(strcmp(op,"ADD")==0)
        {
        	addition(i);
		}
		else if(strcmp(op,"INR")==0||strcmp(op,"INX")==0)
		{
			increment(i);
		}
		else if(strcmp(op,"SUB")==0)
		{
			
			subtraction(i);
		}
		else if(strcmp(op,"DCR")==0||strcmp(op,"DCX")==0)
		{
			decrement(i);
		}
    }
    else
    {
        cout<<"\nInvalid Code. Please enter valid instruction : ";
        goto LOOP;
    }
 }

void memory()
{
	char answer;
	int x,y;
	LOOP1:
	cout<<"Do you want to add any value to a different memory address(y/n):-   ";
	answer=getch();
	if(answer=='y'||answer=='Y')
	{
	LOOP:
	cout<<"\nEnter the memory address:- ";
	cin>>x;
	if(x>65535||x<0)
	{
	cout<<"\nPlease,Enter the correct address....\n";
	goto LOOP;
	}
	cout<<"\nEnter the value to be stored in the address "<<x<<":- ";
	cin>>M[x];
//	y=y/256;
//	M[x]=y;
	goto LOOP1;
	}
	else if(answer=='n'||answer=='N')
	{
		cout<<"\n\n\tContinuing.......\n\n";	
	 }
	 else 
	 {
	 	cout<<"\nChoose either y/n....";
	 	goto LOOP1;
	 }
	
}

int main()
{
	int a,i,b,c,d,e,h,l,x;
	char add[17];
cout<<"A :";
    cin>>a;
    if(a<0)
    borrow=1;
strcpy(A,dtob(a));
cout<<"B :";
    cin>>b;
strcpy(B,dtob(b));
cout<<"C :";
    cin>>c;
strcpy(C,dtob(c));
cout<<"D :";
    cin>>d;
strcpy(D,dtob(d));
cout<<"E :";
    cin>>e;
strcpy(E,dtob(e));
cout<<"H :";
    cin>>h;
    h=h%256;
strcpy(H,dtob(h));
cout<<"L :";
    cin>>l;
    l=l%256;
strcpy(L,dtob(l));
strcpy(add,H);
strcat(add,L);
x=btod(add);
// x=(h*100)+l;
cout<<"M :";
	cin>>M[x];
initialize();

char ans;
int j;
memory();
for(i=0;i<inscount;i=i+6)
{	
	cout<<j<<"> "<<ins[i]->getcode()<<" "<<ins[i]->getoperand()<<" "<<ins[i]->getregister1()<<" "<<ins[i]->getregister2()<<"\t"<<j+1<<"> "<<ins[i+3]->getcode()<<" "<<ins[i+3]->getoperand()<<" "<<ins[i+3]->getregister1()<<" "<<ins[i+3]->getregister2();
	cout<<"\n";
	j=j+2;
}

 		cout<<endl<<"A : "<<A<<"\t"<<btod(A)<<endl;
        cout<<"B : "<<B<<"\t"<<btod(B)<<endl;
        cout<<"C : "<<C<<"\t"<<btod(C)<<endl;
        cout<<"D : "<<D<<"\t"<<btod(D)<<"\tSign Flag is:"<<borrow<<endl;
        cout<<"E : "<<E<<"\t"<<btod(E)<<"\tCarry Flag is:"<<carry<<endl;
        cout<<"H : "<<H<<"\t"<<btod(H)<<endl;
        cout<<"L : "<<L<<"\t"<<btod(L)<<endl;
        cout<<"M : "<<dtob(M[x])<<"\t"<<M[x]<<"\n"<<endl;

for(i=0;i<=65535;i++)
{
	if(M[i]!=0)
	cout<<"\n"<<i<<" :- "<<M[i];
}
LOOP:
	
        input();
        cout<<endl<<"A : "<<A<<"\t"<<btod(A)<<endl;
        cout<<"B : "<<B<<"\t"<<btod(B)<<endl;
        cout<<"C : "<<C<<"\t"<<btod(C)<<endl;
        cout<<"D : "<<D<<"\t"<<btod(D)<<"\tSign Flag is:"<<borrow<<endl;
        cout<<"E : "<<E<<"\t"<<btod(E)<<"\tCarry Flag is:"<<carry<<endl;
        cout<<"H : "<<H<<"\t"<<btod(H)<<endl;
        cout<<"L : "<<L<<"\t"<<btod(L)<<endl;
			strcpy(add,H);
			strcat(add,L);
			unsigned int address=btod(add);
        cout<<"M : "<<dtob(M[address])<<"\t"<<M[address]<<"\n"<<endl;
	for(i=0;i<=65535;i++)
{
	if(M[i]!=0)
	cout<<"\n"<<i<<" :- "<<M[i];
}
        cout<<"\nPress any key to continue or ESC to exit : ";
        ans=getch();

if(ans!=ESC){
goto LOOP;
}


       return 0;
}
