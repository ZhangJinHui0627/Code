#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.定义住宿档案结构体
typedef struct {
    char id[20];        // 学号
    char name[15];      // 姓名
    char className[20]; // 班级
    char dormNo[10];    // 宿舍号
    char inTime[15];    // 入住时间
    char phone[15];     // 联系方式
} StuDorm;

#define MAX_NUM 100     //最大存储100条住宿记录
StuDorm dormArr[MAX_NUM]; // 结构体数组充当内存数据库
int count = 0;            // 当前实际记录条数
FILE *fp;

// 函数声明
void loadData();       // 从文件读取数据到数组
void saveData();       // 将数组数据写入文件保存
void addInfo();        // 1.录入住宿档案
void searchInfo();     // 2.查询档案(学号/姓名双匹配)
void modifyInfo();      // 3.修改档案
void deleteInfo();     // 4.删除档案
void menu();           // 打印主菜单

int main() {
    loadData(); // 程序启动先加载本地文件数据
    int choice;
    while (1) {
        menu();
        printf("请输入功能序号：");
        scanf("%d", &choice);
        getchar(); // 吸收换行符

        switch (choice) {
            case 1: addInfo(); break;
            case 2: searchInfo(); break;
            case 3: modifyInfo(); break;
            case 4: deleteInfo(); break;
            case 0:
                saveData(); // 退出前保存全部数据
                printf("数据已保存，程序退出\n");
                exit(0);
            default:
                printf("输入错误，请重新选择！\n");
        }
        printf("\n按下回车键继续...");
        getchar();
        system("cls"); // 清屏
    }
    return 0;
}

// 主菜单界面
void menu() {
    printf("====================学生住宿档案管理系统====================\n");
    printf("1. 新增学生住宿档案\n");
    printf("2. 查询学生住宿档案\n");
    printf("3. 修改学生住宿档案\n");
    printf("4. 删除学生住宿档案\n");
    printf("0. 退出系统并保存数据\n");
    printf("============================================================\n");
}

// 从dorm.dat加载历史数据
void loadData() {
    fp = fopen("dorm.dat", "rb");
    if (fp == NULL) {
        // 文件不存在则新建，初始条数为0
        return;
    }
    // 循环读取结构体数据
    while (fread(&dormArr[count], sizeof(StuDorm), 1, fp) == 1) {
        count++;
    }
    fclose(fp);
}

// 保存所有数据到dorm.dat
void saveData() {
    fp = fopen("dorm.dat", "wb");
    if (fp == NULL) {
        printf("文件打开失败，保存失败！\n");
        return;
    }
    fwrite(dormArr, sizeof(StuDorm), count, fp);
    fclose(fp);
}

// 功能1：录入新档案
void addInfo() {
    if (count >= MAX_NUM) {
        printf("档案数量已达上限，无法继续添加！\n");
        return;
    }
    StuDorm temp;
    printf("=====录入学生住宿信息=====\n");
    printf("学号：");
    gets(temp.id);
    printf("姓名：");
    gets(temp.name);
    printf("班级：");
    gets(temp.className);
    printf("宿舍号：");
    gets(temp.dormNo);
    printf("入住时间：");
    gets(temp.inTime);
    printf("手机号码：");
    gets(temp.phone);

    dormArr[count] = temp;
    count++;
    printf("新增档案成功！\n");
}

// 功能2：按学号/姓名查询
void searchInfo() {
    if (count == 0) {
        printf("暂无任何住宿档案！\n");
        return;
    }
    char key[20];
    int flag = 0; // 标记是否找到
    printf("请输入要查询的学号或姓名：");
    gets(key);

    printf("\n%-12s%-8s%-12s%-8s%-12s%-12s\n", "学号", "姓名", "班级", "宿舍号", "入住时间", "手机号");
    for (int i = 0; i < count; i++) {
        if (strcmp(dormArr[i].id, key) == 0 || strcmp(dormArr[i].name, key) == 0) {
            printf("%-12s%-8s%-12s%-8s%-12s%-12s\n",
                   dormArr[i].id, dormArr[i].name, dormArr[i].className,
                   dormArr[i].dormNo, dormArr[i].inTime, dormArr[i].phone);
            flag = 1;
        }
    }
    if (!flag) {
        printf("未查询到匹配的住宿档案\n");
    }
}

// 功能3：修改档案
void modifyInfo() {
    if (count == 0) {
        printf("暂无档案，无法修改！\n");
        return;
    }
    char id[20];
    int pos = -1;
    printf("请输入需要修改的学生学号：");
    gets(id);

    // 查找下标
    for (int i = 0; i < count; i++) {
        if (strcmp(dormArr[i].id, id) == 0) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("没有该学生档案\n");
        return;
    }

    // 重新录入新信息覆盖
    printf("=====重新填写新信息=====\n");
    printf("新姓名：");
    gets(dormArr[pos].name);
    printf("新班级：");
    gets(dormArr[pos].className);
    printf("新宿舍号：");
    gets(dormArr[pos].dormNo);
    printf("新入住时间：");
    gets(dormArr[pos].inTime);
    printf("新手机号：");
    gets(dormArr[pos].phone);
    printf("档案修改完成！\n");
}

// 功能4：删除档案（数据前移覆盖）
void deleteInfo() {
    if (count == 0) {
        printf("暂无档案，无法删除！\n");
        return;
    }
    char id[20];
    int pos = -1;
    printf("请输入要删除的学生学号：");
    gets(id);

    for (int i = 0; i < count; i++) {
        if (strcmp(dormArr[i].id, id) == 0) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("未找到该学生\n");
        return;
    }

    // 后面所有记录往前移动一位，覆盖要删除的数据
    for (int i = pos; i < count - 1; i++) {
        dormArr[i] = dormArr[i + 1];
    }
    count--; // 总条数减一
    printf("档案删除成功！\n");
}
