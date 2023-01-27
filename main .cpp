#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <stdlib.h>

void create_project(std::ofstream& project_file, std::string& str);
void project_admin(std::ofstream& project_admin_file, std::string& str);
//bool chek_project_admin_name_in_admin_file(std::string& project_admin_name);
bool chek_project_name_in_project_file(std::string& project_name);
void creat_task(std::ofstream& task_file, std::string& str);
void assigned_name(std::ofstream& assigned_file, std::string& str);
void dead_line(std::ofstream& date_file, std::string& str);
std::string type_conv_int_to_string(int date);
void project_creator_controller();
void status_project(std::ofstream& status_file, std::string& str);
void read_projects();
void choose_project();
void find_choosen_project_info(std::string& str);
void find_project(std::string& str);
void print_info(std::vector<std::string>& v);
void find_admin(std::string& str);
void find_task(std::string& str);
void find_assigned(std::string& str);
void find_deadline(std::string& str);
void find_status(std::string& str);
void modification_in_project(std::string& str);
void update_task(std::vector<std::string>& v, std::string& str);
void delete_from_file(std::string& str);
void creat_new_task(std::string& str);

std::vector<std::string> v, v_task;
std::vector<int> index;

int main()
{
	int num;
	std::cout << "Hello, dear user. If you  want to create a project, please, enter 0, if you have created project, please, enter 1." << std::endl;
  
	std::cin >> num;
	std::cout << std::endl;
  
  if (num == 0)
  {
    project_creator_controller();
  }
    else if(num == 1)
    {
      read_projects();
    }
   
}

/*Read all projects names.*/
void read_projects()
{
  std::string str;
  std::ifstream file_project;
  file_project.open("project.txt");

  if(file_project.is_open())
   {
    while(!file_project.eof())
      {
        getline(file_project, str);
        std::cout << str << std::endl;
      }
   }    
  choose_project(); 
  file_project.close();
}

/*Choose project name by number*/
void choose_project()
{
  std::cout << "Choose the project by number: " << std::endl;
  int number;
  std::cout << "number of project: " << std::endl;
  std::cin >> number;
  
  std::string str;
  str += type_conv_int_to_string(number) + '.';
  find_choosen_project_info(str);

  std::cout << "Do you want to modifier anything in any project?" << std::endl;
  std::cout << "If yes, enter 0, if no, enter 1" << std::endl;

  int ans;
  std::cin >> ans;
  std::cout << std::endl;

  if(ans == 0)
  {
    modification_in_project(str);
  }
  else
  {
    std::cout << "Thank you!" << std::endl;
  }
  
}

/*To change something in projects*/
void modification_in_project(std::string& str)
{
  std::cout << "If you want to update the task, enter 0. If you want to create a new task, enter 1. If you want to delete the task, enter 2." << std::endl;

  int num;
  std::cin >> num;
  std::cout << std::endl;

  if (num == 0)
  {
    v.clear();
    find_task(str);
    update_task(v, str);
    v.clear();
  }
    else if(num == 1)
     {
      creat_new_task(str);
     }
       else if(num == 2)
        {
          delete_from_file(str);
          v.clear();
        }
}

/*Add new task in task.txt*/
void creat_new_task(std::string& str)
{
  std::ofstream task_file;
  task_file.open("task.txt", std::ofstream::app | std::ofstream::out);

  if (task_file.is_open() && !task_file.eof())
  {
   //creat_task(task_file, str);
     std::cout << "Enter the task discribtion: " << std::endl;
   std::string task_name;
  std::cin.ignore();
   getline(std::cin, task_name);
    
   task_file << str << " Task: " << task_name;  
  std::cout << std::endl;
  }
   task_file.close();
}

/*Delete task from task.txt*/
void delete_from_file(std::string& str)
{
  std::ifstream task_file;
  task_file.open("task.txt");
  std::string token;
  
  if (task_file.is_open() && !task_file.eof())
  {
    getline(task_file, token);
    v.push_back(token);
  }
  task_file.close();
  
  std::ofstream task_file_new;
  task_file_new.open("task.txt", std::ofstream::out | std::ofstream::trunc);

  for (int i = 0; i < v.size() && v[i] != str; ++i)
    {
      task_file_new << v[i];
    }
  
  task_file_new.close();
}

