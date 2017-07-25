#include<iostream>
#include<fstream>
#include<cstdio>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cmath>
#include<iomanip>

using namespace std;

class Student
{
	public:
	int admno;
	char name[25];
	char address[50];
	char phone[12];
	char Class[12];
	int marks_fapde[3];
	int marks_Ds[3];
	int marks_DM[3];
	int marks_MEA[3];
	int marks_LST[3];
	int marks_BE[3];
	char password[25];
	int m1,m2,sem;
	struct attend
	{
		int dm[2];
        	int ds[2];
        	int lst[2];
        	int fapde[2];
        	int be[2];
        	int mea[2];
	};
	struct attend a[53];
	int b;
	char ch[100000];
	int dsa[2],dma[2],fapde[2],lst[2],mea[2],be[2];
	float total,percentage,cgpa;

	int writevir()
	{
		int i=0;
		while(1)
		{
			cout<<"\nenter :\n1.enter one point.\n2.return.\n";
			int k;
			cin>>k;
			cin.ignore();
			switch(k)
			{
	 		case 1:cout<<"enter point by point \n";
				while(ch[i]!='\0')
	            		i++;
			    	cout<<"enter the student's virtues:";
		    		cin.getline(&ch[i],1000);
		    		while(ch[i]!='\0')
	            		i++;
		        	ch[i]='\n';
				break;
			case 2:return 1;
			default:exit(1);
				break;
			}
		}
	}

	void showvir()
	{
		cout<<ch;
	}

	 void showattendance()
	 {
	     float p;
   	     cout<<setprecision(2)<<fixed<<"Attendance percentage of the student in ds classes is"<<((dsa[1]*1.0/dsa[0])*100)<<"\n";
	     cout<<setprecision(2)<<fixed<<"Attendance percentage of the student in dm classes is"<<((dma[1]*1.0/dma[0])*100)<<"\n";
	     cout<<setprecision(2)<<fixed<<"Attendance percentage of the student in lst classes is"<<((lst[1]*1.0/lst[0])*100)<<"\n";
       	     cout<<setprecision(2)<<fixed<<"Attendance percentage of the student in fapde classes is"<<((fapde[1]*1.0/fapde[0])*100)<<"\n";
       	     cout<<setprecision(2)<<fixed<<"Attendance percentage of the student in be classes is"<<((be[1]*1.0/be[0])*100)<<"\n";
             cout<<setprecision(2)<<fixed<<"Attendance percentage of the student in mea classes is"<<((mea[1]*1.0/mea[0])*100)<<"\n";
             p=(((dsa[1]*1.0/dsa[0])*100)+((dma[1]*1.0/dma[0])*100)+((lst[1]*1.0/lst[0])*100)+((fapde[1]*1.0/fapde[0])*100)+(be[1]*1.0/be[0]*100)+((mea[1]*1.0/mea[0])*100))/6.0;
             cout<<"the students total attendance percentage till now is"<<p<<"\n";
	 }

    void setData()
    {   
	b=0;
	ch[0]='\0';
        dsa[1]=0,dma[1]=0,fapde[1]=0,lst[1]=0,mea[1]=0,be[1]=0;
        dsa[0]=0,dma[0]=0,fapde[0]=0,lst[0]=0,mea[0]=0,be[0]=0;
        cout << "\nEnter admission no. ";
        cin>>admno;
	cin.ignore();
        cout << "\nEnter name of student ";
	cin.getline(name,25);
        cout << "\nEnter phone number ";
	cin>>phone;
	cin.ignore();
	cout << "\nEnter address ";
	cin.getline(address,50);
	cout << "\nEnter class ";
	cin.getline(Class,12);
	for(int i=1;i<=3;i++)
	password[i-1]=name[i-1];
	m1=0,m2=0,sem=0,total=0;
	for(int i=0;i<3;i++)
   	 {
 	        marks_fapde[i]=0;
	        marks_Ds[i]=0;
	     	marks_DM[i]=0;
        	marks_MEA[i]=0;
        	marks_LST[i]=0;
        	marks_BE[i]=0;
        }
    }
	
    void showData()
    {
        cout<<"\nAdmission no. : "<< admno;
        cout<<"\nStudent Name  : "<< name;
	cout<<"\nAddress       : "<<address;
        cout<<"\nphonenumber   : "<<phone;
	cout<<"\nClass         : "<<Class;
    }

    int retAdmno()
    {
        return admno;
    }

