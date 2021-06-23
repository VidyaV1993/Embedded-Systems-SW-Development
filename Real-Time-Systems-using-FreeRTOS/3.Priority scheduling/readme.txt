
Priority scheduling

- Given the tasks matrix_task() and communicationtask(). 
- The "communicationtask" must send a simulated data packet every 200ms but is often blocked by matrixtask, fix this problem without changing the functionality in the tasks.
- Create a new task "prioritysettask" which: 
 - Sets the priority of "communicationtask" to 4 in case its execution time is more than 1000 milliseconds (done at vApplicationTickHook() to measure ticks)
 - Sets the priority of "communicationtask" to 2 in case its execution time is less than 200 milliseconds (done at vApplicationTickHook() to measure ticks)
- Run the RTOSDemo exe from FreeRTOSv10.0.1\FreeRTOS\Demo\WIN32-MSVC\Debug to view the output.