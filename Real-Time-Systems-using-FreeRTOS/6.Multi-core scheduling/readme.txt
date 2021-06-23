
Task scheduling using SimSo Simulator

- Modify the python code in P_RM.py to use firstfit instead of the current algorithm. Please follow the steps in This document.
- Hint 1: Instead of scheduling the task to the CPU with the lowest utilization chose the first one which has a lower utilization than Urm(x+1) where x is the already scheduled tasks on the CPU 
- Hint 2: have a look at the def packer(self) function in the file P_RM.py
- Schedule the following task set on three processors using your modified algorithm. T1(2,1) T2(2.5,0.1) T3(3,1) T4(4,1) T5(4.5,0.1) T6(5,1) T7(6,1) T8(7,1) T9(8,1) T10(8.5,0.1) T11(9,1)

Programming Assignment

- Create a task "matrixtask" containing the following functionality:provided in assignment 5.
- Create a queue and send the content of (double **)c to the queue in matrixtask with before the vTaskDelay() call (hint: place the c variable in a struct). 
- Create a reader task which reads the content of the queue in case there is something in the queue.
- In case the queue has some content it should save the data in a local (double **) variable.
- Print out the content of the (double **)c variable in case the content is updated. 
- The data transferred from c should be a 10x10 matrix with the value 390 in each slot.
- Provide a screenshot of the execution: Run the application RTOSDemo.exe attached in this folder to see the results.