    void setnewmarks()
    {
	while(1)
	{
		int n;
		cout<<"\n1.MID_1\n2.MID_2\n3.SEMESTER MAIN EXAM\n4.back\n";
		cin>>n;
		cin.ignore();
		if(n!=1&&n!=2&&n!=3&&n!=4)
		{
			cout<<"\nwrong input,enter again\n";
			continue;
		}
		else if(n==4)
		{
			return;
		}
		else
		{
			cout<<"\n enter marks\n1.FAPDE :";
			cin>>marks_fapde[n-1];
			cout<<"\n2.DS    :";
			cin>>marks_Ds[n-1];
			cout<<"\n3.DM    :";
			cin>>marks_DM[n-1];
			cout<<"\n4.MEA   :";
			cin>>marks_MEA[n-1];
			cout<<"\n5.LST   :";
			cin>>marks_LST[n-1];
			cout<<"\n6.BE    :";
			cin>>marks_BE[n-1];
			cout<<"\nDONE\n";
			cin.ignore();
			if(n==1)
				m1=1;
			if(n==2)
				m2=1;
			if(n==3)
				sem=1;
			if(m1==1&&m2==1&&sem==1)
				Totalpercent();
		}
	}
    }

	void showmarks()
	{
		while(1)
		{
			int n;
			cout<<"\n1.MID_1\n2.MID_2\n3.SEMESTER MAIN EXAM\n4.back\n";
               		cin>>n;
			cin.ignore();
			if(n==4)
			{
				return;
			}
			else if(n!=1&&n!=2&&n!=3&&n!=4)
			{
				cout<<"\nwrong input,enter again";
				continue;
			}
			else
			{
				cout<<"\n1.FAPDE :"<<marks_fapde[n-1];
				cout<<"\n2.DS    :"<<marks_Ds[n-1];
				cout<<"\n3.DM    :"<<marks_DM[n-1];
				cout<<"\n4.MEA   :"<<marks_MEA[n-1];
				cout<<"\n5.LST   :"<<marks_LST[n-1];
				cout<<"\n6.BE    :"<<marks_BE[n-1];
				if(m1==1&&m2==1&&sem==1)
				{
					cout<<"\nTotal   :"<<total<<"\nPercentage:"<<percentage<<"\ncgpa:"<<cgpa;
				}
			}
		}
	}

	 void showmarks_1(int n)
        {

		cout<<"\n1.FAPDE :"<<marks_fapde[n-1];
		cout<<"\n2.DS    :"<<marks_Ds[n-1];
               	cout<<"\n3.DM    :"<<marks_DM[n-1];
                cout<<"\n4.MEA   :"<<marks_MEA[n-1];
               	cout<<"\n5.LST   :"<<marks_LST[n-1];
                cout<<"\n6.BE    :"<<marks_BE[n-1];
               	if(m1==1&&m2==1&&sem==1)
                {
                	cout<<"\n\nTotal   :"<<total<<"\nPercentage:"<<percentage<<"\ncgpa:"<<cgpa;
                }

         }


	void changepassword()
	{
		cout<<"\nenter new password";
		cin>>password;
		cin.ignore();
		cout<<"\nDONE\n";
	}

	void Totalpercent()
	{
		total=0;
		total=total+marks_fapde[0]+marks_Ds[0]+marks_DM[0]+marks_MEA[0]+marks_LST[0]+marks_BE[0];
		total=total+marks_fapde[1]+marks_Ds[1]+marks_DM[1]+marks_MEA[1]+marks_LST[1]+marks_BE[1];
		total=total/2.0;
		total=total+marks_fapde[2]+marks_Ds[2]+marks_DM[2]+marks_MEA[2]+marks_LST[2]+marks_BE[2];
		percentage=total/600.0*100.0;
		float x[6];
		x[0]=(marks_fapde[0]+marks_fapde[1])/2.0 + marks_fapde[2];
		x[1]=(marks_Ds[0]+marks_Ds[1])/2.0 + marks_Ds[2];
		x[2]=(marks_DM[0]+marks_DM[1])/2.0 + marks_DM[2];
		x[3]=(marks_MEA[0]+marks_MEA[1])/2.0 + marks_MEA[2];
		x[4]=(marks_LST[0]+marks_LST[1])/2.0 + marks_LST[2];
		x[5]=(marks_BE[0]+marks_BE[1])/2.0 + marks_BE[2];
		cgpa=(floor(x[0]/10.0)+floor(x[1]/10.0)+floor(x[2]/10.0)+floor(x[3]/10.0)+floor(x[4]/10.0)+floor(x[5]/10.0))*3/18.0;
	}

