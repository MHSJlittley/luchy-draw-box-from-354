#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
//#include "genlib.h"
//#include "simpio.h"
//#include <random.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define  MAXSIZE 100

int Max=50;

typedef  int  Status;

//实现了查找、删除、和单次抽奖功能 

//=====创建存储学生信息的结构体 
typedef struct{
    int num;               //学号 
    string name;         //姓名 
    string sex;          //性别 
    string classes;      //班级 
    string intor;       //个人简介 
    //char prize[10];			//奖品	
    int	reward;// 用来表示是否中奖以及中的奖项，用0,1,2,3表示 
}ElemType;
 
typedef  struct {
  	ElemType  *elem;     //指向数据元素的基地址
  	int  length;          //线性表的当前长度                                                      
 }SqList;

//=====初始化操作 
Status InitList_Sq(SqList &L){    //构造一个空的顺序表L
    L.elem=new ElemType[MAXSIZE];   //为顺序表分配空间
    if(!L.elem) exit(OVERFLOW);       //存储分配失败
    L.length=0;					  //空表长度为0
    return OK;
}

//======销毁线性表L
void DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;    //释放存储空间
}

//=====清空线性表L
void ClearList(SqList &L) 
{
   L.length=0;                //将线性表的长度置为0
}

//=====求线性表L的长度
int GetLength(SqList L)
{
   return (L.length);             
}

//=====判断线性表L是否为空 
int IsEmpty(SqList L)
{
  if (L.length==0) return 1;      
   else return 0;
}

//=====获取线性表L中的第i个数据元素的内容，形参e带出值 
Status GetElem(SqList L,int i,ElemType &e)
{
  if (i<1||i>L.length) return ERROR;//判断i值是否合理
    e=L.elem[i-1];   //第i-1的单元存储着第i个数据
  return OK;
} 

//=====查找学号是否存在且该学生是否中奖 
int LocateELem(SqList L,int e)
{
  for (int i=0;i< L.length;i++)
      if (L.elem[i].num==e) return i+1;                
  return 0;
}

//=====删除抽奖学生的信息
/*void DeleteStudents(SqList  &Ls){
int a,i;
cout<<"请输入要删除学生的学号：";cin>>a;
i=LocateELem(Ls,a);
ListDelete_Sq(Ls,i);
}*/

//=====在线性表L中第i个数据元素之前插入数据元素e 
Status ListInsert_Sq(SqList &L,int i ,ElemType e){
   if(i<1 || i>L.length+1) return ERROR;  //i值不合法
   if(L.length==MAXSIZE) return ERROR;    //当前存储空间已满     
   for(int j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //插入位置及之后的元素后移
    L.elem[i-1]=e;               //将新元素e放入第i个位置
  ++L.length;		     	//表长增1
  return OK;
}
//=====将学生的信息输入到结构体中 
void InStudent(SqList  &Ls){
	ifstream fin("challengers.txt");
if(!fin.is_open())
{
cerr<<"无法打开文件 "<<"challengers.txt"<<endl;
exit(0);
}//文件输入 
	InitList_Sq(Ls);
	ElemType e;
	int n,i;
	cout<<"请输入有几个学生参加抽奖:";
	fin>>n;//cin>>n; 
	cout<<"请输入学生的信息：\n";
	for( i=1;i<=n;i++){
		fin>>e.name;			//姓名 
		fin>>e.num;			//学号 
		fin>>e.sex;			//性别 
		fin>>e.classes;		//班级 
		fin>>e.intor;			//个人简介 
		fin>>e.reward; //奖项 
		cout<<endl;
		ListInsert_Sq(Ls,i,e);
	}
	fin.close();
}

//=====输出学生信息到屏幕上 
void OutStudent(SqList &L)
	{
	ofstream fout("lucky.txt");
	if(!fout.is_open())
	{
	cerr<<"无法打开文件 "<<"lucky.txt"<<endl;
	exit(0);
	}//文件输出 

	int i;
	for(i=1;i<=L.length;i++)
	if(L.elem[i-1].reward==1){
	fout<<L.elem[i-1].name<<"\n";
    fout<<L.elem[i-1].num<<"\n";
    fout<<L.elem[i-1].sex<<"\n";
    fout<<L.elem[i-1].classes<<"\n";
    fout<<L.elem[i-1].intor<<"\n";
    fout<<L.elem[i-1].reward<<"\n";	
	}//输出一等奖； 
	for(i=1;i<=L.length;i++)
	if(L.elem[i-1].reward==2){
	fout<<L.elem[i-1].name<<"\n";
    fout<<L.elem[i-1].num<<"\n";
    fout<<L.elem[i-1].sex<<"\n";
    fout<<L.elem[i-1].classes<<"\n";
    fout<<L.elem[i-1].intor<<"\n";
    fout<<L.elem[i-1].reward<<"\n";	
	}//输出二等奖 
	for(i=1;i<=L.length;i++)
	if(L.elem[i-1].reward==3){
	fout<<L.elem[i-1].name<<"\n";
    fout<<L.elem[i-1].num<<"\n";
    fout<<L.elem[i-1].sex<<"\n";
    fout<<L.elem[i-1].classes<<"\n";
    fout<<L.elem[i-1].intor<<"\n";
    fout<<L.elem[i-1].reward<<"\n";	
	}//输出三等奖  
    cout<<"OK";
}
void OutChallengers(SqList &Ls){
	ofstream fout("challengers.txt");
	if(!fout.is_open())
	{
	cerr<<"无法打开文件 "<<"challengers.txt"<<endl;
	exit(0);
	}//文件输出 

	fout<<Ls.length<<endl;
	for(int i=1;i<=Ls.length;i++)
	{
	fout<<Ls.elem[i-1].name<<" ";
	fout<<Ls.elem[i-1].num<<" ";
	fout<<Ls.elem[i-1].sex<<" ";
	fout<<Ls.elem[i-1].classes<<" "; 
	fout<<Ls.elem[i-1].intor<<" ";
	fout<<Ls.elem[i-1].reward<<endl;
}
	fout.close();
}
//----查询此人是否中奖 
int GetorGot(SqList &L,int j)
{
	return L.elem[j-1].reward;
}

int DanCiChouJiang(int number,int A[])//number 
{
	int a,j;
	a=rand()%50+1;
	for(j=a;j<Max;j++){
		A[j+1]=A[j];
	}
	Max--;
	return a;
}
int DawrBox(SqList &L)
{
	srand((int) time(NULL));
	int i;
	int number;
	int JP;
	int A[50];
	for(i=1;i<=50;i++){
		A[i]=i;
	}
	
	printf("请输入你的学号：\n");
	cin>>number;//number=GetInteger();//number 
	int j=LocateELem(L,number);//通过查询学号返还该学生的信息的位置 
	if(!GetorGot(L,j)) JP=DanCiChouJiang(number,A);//如果没中奖过，抽奖 
	else return 0;//如果中奖过，结束程序 
	if(JP==1){
		printf("一等奖\n");
	}
	else if(2<=JP&&JP<=3){
		printf("二等奖\n");
	}
	else if(4<=JP&&JP<=6){
		printf("三等奖\n");
	}
	else{
		printf("No \n");
	}
}
//void introduction()
//{
//	
//}

int main()
{ 
	SqList  Ls;//创建建构体 
	InStudent(Ls);//输入学生信息 
	int i=1;
	while(i)
	{ 
	DawrBox(Ls);
	cin>>i; 
	} 
	OutStudent(Ls);//输出学生信息 
	OutChallengers(Ls); //输出中奖者信息 

    return 0;
}

