#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include<stdbool.h>
#define n 10
#define m 10

int max[10][5],need[10][5],pid1,work[5],alloc[10][5],avail[5];
void unlock( struct sembuf sem_op,int semid)
{
   
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    semop(semid, &sem_op, 1);
}
void lock(struct sembuf sem_op,int semid)
{

    
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    semop(semid, &sem_op, 1);
}
5
5




  /*struct resources{
        int process;
	int alloc[5][10];
	int max[5][10];
	int need[][10];
	int request[1][10];
         int avail[1][10];
     };
   */

void print_bankers(){
	printf("\nAllocation matrix:\n");
  for(int i=0;i<10;i++){
  	for(int j=0;j<5;j++){
  			printf("%d ",alloc[i][j]);
  	}
  	printf("\n");
  }
  
  printf("\nMaximum requirement matrix:\n");
  for(int i=0;i<10;i++){
  	for(int j=0;j<5;j++){
  			printf("%d ",max[i][j]);
  	}
  	printf("\n");
  }
  
  printf("\nNeed matrix:\n");
  for(int i=0;i<10;i++){
  	for(int j=0;j<5;j++){
  			printf("%d ",need[i][j]);
  	}
  	printf("\n");
  }
  
  printf("\nMax resource available:\n");
  for(int i=0;i<5;i++){
  		printf("%d ",avail[i]);
  	
  }
  printf("\n");
}