	void updateattendance1()
	{
		cout<<"\nlast updated week was"<<b<<"th week\n";
	        cout<<"enter the no of classes that were held this week for ds classes    :";
                cin>>a[b].ds[0];
                cin.ignore();
                cout<<"enter the no of classes the student appeared for ds classes        :";
                cin>>a[b].ds[1];
                cin.ignore();
                dsa[0]=dsa[0]+a[b].ds[0];
                dsa[1]=dsa[1]+a[b].ds[1];

	        cout<<"enter the no of classes that were held this week for dm classes    :";
                cin>>a[b].dm[0];
                cin.ignore();
                cout<<"enter the no of classes the student appeared for dm classes        :";
                cin>>a[b].dm[1];
                cin.ignore();
                dma[0]=dma[0]+a[b].dm[0];
                dma[1]=dma[1]+a[b].dm[1];

	        cout<<"enter the no of classes that were held this week for lst classes   :";
                cin>>a[b].lst[0];
                cin.ignore();
                cout<<"enter the no of classes the student appeared for lst classes       :";
                cin>>a[b].lst[1];
                cin.ignore();
                lst[0]=lst[0]+a[b].lst[0];
                lst[1]=lst[1]+a[b].lst[1];

	        cout<<"enter the no of classes that were held this week for fapde classes :";
                cin>>a[b].fapde[0];
                cin.ignore();
                cout<<"enter the no of classes the student appeared for fapde classes     :";
                cin>>a[b].fapde[1];
                cin.ignore();
                fapde[0]=fapde[0]+a[b].fapde[0];
                fapde[1]=fapde[1]+a[b].fapde[1];

	        cout<<"enter the no of classes that were held this week for be classes    :";
                cin>>a[b].be[0];
                cin.ignore();
                cout<<"enter the no of classes the student appeared for be classes        :";
                cin>>a[b].be[1];
                cin.ignore();
                be[0]=be[0]+a[b].be[0];
                be[1]=be[1]+a[b].be[1];

	        cout<<"enter the no of classes that were held this week for mea classes   :";
                cin>>a[b].mea[0];
                cin.ignore();
                cout<<"enter the no of classes the student appeared for mea classes       :";
                cin>>a[b].mea[1];
                cin.ignore();
                mea[0]=mea[0]+a[b].mea[0];
                mea[1]=mea[1]+a[b].mea[1];

                b++;
	}

	void updateattendanceds(int d,int s)
	{
    		a[b].ds[0]=d;
    		a[b].ds[1]=s;
     		dsa[0]=dsa[0]+a[b].ds[0];
                dsa[1]=dsa[1]+a[b].ds[1];
	}

	void updateattendancelst(int d,int s)
	{
    		a[b].lst[0]=d;
    		a[b].lst[1]=s;
     		lst[0]=lst[0]+a[b].lst[0];
                lst[1]=lst[1]+a[b].lst[1];
	}

	void updateattendancefapde(int d,int s)
	{
    		a[b].fapde[0]=d;
    		a[b].fapde[1]=s;
     		fapde[0]=fapde[0]+a[b].fapde[0];
                fapde[1]=fapde[1]+a[b].fapde[1];
	}

	void updateattendancemea(int d,int s)
	{
    		a[b].mea[0]=d;
    		a[b].mea[1]=s;
     		mea[0]=mea[0]+a[b].mea[0];
        	mea[1]=mea[1]+a[b].mea[1];
	}
	
	void updateattendancebe(int d,int s)
	{
    		a[b].be[0]=d;
    		a[b].be[1]=s;
     		be[0]=be[0]+a[b].be[0];
                be[1]=be[1]+a[b].be[1];
	}

	void updateattendancedm(int d,int s)
	{
    		a[b].dm[0]=d;
    		a[b].dm[1]=s;
     		dma[0]=dma[0]+a[b].dm[0];
                dma[1]=dma[1]+a[b].dm[1];
	}

