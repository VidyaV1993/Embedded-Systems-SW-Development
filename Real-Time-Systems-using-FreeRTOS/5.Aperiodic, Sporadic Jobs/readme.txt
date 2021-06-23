
Task scheduling using SimSo Simulator

- Consider the tasks T1(3, 0.5), T2(4, 1.5, 3), T3(7, 1.0, 5) and the EDF scheduler. 
- A sporadic job arrives at t=50 having the execution time of 10 and a relative deadline of 30. 
- Create the sporadic task in SimSo by selecting: ”generate task set” and then list of act. Dates to the release time
 - U (utilization factor) : See general tab in results window
 - Response time : See tasks tab in results window
 - Tasks missing deadline or not : See Gantt chart and logs tab in results window
 - Minimum/maximum/average response time of all tasks : See results window
 - Response time for the sporadic job: See results window

Programming Assignment

- Consider the "matrixtask" containing the functionality given in Assignment 2. (Copy the C-code from matrixtask in Assignment 2)
- Add a software timer in main() to trigger a software interrupt every 5 seconds. 
- Define a Timer callback function outside main()- provided in assignment 4.
- Create an aperiodic task - provided in assignment 4.
- The following questions should be solved with programming and the questions should be answered in a report: See programming_assignment.txt for answers.
	- Is the system fast enough to handle all aperiodic tasks? Why?
	- If not, solve this problem without alter the functionality of any task
	- What is the response time of the aperiodic task?  
	- Provide a screenshot of the running system