/*Updatee the task in vector*/
void update_task(std::vector<std::string>& v, std::string& str)
{

   for (int i = 0; i < v.size(); ++i)
      std::cout << v[i] ;
  
  std::cout << "Dear admin, which number task do you want to update? " << std::endl;
  std::cout << "Please, enter a number of task start count from 0. " << std::endl;

   int number_task;
    std::cin >> number_task;

  int counter = 0;
  for (int i = 0; i < v.size(); ++i)
    {
      if(v[i] == str)
      {
        ++counter;
        index.push_back(i);
      }
    }
   
   std::cout << "Enter a new task. " << std::endl;
  
     for (int i = index[number_task] * number_task; i < v.size(); ++i)
      {
        if (v[i] != str && v[i] != "|")
         {
           v.erase(v.begin() + i);
           v.insert(v.begin() + i, " ");
           std::string new_str;
           std::cin >> new_str;
           v.at(i + 1) = str + " Task: " + new_str;
          }  
      }

  std::ifstream task_file;
  task_file.open("task.txt");
  std::string token;
  
  while (task_file.is_open() && !task_file.eof())
    {
      getline(task_file, token);
      v_task.push_back(token);
    }
task_file.close();

  std::fstream task_file_new;
  task_file_new.open("task.txt");

  if (task_file_new.is_open())
  {
    for (int i = 0; i < v_task.size(); ++i)
      
      {
        if (v_task[i] != str)
         {
           task_file_new << v_task[i];
          }
  
           else 
            {
              for (int i = 0; i < v.size(); ++i)
             {
               task_file_new << v[i];
              }
            }
      }
  }
  
  task_file_new.close();
  v_task.clear();
}

/*Find the information about choosen project(Admin, Task, Deadline, Status and Assigned)*/
void find_choosen_project_info(std::string& str)
{ 
  find_project(str);
   print_info(v);
  find_admin(str);
   print_info(v);
  find_task(str);
   print_info(v);
  find_assigned(str);
   print_info(v);
  find_deadline(str);
   print_info(v);
  find_status(str);
   print_info(v);
}


/*Find status from status.txt*/
void find_status(std::string& str)
{
  std::ifstream status_file;
  status_file.open("status.txt");
  std::string token;
  
  if(status_file.is_open())
   {
     while(!status_file.eof())
       {
         status_file >> token;
     
           while(str == token)
            {
              v.push_back(str);
              getline(status_file, token);
              v.push_back(token);
              v.push_back(" |");
           }
       }
   }   
  status_file.close();
}

/*Find deadline from date.txt*/
void find_deadline(std::string& str)
{
   std::ifstream deadline_file;
  deadline_file.open("date.txt");
  std::string token;
  
  if(deadline_file.is_open())
   {
     while(!deadline_file.eof())
       {
         deadline_file >> token;
     
           while(str == token)
            {
              v.push_back(str);
              getline(deadline_file, token);
              v.push_back(token);
              v.push_back(" |");
           }
       }
   }  
  deadline_file.close();
}

/*Find assigned from assigned.txt*/
void find_assigned(std::string& str)
{
  std::ifstream assigned_file;
  assigned_file.open("assigned.txt");
  std::string token;
  
  if(assigned_file.is_open())
   {
     while(!assigned_file.eof())
       {
         assigned_file >> token;
     
           while(str == token)
            {
              v.push_back(str);
              getline(assigned_file, token);
              v.push_back(token);
              v.push_back(" |");
           }
       }
   }  
  assigned_file.close();
}

/*Find task from task.txt*/
void find_task(std::string& str)
{
  std::ifstream task_file;
  task_file.open("task.txt");
  std::string token;
  
  if(task_file.is_open())
   {
     while(!task_file.eof())
       {
         task_file >> token;
     
           while(str == token)
            {
              v.push_back(str);
              getline(task_file, token);
              v.push_back(token);
              v.push_back(" | ");
            }
       }
   }   
  task_file.close();
}

/*Find admin name from admin.txt*/
void find_admin(std::string& str)
{
  std::ifstream project_admin_file;
  project_admin_file.open("admin.txt");
  std::string token;
  
  if(project_admin_file.is_open())
   {
     while(!project_admin_file.eof())
       {
         project_admin_file >> token;
     
           while(str == token)
            {
              v.push_back(str);
              getline(project_admin_file, token);
              v.push_back(token);
              //v.push_back(" |");
           }
       }
   }  
  project_admin_file.close();
}

/*Find project from project.txt*/
void find_project(std::string& str)
{
  std::ifstream project_file;
  project_file.open("project.txt");
  std::string token;
  
  if(project_file.is_open())
   {
     while(!project_file.eof())
       {
         project_file >> token;
     
           while(str == token)
            {
              v.push_back(str);
              getline(project_file, token);
              v.push_back(token);
             // v.push_back(" ");
           }
       }
   }  
  project_file.close();
}

/*Print vector*/
void print_info(std::vector<std::string>& v)
{
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i];
  std::cout << std::endl;
  v.clear();
}