	void modattend()
	{
	        cout<<"last updated week was"<<b<<"th week\n";
        	cout<<"enter the week that you need to modify\n";
        	int k;
        	cin>>k;
        	cin.ignore();
        	cout<<"the classes attended by this student in this week according to subjects is:\n";
        	cout<<"DS:"<<a[k].ds[1]<<" out of "<<a[k].ds[0]<<" classes.\n";
        	cout<<"LST:"<<a[k].lst[1]<<" out of "<<a[k].lst[0]<<" classes.\n";
        	cout<<"DM:"<<a[k].dm[1]<<" out of "<<a[k].dm[0]<<" classes.\n";
        	cout<<"MEA:"<<a[k].mea[1]<<" out of "<<a[k].mea[0]<<" classes.\n";
        	cout<<"FAPDE:"<<a[k].fapde[1]<<" out of "<<a[k].fapde[0]<<" classes.\n";
        	cout<<"BE:"<<a[k].be[1]<<" out of "<<a[k].be[0]<<" classes.\n";

        	while(1)
        	{
        		cout<<"enter :\n1.ds.\n2.dm.\n3.lst.\n4.be.\n5.mea.\n6.fapde.\n7.return";
        		int o;
        		cin>>o;
        		cin.ignore();
        		switch(o)
        		{
                		case 1:cout<<"enter the no of classes attended in ds:\n";
                        		int e,r;
                        		cin>>e;
                        		cout<<"enter the no of classes happened in ds this week:\n:";
                        		cin>>r;
                        		int m,n;
                        		m=a[k].ds[0];
                        		n=a[k].ds[1];
                        		a[k].ds[0]=r;
                        		a[k].ds[1]=e;
                        		dsa[0]=dsa[0]+r-m;
                        		dsa[1]=dsa[1]+e-n;
                        		break;

                		case 2:cout<<"enter the no of classes attended in dm:\n";
                       			cin>>e;
                       			cout<<"enter the no of classes happened in dm this week:\n:";
                       			cin>>r;
                       			m=a[k].dm[0];
                       			n=a[k].dm[1];
                       			a[k].dm[0]=r;
                       			a[k].dm[1]=e;
                       			dma[0]=dma[0]+r-m;
                       			dma[1]=dma[1]+e-n;
                       			break;

                		case 3:cout<<"enter the no of classes attended in lst:\n";
                        		cin>>e;
                        		cout<<"enter the no of classes happened in lst this week:\n:";
                        		cin>>r;
                        		m=a[k].lst[0];
                        		n=a[k].lst[1];
                        		a[k].lst[0]=r;
                        		a[k].lst[1]=e;
                        		lst[0]=lst[0]+r-m;
                        		lst[1]=lst[1]+e-n;

                		case 4:cout<<"enter the no of classes attended in be:\n";
		                        cin>>e;
                		        cout<<"enter the no of classes happened in be this week:\n:";
                        		cin>>r;
                        		m=a[k].be[0];
                        		n=a[k].be[1];
                        		a[k].be[0]=r;
                        		a[k].be[1]=e;
                        		be[0]=be[0]+r-m;
                        		be[1]=be[1]+e-n;

                		case 5:cout<<"enter the no of classes attended in mea:\n";
		                        cin>>e;
                		        cout<<"enter the no of classes happened in mea this week:\n:";
                       		        cin>>r;
                        		m=a[k].mea[0];
                        		n=a[k].mea[1];
		                        a[k].mea[0]=r;
                		        a[k].mea[1]=e;
		                        mea[0]=mea[0]+r-m;
		                        mea[1]=mea[1]+e-n;

                		case 6:cout<<"enter the no of classes attended in fapde:\n";
                        		cin>>e;
		                        cout<<"enter the no of classes happened in fapde this week:\n:";
                		        cin>>r;
		                        m=a[k].fapde[0];
                		        n=a[k].fapde[1];
		                        a[k].fapde[0]=r;
		                        a[k].fapde[1]=e;
		                        fapde[0]=fapde[0]+r-m;
		                        fapde[1]=fapde[1]+e-n;

                		case 7:return;
			}
		}
	}

};



void record_setnewmarks(int n)
{
    fstream file;
    file.open("student1.dat",ios::in | ios::out);

    Student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            obj.setnewmarks();

            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);

            file.write((char*)&obj, sizeof(obj));
        }
    }

    file.close();
}

/*
* function to write in a binary file.
*/

void write_personaldetails_record()
{
    ofstream outFile;
    outFile.open("student1.dat", ios::binary | ios::app);

    Student obj;
    obj.setData();

    outFile.write((char*)&obj, sizeof(obj));
    int j=obj.admno;
    outFile.close();

    record_setnewmarks(j);
}

void modify_marks_record(int n)
{
	int k=-1;
     while(k!=0)
     {

		fstream file;
    		file.open("student1.dat",ios::in | ios::out);

   		 Student obj;
		 k=0;

   	 while(file.read((char*)&obj, sizeof(obj)))
	 {

   	    	 if(obj.retAdmno() == n)
   	         {
           		k=1;
			int y;
			while(1)
			{
				cout<<"\n1.MID_1\n2.MID_2\n3.SEMESTER MAIN EXAM\n4.BACK\n";
				cin>>y;
				cin.ignore();
				if(y!=1&&y!=2&&y!=3&&y!=4)
				{
					cout<<"\nworng input,enter again";
					continue;
				}
				else if(y==4)
				{
					return;
				}
				else
				{
					break;
				}
			}
			int x;
			cout<<"\nprevious details are\n";
			obj.showmarks_1(y);

			cout<<"\nMODIFY\n";
			cout<<"\n1.FAPDE"<<"\n2.DS"<<"\n3.DM"<<"\n4.MEA"<<"\n5.LST"<<"\n6.BE"<<"\n7.back\n";
			cin>>x;
			cin.ignore();
			if(x==1)
			{
				cout<<"\nenter\n";
				cin>>obj.marks_fapde[y-1];
				cin.ignore();
				obj.Totalpercent();
				   int pos = -1 * sizeof(obj);
           				 file.seekp(pos, ios::cur);
           				 file.write((char*)&obj, sizeof(obj));

			}
			else if(x==2)
			{
				cout<<"\nenter\n";
				cin>>obj.marks_Ds[y-1];
				cin.ignore();
				 obj.Totalpercent();
				   int pos = -1 * sizeof(obj);
		        	  file.seekp(pos, ios::cur);
	       		   	 file.write((char*)&obj, sizeof(obj));

			}
			else if(x==3)
                        {
                                cout<<"\nenter\n";
                                cin>>obj.marks_DM[y-1];
				cin.ignore();
				 obj.Totalpercent();
                                   int pos = -1 * sizeof(obj);
                                  file.seekp(pos, ios::cur);
                                 file.write((char*)&obj, sizeof(obj));

                        }
			else if(x==4)
                        {
                                cout<<"\nenter\n";
                                cin>>obj.marks_MEA[y-1];
				cin.ignore();
				 obj.Totalpercent();
                                   int pos = -1 * sizeof(obj);
                                  file.seekp(pos, ios::cur);
                                 file.write((char*)&obj, sizeof(obj));

                        }

			else if(x==5)
                        {
                                cout<<"\nenter\n";
                                cin>>obj.marks_LST[y-1];
				cin.ignore();
				 obj.Totalpercent();
                                   int pos = -1 * sizeof(obj);
                                  file.seekp(pos, ios::cur);
                                 file.write((char*)&obj, sizeof(obj));

                        }
			else if(x==6)
                        {
                                cout<<"\nenter\n";
                                cin>>obj.marks_BE[y-1];
				cin.ignore();
				 obj.Totalpercent();
                                   int pos = -1 * sizeof(obj);
                                  file.seekp(pos, ios::cur);
                                 file.write((char*)&obj, sizeof(obj));

                        }
			else if(x==7)
			{
				return ;
			}
			else
			{
				cout<<"\nwrong input";

       		      	}

		}
		else if(k==0)
		{
			continue;

		}

 	   }

    	file.close();
	}
	if(k==0)
	{
		cout<<"\nnot found";
	}
}