void input_bankers() //int work[1][10],int request[1][10],
{
  
   int semid;
   semid = semget(IPC_PRIVATE, 10, IPC_CREAT|0777);
   semctl(semid, 0, SETVAL, 1);
   struct sembuf sem_op;

  
   for(int i=0;i<5;i++)
   {  printf("Maximum availability of resource  %d : ",i );
       scanf("%d",&avail[i]);
     }

    pid_t pid1 = fork();
        if(pid1!=0)
        {
          printf("Parent process \n ");
        
        }
        else if(pid1==0)
        {
            lock(sem_op,semid);
            
            printf("Process 1 \t pid1:%d Parent pid1:%d\n", getpid(), getppid());
            printf("----------\n");
            printf("Allocation of process 1:\n");
            for(int i=0;i<5;i++)
            {
              printf("Resource %d : ",i+1);
              scanf("%d",&alloc[0][i]);
            }
              
            for(int j=0;j<5;j++)
            {
              printf("Maximum of resource %d process 1 can hold : ",j+1);
              scanf("%d",&max[0][j]);
              need[0][j] = max[0][j]-alloc[0][j];
            }
            printf("Need of process 1 : [");
            for(int j=0;j<5;j++){
            	printf("%d ",need[0][j]);
            }
            printf("]\n\n");
            unlock(sem_op,semid);
        
        	if(pid1==0){
          		lock(sem_op,semid);
         		 printf("Process 2 \t  pid1:%d Parent pid1:%d\n", getpid(), getppid()); 
         		 printf("----------\n");
          		 printf("Allocation of process 2:\n");
				 for(int i=0;i<5;i++){
              		printf("Resource %d : ",i+1);
              		scanf("%d",&alloc[1][i]);
            	  }
            	for(int j=0;j<5;j++){
              		printf("Maximum of resource %d process 2 can hold : ",j+1);
              		scanf("%d",&max[1][j]);
              		need[1][j] = max[1][j]-alloc[1][j];
            	}
            	printf("Need of process 2 : [");
            	for(int j=0;j<5;j++){
            		printf("%d ",need[1][j]);
            	}
           	 	printf("]\n\n");
            	unlock(sem_op,semid);
        
  
		      if(pid1==0){
          			lock(sem_op,semid);
          			printf("Process 3 \t pid1:%d Parent pid1:%d\n", getpid(), getppid());
          			printf("----------\n");
          		 	printf("Allocation of process 3:\n");
           			for(int i=0;i<5;i++){
              			printf("Resource %d : ",i+1);
              			scanf("%d",&alloc[2][i]);
    				}
          			for(int j=0;j<5;j++){
            			printf("Maximum of resource %d process 3 can hold : ",j+1);
              			scanf("%d",&max[2][j]);
              			need[2][j] = max[2][j]-alloc[2][j];
         			 }
         			 printf("Need of process 3 : [");
            		for(int j=0;j<5;j++){
            			printf("%d ",need[2][j]);
            		}
           	 		printf("]\n\n");
        			unlock(sem_op,semid);

        		if(pid1==0){
          			lock(sem_op,semid);
          			printf("Process 4 \t pid1:%d Parent pid1:%d\n", getpid(), getppid());
          			printf("----------\n");
          		 	printf("Allocation of process 4:\n");
           			for(int i=0;i<5;i++){
              			printf("Resource %d : ",i+1);
              			scanf("%d",&alloc[3][i]);
    				}
          			for(int j=0;j<5;j++){
            			printf("Maximum of resource %d process 4 can hold : ",j+1);
              			scanf("%d",&max[3][j]);
              			need[3][j] = max[3][j]-alloc[3][j];
         			 }
         			 printf("Need of process 4 : [");
            		for(int j=0;j<5;j++){
            			printf("%d ",need[3][j]);
            		}
           	 		printf("]\n\n");
        			unlock(sem_op,semid);

        		if(pid1==0){
          			lock(sem_op,semid);
          			printf("Process 5 \t pid1:%d Parent pid1:%d\n", getpid(), getppid());
          			printf("----------\n");
          		 	printf("Allocation of process 5:\n");
           			for(int i=0;i<5;i++){
              			printf("Resource %d : ",i+1);
              			scanf("%d",&alloc[4][i]);
    				}
          			for(int j=0;j<5;j++){
            			printf("Maximum of resource %d process 5 can hold : ",j+1);
              			scanf("%d",&max[4][j]);
              			need[4][j] = max[4][j]-alloc[4][j];
         			 }
         			 printf("Need of process 5 : [");
            		for(int j=0;j<5;j++){
            			printf("%d ",need[4][j]);
            		}
           	 		printf("]\n\n");
        			unlock(sem_op,semid);
       

        		if(pid1==0){
          			lock(sem_op,semid);
          			printf("Process 6 \t pid1:%d Parent pid1:%d\n", getpid(), getppid());
          			printf("----------\n");
          		 	printf("Allocation of process 6:\n");
           			for(int i=0;i<5;i++){
              			printf("Resource %d : ",i+1);
              			scanf("%d",&alloc[5][i]);
    				}
          			for(int j=0;j<5;j++){
            			printf("Maximum of resource %d process 6 can hold : ",j+1);
              			scanf("%d",&max[5][j]);
              			need[5][j] = max[5][j]-alloc[5][j];
         			 }
         			 printf("Need of process 6 : [");
            		for(int j=0;j<5;j++){
            			printf("%d ",need[5][j]);
            		}
           	 		printf("]\n\n");
        			unlock(sem_op,semid);

        		if(pid1==0){
          			lock(sem_op,semid);
          			printf("Process 7 \t pid1:%d Parent pid1:%d\n", getpid(), getppid());
          			printf("----------\n");
          		 	printf("Allocation of process 7:\n");
           			for(int i=0;i<5;i++){
              			printf("Resource %d : ",i+1);
              			scanf("%d",&alloc[6][i]);
    				}
          			for(int j=0;j<5;j++){
            			printf("Maximum of resource %d process 7 can hold : ",j+1);
              			scanf("%d",&max[6][j]);
              			need[6][j] = max[6][j]-alloc[6][j];
         			 }
         			 printf("Need of process 7 : [");
            		for(int j=0;j<5;j++){
            			printf("%d ",need[6][j]);
            		}
           	 		printf("]\n\n");
        			unlock(sem_op,semid);

        		if(pid1==0){
          			lock(sem_op,semid);
          			printf("Process 8 \t pid1:%d Parent pid1:%d\n", getpid(), getppid());
          			printf("----------\n");
          		 	printf("Allocation of process 8:\n");
           			for(int i=0;i<5;i++){
              			printf("Resource %d : ",i+1);
              			scanf("%d",&alloc[7][i]);
    				}
          			for(int j=0;j<5;j++){
            			printf("Maximum of resource %d process 8 can hold : ",j+1);
              			scanf("%d",&max[7][j]);
              			need[7][j] = max[7][j]-alloc[7][j];
         			 }
         			 printf("Need of process 8 : [");
            		for(int j=0;j<5;j++){
            			printf("%d ",need[7][j]);
            		}
           	 		printf("]\n\n");
        			unlock(sem_op,semid);

        		if(pid1==0){
          			lock(sem_op,semid);
          			printf("Process 9 \t pid1:%d Parent pid1:%d\n", getpid(), getppid());
          			printf("----------\n");
          		 	printf("Allocation of process 9:\n");
           			for(int i=0;i<5;i++){
              			printf("Resource %d : ",i+1);
              			scanf("%d",&alloc[8][i]);
    				}
          			for(int j=0;j<5;j++){
            			printf("Maximum of resource %d process 9 can hold : ",j+1);
              			scanf("%d",&max[8][j]);
              			need[8][j] = max[8][j]-alloc[8][j];
         			 }
         			 printf("Need of process 9 : [");
            		for(int j=0;j<5;j++){
            			printf("%d ",need[8][j]);
            		}
           	 		printf("]\n\n");
        			unlock(sem_op,semid);

        		if(pid1==0){
          			lock(sem_op,semid);
          			printf("Process 10 \t pid1:%d Parent pid1:%d\n", getpid(), getppid());
          			printf("----------\n");
          		 	printf("Allocation of process 10:\n");
           			for(int i=0;i<5;i++){
              			printf("Resource %d : ",i+1);
              			scanf("%d",&alloc[9][i]);
    				}
          			for(int j=0;j<5;j++){
            			printf("Maximum of resource %d process 10 can hold : ",j+1);
              			scanf("%d",&max[9][j]);
              			need[9][j] = max[9][j]-alloc[9][j];
         			 }
         			 printf("Need of process 10 : [");
            		for(int j=0;j<5;j++){
            			printf("%d ",need[9][j]);
            		}
           	 		printf("]\n\n");
        			unlock(sem_op,semid);

      			}
      		   }
  		     }
	       }
	     }
       }
     }
   }
  }
 }  
 
}