/*Project creator controller*/
void project_creator_controller()
{
 std::ofstream project_admin_file, project_file, task_file, assigned_file, date_file, status_file;
 std::string project_admin_path, project_path, task_path, assigned_path, date_path, status_path;   
  
    std::cout << "Enter the name of the project admin file as show: ' admin ' " << std::endl;
    std::cin >> project_admin_path;
    project_admin_file.open (project_admin_path + ".txt");

    std::cout << "Enter the name of the project file as show: ' project ' " << std::endl;
    std::cin >> project_path;
    project_file.open (project_path + ".txt");

    std::cout << "Enter the name of the task file as show: ' task  ' " << std::endl;
    std::cin >> task_path;
    task_file.open (task_path + ".txt");
    
    std::cout << "Enter the name of the assigned file as show: ' assigned ' " << std::endl;
    std::cin >> assigned_path;
    assigned_file.open (assigned_path + ".txt");

    std::cout << "Enter the name of the date file as show: ' date '" << std::endl;
    std::cin >> date_path;
    date_file.open (date_path + ".txt");

   std::cout << "Enter the name of status file as show: ' status '" << std::endl;
    std::cin >> status_path;
    status_file.open (status_path + ".txt") ;

  std::cout << "Please, enter the number of your project by this format: '1' " << std::endl;
  int project_number;
  std::cout << "project_number = ";
  std::cin >> project_number;
  std::string str = type_conv_int_to_string(project_number) + '.' + ' ';
  
  
    if (project_admin_file.is_open() && project_file.is_open() && task_file.is_open() && assigned_file.is_open() && date_file.is_open() && status_file.is_open())
    {
      project_admin(project_admin_file, str);
      create_project(project_file, str); 
      creat_task(task_file, str);
      assigned_name(assigned_file, str);
      dead_line(date_file, str);
      status_project(status_file, str);
    }
    else
    {
        std::cout << "\nError !" << std::endl;
    }
  project_admin_file.close();
  project_file.close();
  task_file.close();
  assigned_file.close();
  date_file.close();
  status_file.close();
}

/*Create new project*/
void  create_project(std::ofstream& project_file, std::string& str)
{

   std::cout << "Enter the project's name: " << std::endl;
   std::string project_name;
  // std::cin.ignore();
   getline(std::cin, project_name);
   if (!chek_project_name_in_project_file(project_name))
    {
      project_file << str << "Project: " << project_name;
    }
  else 
    {
     std::cout << "The name of project you have in project file." << std::endl;
    }     
  std::cout << std::endl;
}

/*Create task for project*/
void creat_task(std::ofstream& task_file, std::string& str)
{
  std::cout << "Enter the task discribtion: " << std::endl;
   std::string task_name;
  // std::cin.ignore();
   getline(std::cin, task_name);
   task_file << str << "Task: " << task_name;  
  std::cout << std::endl;
}

/*Add admin name in admin.txt file */
void project_admin(std::ofstream& project_admin_file, std::string& str)
{
  std::cout << "Enter the project andmin name. Only project andmin can change or add or delete tasks or projects: " << 
  std::endl;
  
  std::string project_admin_name;
  std::cin.ignore();
  getline(std::cin, project_admin_name);
  project_admin_file << str << "Admin: "<< project_admin_name;
  std::cout << std::endl;
}

/*Add assigned name in assigned.txt file if we have not. */
void assigned_name(std::ofstream& assigned_file, std::string& str)
{
  std::cout << "Enter the assigned name: " << std::endl;
 std::string assigned_name;
 // std::cin.ignore();
  getline(std::cin, assigned_name);
  assigned_file << str << "Assigned: " << assigned_name;

  std::cout << std::endl;
}

void dead_line(std::ofstream& date_file, std::string& str)
{
  std::cout << "Please, enter the deadline by this format: day/month/year " << std::endl;
  int day, month, year;
  std::cout << "day ";
  std::cin >> day;
  std::cout << std::endl;

  std::cout << "month ";
  std::cin >> month;
  std::cout << std::endl;

  std::cout << "year ";
  std::cin >> year;
  std::cout << std::endl;
  
  std::string date_name;

  if (day >= 1 && day <= 31)
  {
   date_name += type_conv_int_to_string(day);
  }

    if (month >= 1 && month <= 12)
  {
   date_name = date_name + '/' + type_conv_int_to_string(month) + '/';
  }
  
  date_name += type_conv_int_to_string(year);
  date_file << str << "Deadline: " << date_name; 
  std::cout << std::endl;
}

std::string type_conv_int_to_string(int date)
{
  std::string str = std::to_string(date); 
  return str;
}

/*Chek project_name we have in project file or not*/
bool chek_project_name_in_project_file(std::string& project_name)
{
   std::ifstream file;
  std::string str, tmp;
   if (file.is_open())
   {
    file >> tmp;
     str += tmp; 
   }
  else 
   {
      std::cout << "Something was gone wrong!!!" << std::endl;
   }

  if(project_name.length() == str.length())
    {  
     {
       for (int i = 0; i < project_name.length(); )
        {
          if (project_name[1] == str[i])
           {
             ++i;
           } 
        }
      }  
      return true;
    }
  else 
    {
     return false;
    } 
}

void status_project(std::ofstream& status_file, std::string& str)
{
  //std::cout << "Please, define the status for your project." << std::endl;
  std::cout << " Enter 1, if your project is to do. Enter 2, if your project is in process. Enter 3, if your project is done." << std::endl;
  
  int num;
  std::cin >> num;
  std::cout << std::endl;

  switch(num)
    {
      case 1:
          status_file << str << "Status: " << "to do";
          break;
        
      case 2:
           status_file << str << "Status: " << "in process";
          break;
      case 3:
          status_file << str << "Status: " << "done";
          break;
      default:
      std::cout << "Overdue!!!!!";   
      }
  std::cout << std::endl;
}
