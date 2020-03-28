# os-project
This is slightly different from Shortest job first
Consider a scheduling approach which is non-pre-emptive similar to shortest job next in nature.
The priority of each job is dependent on its estimated run time, and also the amount of time it has spent waiting.
Jobs gain higher priority the longer they wait, which prevents indefinite postponement.
The jobs that have spent a long time waiting compete against those estimated to have short run times. 
The priority can be computed as:  Priority = 1+ Waiting time / Estimated run time 
---As this approach is based on non-pre-emptive similar to shortest job next we will first prioritise all the processes 
and then arrange them in the order of priority. We will use C programming language to implement the above challenge.