int safety()
{
	printf("\n.......Safety checking.....\n");
    bool arr[2]= {true,false};
    int temp;
    bool flag;
    bool finish[10];
    for(int i=0;i<10;i++)
    {
       finish[i]=false;
    }
    for(int j=0;j<5;j++)
    {	
    	temp=0;
    	for(int i=0;i<10;i++){
    		temp+=alloc[i][j];
    	}
        work[j]=temp;
    }
	
	printf("\nWork:\n");
  for(int i=0;i<5;i++){
  		printf("%d ",work[i]);
  	
  }
  printf("\n");
    //while(count<10){
     for(int i=0;i<10;i++)
     {
     	if(finish[i]==false){
     		printf("Checking for process %d....\n",i+1);
     		flag = true;
     		for(int j=0;j<5;j++){
     			if(need[i][j] > work[j]){
     				flag=false;
     			}
     		}
     		if(flag==true){
     			printf("Process %d done..\n",i+1);
     			for(int j=0;j<5;j++){
     				work[j] = work[j]+alloc[i][j];
     				finish[i]=true;
     				 printf("%d ",work[j]);
           
     			}
     			printf("\n");
     		}
     		
     		
     	}
     	
     	
     }
     flag=true;
     for(int i=0;i<10;i++){
     	if(finish[i]==false){
     		flag=false;
     		
     	}
     }
    if(flag==true){
    	return 1;
    }
	else{
		return 0;
	}
 

     
}

void res_req(int p, int request[]){
	bool flag = true;
   for(int i=0;i<5;i++){
   		if(request[i] > need[p-1][i] || request[i] > avail[i]){
   			flag=false;
   		}
   }
   if(flag==true){
   		for(int i=0;i<5;i++){
   			alloc[p-1][i]=alloc[p-1][i]+request[i];
   			need[p-1][i]=need[p-1][i]-request[i];
   			printf("Resources allocated.....");
   			print_bankers();
   		}
   }
   else{
   		printf("Resources unavailable\n");
   }
   
   /*if(request[1][5]<=need[10][5] && request[1][5]<=avail[10][5])
   {
     //if(request[1][5]<=avail[10][5])
     // {
       avail[1][5]=avail[1][5]-request[1][5];
       alloc[10][5]=alloc[10][5]+request[1][5];
       need[10][5]=need[10][5]-request[1][5];
       
      }
      else{
             printf("Resources unavailable");
          }
    //}*/
} 


int main()
{ 
  
  


 /* int avail[i][j]={3,3,2,1,4};
  
  int alloc[10][5]={{1,2,3,4,5,
                     4,5,7,9,5,
                     7,1,5,6,4,
                     2,2,3,4,5,
                     7,4,1,2,3,
                     8,9,4,5,6,
                     4,5,6,1,2,
                     7,5,4,2,10,
                     8,5,2,1,3,
                     7,5,4,3,2}};
  need[0][j] = max[0][j] - alloc[0][i];*/

        
input_bankers();

sleep(45);
print_bankers();

	sleep(47);      
    int a=safety();
 	if(a==1){
 
  printf("Safe state\n");
  
  }
 
  else{
   printf("Unsafe state\n");
  
    }
    sleep(49);
 printf("\n.........request..........\n");
 int process=4;
 int request[5] ={0,7,6,5,8};
 res_req(process,request);

 

  return 0;
}

