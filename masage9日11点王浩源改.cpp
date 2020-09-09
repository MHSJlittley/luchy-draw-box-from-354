#include <iostream>
#include <fstream>
using namespace std;
#include <stdio.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define  MAXSIZE 100
typedef  int  Status;
//实现了文件输入输出 输入文件名challengers.txt 输出文件名challengers.txt和lucky.txt； 
//输出文件lucky.txt按一二三等奖排序；  
//输入文件challengers.txt能够更新数据 

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

//=====在线性表L中查找值为e的数据元素
int LocateELem(SqList L,int e)
{
  for (int i=0;i< L.length;i++)
      if (L.elem[i].num==e) return i+1;                
  return 0;
}

//=====将线性表L中第i个数据元素删除
Status ListDelete_Sq(SqList &L,int i){
   int j;
   if((i<1)||(i>L.length)) return ERROR;//i值不合法
   for(j=i;j<=L.length-1;j++) 
    L.elem [j-1]=L.elem [j]; //被删除元素之后的元素前移  
   --L.length;               	//表长减1
  return OK;
}

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
void OutStudent(SqList &L){
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
}
int main()
{ 
	SqList  Ls;
	InStudent(Ls);
	OutStudent(Ls);

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
	
 
    return 0;
}

