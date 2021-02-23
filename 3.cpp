#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<stdio.h>
int TCP;
int UDP;
int ICMP;
int ANY;
using namespace std;
void iprules()
{
    cout<<"Enter IP RULES:\n";
    cout<<"TCP:-";
    cin>>TCP;
    cout<<"UDP:-";
    cin>>UDP;
    cout<<"ICMP:-";
    cin>>ICMP;
    cout<<"ANY:-";
    cin>>ANY;
}
void newvm()
{   char c;
    cout<<"\nDo you want to add a new VM?(y\n)\n";
    cin>>c;
    if(c=='y'||c=='Y')
    {
        fstream fout;

    fout.open("vm.csv", ios::out | ios::app);

    cout << "Enter the details of VM:"
         << " SRC_IP DST_IP SERVICE PORT ACTION"
    << endl;

    string SRC_IP,DST_IP,SERVICE,PORT,ACTION;


        cin>>SRC_IP
        >>DST_IP
        >>SERVICE
        >>PORT
        >>ACTION;

        fout << SRC_IP << ", "
             << DST_IP << ", "
             << SERVICE << ", "
             << PORT << ", "
             << ACTION<<"\n";


    }
    else
        return;
}

class ctable
{
public:
    string ipaddr;
    int service;
};
class mtable
{
public:
    int Sr;
    string Src_ip;
    string Des_ip;
    string Service;
    string Port;
    string Action;
};
bool *var[100];
int cnt=0;
mtable *obj[100];
ctable *obj1[100];
void read_record()
{
    for(int z=0; z<100; z++)
    {
        obj[z]=new mtable;
    }

    ifstream ip("vm.csv");

    if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string src_ip;
    string des_ip;
    string service;
    string port;
    string action;

    getline(ip,src_ip,',');
    getline(ip,des_ip,',');
    getline(ip,service,',');
    getline(ip,port,',');
    getline(ip,action,'\n');

    int z=0;

    while(ip.good())
    {

        getline(ip,src_ip,',');
        getline(ip,des_ip,',');
        getline(ip,service,',');
        getline(ip,port,',');
        getline(ip,action,'\n');
        obj[z]->Sr=cnt;
        obj[z]->Src_ip=src_ip;
        obj[z]->Des_ip=des_ip;
        obj[z]->Service=service;
        obj[z]->Port=port;
        obj[z]->Action=action;
        cnt++;
        z++;
    }
    cnt--;
    ip.close();
}

int l=0;
void fun()
{
    int flag=0,value;
    string x,y,all="ALLOW";
    cout<<"Enter Infected VM IP:\n";
    cin>>x;

    for(int i=0; i<cnt; i++)
    {
        if((x.compare(obj[i]->Src_ip)==0)&&((all.compare(obj[i]->Port)==0)||(all.compare(obj[i]->Action)==0)))
        {
            *var[obj[i]->Sr]=1;
            y=obj[i]->Des_ip;
            for(int j=0; j<l; j++)
            {
                if((y.compare(obj1[j]->ipaddr))==0)
                {
                    flag=1;
                    switch(obj[i]->Service[0])
                    {
                    case 'T':
                        value=TCP;
                        break;
                    case 'U':
                        value=UDP;
                        break;
                    case 'I':
                        value=ICMP;
                        break;
                    case 'A':
                        value=ANY;
                        break;
                    }
                    if(value<(obj1[j]->service))
                        obj1[j]->service=value;
                }
            }
            if(flag==0)
            {
                obj1[l]= new ctable;
                obj1[l]->ipaddr=obj[i]->Des_ip;
                switch(obj[i]->Service[0])
                {
                case 'T':
                    obj1[l]->service=TCP;
                    break;
                case 'U':
                    obj1[l]->service=UDP;
                    break;
                case 'I':
                    obj1[l]->service=ICMP;
                    break;
                case 'A':
                    obj1[l]->service=ANY;
                    break;
                }
                l++;
            }
        }

    }
}

void fun2(string x)
{
    int flag=0;
    string all="ALLOW",y;
    int value;
    for(int i=0; i<cnt; i++)
    {
        if((x.compare(obj[i]->Src_ip)==0)&&((all.compare(obj[i]->Port)==0)||(all.compare(obj[i]->Action)==0)))
        {
            *var[obj[i]->Sr]=1;
            y=obj[i]->Des_ip;
            for(int j=0; j<l; j++)
            {
                if((y.compare(obj1[j]->ipaddr))==0)
                {
                    flag=1;
                    switch(obj[i]->Service[0])
                    {
                    case 'T':
                        value=TCP;
                        break;
                    case 'U':
                        value=UDP;
                        break;
                    case 'I':
                        value=ICMP;
                        break;
                    case 'A':
                        value=ANY;
                        break;
                    }
                    if(value<(obj1[j]->service))
                        obj1[j]->service=value;
                }
            }
            if(flag==0)
            {
                obj1[l]= new ctable;
                obj1[l]->ipaddr=obj[i]->Des_ip;
                switch(obj[i]->Service[0])
                {
                case 'T':
                    obj1[l]->service=TCP;
                    break;
                case 'U':
                    obj1[l]->service=UDP;
                    break;
                case 'I':
                    obj1[l]->service=ICMP;
                    break;
                case 'A':
                    obj1[l]->service=ANY;
                    break;
                }
                l++;
            }
        }
    }

}

void fun1()
{
    string z;
    for(int i=0; i<cnt; i++)
    {
        if(*var[i])
        {
            z=obj[i]->Des_ip;
            fun2(z);
        }
    }
}

void fun3()
{
    for(int i=0; i<l; i++)
    {
        cout<<'\n';
        cout<<"IP:"<<obj1[i]->ipaddr<<'\n';
        cout<<"Cost:"<<obj1[i]->service<<'\n';
    }
}

void bubbleSort()
{
    ctable *temp;
    int i, j;
    bool swapped;
    for (i = 0; i < l-1; i++)
    {
        swapped = false;
        for (j = 0; j < l-i-1; j++)
        {
            if (obj1[j]->service> obj1[j+1]->service)
            {
                temp=obj1[j];
                obj1[j]=obj1[j+1];
                obj1[j+1]=temp;
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void fun4()
{
    cout<<'\n'<<"VM(s) (IPs) in descending order of risk are:\n";
    for(int i=0;i<l-1;i++)
    {
        cout<<"("<<obj1[i]->ipaddr<<") "<<"> ";
    }
    cout<<"("<<obj1[l-1]->ipaddr<<") ";
}

int main()
{    iprules();
     newvm();
    read_record();
    for(int i=0; i<cnt; i++)
    {
        var[i]= new bool[cnt];
        *var[i]=0;
    }
    fun();
    fun1();
    bubbleSort();
    fun3();
    fun4();
    return 0;
}
