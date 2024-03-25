#include<stdio.h>
#include<conio.h>
#include <stdlib.h> 
#include<time.h>

int data[4][4];
int data_old[4][4];//���ݵı��ݣ����ڱȽ�data[][]�Ƿ�仯
int opTimes=0;//��¼�����Ĳ���

void copyData()
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			data_old[i][j]=data[i][j];

}
int compareData()
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(data_old[i][j] != data[i][j])return 0; 
	return 1; 
}

int getEmptyNum()
{
	int i,j,n=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(data[i][j]==0)
				n++;
	return n;
}

void putNewNum()
{
	int i,j,c=0;
	c=1+rand()%getEmptyNum();//�������������Χ:[1,�հ׵�Ԫ����)
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(data[i][j]==0)
			{
				c--;
				if(c==0)
					data[i][j]=2;//��2����ĳ�հ׵�Ԫ����
			}	
}

int getMaxScore()
{
	int max=0;
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(data[i][j]>max)max=data[i][j];
		}
	return max;
}

void printLine(int L)//��ӡĳһ��
{
	int i=0;

	for(i=0;i<4;i++)
	{
		printf("��");
		if(data[L][i]==0)printf("    ");
		else printf("%4d",data[L][i]);
	}
	printf("��\n");
}
void printMap()//��ӡ������ά����ͷ�����Ϣ
{
	printf("��----��----��----��----��\n");
	printLine(0);
	printf("��----��----��----��----��\n");
	printLine(1);
	printf("��----��----��----��----��\n");
	printLine(2);
	printf("��----��----��----��----��\n");
	printLine(3);
	printf("��----��----��----��----��\n");
	printf("������%d\n",getMaxScore());
	printf("����������%d\n",opTimes);
	printf("ʣ��ռ䣺%d\n",getEmptyNum());
}

void moveUP()
{
	int i,j;
	int m=0,n=0;
	for(i=0;i<4;i++)//��
	{
		//�ƶ�����
		j=0;n=0;		 //jΪ��ǰ�ж���������
		while(n<3 && j<3)//nΪ�ƶ��Ĵ���
		{
			if(data[j][i]==0)   //�����ֿհ׸�
			{
				for(m=j;m<3;m++)//�·���������ƽ��1�񣬸��ǿհ׸�
					data[m][i]=data[m+1][i];	
				data[3][i]=0;	//���һ����0
				n++;			//�ƶ��Ĵ���+1
				
			}else j++; //�����õ�ǰ�ж���������+1
		}

		//�ϲ�����
		for(j=0;j<3;j++)//��
			if(data[j][i]==data[j+1][i] && data[j][i]!=0)//��ͬ(�Ҳ���0)��ϲ�
			{											 // 0��0����Ҫ�ϲ�
				data[j][i]=data[j][i]*2;//����ı���ϲ��������
				data[j+1][i]=0;			//���������
			}
		//�ƶ�����
		j=0;n=0;
		while(n<3 && j<3)
		{
			if(data[j][i]==0)
			{
				for(m=j;m<3;m++)
					data[m][i]=data[m+1][i];	
				data[3][i]=0;
				n++;	
			}else j++;
		}
	}
}

void moveDOWN()
{
	int i,j;
	int m=0,n=0;
	for(i=0;i<4;i++)//��
	{
		//�ƶ�����
		j=3;n=0;
		while(n<3 && j>0)
		{
			if(data[j][i]==0)
			{
				for(m=j;m>0;m--)data[m][i]=data[m-1][i];	
				data[0][i]=0;
				n++;	
			}else j--;
		}

		//�ϲ�����
		for(j=3;j>0;j--)//��
			if(data[j][i]==data[j-1][i] && data[j][i]!=0)//��ͬ(�Ҳ���0)��ϲ�
			{
				data[j][i]=data[j][i]*2;//����ı���ϲ��������
				data[j-1][i]=0;			//���������
			}
		//�ƶ�����
		j=3;n=0;
		while(n<3 && j>0)
		{
			if(data[j][i]==0)
			{
				for(m=j;m>0;m--)data[m][i]=data[m-1][i];	
				data[0][i]=0;
				n++;	
			}else j--;
		}
	}
}