void modify_details_record(int n)
{
     int k=-1;
     while(k!=0)
     {
                 fstream file;
                 file.open("student1.dat",ios::in | ios::out);
                 Student obj;
                 k=0;
         while(file.read((char*)&obj, sizeof(obj)))
         {
                 if(obj.retAdmno() == n)
                 {
                        k=1;
                        int x;
                        cout<<"\nprevious details are\n";
                        obj.showData();
                        cout<<"\nMODIFY\n";
                        cout<<"\n1.NAME"<<"\n2.ADDRESS"<<"\n3.PHONE NUMBER"<<"\n4.CLASS"<<"\n5.BACK\n";
                        cin>>x;
			cin.ignore();
                        if(x==1)
                        {
                                cout<<"\nenter\n";
				cin.getline(obj.name,24);
                                int pos = -1 * sizeof(obj);
                                file.seekp(pos, ios::cur);
                                file.write((char*)&obj, sizeof(obj));
			}
			else if(x==2)
                        {
                                cout<<"\nenter\n";
				cin.getline(obj.address,49);
                                int pos = -1 * sizeof(obj);
                                file.seekp(pos, ios::cur);
                                file.write((char*)&obj, sizeof(obj));
                        }
			else if(x==3)
                        {
                                cout<<"\nenter\n";
                                cin>>obj.phone;
				cin.ignore();
                                int pos = -1 * sizeof(obj);
                                file.seekp(pos, ios::cur);
                                file.write((char*)&obj, sizeof(obj));
                        }
			else if(x==4)
                        {
                                cout<<"\nenter\n";
                                cin.getline(obj.Class,11);
                                int pos = -1 * sizeof(obj);
                                file.seekp(pos, ios::cur);
                                file.write((char*)&obj, sizeof(obj));
                        }
			else if(x==5)
			{
				return;
			}
			else
			{
				cout<<"\nwrong input";
			}
		}

		else if(k==0)
		{
			continue;
		}
   	}

	file.close();
     }

     if(k==0)
     {
	cout<<"\nnot found";
     }
}

int search(int n,char pass[25])
{
      ifstream inFile;
    inFile.open("student1.dat", ios::binary);

    Student obj;
	int i;
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
	{
         	for( i=0;pass[i]!='\0'||obj.password[i]!='\0';i++)
		{
			if(pass[i]!=obj.password[i])
			{
				return 0;
			}
		}
		if(pass[i]=='\0'&&obj.password[i]=='\0')
			return 1;
		else
			return 0;
        }
    }

    inFile.close();
}

Student search_display(int n)
{
    ifstream inFile;
    inFile.open("student1.dat", ios::binary);

    Student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            obj.showData();
		return obj;
        }
    }

    inFile.close();
}

void modify_password(int n)
{
    fstream file;
    file.open("student1.dat",ios::in | ios::out);

    Student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            obj.changepassword();

            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);

            file.write((char*)&obj, sizeof(obj));
        }
    }

    file.close();
}

int numberofrecords()
{
	int i=0;
	fstream fmp;
	Student obj;
	fmp.open("student1.dat",ios::in|ios::out);
	while(fmp.read((char*)&obj,sizeof(obj)))
	{
		i++;
	}
	fmp.close();
	return i;
}

