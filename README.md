Project Management System

This is a simple console-based project management system implemented in C++. It allows users to create and manage projects, add tasks to projects, assign project administrators, set deadlines, and track project statuses. The system saves project-related information in separate files for each aspect, such as project details, assigned names, deadlines and statuses.

Features:

1. Create a New Project: Users can create new projects and assign project administrators to manage them.
2. Add Tasks: For each project, users can add tasks with their descriptions.
3. Assign Names: Users can assign team members' names to specific projects.
4. Set Deadlines: Projects can have deadlines specified by users.
5. Track Status: The system provides options to set project status (To Do, In Progress, or Done).
6. Modify Projects and Tasks: Users can update or delete tasks and projects.

Usage:
1. Compile and Run: Compile the main.cpp file and run the executable.
2. Create a Project: If you want to create a new project, enter 0 when prompted. You will need to enter the project admin's name, project name, task description, assigned name, deadline, and status.
3. View Existing Projects: If you already have projects created, enter 1 when prompted. The system will display the names of existing projects.
4. Choose a Project: Select a project by entering the corresponding project number.
5. Modify Projects or Tasks: The system will prompt you to update tasks, create new tasks, or delete tasks. Enter 0 to update a task, 1 to create a new task, or 2 to delete a task.

File Organization:

The system uses separate text files to store project-related data:

* project.txt: Contains project names.
* admin.txt: Contains project administrators' names.
* task.txt: Contains task descriptions.
* assigned.txt: Contains assigned names.
* date.txt: Contains project deadlines.
* status.txt: Contains project statuses.

Notes:

The system is currently a basic console prototype and may not handle all edge cases or errors.
Ensure that input data is entered correctly and follow the specified date format (day/month/year).
The system does not support concurrent access to files and is not suitable for multi-user scenarios.
