#include<iostream>
#include<fstream>
#include<process.h>
#include<conio.h>
using namespace std;
class hotel
{
	private:
        char name[15];
        int s_no;
        char fname[15];
        char nationality[10];
        long pno;
        char check_in[10];
        char check_out[10];
        int room_charge;
	public:
        void read()
		{
            cout<<"Enter Customer Name\n";
            cin>>name;
            cout<<"Enter serial number\n";
            cin>>s_no;
            cout<<"Enter Father's name\n";
            cin>>fname;
            cout<<"Enter Nationality\n";
            cin>>nationality;
            cout<<"Enter Phone number\n";
            cin>>pno;
            cout<<"Enter Check in date\n";
            cin>>check_in;
            cout<<"Enter Check out date\n";
            cin>>check_out;
            cout<<"Enter room charges\n";
            cin>>room_charge;
		}
        void show()
		{
            cout<<"*************************\n";
            cout<<"Customer's Name-->"<<name<<"\n";
            cout<<"Customer's Serial Number-->"<<s_no<<"\n";
            cout<<"Customer's Father Name-->"<<fname<<"\n";
            cout<<"Customer's Nationality-->"<<nationality<<"\n";
            cout<<"Customer's Phone Number-->"<<pno<<"\n";
            cout<<"Check_in date-->"<<check_in<<"\n";
            cout<<"Check_out date-->"<<check_out<<"\n";
            cout<<"Room charges-->"<<room_charge<<"\n";
            cout<<"*************************"<<"\n";
		}
        int search(int eno)
		{
            if(eno==s_no)
            return 1;
            else
            return 0;
		}
};
int main()
{
	hotel h1;
	int customer_no;
	char ch1='y';
    while( ch1=='y'|| ch1=='Y')
	{
        cout<<"1.To add new customer\n";
        cout<<"2.To Retrieve the last added customer\n";
        cout<<"3.To Search for the customer\n";
        cout<<"4.To View all the records\n";
        cout<<"5.To update the record\n";
        cout<<"6.To delete the record\n";
        int opt;
        cout<<"Enter the option\n";
        cin>>opt;
//        switch(opt)
//		{
//            case '1':
        if(opt==1)
        {

                char ch ='y';
                while(ch=='y'||ch=='Y')
                {
                    h1.read();
                    ofstream out("hotel.dat",ios::app|ios::binary);
                    out.write((char *)&h1,sizeof(h1));
                    cout<<"Do you want to add new record?\n";
                    cout<<"Enter y for yes and n for n\n";
                    cin>>ch;
                    out.close();
                }
        }else if(opt==2){
//			break;
//            case '2':
                ifstream in("hotel.dat",ios::binary);
                in.seekg(-66,ios::end);
                in.read((char *)&h1,sizeof(h1));
                h1.show();
                in.close();
        }else if(opt==3){
//			break;
//            case '3':
                int flag=0;
                cout<<"Enter the customer's serial_no to be searched?";
                cin>>customer_no;
                cout<<"Customer's serial_no is --> "<<customer_no<<"\n";
                ifstream in2("hotel.dat",ios::binary);
                if(!in2)
                {
                    cout<<"File cannot open\n";
                }
                in2.seekg(0,ios::beg);
                while(in2.eof()==0)
                {
                    in2.read((char*)&h1,sizeof(h1));
                    int r=h1.search(customer_no);
                    if(r==1)
                    {
                        flag=1;
                        h1.show();
                    }
                }
                if(flag==1)
                    break;
                else
                    cout<<"No Record found";
                in2.close();
        }else if(opt==4){
//            break;
//            case '4':
                ifstream in1("hotel.dat",ios::binary);
                if(!in1)
                {
                    cout<<"File is not present";
                }
                in1.seekg(0,ios::end);
                int p=in1.tellg();
                in1.seekg(0,ios::beg);
                for(int i=0;i<p;i++)
                {
                    in1.read((char*)&h1,sizeof(h1));
                    h1.show();
                    i=i+66;
                }
                in1.close();
        }else if(opt==5){
//			break;
//            case '5':
                int no;
                cout<<"Enter the serial_no to be updated\n";
                cin>>no;
                ifstream in3("hotel.dat",ios::binary);
                ofstream out2("temp.dat",ios::binary);
                in3.seekg(0,ios::end);
                int p1=in3.tellg();
                in3.seekg(0,ios::beg);
                for(int k=0;k<p1;k++)
                {
                    in3.read((char *)&h1,sizeof(h1));
                    int l=0;
                    l=h1.search(no);
                    if(l==1)
                    {
                        cout<<"Before updation\n";
                        h1.show();
                        cout<<"Enter the new details\n";
                        h1.read();
                    }
                    out2.write((char*)&h1,sizeof(h1));
                    k=k+66;
				}
				in3.clear();
			    in3.close();
                out2.close();
                ifstream in4("temp.dat",ios::binary);
                in4.seekg(0,ios::end);
                int p2=in4.tellg();
                in4.seekg(0,ios::beg);
                ofstream out3("hotel.dat",ios::binary);
                for(int j=0;j<p2;j++)
                {
                    in4.read((char *)&h1,sizeof(h1));
                    out3.write((char *)&h1,sizeof(h1));
                    j=j+66;
                }
        }else if(opt==6){
//            break;
//            case '6':
                int s;
                cout<<"Enter the serial no to be deleted\n";
                cin>>s;
                ifstream del("hotel.dat",ios::binary);
                del.seekg(0,ios::end);
                int p3=del.tellg();
                del.seekg(0,ios::beg);
                ofstream t("temp.dat",ios::binary);
                for(int m=0;m<p3;m++)
                {
                    del.read((char *)&h1,sizeof(h1));
                    int b=h1.search(s);
                    if(b==1)
                    {
                        cout<<"Deleted information is:-\n" ;
                        h1.show();
                    }
                    else
                    {
                        t.write((char *)&h1,sizeof(h1));
                    }
                    m=m+66;
                }
                del.clear();
                del.close();
                t.close();
                ifstream t1("temp.dat",ios::binary);
                ofstream t2("hotel.dat",ios::binary);
                t1.seekg(0,ios::end);
                int p4=t1.tellg();
                t1.seekg(0,ios::beg);
                for(int c=0;c<p4;c++)
                {
                    t1.read((char *)&h1,sizeof(h1));
                    t2.write((char *)&h1,sizeof(h1));
                    c=c+66;
                }
        }
        cout<<"Show the menu again?\n";
        cout<<"Enter y for yes and n for no\n";
        cin>>ch1;
	}
	getch();
	return 0;
}