void print_details_to_file()
{
	fstream file,fp;
	file.open("student1.dat",ios::in|ios::out);
	fp.open("Details.txt",ios::in|ios::out);
	Student obj;
	while(file.read((char*)&obj,sizeof(obj)))
	{
		fp<<obj.admno<<"   "<<setw(25)<<obj.name<<"   "<<setw(10)<<obj.phone<<"   "<<setw(25)<<obj.address<<"\n";
	}
	file.close();
	fp.close();
}

void print_marks_to_file()
{
        fstream file,fp;
        file.open("student1.dat",ios::in|ios::out);
        fp.open("Marks.txt",ios::in|ios::out);
        Student obj;
        while(file.read((char*)&obj,sizeof(obj)))
        {
		fp<<"\n\n";
		if(obj.m1==1&&obj.m2==1&&obj.sem==1)
		{
                	fp<<obj.admno<<"\n"<<obj.name<<"\n"<<"\n";
			fp<<"SUBJECT"<<"         "<<"MID 1 "<<"MID 2 "<<"SEM "<<"TOTAL\n";

		        fp<<setw(7)<<left<<"FAPDE"<<"         "<<setw(6)<<obj.marks_fapde[0]<<setw(6)<<obj.marks_fapde[0]<<setw(4)<<obj.marks_fapde[2]<<setw(5)<<(obj.marks_fapde[0]+obj.marks_fapde[1])/2.0+obj.marks_fapde[2]<<"\n";

			 fp<<setw(7)<<left<<"DS"<<"         "<<setw(6)<<obj.marks_Ds[0]<<setw(6)<<obj.marks_Ds[0]<<setw(4)<<obj.marks_Ds[2]<<setw(5)<<(obj.marks_Ds[0]+obj.marks_Ds[1])/2.0+obj.marks_Ds[2]<<"\n";

			fp<<setw(7)<<left<<"DM"<<"         "<<setw(6)<<obj.marks_DM[0]<<setw(6)<<obj.marks_DM[0]<<setw(4)<<obj.marks_DM[2]<<setw(5)<<(obj.marks_DM[0]+obj.marks_DM[1])/2.0+obj.marks_DM[2]<<"\n";

			fp<<setw(7)<<left<<"MEA"<<"         "<<setw(6)<<obj.marks_MEA[0]<<setw(6)<<obj.marks_MEA[0]<<setw(4)<<obj.marks_MEA[2]<<setw(5)<<(obj.marks_MEA[0]+obj.marks_MEA[1])/2.0+obj.marks_MEA[2]<<"\n";

			fp<<setw(7)<<left<<"LST"<<"         "<<setw(6)<<obj.marks_LST[0]<<setw(6)<<obj.marks_LST[0]<<setw(4)<<obj.marks_LST[2]<<setw(5)<<(obj.marks_LST[0]+obj.marks_LST[1])/2.0+obj.marks_LST[2]<<"\n";

			fp<<setw(7)<<left<<"BE"<<"         "<<setw(6)<<obj.marks_BE[0]<<setw(6)<<obj.marks_BE[0]<<setw(4)<<obj.marks_BE[2]<<setw(5)<<(obj.marks_BE[0]+obj.marks_BE[1])/2.0+obj.marks_BE[2]<<"\n";

			fp<<"TOTAL MARKS:"<<obj.total<<" percentage:"<<obj.percentage<<" CGPA:"<<obj.cgpa<<"\n";
		}
        }
        file.close();
        fp.close();
}


void print_ranks()
{
	int x=numberofrecords();
        fstream file,fp;
        file.open("student1.dat",ios::in|ios::out);
        fp.open("Ranks_Total.txt",ios::in|ios::out);
        Student obj[x];
	int i=0;
        while(file.read((char*)&obj[i],sizeof(obj[i])))
	{
		i++;
	}
	for(i=0;i<x-1;i++)
	{
		for(int j=0;j<x-i-1;j++)
		{
			if(obj[j].total<obj[j+1].total)
			{
				Student temp;
				temp=obj[j+1];
				obj[j+1]=obj[j];
				obj[j]=temp;
			}
		}
	}

	fp<<"\nRANK  "<<"ADMNO  "<<setw(25)<<left<<"NAME"<<"  "<<"TOTAL  "<<"CGPA\n\n";

	for(i=0;i<x;i++)
	{
		fp<<setw(6)<<left<<i+1<<setw(7)<<obj[i].admno<<setw(27)<<obj[i].name<<setw(7)<<obj[i].total<<setw(5)<<obj[i].cgpa<<"\n";
	}
	file.close();
	fp.close();
}


void display()
{
    ifstream inFile;
    inFile.open("student1.dat", ios::binary);

    Student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData();
	obj.showmarks();
    }

    inFile.close();
}

/*
* function to search and display from binary file
*/

void search(int n)
{
    ifstream inFile;
    inFile.open("student1.dat", ios::binary);

    Student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            obj.showData();
        }
    }

    inFile.close();
}