void moveLEFT()
{
	int i,j;
	int m=0,n=0;
	for(i=0;i<4;i++)
	{
		//�ƶ�����
		j=0;n=0;
		while(n<3 && j<3)
		{
			if(data[i][j]==0)
			{
				for(m=j;m<3;m++)data[i][m]=data[i][m+1];	
				data[i][3]=0;
				n++;	
			}else j++;
		}
		//�ϲ�����
		for(j=0;j<3;j++)
			if(data[i][j]==data[i][j+1] && data[i][j]!=0)
			{
				data[i][j]=data[i][j]*2;
				data[i][j+1]=0;		
			}
		//�ƶ�����
		j=0;n=0;
		while(n<3 && j<3)
		{
			if(data[i][j]==0)
			{
				for(m=j;m<3;m++)data[i][m]=data[i][m+1];	
				data[i][3]=0;
				n++;	
			}else j++;
		}
	}
}

void moveRIGHT()
{
	int i,j;
	int m=0,n=0;
	for(i=0;i<4;i++)
	{
		//�ƶ�����
		j=3;n=0;
		while(n<3 && j>0)
		{
			if(data[i][j]==0)
			{
				for(m=j;m>0;m--)data[i][m]=data[i][m-1];	
				data[i][0]=0;
				n++;	
			}else j--;
		}
		//�ϲ�����
		for(j=3;j>0;j--)
			if(data[i][j]==data[i][j-1] && data[i][j]!=0)
			{
				data[i][j]=data[i][j]*2;
				data[i][j-1]=0;			
			}
		//�ƶ�����
		j=3;n=0;
		while(n<3 && j>0)
		{
			if(data[i][j]==0)
			{
				for(m=j;m>0;m--)data[i][m]=data[i][m-1];	
				data[i][0]=0;
				n++;	
			}else j--;
		}
	}
}

int isGameover()
{
	int i,j;
    for(i=0;i<4;++i)
	{
        for(j=0;j<4;++j)
		{
            if(data[i][j]==0)//����һ��Ϊ�գ���Ϸ����
                return 0;
            if(i>0)
			{
                if(data[i-1][j]==data[i][j])//�����������ڵĵ�Ԫֵ��ͬ����Ϸ����
                    return 0;
            }
            if(j>0)
                if(data[i][j-1]==data[i][j])
                    return 0;
        }
    }
    return 1;
}

int main()
{
	int ch;
	srand(time(NULL));//��ϵͳ��ǰʱ������rand()����������ӣ���֤ÿ������������в�һ��
    putNewNum();//����������2
	putNewNum();
	copyData(); //��������
	printMap(); //��ʾ
	while( (ch=getch())!=0x1B )
    { /* ��ESC���˳�����ѭ�� */
		
		  switch(ch)
		  {
		  case 0xE0:
			 switch(ch=getch())
			 {//ʶ���¼�
				case 72:  moveUP(); break;
				case 80:  moveDOWN(); break;
				case 75:  moveLEFT(); break;
				case 77:  moveRIGHT(); break;
				default:
				   break;
			 }
			 if(compareData()==0)//���ݲ�һ��˵�������е��������ұ��ƶ���
			 {
				putNewNum();  //�����µ����֡�2��
				copyData();   //�������������
				opTimes++;	  //�����Ĵ���+1
				
			 }
			 system("cls");  //����
			 printMap();	 //��ʾ	
			 if(isGameover())printf("��Ϸ����,��Q���˳�\n");
			 //if(getMaxScore()>=2048){}//����Ҳ�����жϷ���>=2048����ʾͨ��
			 break;
		  default:break;
		  }	
	 }
	 return 1;
}

