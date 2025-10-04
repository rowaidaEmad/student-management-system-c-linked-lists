/*
 ============================================================================
 Name        : Project1_Student_Managemnt_System_With_Linked_List.c
 Author      : Rowaida
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define yes 1
#define no 0
/*some notes about my code:
 * 1. helper functions are build functions to help the major functions that are called in the main program
 * the are not build to be used alone , the helper functions contains logically repeated code  can be
 * used to avoid repeated in future program expanding
 *
 * 2.major functions that are called in the main are 7 as descried in the project requirements
 *
 */
//--------Data Structures----------
struct student{
	int id;
	char name[50];
	int age;
	float gpa;
};
struct node{
	struct student data;
	struct node *next;
};
struct node* head =NULL;
//---------prototypes---------------------------------------------
void addStudent(const struct student *const ptr);
int exist(int id,struct node ** ptr,struct node **prevptr);//helper function to check if id exists & re-point pointer to the node of this id
void addNodeAtEnd(struct node * newnode);//helper function a
void displayStudents(void);
struct student collectDataCorrectlly(int is_update);//helper function

void searchStudentByID(int id);

void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);
void myFlush(){ //helper function to flush
	/** idea:
	 * so we clear the buffer by reading the chars in buffers until no more so it reach end of file or it is end of line if user entered newline
	 * why clear buffer -> because if scanf read something unexpected ex:wrong type it will be left in the buffer and read the wrong input forever if not cleared from buffer manually
	 * so infinite loop may occur or skipped prompts
	 */
	int ch;
	while( ((ch = getchar())!='\n') && (ch!=EOF) ){}
}
//--------Main Program-------------------------------------------
int main(void) {
	setbuf(stdout, NULL);

	int close_flag=0;
	while(!close_flag)
	{	int choice;
	    printf("------------------------------------------------------------\n");
		printf("1. Add Student\n");
		printf("2. Display Students\n");
		printf("3. Search Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Delete Student\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Search for Student with Highest GPA\n");
		printf("8. Exit\n");
		printf("Enter choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			{
				//collect new student data
				struct student newStudent = collectDataCorrectlly(no);//this no means it is not an update
				addStudent(&newStudent);//add new student
				break;
			}
			case 2:
				displayStudents();
				break;
			case 3:
			{
				int correctID=0 ,id;
				printf("Enter student ID to Search it's information: ");
				correctID=scanf("%d",&id);
				while(!correctID)
				{
					printf("Invalid ID input -enter an integer- , again Enter student ID to Search it's information: \n");
					myFlush();
					correctID=scanf("%d",&id);
				}
				searchStudentByID(id);
				break;
			}
			case 4:
			{
				int correctID=0 ,id;
				printf("Enter student ID to Update it's information: ");
				correctID=scanf("%d",&id);
				while(!correctID)
				{
					printf("Invalid ID input -enter an integer- , again Enter student ID to Update it's information: \n");
					myFlush();
					correctID=scanf("%d",&id);
				}
				updateStudent(id);
				break;
			}
			case 5:
			{
				int correctID=0 ,id;
				printf("Enter student ID to Delete it's information: ");
				correctID=scanf("%d",&id);
				while(!correctID)
				{
					printf("Invalid ID input -enter an integer- , again Enter student ID to Delete it's information: \n");
					myFlush();
					correctID=scanf("%d",&id);
				}
				deleteStudent(id);
			 }
				break;
			case 6:
				printf("Average GPA = %.3f\n",calculateAverageGPA());
				break;
			case 7:
				searchHighestGPA();
				break;
			case 8:
			{
				close_flag=1;
				printf("Exiting....\n");
				break;
			}
		}

	}

	return EXIT_SUCCESS;
}
//---------------Functions implementations------------------------------------------
int exist(int id,struct node ** ptr,struct node **prevptr){
	struct node* current = head;
	struct node*prev = NULL;

	while(current != NULL){
		if(current->data.id == id)
		{	if(prevptr != NULL)
				*prevptr=prev; // changing what passed pointer points to ,to point to prev node if needed
			if(ptr != NULL)
				*ptr=current; //changing what passed pointer points to ,to point to needed node if needed
			return true;
		}//if not found yet keep iterating
		prev=current;
		current = current->next;

	}
	return false;//not found or empty list; head==null

}
void addNodeAtEnd(struct node * newnode){
	if(head==NULL){
		head = newnode;
	}
	else{
		struct node *iterator=head;
		while(iterator->next != NULL){
			iterator=iterator->next;
		}//iterator now arrived at last node
		iterator->next=newnode;
	}
}

