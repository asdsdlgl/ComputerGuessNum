#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int comp[999999][9]={0};
int remain=0;
int a=0,b=0;
int recursive(int n,int p){              //recursive���	
	if(p==0)
		return 1;
	else
		return n*recursive(n-1,p-1);
}
void database(int maxnum,int n,int p){
	int i,j,m,flag=0,k,max=1,start=123456789,temp;
	for(i=0;i<9-p;i++)
		start/=10;                          //��X�_�l��
		
    for(i=0;i<p;i++){
     	max=max*10;                   //��X10��p����
	}
	for(i=0; (start<max)&&(i<maxnum) ; start++,i++){
		
		temp = start;
		
		for(j=p-1;(j>=0)&&(flag==0);j--){
			
			comp[i][j]=temp%10;
			if(comp[i][j]>n||comp[i][j]==0){		//��Ƥj��n ����0���� 
				for(m=0;m<=j;m++)		//���~�k�s 
					comp[i][m]=0;
				i--;
				flag=1;
			}
			temp /= 10;
			}
			
		for(m=1;(m<p)&&(flag == 0);m++)
			for(k=0 ; (k<m)&&(flag == 0) ; k++)
				if(comp[i][k]==comp[i][m]){		//��ƼƦr�@�ˤ��� 
					for(j=0;j<p;j++)		//���~�k�s 
						comp[i][j]=0;
					i--;
					flag = 1; 
				}
				
		flag = 0;
	}
}

int ask(int p){
	int i,remainNum=0;						//�@�w�n�NremainNum��l�� 
	printf("�аݬO:");
	if(remain>1)
		remainNum=rand()%remain;			//�Ѿl�Ȥ�@�j�A���q���H����random 
//	printf("remainNum = %d\n",remainNum);

	for(i=0;i<p;i++)
		printf("%d",comp[remainNum][i]);	//�q���ݪ��a�Ʀr 
		
	printf("\n");
	
	if(remain==1||remain==0)return 1;		//�@��0�^�� 
	
	return remainNum;
}

void reply(){
	scanf("%d %d",&a,&b);
	printf("�q�������׬O:%dA %dB:\n",a,b);		//���a�^�� 
	
}

void check(int remainNum,int n,int p){
	int i,j,k,c,d;
	int temp[p]={0};
	for(i=0;i<p;i++)
		temp[i]=comp[remainNum][i];			//�N�q���ݪ��ȶǤJ�Ȧs�}�C 
		
	
	for(i=0;i<remain;i++){
		c = 0;
		d = 0;
		
		for(j=0;j<p;j++)
			for(k=0;k<p;k++){
				if(comp[i][j] == temp[k]){		//��Ȧs�}�C����� ���/�Ʀr�@�˴Nc++ ��Ƥ��P�Ʀr�@�˴Nd++ 
					if(j==k)
						c++;
					else
						d++;
				}
			}
			
		if(!((a==c)&&(b==d))){					//���X��c d�򪱮a��J��a b����� 
			for(j=i;j<remain;j++)				//���첾 ��a��c"���P"���}�C�h�� �Ӫ��a���ץ���ac�@�� 
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

	printf("�п�J N :");
	scanf("%d",&n);
	printf("�п�J P :");
	scanf("%d",&p);
	
	if(n>=p){					//��J���ȭn n �� p �j 
	
		maxnum = recursive(n,p);
		remain = maxnum;
		database(remain,n,p);	//�q����Ʈw�ئn 
	
		printf("remain = %d\n",remain);
	
		while(1){
		
		if((a==p)&&(b==0)){
			printf("success");
			break;
		}
		temp = ask(p);		//�q���ݼƦr 
		reply();			//���a�^�� 
	
		if((a==p)&&(b==0)){		//���פ@�˴N�����j�� 
			printf("success");
			break;
		}
	
		check(temp,n,p);			//�}�C�� ��q�����Ȱ���� �񧹸򪱮a��J��a c�@�˧@�O�d 
	
		printf("remain = %d\n",remain);
		}
	}
	else 
		printf("�Э��s ���ӿ�J N > P "); //n��p�p�����}�C 
		} 
