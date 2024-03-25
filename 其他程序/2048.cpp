#include<stdio.h>
#include<conio.h>
#include <stdlib.h> 
#include<time.h>

int data[4][4];
int data_old[4][4];//数据的备份，用于比较data[][]是否变化
int opTimes=0;//记录操作的步数

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
	c=1+rand()%getEmptyNum();//生成随机数，范围:[1,空白单元格数)
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(data[i][j]==0)
			{
				c--;
				if(c==0)
					data[i][j]=2;//把2放入某空白单元格内
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

void printLine(int L)//打印某一行
{
	int i=0;

	for(i=0;i<4;i++)
	{
		printf("│");
		if(data[L][i]==0)printf("    ");
		else printf("%4d",data[L][i]);
	}
	printf("│\n");
}
void printMap()//打印整个二维数组和分数信息
{
	printf("┌----┬----┬----┬----┐\n");
	printLine(0);
	printf("├----┼----┼----┼----┤\n");
	printLine(1);
	printf("├----┼----┼----┼----┤\n");
	printLine(2);
	printf("├----┼----┼----┼----┤\n");
	printLine(3);
	printf("└----┴----┴----┴----┘\n");
	printf("分数：%d\n",getMaxScore());
	printf("操作次数：%d\n",opTimes);
	printf("剩余空间：%d\n",getEmptyNum());
}

void moveUP()
{
	int i,j;
	int m=0,n=0;
	for(i=0;i<4;i++)//列
	{
		//移动操作
		j=0;n=0;		 //j为当前判定的所在行
		while(n<3 && j<3)//n为移动的次数
		{
			if(data[j][i]==0)   //若发现空白格
			{
				for(m=j;m<3;m++)//下方数据向上平移1格，覆盖空白格
					data[m][i]=data[m+1][i];	
				data[3][i]=0;	//最后一行置0
				n++;			//移动的次数+1
				
			}else j++; //否则：让当前判定的所在行+1
		}

		//合并操作
		for(j=0;j<3;j++)//行
			if(data[j][i]==data[j+1][i] && data[j][i]!=0)//相同(且不是0)则合并
			{											 // 0和0不需要合并
				data[j][i]=data[j][i]*2;//上面的保存合并后的数字
				data[j+1][i]=0;			//下面的清零
			}
		//移动操作
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
	for(i=0;i<4;i++)//列
	{
		//移动操作
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

		//合并操作
		for(j=3;j>0;j--)//行
			if(data[j][i]==data[j-1][i] && data[j][i]!=0)//相同(且不是0)则合并
			{
				data[j][i]=data[j][i]*2;//下面的保存合并后的数字
				data[j-1][i]=0;			//上面的清零
			}
		//移动操作
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
		//移动操作
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
		//合并操作
		for(j=0;j<3;j++)
			if(data[i][j]==data[i][j+1] && data[i][j]!=0)
			{
				data[i][j]=data[i][j]*2;
				data[i][j+1]=0;		
			}
		//移动操作
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
		//移动操作
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
		//合并操作
		for(j=3;j>0;j--)
			if(data[i][j]==data[i][j-1] && data[i][j]!=0)
			{
				data[i][j]=data[i][j]*2;
				data[i][j-1]=0;			
			}
		//移动操作
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
            if(data[i][j]==0)//任意一点为空，游戏继续
                return 0;
            if(i>0)
			{
                if(data[i-1][j]==data[i][j])//任意两个相邻的单元值相同，游戏继续
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
	srand(time(NULL));//用系统当前时间设置rand()随机序列种子，保证每次运行随机序列不一样
    putNewNum();//先生成两个2
	putNewNum();
	copyData(); //备份数组
	printMap(); //显示
	while( (ch=getch())!=0x1B )
    { /* 按ESC键退出的死循环 */
		
		  switch(ch)
		  {
		  case 0xE0:
			 switch(ch=getch())
			 {//识别按下键
				case 72:  moveUP(); break;
				case 80:  moveDOWN(); break;
				case 75:  moveLEFT(); break;
				case 77:  moveRIGHT(); break;
				default:
				   break;
			 }
			 if(compareData()==0)//数据不一样说明格子中的数字能且被移动了
			 {
				putNewNum();  //放置新的数字‘2’
				copyData();   //备份数组的数据
				opTimes++;	  //操作的次数+1
				
			 }
			 system("cls");  //清屏
			 printMap();	 //显示	
			 if(isGameover())printf("游戏结束,按Q键退出\n");
			 //if(getMaxScore()>=2048){}//这里也可以判断分数>=2048，提示通关
			 break;
		  default:break;
		  }	
	 }
	 return 1;
}