void addStudent(const struct student *const ptr)
{
	if(exist(ptr->id,NULL,NULL))
	{
		printf("ID: %d already exists\n",ptr->id);
		return;
	}
	else
	{	//creat new node
		struct node * newnode =(struct node* ) malloc(sizeof(struct node));
		if(newnode == NULL) //if allocation fails
		{
			printf("Error occurred: can't new allocate memory \n");
			return;
		}
		else{
			//copy of the new student to the new node
			newnode->data=*ptr;
			newnode->next=NULL;
			//add the node in the linked list at end
			addNodeAtEnd(newnode);
		}
	}

}
void displayStudents(void){
	const struct node* it=head;
	if(head==NULL)
	{
		printf("No students are added yet\n");
		return;
	}
	//else
	while(it!= NULL)
	{
		//it->data.age
		printf("[ ID: %d, Name: %s, Age: %d, GPA: %.3f ]\n",it->data.id,it->data.name,it->data.age,it->data.gpa);
		it=it->next;
	}
}
struct student collectDataCorrectlly(int is_update){
	struct student s;
	int doneID=no,doneAge=no,doneGPA=no;//flags
	if(!is_update){
		printf("Enter Student ID: \n");
		doneID=scanf("%d",&s.id);
		while(!doneID)
		{
			printf("Invalid ID input -enter an integer- , again Enter Student ID: \n");
			myFlush();
			doneID=scanf("%d",&s.id);
		}
	}
	else printf("update starting..\n");

	printf("Enter name: \n");
	scanf("%s",s.name); //in auto take it's specified size , rest will not be included

	printf("Enter age: \n");
	doneAge = scanf("%d",&s.age);
	while(!doneAge)
	{
		printf("Invalid Age input -enter an integer- , again Enter Age: \n");
		myFlush();
		doneAge = scanf("%d",&s.age);
	}

	printf("Enter GPA: \n");
	doneGPA = scanf("%f",&s.gpa);
	while(!doneGPA)
	{
		printf("Invalid GPA input -enter a Number(float or integer)- , again Enter GPA: \n");
		myFlush();
		doneGPA = scanf("%f",&s.gpa);
	}

	return s;
}

void updateStudent(int id){
	struct node* foundNode=NULL;//initialize

	if(!exist(id,&foundNode,NULL))
	{
		printf("ID: %d do NOT exist\n",id);
		return;
	}//else update and realloc
	struct student updatedStudent = collectDataCorrectlly(yes);//yes means update not new allocation
	updatedStudent.id=id;//id do not changes
	foundNode->data=updatedStudent;
	printf("update is done\n");

}
void deleteStudent(int id){
	   struct node* foundNode=NULL;//initialize
	   struct node* prevNode=NULL;
		if(!exist(id,&foundNode,&prevNode))
		{
			printf("ID: %d do NOT exist\n",id);
			return;
		}
		if(head == foundNode){//if delete node is the first node
			head=foundNode->next;
			free(foundNode);
		}
		else{//node found and it is not the first node

			prevNode->next=foundNode->next;
			free(foundNode);
		}
		printf("delete is done successfully \n");

}
void searchStudentByID(int id){
	struct node* neededStudentNode=NULL;

	if(!exist(id,&neededStudentNode,NULL)){
		printf("student ID: %d do NOT exist\n",id);
		return;
	}
	else if(neededStudentNode != NULL){
		printf("student found:\n");
		printf("ID: %d, Name: %s, Age: %d, GPA: %.3f \n",neededStudentNode->data.id,neededStudentNode->data.name,neededStudentNode->data.age,neededStudentNode->data.gpa);
	}
}
float calculateAverageGPA(void){
	struct node*it=head;
	int count=0;
	float sum=0;
	while(it!=NULL){
		sum+=it->data.gpa;
		it=it->next;
		count++;
	}
	if(count>0){
		return sum/count;
	}
	return 0.0;
}
void searchHighestGPA(void){
	if(head == NULL)
	{
		printf("There are no students yet!\n");
		return;
	}
	else
	{   printf("student/s with highest GPA:\n");
		struct node*it=head;
		float maxgpa= head->data.gpa;
			while(it != NULL)
			{
				if(it->data.gpa>maxgpa)
				{
					maxgpa=it->data.gpa;
				}
				it=it->next;
			}

			it=head;//go from start again
			while(it!=NULL)
			{
				if(it->data.gpa == maxgpa)
				{
					searchStudentByID(it->data.id);
				}
				it=it->next;
			}

	}

}
