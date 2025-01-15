#include <stdio.h>
#include <string.h>
#define MAX_employeeS 1000

//employee structure containing name and id
struct employee
{
    char name[100];
    char position[100];
    int salary;
    int id;
};

//Add employee function
void addEmployee(struct employee employees[], int *total_employee_at_this_moment)
{
    struct employee newemployee;

    printf("\nName : ");
    scanf("%s",newemployee.name);
    printf("\nPosition : ");
    scanf("%s",newemployee.position);
    printf("\nSalary : ");
    scanf("%d",&newemployee.salary);

    //id generate
    newemployee.id = (*total_employee_at_this_moment)+1;
    employees[*total_employee_at_this_moment]= newemployee; // 0

    (*total_employee_at_this_moment)++;//1 //while adding first employee it becomes 1
    printf("New Employee ID %d\n", newemployee.id);
}

//update Employee information
void updateInfo(struct employee employees[], int total_employee_at_this_moment)
{
    int given_id;
    printf("Enter ID: ");
    scanf("%d", &given_id);
    int found = 0;
    for (int i = 0; i < total_employee_at_this_moment; i++)
    {
        if(given_id == employees[i].id)
        {
            found = 1;
            printf("New Name:");
            scanf("%s", employees[i].name);
            printf("New Position:");
            scanf("%s", employees[i].position);
            printf("New Salary:");
            scanf("%s", employees[i].salary);
            printf("\nNew Employee with ID %d updated!", given_id);
            break;
        }
    }

    if(found == 0)
    {
        printf("Employee with ID %d Not Found\n", given_id);
    }

}



//delete employee
void deleteemployee(struct employee employees[], int *total_employee_at_this_moment)
{
    int given_id;
    printf("Enter ID: ");
    scanf("%d", &given_id);
    int found = 0;
    for (int i = 0; i < *total_employee_at_this_moment; i++)
    {
        if(given_id == employees[i].id)
        {
            found =1;
            for (int j = i; j < *total_employee_at_this_moment-1; j++)
            {
                employees[j]= employees[j+1];
            }
            (*total_employee_at_this_moment)--;
            printf("\Employee  with ID %d Deleted Successfully ", given_id);
            break;
        }
    }

    if(found == 0)
    {
        printf("Employee with id %d not found\n", given_id);
    }


}

//view employee information
void viewemployeeInfo(struct employee employees[], int total_employee_at_this_moment)
{
    int given_id;
    printf("Enter ID: ");
    scanf("%d", &given_id);
    int found = 0;
    for (int i = 0; i < total_employee_at_this_moment; i++)
    {
        if(given_id == employees[i].id)
        {
            found = 1;

            printf("\nName: %s", employees[i].name);

            printf("\nPosition: %s", employees[i].position);

            printf("\nSalary: %d", employees[i].salary);

            printf("\n Employee  ID: %d ", given_id);
            break;
        }
    }

    if(found == 0)
    {
        printf("Employee with ID %d Not Found\n", given_id);
    }

}



//main function

int main()
{
    struct employee employees[MAX_employeeS];
    int total_employee_at_this_moment = 0;

    int choice;
    while(1)
    {
        printf("\n----------------------\n");
        printf("!!Employee Record Management System!!\n");
        printf("----------------------\n");

        printf("1. Add New Employee\n");
        printf("2. Update Employee Information\n");
        printf("3. Delete Employee\n");
        printf("4. View Employee Information\n");
        printf("5. Exit\n");
        printf("Enter  Choice: ");
        scanf("%d", &choice);

        //function calls here----
        switch(choice)
        {
        case 1:
            addEmployee(employees, &total_employee_at_this_moment);
            break;
        case 2:
            updateInfo(employees, total_employee_at_this_moment);
            break;
        case 3:
            deleteemployee(employees, &total_employee_at_this_moment);
            break;
        case 4:
            viewemployeeInfo(employees, &total_employee_at_this_moment);
            break;
        case 5:
            printf("Exiting....\n");
            return 0;

        default:
            printf("INVALID CHOICE! TRY AGAIN.\n");
            break;

        }

    }
    return 0;
}

