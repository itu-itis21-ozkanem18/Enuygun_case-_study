#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include<algorithm>
  int char_to_int(char c){      //Char to int function it transforms char to int by leveraging the ASCII values of 
    return c - 'A';            //characters it only accepts uppercase chars index starts from 0 A=0,B=1....
  }
class task {      // task class
    private:
    std::string name;                       // name property of task 
    std::string dependencies;              // dependencies of task as string if there are multiple dependency they are written concatenated
    int time_cost;                        // Unit time cost of completing task
    int early_start;                     // earliest time that task can be started 
    int early_finish;                   // earliest time that task can be finished  
    public:
    task (std::string name,std::string dependencies,int time_cost){      // constructor with parameter for task class
        this->name=name;                          
        this->dependencies=dependencies;
        this->time_cost=time_cost;
        this->early_finish=time_cost;                                    
    }
      int get_time_cost(){                                               // getter function of time_cost of task returns int
        return time_cost;
      }
      std::string get_dependencies(){                                    // getter function of dependencies of task returns string
        return dependencies;
      }
    void print_task_properties(){                                        //print function of task prints the properties of task 
        std::cout<<name
        <<"               "
        <<dependencies
        <<"               "
        <<time_cost
        <<"               "
        <<early_start
        <<"               "
        <<early_finish
        <<std::endl;
    }
    void set_early_start(int start){                                     // setter function of early_start takes int
        this->early_start=start;

    }
    void set_early_finish(int finish){                                   // setter function of early finish takes int
        this->early_finish=finish;

    }
    int get_early_start(){                                               //getter function of early start returns int
        return early_start;
    }
    int get_early_finish(){                                              // getter function of early finish returns int
        return early_finish;
    }

};
class job      // job class
{
private:
    std::vector<task*> task_vector;      //vector of pointers to task class 
         int get_highest_cost_dependency(std::string dependencies){             //method to calculate highest early finish time 
        int k = 0 ;                                                        // of the dependencies of task
        for (int i = 0; i < dependencies.size(); i++){                    // converts the names of the tasks to int to locate
            int temp = char_to_int(dependencies[i]); ;                   // neccesarry task in task_vector
            if (task_vector[temp]->get_early_finish()>k){                // compares early start times of the dependencies updates if higher
                k=task_vector[temp]->get_early_finish(); 
            }
        }
        return k ;                                                      // returns the highest value as int
    }
public:
    void push_task(task* input){        // push task method of job class to add tasks to the job object 
        task_vector.push_back(input);  // accepts pointer to task class pushes to the task vector 
    }
    void print_job(){                 // print method of job class prints the properties of tasks in task_vector
        std::cout<<"Task Name"<<"    "<<"dependencies"<<"    "<<"time_cost"<<"    "<<"early_start"<<"    "<<"early_finish"<<std::endl;
        for (int i = 0; i < task_vector.size(); i++)
        { task_vector[i]->print_task_properties(); }
    }

    void calculate_time(){                                          //method to calculate early start and finish time of each task in 
        for (int i = 0; i < task_vector.size(); i++)               // task_vector of job object
        {int highest_cost_dependency = get_highest_cost_dependency(task_vector[i]->get_dependencies()); 
         task_vector[i]->set_early_start(highest_cost_dependency);
         task_vector[i]->set_early_finish(task_vector[i]->get_time_cost()+highest_cost_dependency);
        }
    }
    void sort_tasks_by_early_finish() {                            //method to sort tasks by the earliest available finish time
        std::sort(task_vector.begin(), task_vector.end(), [](task* a, task* b)
        {return a->get_early_finish() < b->get_early_finish();});
    }
    void sort_tasks_by_early_start() {                            //method to sort tasks by the earliest avalible start time 
        std::sort(task_vector.begin(), task_vector.end(), [](task* a, task* b) 
        {return a->get_early_start() < b->get_early_start();});
    }
};




int main (){
    
    std::string line ;                     
    std::ifstream Input_File;
    Input_File.open("tasks.csv");
    job job1;
    while (std::getline(Input_File,line))
    {
        std::stringstream ss(line);
        std::string name;
        std::string dependency;
        std::string time_cost;
        std::getline(ss,name,',');
        std::getline(ss,dependency,',');
        std::getline(ss,time_cost,',');
        job1.push_task(new task(name,dependency,stoi(time_cost)));
    }
    //job1.print_job();
    job1.calculate_time();
    job1.sort_tasks_by_early_finish();
    job1.print_job();
  
  
  
}
