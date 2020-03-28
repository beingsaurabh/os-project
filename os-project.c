#include<stdio.h>
#include<conio.h>
void proc_inp()          //function
{
  prog_main:  //main program block
  {
  printf("********* Scheduling the processes***********\n\n");
  printf("Please put the  no. of Processes : ");
  int n,y=0,z=0;
  double avg_waiting,avg_turnaround,burstTime[n],arrivalTime[n];
  scanf("%d",&n ); 
  double min,total=0,total2=0,wait_final, turnaround_final;
  if (n<=0)
  {
  	printf("\nPlease enter a postive value in no of processes.\n");
  	goto prog_main;
  
  }
  double wait_avg, turnaround_avg,process[n], var3,completionTime[n];
  
  printf("***Please Enter the following details***");
  double waitingTime[n],turnaroundTime[n],priority[n];
  
  for(y=0;y<n;y++)
  {
    printf("\nPlease put the Burst Time for P(%d) : ", y+1 );
    scanf("%lf", &burstTime[y]);
    printf("Please put the Arrival Time for P(%d) : ", y+1 );
    scanf("%lf", &arrivalTime[y] );
    process[y]=y+1;
  }

  printf("\n\n***********Given Values are **********\n\n");
  printf("* Process * Arrival Time * Burst Time *\n");
  for(y=0;y<n;y++)
  {
    printf("*  P[%0.0lf]   *       %0.0lf      *     %0.0lf      *\n",process[y],arrivalTime[y],burstTime[y]);
  }


  printf("\n\n********* Sorting Processes according to ArrivalTime***********\n");

  for(y=0;y<n;y++)
  {
    for(z=0;z<n;z++)
    {
      if(arrivalTime[y]<arrivalTime[z])
      {
        
        var3 = burstTime[z];
        burstTime[z] = burstTime[y];
        burstTime [y] = var3;
	
	      var3 = process[z];
        process[z] = process[y];
        process[y] = var3;

	      var3 = arrivalTime[z];
        arrivalTime[z] = arrivalTime[y];
        arrivalTime[y] = var3;
      
      }
    }
  }
  printf("* Process * Arrival Time * Burst Time *\n");
  for(y=0;y<n;y++)
  {
    printf("*  P[%0.0lf]   *       %0.0lf      *     %0.0lf      *\n",process[y],arrivalTime[y],burstTime[y]);
  }

  int k = 1;
  double b_time = 0;
  for(z=0;z<n;z++)
  {
    b_time = b_time + burstTime[z];
    min = burstTime[k];

    for(y=k;y<n;y++)
    {
      if((b_time >= arrivalTime[y])&&(burstTime[y]<min))
      {
        var3 = burstTime[k];
        burstTime[k] = burstTime[y];
        burstTime[y] = var3;

        var3 = arrivalTime[k];
        arrivalTime[k] = arrivalTime[y];
        arrivalTime[y] = var3;

        var3 = process[k];
        process[k] = process[y];
        process[y] = var3;
      }
    }
    k++;
  }
  waitingTime[0] = 0;
  for(y=1;y<n;y++)
  {
    total += burstTime[y-1];
    waitingTime[y] = total - arrivalTime[y];
    wait_final += waitingTime[y]; 
  }
  wait_avg = wait_final/n;
  for(y=0;y<n;y++)
  {
    total2 += burstTime[y];
    turnaroundTime[y] = total2 - arrivalTime[y];
    turnaround_final += turnaroundTime[y];
  }
  turnaround_avg=turnaround_final/n;
printf("\n\n ************ Caculating Waiting Time & Turn Around Time ************\n\n");
  printf("* Process * Arrival Time * Burst Time *  Waiting Time  *  Turn Around Time  *\n");
  for(y=0;y<n;y++)
  {
    printf("*  P[%0.0lf]   *       %0.0lf      *     %0.0lf      *        %0.0lf       *         %0.0lf          *\n",
	process[y],arrivalTime[y],burstTime[y],waitingTime[y],turnaroundTime[y]);
  }




  
  completionTime[0] = burstTime[0];
  for(y=1;y<n;y++)
  {
    completionTime[y] = completionTime[y-1] + burstTime[y];
  }

printf("The priority can be computed as :  Priority = 1+ Waiting time / Estimated run time\n\n");

  for(y=0;y<n;y++)
  {
    priority[y] = 1+waitingTime[y]/completionTime[y];
   printf("Priority of P[%0.0lf] = %lf \n",process[y],priority[y]);
  }
  


  printf("\n\n ************** Scheduling(Prioritising) the Processes ****************\n\n");
  printf("* Process * Arrival Time * Burst Time *  Waiting Time  *  Turn Around Time  *\n");
  printf("*  P[%0.0lf]   *       %0.0lf      *     %0.0lf      *        %0.0lf       *         %0.0lf          *\n",
  process[0],arrivalTime[0],burstTime[0],waitingTime[0],turnaroundTime[0]);
  for(y=n-1;y>0;y--)
  {
    printf("*  P[%0.0lf]   *       %0.0lf      *     %0.0lf      *        %0.0lf       *         %0.0lf          *\n",
	process[y],arrivalTime[y],burstTime[y],waitingTime[y],turnaroundTime[y]);
  }

printf("\n\nAVG waiting time = Sum of waiting time of all the processes/total no of processes\n");
printf("AVG Turn around time = Sum of Turn around time of all the processes/total no of processes.\n");  

  printf("\n\n\n\t\t\tAverage Turn Around Time : %lf",turnaround_avg);
  printf("\n\t\t\tAverage Waiting Time     : %lf\n\n",wait_avg);
  printf("\n\t\t\t\t\tEnd Of Program");
  printf("\n\t\t\t\t\t******");

  
	
}
  
}

int main()
{
	proc_inp();
	printf("\n\t\t\t\t\tEnd Of Program");
    printf("\n\t\t\t\t\t***********");
    printf("\n\t\t\t\t\tMADE BY Saurabh Tripathi");
    printf("\n\t\t\t\t\tRoll no 02 , 11807532");
}