/*
* function to delete a record
*/

void delete_record(int n)
{
    Student obj;
    ifstream inFile;
    inFile.open("student1.dat", ios::binary);

    ofstream outFile;
    outFile.open("temp1.dat", ios::out | ios::binary);

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() != n)
        {
            outFile.write((char*)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();

    remove("student1.dat");
    rename("temp1.dat", "student1.dat");
}

/*
* function to modify a record
*/

void modify_record(int n)
{
    fstream file;
    file.open("student1.dat",ios::in | ios::out);

    Student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            cout << "\nEnter the new details of student";
            obj.setData();

            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);

            file.write((char*)&obj, sizeof(obj));
        }
    }

    file.close();
}

void attendance(int y)
{
                        fstream file;
                        file.open("student1.dat",ios::in | ios::out);

                        Student obj;

                        while(file.read((char*)&obj, sizeof(obj)))
                        {
                            if(obj.retAdmno() == y)
                            {

                                    obj.updateattendance1();

                                    int pos = -1 * sizeof(obj);
                                    file.seekp(pos, ios::cur);

                                    file.write((char*)&obj, sizeof(obj));
                            }
                        }

                        file.close();
}


void attendancewholeclass()
{
                        int n=numberofrecords();
                        cout<<"how many ds classes took place this week\n";
                        int d;
                        cin>>d;
                        cin.ignore();
                        int s[n];
                        cout<<"enter the number of ds classes attended by  students in the order of thier admnos\n";
                        for(int i=0;i<n;i++)
                        cin>>s[i];
                        cin.ignore();

                        cout<<"how many dm classes took place this week\n";
                        int m;
                        cin>>m;
                        cin.ignore();
                        int dmm[n];
                        cout<<"enter the number of dm classes attended by  students in the order of thier admnos\n";
                        for(int i=0;i<n;i++)
                        cin>>dmm[i];
                        cin.ignore();

                        cout<<"how many lst classes took place this week\n";
                        int l;
                        cin>>l;
                        cin.ignore();
                        int st[n];
                        cin.ignore();
                        cout<<"enter the number of lst classes attended by  students in the order of thier admnos\n";
                        for(int i=0;i<n;i++)
                        cin>>st[i];
                        cin.ignore();

                        cout<<"how many fapde classes took place this week\n";
                        int f;
                        cin>>f;
                        cin.ignore();
                        int fa[n];
                        cout<<"enter the number of fapde classes attended by  students in the order of thier admnos\n";
                        for(int i=0;i<n;i++)
                        cin>>fa[i];
                        cin.ignore();

                        cout<<"how many mea classes took place this week\n";
                        int e;
                        cin>>e;
                        cin.ignore();
                        int ea[n];
                        cout<<"enter the number of mea classes attended by  students in the order of thier admnos\n";
                        for(int i=0;i<n;i++)
                        cin>>ea[i];
                        cin.ignore();

                        cout<<"how many be classes took place this week\n";
                        int b;
                        cin>>b;
                        cin.ignore();
                        int bel[n];
                        cout<<"enter the number of mea classes attended by  students in the order of thier admnos\n";
                        for(int i=0;i<n;i++)
                        cin>>bel[i];
                        cin.ignore();

                        fstream file;
                        file.open("student1.dat",ios::in | ios::out);
                        Student obj;
                        int i=0;
                        while(file.read((char*)&obj, sizeof(obj)))
                        {
                                        obj.updateattendanceds( d,s[i]);
                                        obj.updateattendancedm( m, dmm[i]);
                                        obj.updateattendancelst(l,st[i]);
                                        obj.updateattendancefapde(f,fa[i]);
                                        obj.updateattendancebe( b, bel[i]);
                                        obj.updateattendancemea(e,ea[i]);

                                        obj.b+=1;
                                        int pos = -1 * sizeof(obj);
                                        file.seekp(pos, ios::cur);
                                        file.write((char*)&obj, sizeof(obj));
                                        i++;
                        }
                        file.close();
}

void showatt()
{
    cout<<"enter the students admno:\n";
    int y;
    cin>>y;
    cin.ignore();
    fstream file;
    file.open("student1.dat",ios::in | ios::out);
    Student obj;
    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == y)
        {

            obj.showattendance();
        }
    }
    file.close();
}

void modifyattend(int j)
{
    cin.ignore();
    fstream file;
    file.open("student1.dat",ios::in | ios::out);
    Student obj;
    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == j)
        {
            obj.modattend();
	    int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);
       	    file.write((char*)&obj,sizeof(obj));
        }
    }
    file.close();
}

void writevirtues(int j)
{
    fstream file;
    file.open("student1.dat",ios::in | ios::out);
    Student obj;
    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == j)
        {
            int i=obj.writevir();
            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);
   	    file.write((char*)&obj,sizeof(obj));
        }
    }
    file.close();
}

