#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 100

void menu();
void list();
void add();
void delete();
// int update(int id);
int findIndex(int id);


typedef struct Customer
{
    char name[50];
    char gender; // m或者f
    int age;
    char phone[50];
    char email[50];
    int id;
} Customer;

Customer customers[NUM];
int loop = 1;
char key;
int customerNum = 1;
char choice = ' ';
char n;


int update(int id)
{
     int index = findIndex(id);

    if (index == -1) {
        printf("用户不存在");
        return 0;
    }

    rewind(stdin);
    printf("\n-------修改客户-------");
    printf("\n姓名(%s):", customers[index].name);

    char ch, b[50], name[50];
	ch=getchar();
	if (ch == 10) {
		// printf("打了空格\n");
	} else {
		//不是空格 保存字符
		scanf("%s", b);
		strcpy(name, &ch);
		strcat(name, b);
        printf("name=%s\n", name);
        strcpy(customers[index].name, name);
	}

    char gender; // m或者f
    rewind(stdin);
    printf("\n性别(%c): ", customers[index].gender);

	gender=getchar();
    if (ch == 10) {
		// printf("打了空格\n");
	} else {
        customers[index].gender = gender;
    }

    int age;
    rewind(stdin);
    char c[50], ageStr[50];
    printf("\n 年龄:(%d)", customers[index].age);


	char ch2=getchar();
    if (ch2 == 10) {
		// printf("打了空格\n");
	} else {
		//不是空格 保存字符
		scanf("%s", c);
        printf("c=%s\n", c);
		strcpy(ageStr, &ch2);
		strcat(ageStr, c);
        printf("age=%s\n", ageStr);
        customers[index].age = atoi(ageStr);
	}


    rewind(stdin);
    printf("\n 电话(%s):", customers[index].phone);
    char d[50], phone[50];
	ch=getchar();
	if (ch == 10) {
		// printf("打了空格\n");
	} else {
		//不是空格 保存字符
		scanf("%s", d);
		strcpy(phone, &ch);
		strcat(phone, d);
        printf("phone=%s\n", phone);
        strcpy(customers[index].phone, phone);
	}



    rewind(stdin);
    char e[50], email[50];
    printf("\n 邮箱(%s):", customers[index].email);
    ch=getchar();
	if (ch == 10) {
		// printf("打了空格\n");
	} else {
		//不是空格 保存字符
		scanf("%s", e);
		strcpy(email, &ch);
		strcat(email, e);
        printf("email=%s\n", email);
        strcpy(customers[index].email, email);
	}

    printf("\n-------修改完成-------");
    return 0;
}

void menu()
{
    do
    {
        printf("\n\n-------客户信息管理软件---------");
        printf("\n                      1.添加客户");
        printf("\n                      2.修改客户");
        printf("\n                      3.删除客户");
        printf("\n                      4.客户列表");
        printf("\n                      5.退出");
        printf("\n请选择（1-5）");
        scanf("%c", &key);
        getchar();

        switch (key)
        {
        case '1':
            add();
            break;
         case '2':{
             int id;
             printf("请输入需要修改的用户的id\n");
             scanf("%d", &id);
            update(id);
            break;
         }
            
         case '3':
            delete();
            break;
         case '4':
            list();
            break;

        case '5':
            do
            {
                printf("\n确认是否退出(Y/N):");
                scanf("%c", &choice);
                getchar();
            } while (choice != 'Y' && choice != 'N');

            if (choice == 'Y') {
                loop = 0;
            }
            break;
            
        
        default:
            printf("\n 你输入有误， 请重新输入...");
            break;
        }
    } while (loop);

    printf("\n 你退出了客户管理系统");
    getchar();
    
}

void get(Customer *customer)
{
    printf("\n%d\t%s\t%c\t%d\t%s\t%s", (*customer).id, (*customer).name, (*customer).gender, (*customer).age, (*customer).phone, (*customer).email);
}

void list()
{
    printf("----------客户列表-----------");
    printf("\n编号\t姓名\t性别\t年龄\t电话\t邮箱");
    for (int i = 0; i < customerNum; i++)
    {
        get(&customers[i]);
    }
    
}

void add()
{
    customers[customerNum].id = customerNum + 1;
    printf("\n-------添加客户-------");
    printf("\n姓名:");
    scanf("%s", customers[customerNum].name);
    getchar();
    printf("\n性别: ");
    scanf("%c", &(customers[customerNum].gender));
    getchar();
    printf("\n 年龄:");
    scanf("%d", &(customers[customerNum].age));
    getchar();
    printf("\n 电话:");
    scanf("%s", customers[customerNum].phone);
    getchar();
    printf("\n 邮箱:");
    scanf("%s", customers[customerNum].email);
    getchar();
    customerNum++;
    printf("\n-------添加完成-------");
}

int findIndex(int id)
{
    int index = -1;
    int i;
    for (i = 0; i < customerNum; i++)
    {
        if (customers[i].id == id) {
            index = i;
        }
    }

    return index;
}

int destroy(int id)
{
    int index = findIndex(id);

    if (index == -1) {
        return 0; //失败
    } else {
        for (int i = index + 1; i < customerNum; i++)
        {
            customers[i-1] = customers[i];
        }

        customerNum--;
        return 1;
    }
}

void delete()
{
    int id = 0;
    char choice = ' ';
    printf("\n----------删除客户-----------");
    printf("\n请选择待删除的客户编号(-1退出)：");
    scanf("%d", &id);
    getchar();

    if (id == -1) {
        printf("放弃删除\n");
        return;
    }

    printf("\n确认是否删除（Y/N）:");
    scanf("%c", &choice);
    getchar();

    if (choice == 'Y') {
        if (!destroy(id)) {
            printf("\n-----删除失败----");
        } else {
            printf("\n-----删除成功----");
        }
    }
}

int main() {

    customers[0].id = 1;
    customers[0].age = 10;
    strcpy(customers[0].email, "test@test.com");
    customers[0].gender = 'f';
    strcpy(customers[0].name, "test");
    strcpy(customers[0].phone, "phone");

    menu();
    return 0;
}

