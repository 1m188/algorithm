/*
Description
设计一个类Person表示人，类的定义为：
class Person{
	private:
		char name[20],sex,Id[20];
	public:
		void setPerson(char *p,char s,char *d){
		
		}
		char* getName(){
			
		}
		char getSex(){
			
		}
		char* getId(){
			
		}
};
然后将人的信息按照格式输出。
PS:
字符串之间的copy，比如要将字符串a的值赋值给字符串b使用
strcpy(b,a)

Input
第一行输入一个t，代表t组数据，然后输入name，sex，Id;

Output
按照Sample Output格式输出

Sample Input
2
Joe m 20150106
Jan f 20150107

Sample Output
The sex of Joe is m
The Id of Joe is 20150106
The sex of Jan is f
The Id of Jan is 20150107
*/

#include "cstdio"
#include "cstring"
#include "vector"

class Person
{
  private:
    char name[20], sex, Id[20];

  public:
    void setPerson(char *p, char s, char *d);
    char *getName();
    char getSex();
    char *getId();
};

void Person::setPerson(char *p, char s, char *d)
{
    strcpy_s(name, 20, p);
    sex = s;
    strcpy_s(Id, 20, d);
}

char *Person::getName()
{
    return name;
}

char Person::getSex()
{
    return sex;
}

char *Person::getId()
{
    return Id;
}

int main() //PE。首先，类很烂，容易内存泄漏，而且封装性不好，甚至连构造函数都没有。然后就是总是PE....
{
    int t = 0;
    scanf("%d", &t);
    std::vector<Person> p(t, Person());
    for (int i = 0; i < t; i++)
    {
        char name[20]{};
        scanf("%s", name);
        getchar(); //注意，由于输入了字符串之后有一个空格，所以这个空格要用getchar吃掉，不然会传到下一个sex里面
        char sex{};
        scanf("%c", &sex);
        char Id[20]{};
        scanf("%s", Id);
        p[i].setPerson(name, sex, Id);
    }

    for (std::vector<Person>::iterator it = p.begin(); it != p.end(); it++)
    {
        printf("The sex of %s is %c\n", (*it).getName(), (*it).getSex());
        printf("The Id of %s is %s", (*it).getName(), (*it).getId());
        if (it != p.end() - 1)
        {
            printf("\n");
        }
    }

    return 0;
}