void showvirtues(int j)
{
       
    fstream file;
    file.open("student1.dat",ios::in | ios::out);
    Student obj;
    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == j)
        {
            obj.showvir();
        }
    }
    file.close();
}







int main()
{
  int no=0;
  int m,n,o=0,p,q,xy;
  char pass[25];
  string adminpass;

  while(1)
  {
    cout<<"\n1.Student login";
    cout<<"\n2.Admin login\n3.Exit\n";
    cin>>m;
    cin.ignore();
    switch(m)
    {
      case 1:cout<<"\nenter roll number\n";
      	     cin>>n;
             cin.ignore();
      	     cout<<"\nenter password";
      	     cin.getline(pass,25);
      	     if(search(n,pass))
      	     {
             	cout<<"           WELCOME        \n ";
	     	Student obj=search_display(n);
		while(o!=1)
		{
	  		cout<<"\n\n1.Show marks\n2.Change password\n3.show attendance\n4.Virtues\n5.Exit\n";
	  		cin>>p;
	  		cin.ignore();
	  		switch(p)
	  		{
	    			case 1:obj.showmarks();
	           			break;
	    			case 2:modify_password(n);
		   			break;
            			case 3:obj.showattendance();
            	    			break;
				case 4:showvirtues(n);
					break;
	    			case 5:o=1;
		   			break;
	    			default:exit(1);
	  		}
        	}
      	    }
	
     	    else
            {
      		  cout<<"wrong password";
		  exit(1);
      	    }
		break;

      case 2:cout<<"\nenter password :";
	     cin>>adminpass;
	     if(adminpass=="password")
	     {
	       while(1)
	       {
		 no=numberofrecords();
                 cout<<"\n\t\t\t\t\t\t          WELCOME\n";
                 cout<<"\n\n\t\t\t\t\t\tNumber of records:"<<no<<endl;
                 cout<<"\n\t\t\t\t\t\t1.New set of records\n\t\t\t\t\t\t2.Show Details&Marks of student\n\t\t\t\t\t\t3.Modify details\n\t\t\t\t\t\t4.Modify Marks\n\t\t\t\t\t\t5.print details to file\n\t\t\t\t\t\t6.print marks to file\n\t\t\t\t\t\t7.print ranks\n\t\t\t\t\t\t8.Attendance\n\t\t\t\t\t\t9.Virtues\n\t\t\t\t\t\t10.Exit\n";

		 cin>>q;
		 cin.ignore();
		 switch(q)
		 {
		   case 1:int x;
			  cout<<"\nenter number of records\n";
			  cin>>x;
			  cin.ignore();
			  for(int j=1;j<=x;j++)
			  {
			    write_personaldetails_record();
			  }
			  break;
		   case 2:display();
			  break;
	           case 3:int n1;
		   	  cout<<"\nenter roll number";
		          cin>>n1;
			  cin.ignore();
			  modify_details_record(n1);
			  break;
		   case 4:int n2;
			  cout<<"\nenter roll number";
			  cin>>n2;
			  cin.ignore();
			  modify_marks_record(n2);
			  break;
		   case 5:print_details_to_file();
				break;
		   case 6:print_marks_to_file();
				break;
		   case 7:print_ranks();
				break;
            	   case 8:cout<<"the class has "<<no<<" no of students\n";
                    	  cout<<"enter\n\n1.to update a single student's attendance\n2.to update whole class attendance\n3.show attendance\n4.modify attendance\n5.exit\n";
                    	
			int j;
                    	cin>>j;
                    	cin.ignore();
                    	switch(j)
                    	{
                       	 case 1:cout<<"enter the admno of the student:";
                                int h;
                                cin>>h;
                                cin.ignore();
                       	        attendance(h);
                       	        break;
                       	 case 2:attendancewholeclass();
                                break;
                       	 case 3:showatt();
                                break;
			 case 4:cout<<"enter the admno of the student:\n";
                                cin>>h;
            		        modifyattend(h);
				break;
                       	 case 5:exit(1);
                                break;
                       	 default:exit(1);
                   	 }
				break;

             	   case 9: xy=0;
			  while(xy==0)
			  {
				cout<<"\nEnter:\n1.To update virtues.\n2.Show virtues.\n3.Exit\n";
				int q;
				cin>>q;
				cin.ignore();
				switch(q)
				{
					int h;
					case 1:cout<<"enter the admno of the student:";
                                               cin>>h;
                            		       cin.ignore();
					       writevirtues(h);
 	                     		       break;
					case 2:cout<<"enter the admno of the student:";
                          	    	       cin>>h;
                            	   	       cin.ignore();
					       showvirtues(h);
					       break;
					case 3:xy=1;
					       break;
					default:exit(1);
				}
			  }
			  break;

		   case 10:exit(1);
                  }
	       }
	    }
   	default:exit(1);
    }
  }
}



