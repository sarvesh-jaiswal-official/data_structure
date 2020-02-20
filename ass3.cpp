#include<iostream>
using namespace std;
class matrix
{
       int a[10][10],b[10][10],c[10][10];
       int row,colmn;
       public:
       void getdata()
          {
          cout<<"\nEnter the no of rows ";
          cin>>row;
          cout<<"\nEnter the the no of columns";
          cin>>colmn;
         }
   void x()
{
          cout<<"Enter the elements of mat A";
               for(int i=0;i<row;i++)
                  {
                    for(int j=0;j<colmn;j++)
                      {
                        cin>>a[i][j];
                      }
                  }
}
    void y()
{
         cout<<"Enter the elements of mat B";
               for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                          cin>>b[i][j];
                        }
                    }
           
} 
      void add()
           {
		x();
		y();
             int  i,j;
                    for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                          c[i][j]=a[i][j]+b[i][j];
                      
                        }
                    }
			for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                          cout<<"\n"<<c[i][j];
                      
                        }
                    }

           }
            void sub()
{
 		x();
                y();
            int  i,j;
                    for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                          c[i][j]=a[i][j]-b[i][j];
                      
                        }
                    }
			for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                          cout<<"\n"<<c[i][j];
                      
                        }
                    }
}
         void transpose()
{
		x();
               int  i,j;                
			for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                          cout<<"\n"<<a[j][i];
                      
                        }
                    }
 } 
	void uppertriangular()
	{
 	    x();
	    int flag=0;
	    int count=0;
		for(int i=0;i<row;i++)
		{
		for(int j=0;j<colmn;j++)
		{
			if(i>j)
			count++;
			  {
			if (a[i][j]==0)
			flag++;
			  }
		}
		}
              cout<<"\nCount="<<count;
                if(flag<count)
		{
		cout<<"Matrix is not upper triangular";
		}
		else
		{
		cout<<"Matrix is upper triangular";
		}
	}
   void diagadd()
{ 
 		      x();
                      int sum=0;
                      int i,j;    
			for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                          if(i==j)
			   {
                         sum=sum+a[i][j];
                           }                    
                        }
                    }
             cout<<"Sum="<<sum;
}
    void multiply()
	{
          x();
	  y();
       int  i,j,k;   
			for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                          c[i][j]=0;
                      
                        }
                    }
                    for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                       for(int k=0;k<colmn;k++)
			    {
                          c[i][j]=c[i][j]+a[i][k]*b[k][j];
                             }
                        }
                    }
			for(int i=0;i<row;i++)
                    {
                      for(int j=0;j<colmn;j++)
                        {
                          cout<<"\n"<<c[i][j];
                      
                        }
                    }
        }     
};
  
int main()
{
matrix m;
m.getdata();
int ch;
char op;
do
{
cout<<"\n1.Add,2.Subtraction,3.Transpose,4.uppertriangular,5.diagonaladd,6.multiply";
cout<<"Enter the choice";
 cin>>ch; 

switch(ch)
{
 case 1:m.add();
 break;
 case 2:m.sub();
 break;
 case 3:m.transpose();
break;
case 4:m.uppertriangular();
break;
case 5:m.diagadd();
break;
case 6:m.multiply();
break;
 }
cout<<"Do you want to continue?";
cin>>op;
}while(op=='y'||op=='Y');

return 0;
}
