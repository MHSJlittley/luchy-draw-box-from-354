#include <iostream>
#include <fstream>
using namespace std;
#include <stdio.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define  MAXSIZE 100
typedef  int  Status;
//ʵ�����ļ�������� �����ļ���challengers.txt ����ļ���challengers.txt��lucky.txt�� 
//����ļ�lucky.txt��һ�����Ƚ�����  
//�����ļ�challengers.txt�ܹ��������� 

//=====�����洢ѧ����Ϣ�Ľṹ�� 
typedef struct{
    int num;               //ѧ�� 
    string name;         //���� 
    string sex;          //�Ա� 
    string classes;      //�༶ 
    string intor;       //���˼�� 
    //char prize[10];			//��Ʒ	
    int	reward;// ������ʾ�Ƿ��н��Լ��еĽ����0,1,2,3��ʾ 
}ElemType;
 
typedef  struct {
  	ElemType  *elem;     //ָ������Ԫ�صĻ���ַ
  	int  length;          //���Ա�ĵ�ǰ����                                                      
 }SqList;

//=====��ʼ������ 
Status InitList_Sq(SqList &L){    //����һ���յ�˳���L
    L.elem=new ElemType[MAXSIZE];   //Ϊ˳������ռ�
    if(!L.elem) exit(OVERFLOW);       //�洢����ʧ��
    L.length=0;					  //�ձ���Ϊ0
    return OK;
}

//======�������Ա�L
void DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;    //�ͷŴ洢�ռ�
}

//=====������Ա�L
void ClearList(SqList &L) 
{
   L.length=0;                //�����Ա�ĳ�����Ϊ0
}

//=====�����Ա�L�ĳ���
int GetLength(SqList L)
{
   return (L.length);             
}

//=====�ж����Ա�L�Ƿ�Ϊ�� 
int IsEmpty(SqList L)
{
  if (L.length==0) return 1;      
   else return 0;
}

//=====��ȡ���Ա�L�еĵ�i������Ԫ�ص����ݣ��β�e����ֵ 
Status GetElem(SqList L,int i,ElemType &e)
{
  if (i<1||i>L.length) return ERROR;//�ж�iֵ�Ƿ����
    e=L.elem[i-1];   //��i-1�ĵ�Ԫ�洢�ŵ�i������
  return OK;
} 

//=====�����Ա�L�в���ֵΪe������Ԫ��
int LocateELem(SqList L,int e)
{
  for (int i=0;i< L.length;i++)
      if (L.elem[i].num==e) return i+1;                
  return 0;
}

//=====�����Ա�L�е�i������Ԫ��ɾ��
Status ListDelete_Sq(SqList &L,int i){
   int j;
   if((i<1)||(i>L.length)) return ERROR;//iֵ���Ϸ�
   for(j=i;j<=L.length-1;j++) 
    L.elem [j-1]=L.elem [j]; //��ɾ��Ԫ��֮���Ԫ��ǰ��  
   --L.length;               	//����1
  return OK;
}

//=====�����Ա�L�е�i������Ԫ��֮ǰ��������Ԫ��e 
Status ListInsert_Sq(SqList &L,int i ,ElemType e){
   if(i<1 || i>L.length+1) return ERROR;  //iֵ���Ϸ�
   if(L.length==MAXSIZE) return ERROR;    //��ǰ�洢�ռ�����     
   for(int j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //����λ�ü�֮���Ԫ�غ���
    L.elem[i-1]=e;               //����Ԫ��e�����i��λ��
  ++L.length;		     	//����1
  return OK;
}
//=====��ѧ������Ϣ���뵽�ṹ���� 
void InStudent(SqList  &Ls){
	ifstream fin("challengers.txt");
if(!fin.is_open())
{
cerr<<"�޷����ļ� "<<"challengers.txt"<<endl;
exit(0);
}//�ļ����� 
	InitList_Sq(Ls);
	ElemType e;
	int n,i;
	cout<<"�������м���ѧ���μӳ齱:";
	fin>>n;//cin>>n; 
	cout<<"������ѧ������Ϣ��\n";
	for( i=1;i<=n;i++){
		fin>>e.name;			//���� 
		fin>>e.num;			//ѧ�� 
		fin>>e.sex;			//�Ա� 
		fin>>e.classes;		//�༶ 
		fin>>e.intor;			//���˼�� 
		fin>>e.reward; //���� 
		cout<<endl;
		ListInsert_Sq(Ls,i,e);
	}
	fin.close();
}

//=====���ѧ����Ϣ����Ļ�� 
void OutStudent(SqList &L){
	{
	ofstream fout("lucky.txt");
	if(!fout.is_open())
	{
	cerr<<"�޷����ļ� "<<"lucky.txt"<<endl;
	exit(0);
	}//�ļ���� 

	int i;
	for(i=1;i<=L.length;i++)
	if(L.elem[i-1].reward==1){
	fout<<L.elem[i-1].name<<"\n";
    fout<<L.elem[i-1].num<<"\n";
    fout<<L.elem[i-1].sex<<"\n";
    fout<<L.elem[i-1].classes<<"\n";
    fout<<L.elem[i-1].intor<<"\n";
    fout<<L.elem[i-1].reward<<"\n";	
	}//���һ�Ƚ��� 
	for(i=1;i<=L.length;i++)
	if(L.elem[i-1].reward==2){
	fout<<L.elem[i-1].name<<"\n";
    fout<<L.elem[i-1].num<<"\n";
    fout<<L.elem[i-1].sex<<"\n";
    fout<<L.elem[i-1].classes<<"\n";
    fout<<L.elem[i-1].intor<<"\n";
    fout<<L.elem[i-1].reward<<"\n";	
	}//������Ƚ� 
	for(i=1;i<=L.length;i++)
	if(L.elem[i-1].reward==3){
	fout<<L.elem[i-1].name<<"\n";
    fout<<L.elem[i-1].num<<"\n";
    fout<<L.elem[i-1].sex<<"\n";
    fout<<L.elem[i-1].classes<<"\n";
    fout<<L.elem[i-1].intor<<"\n";
    fout<<L.elem[i-1].reward<<"\n";	
	}//������Ƚ� 
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
cerr<<"�޷����ļ� "<<"challengers.txt"<<endl;
exit(0);
}//�ļ���� 
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

