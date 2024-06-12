**Compiled with c++11 or higher

**
  In order to complete task D of job J, task A of job J needs to be completed (D depends on A)
  I interpreted part above as
  in order to start task D task A must have been finished
  since if tasks can start simultaneously and only wait their dependencies to be completed to get 
  completed then table below happens 
  time   task(time left)(status 1 : completed 0:incompleted)
  1     A(2)(0)  B(1)(0)  C(3)(0)  D(4)(0)  E(1)(0)  F(2)(0)
  2     A(1)(0)  B(0)(1)  C(2)(0)  D(3)(0)  E(0)(0)  F(1)(0)
  3     A(0)(1)  B(0)(1)  C(1)(0)  D(2)(0)  E(0)(0)  F(0)(0)
  4     A(0)(1)  B(0)(1)  C(0)(1)  D(1)(0)  E(0)(1)  F(0)(0)
  5     A(0)(1)  B(0)(1)  C(0)(1)  D(0)(1)  E(0)(1)  F(0)(1)
  so i assumed cost 8 in pdf is typo of real time 11 - 3(time cost of F)=8

  ** 
  i assumed tasks placed in tasks.csv hierarchically for simplicity
  **
  to use csv file write  the name of the tasks alphabetically to the first place 
  write the dependencies to the second place order of dependecies is irrelevant if none leave empty
  write the time cost to the third place 
  all places seperated by comma(,)
  **
  in my solution there is 2 classes 
  1) task class contains the properties of tasks and necessary methods implemented
  2) job class contains a vector of pointers that pointing to task class and necessary methods implemented
  ** 
  alghoritm to find minimum finish time 
  first traverse through the task vector and set their earlies available start time as
  maximum of earliest available finish time 
  by definition earliest finish time = earlist start + time cost
  **
  time complexity for calculation of minimum time is 
  iteration through the vector O(n) X  getting the highest cost dependency O(m) = O(n*m)
  for the worst case m=n therefore complexity = O(n^2)
  for the best case m=0 all task independet time complexity O(n)

  for large number of tasks it is safe to say that it is easy to create a hierarcy 
  example
  A independet              we can easily simplify
  B depends A               it to C depends on B 
  C depends A and B         since B is already dependends on A 
  
  also it is also assumable that for large sets of tasks that it is not likely that a most of the 
  tasks to depend on all of the tasks before them thus complexity is closer to the O(n) side  

  time complexity for sorting is O(nlog(n))