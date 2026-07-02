#include<stdio.h>
#include<string.h>
#define MAX 100         //最大存储100条住宿记录

typedef struct
{
    char id[20];        //学号
    char name[20];      //姓名
    char classname[20]; //班级
    char dormno[20];    //宿舍号
    char phone[15];     //联系方式
    char date[20];      //入住时间
}Student;

Student dormArr[MAX];   // 结构体数组充当内存数据库
int count=0;            //当前实际记录条数
FILE *fp;

//函数声明
void input_student();   //录入
void query_student();   //查询
void modifyStu();       //修改
void deleteStu();       //删除
void save_data();       //保存数据
void load_data();       //加载数据
void menu();            //菜单

// 主菜单界面
void menu()
{
    printf("==========学生住宿档案管理系统==========\n");
    printf("1. 新增学生住宿档案\n");
    printf("2. 查询学生住宿档案\n");
    printf("3. 修改学生住宿档案\n");
    printf("4. 删除学生住宿档案\n");
    printf("0. 退出系统并保存数据\n");
    printf("========================================\n");
}


void load_data()
{
    fp=fopen("dorm.dat","rb");
    if(fp==NULL)
    {
        //文件不存在则新建，初始条数为0
        return;
    }
    //循环读取结构体数据
    while(fread(&dormArr[count],sizeof(Student),1,fp)==1)
    {
        count++;
    }
    fclose(fp);
}

// 保存所有数据到dorm.dat
void save_data()
{
    fp=fopen("dorm.dat","wb");
    if(fp==NULL)
    {
        printf("文件打开失败，保存失败！\n");
        return;
    }
    fwrite(dormArr, sizeof(Student), count, fp);
    fclose(fp);
}

//录入新档案
void input_student()
{
    if(count>=MAX)
    {
        printf("档案数量已达上限，无法继续添加！\n");
        return;
    }
    Student s;
    printf("=====录入学生住宿信息=====\n");
    printf("学号：");
    scanf("%s", s.id);
    getchar();           //吸收回车符
    printf("姓名：");
    scanf("%s", s.name);
    getchar();
    printf("班级：");
    scanf("%s", s.classname);
    getchar();
    printf("宿舍号：");
    scanf("%s", s.dormno);
    getchar();
    printf("入住时间：");
    scanf("%s", s.date);
    getchar();
    printf("手机号码：");
    scanf("%s", s.phone);
    getchar();

    dormArr[count]=s;
    count++;
    printf("新增档案成功！\n");
}

//按学号/姓名查询
void query_student()
{
    if (count==0)
    {
        printf("暂无任何住宿档案！\n");
        return;
    }
    char key[20];
    int flag=0;//标记是否找到
    printf("请输入要查询的学号或姓名：");
    scanf("%19s", key);

    printf("\n%-12s%-8s%-12s%-8s%-12s%-12s\n","学号","姓名","班级","宿舍号","入住时间","手机号");
    for (int i=0;i<count;i++)
    {
        if (strcmp(dormArr[i].id,key)==0||strcmp(dormArr[i].name,key)==0)
        {
            printf("%-12s%-8s%-12s%-8s%-12s%-12s\n",dormArr[i].id, dormArr[i].name, dormArr[i].classname,dormArr[i].dormno, dormArr[i].date, dormArr[i].phone);
            flag=1;
        }
    }
    if (!flag)
    {
        printf("未查询到匹配的住宿档案\n");
    }
}

//修改档案
void modifyStu()
{
    if(count==0)
    {
        printf("暂无档案，无法修改！\n");
        return;
    }

    char id[20];
    int pos=-1;
    printf("请输入需要修改的学生学号：");
    scanf("%19s", id);

    // 查找下标
    for(int i=0;i<count;i++)
    {
        if (strcmp(dormArr[i].id,id)==0)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        printf("没有该学生档案\n");
        return;
    }

    //重新录入新信息覆盖
    printf("=====重新填写新信息=====\n");
    printf("新姓名：");
    scanf("%19s", dormArr[pos].name);
    printf("新班级：");
    scanf("%19s", dormArr[pos].classname);
    printf("新宿舍号：");
    scanf("%19s", dormArr[pos].dormno);
    printf("新入住时间：");
    scanf("%19s", dormArr[pos].date);
    printf("新手机号：");
    scanf("%14s", dormArr[pos].phone);
    printf("档案修改完成！\n");
}

//删除档案（数据前移覆盖）
void deleteStu()
{
    if (count==0)
    {
        printf("暂无档案，无法删除！\n");
        return;
    }
    char id[20];
    int pos=-1;
    printf("请输入要删除的学生学号：");
    scanf("%19s",id);

    for(int i=0;i<count;i++)
    {
        if(strcmp(dormArr[i].id,id)==0)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        printf("未找到该学生\n");
        return;
    }

    //后面所有记录往前移动一位，覆盖要删除的数据
    for (int i=pos;i<count-1;i++)
    {
        dormArr[i]=dormArr[i+1];
    }
    count--;//总条数减一
    printf("档案删除成功！\n");
}

int main()
{
    load_data();
    int choice;
    while(1)
    {
        menu();
        printf("请输入功能序号:");
        scanf("%d",&choice);
        getchar();

        switch(choice)
        {
            case 1:input_student();break;
            case 2:query_student();break;
            case 3:modifyStu();break;
            case 4:deleteStu();break;
            case 0:
                save_data();
                printf("感谢使用，再见！\n");
                return 0;
            default:
                printf("输入错误，请重新选择！\n");
                break;
        }
    }
}
