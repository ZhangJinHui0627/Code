#include<stdio.h>
#include<string.h>
#define MAX_NUM 100    //最大存储100条住宿记录

typedef struct
{
    char id[20];        //学号
    char name[20];      //姓名
    char classname[20]; //班级
    char dormno[20];    //宿舍号
    char phone[15];     //联系方式
    char date[20];      //入住时间
}Student;

//函数声明
void input_student(); //录入
void query_student(); //查询
void modifyStu();     //修改
void deleteStu();     //删除
void save_data();     //保存数据
void load_data();     //加载数据
int menu();           //菜单
int count=0;          //当前实际记录条数
Student dormArr[MAX_NUM]; // 结构体数组充当内存数据库

//功能3:修改档案
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
    gets(id);

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
    gets(dormArr[pos].name);
    printf("新班级：");
    gets(dormArr[pos].classname);
    printf("新宿舍号：");
    gets(dormArr[pos].dormno);
    printf("新入住时间：");
    gets(dormArr[pos].date);
    printf("新手机号：");
    gets(dormArr[pos].phone);
    printf("档案修改完成！\n");
}

//功能4：删除档案（数据前移覆盖）
void deleteInfo()
{
    if (count==0)
    {
        printf("暂无档案，无法删除！\n");
        return;
    }
    char id[20];
    int pos=-1;
    printf("请输入要删除的学生学号：");
    gets(id);

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
