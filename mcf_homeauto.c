# include <regx51.h>
# define LCDPort P0
sbit RS=P2^2;
sbit RW=P2^1;
sbit EN=P2^0;
sbit F=P2^7;
sbit FI=P1^1;
sbit FO=P2^5;
sbit LI=P1^2;
sbit LO=P2^6;
unsigned int test=-1;
unsigned char i,k=0;
unsigned char c;
unsigned char hr ,hr1=0;
unsigned char min,min1=0;
unsigned char sec,sec1=0;
char A[]="No  Of  People  in  Room    ";
char fo[]=" FanOn";
char fof[]=" FanOff";
char lo[]=" LightOn";
char lof[]=" LightOff";
unsigned char x=0;
unsigned char z1,z2,z3,t1,t2,t3;
		 void delay(int t)
     {
	        int i;
		while(t>0)
		  {
		    i=1275;
			while(i>0) i--;
			t--;
		  }
	 } void delay1(int t)
     {
	        int i;
		while(t>0)
		  {
		    i=10;
			while(i>0) i--;
			t--;
		  }
	 }
  void LCDCommand(unsigned char Value)
     {
	        RS=0;
		RW=0;
		LCDPort=Value;
		EN=1;
		delay(0);
		EN=0;
		return;
	}

 void LCDData(unsigned char Value)
     {
	        RS=1;
		RW=0;
		LCDPort=Value;
		EN=1;
		delay1(1);
		EN=0;
		return;
	}
 void LCDInit()
    {
	  LCDCommand(0x38);
	  LCDCommand(0x06);
	  LCDCommand(0x0c);
	  LCDCommand(0x01);
	}
 LCDPuts(char *s)
    {
	   int i;
	   for(i=0;s[i];i++) LCDData(s[i]);
     	}
		LCDint(test)
		{
	char c[]={48,49,50,51,52,53,54,55,56,57};
			int t1,t2,t3;
		  t3=(test/100);
	     LCDData(c[t3]);
		  	test=test%100;
				t2=(test/10);
		     LCDData(c[t2]);
	        t1=(test%10); 
			     LCDData(c[t1]);
			

			}
		lcd_data_int(int time_val)   
{
int int_amt;
int_amt=time_val/10;
LCDData(int_amt+48);
int_amt=time_val%10; 
LCDData(int_amt+48);
}
void automate()
{
	if(test>0)
{
	if(FI==1 && LI==1)
	{
		FO=1;
	while(fo[x]!='\0')
	{
SBUF=fo[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;
		LO=1;
	while(lo[x]!='\0')
	{
SBUF=lo[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;
		
	}
	
	else if(FI==1)
	{
	FO=1;
	while(fo[x]!='\0')
	{
SBUF=fo[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;
	}
	
	else if(LI==1)
{
	LI=1;
	while(lo[x]!='\0')
	{
SBUF=lo[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;
	
	
}

else if(FI==0 && LI==0)
{
	FO=0;
	while(fof[x]!='\0')
	{
SBUF=fof[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;
		
LO=0;
	while(lof[x]!='\0')
	{
SBUF=lof[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;
		
}
else if (LI==0)
{
	LO=0;
	while(lof[x]!='\0')
	{
SBUF=lof[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;
	
}
else 
{
	FO=0;
	while(fof[x]!='\0')
	{
SBUF=fof[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;
	
}



} 
else
{
	FO=0;
	while(fof[x]!='\0')
	{
SBUF=fof[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;
		
		
			LO=0;
	while(lof[x]!='\0')
	{
SBUF=lof[x];  
while(TI==0);
TI=0;
x++;
    }
	x=0;

}


	}




		void ISR_ex0(void) interrupt 0
{
	 test++;
	LCDCommand(0x01);
		delay1(1);
			LCDPuts("     #People");
	LCDPuts(" ");
	LCDint(test);
	
		if (test==0)
		{
			F=1;
		}
		else if(test>0)
		{
		F=0;
		}
		else
		{
		F=1;
		}
	 
		
		t3=(test/100);
test=test%100;
t2=(test/10);
t1=(test%10); 
z3=t3+48;
z2=t2+48;
z1=t1+48;
		
while(A[x]!='\0')
	{
SBUF=A[x];  
while(TI==0);
TI=0;
x++;
    }
	
SBUF=z3;  
while(TI==0);
TI=0;
		
SBUF=z2;  
while(TI==0);
TI=0;
		
SBUF=z1;  
while(TI==0);
TI=0;

x=0;

automate();
		
}

void ISR_ex1(void) interrupt 2
{
	test--;
	LCDCommand(0x01);
		delay1(1);
		LCDPuts("     #People");
	LCDPuts(" ");
	LCDint(test);
	
		if (test==0)
		{
			F=1;
		}
		else if(test>0)
		{
		F=0;
		}
		else
		{
		F=1;
		}
		t3=(test/100);
test=test%100;
t2=(test/10);
t1=(test%10); 
z3=t3+48;
z2=t2+48;
z1=t1+48;
		
while(A[x]!='\0')
	{
SBUF=A[x];  
while(TI==0);
TI=0;
x++;
    }
	
SBUF=z3;  
while(TI==0);
TI=0;
		
SBUF=z2;  
while(TI==0);
TI=0;
		
SBUF=z1;  
while(TI==0);
TI=0;

x=0;
automate();
}


 void main()
    {
		
              
			IE = 0x95;
			TCON=0x05;
			TMOD=0x20;                                
      TH1=0xFD;                                     
      SCON=0x50;

		
      TR1=1;    
	    LCDInit();
			LCDCommand(0x01);
		  delay(1);
		 	LCDPuts("     #People");
	    LCDPuts(" ");
	     LCDint(test);
			while(1)
			{
		  LCDCommand(0xc0);
		   LCDPuts("Time ");
for(k=0;k<2;k++)
  {
   for(hr=hr1;hr<12;hr++)
   {
    for(min=min1;min<60;min++)
     {
      for(sec=0;sec<60;sec++)
      {
       LCDCommand(0xc0);
       delay(1);
				LCDPuts("Time ");
       lcd_data_int(hr);
      LCDData(':');
       lcd_data_int(min);
       LCDData(':');
       lcd_data_int(sec);
       
       LCDPuts("    ");
      delay(100);
      }
     }
    min1=0;
    }
	 

  }
     
}            
}