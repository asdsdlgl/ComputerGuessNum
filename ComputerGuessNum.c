#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int comp[999999][9]={0};
int remain=0;
int a=0,b=0;
int recursive(int n,int p){              //recursive函數	
	if(p==0)
		return 1;
	else
		return n*recursive(n-1,p-1);
}
void database(int maxnum,int n,int p){
	int i,j,m,flag=0,k,max=1,start=123456789,temp;
	for(i=0;i<9-p;i++)
		start/=10;                          //算出起始值
		
    for(i=0;i<p;i++){
     	max=max*10;                   //算出10的p次方
	}
	for(i=0; (start<max)&&(i<maxnum) ; start++,i++){
		
		temp = start;
		
		for(j=p-1;(j>=0)&&(flag==0);j--){
			
			comp[i][j]=temp%10;
			if(comp[i][j]>n||comp[i][j]==0){		//位數大於n 等於0不算 
				for(m=0;m<=j;m++)		//錯誤歸零 
					comp[i][m]=0;
				i--;
				flag=1;
			}
			temp /= 10;
			}
			
		for(m=1;(m<p)&&(flag == 0);m++)
			for(k=0 ; (k<m)&&(flag == 0) ; k++)
				if(comp[i][k]==comp[i][m]){		//位數數字一樣不算 
					for(j=0;j<p;j++)		//錯誤歸零 
						comp[i][j]=0;
					i--;
					flag = 1; 
				}
				
		flag = 0;
	}
}

int ask(int p){
	int i,remainNum=0;						//一定要將remainNum初始化 
	printf("請問是:");
	if(remain>1)
		remainNum=rand()%remain;			//剩餘值比一大再取電腦隨機取random 
//	printf("remainNum = %d\n",remainNum);

	for(i=0;i<p;i++)
		printf("%d",comp[remainNum][i]);	//電腦問玩家數字 
		
	printf("\n");
	
	if(remain==1||remain==0)return 1;		//一或0回傳 
	
	return remainNum;
}

void reply(){
	scanf("%d %d",&a,&b);
	printf("電腦的答案是:%dA %dB:\n",a,b);		//玩家回答 
	
}

void check(int remainNum,int n,int p){
	int i,j,k,c,d;
	int temp[p]={0};
	for(i=0;i<p;i++)
		temp[i]=comp[remainNum][i];			//將電腦問的值傳入暫存陣列 
		
	
	for(i=0;i<remain;i++){
		c = 0;
		d = 0;
		
		for(j=0;j<p;j++)
			for(k=0;k<p;k++){
				if(comp[i][j] == temp[k]){		//跟暫存陣列做比較 位數/數字一樣就c++ 位數不同數字一樣就d++ 
					if(j==k)
						c++;
					else
						d++;
				}
			}
			
		if(!((a==c)&&(b==d))){					//測出的c d跟玩家輸入的a b做比較 
			for(j=i;j<remain;j++)				//做位移 讓a跟c"不同"的陣列去除 而玩家答案必跟ac一樣 
				for(k=0;k<p;k++){
					comp[j][k]=comp[j+1][k];
				}
			remain--;
			i--;
		}
	}
}

int main(){
	int i,j,n,p,maxnum,k,temp;
	srand(time(NULL));

	printf("請輸入 N :");
	scanf("%d",&n);
	printf("請輸入 P :");
	scanf("%d",&p);
	
	if(n>=p){					//輸入的值要 n 比 p 大 
	
		maxnum = recursive(n,p);
		remain = maxnum;
		database(remain,n,p);	//電腦資料庫建好 
	
		printf("remain = %d\n",remain);
	
		while(1){
		
		if((a==p)&&(b==0)){
			printf("success");
			break;
		}
		temp = ask(p);		//電腦問數字 
		reply();			//玩家回答 
	
		if((a==p)&&(b==0)){		//答案一樣就結束迴圈 
			printf("success");
			break;
		}
	
		check(temp,n,p);			//陣列中 跟電腦的值做比較 比完跟玩家輸入的a c一樣作保留 
	
		printf("remain = %d\n",remain);
		}
	}
	else 
		printf("請重新 應該輸入 N > P "); //n比p小結束陣列 
		} 
