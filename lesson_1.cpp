/*
Основы ООП - в электронном виде
Сборник задач и упражнений по С++

С++ - 1979 -> 1998 - ANSI-стандарт + STL - стандартная библиотека шаблонов

    Инкапсуляция - объединение данных и объекта 
АТД - абстрактный тип данных, все данные private 

    Полиморфизм - одинаковый интерфейс для похожих операций над разными типами
1) Статический - перегрузка операций и перегрузка функций - одно и тоже имя функций с различной сигнатурой (тип и количество параметров
2) Динамический
3) Параметрический 

    Наследование - создание иерархии классов
Человек -> студент
*/

#include <string.h>  
#include <cstring> // -> std

namespace A { 
    int a; 
    void f();
};

void A::f() {...}

int main()
{
    A::a = 5;

    using A::a;
    a = 5;

    using namespace A;
    a = 5;
}



namespace A {
    int a;
    namespace B { 
        int b;
        void f() {a += 2;}
    };
};

A::B::b



// С коллоквиума

namespace N {
    int f = 2;
    int g = 2;
};
namespace M {
    int f = 3;
    int g = -3;
};
int f = -5;

int main(void)
{
    int f = 1;
    cout << ::f << N::f << M::f << endl; // ::f - обращение к глобальной переменной. Output: -5 2 3 
    using namespace N;
    cout << f << g << endl; // Output: 1 2 - локальная > переменная из пространства имен (== глобальная)
}



#include <iostream>
using namespace std;
int a = 15;
double b = 1.3;
cout << "a=" << a << "b=" << b << endl;
int i;
double x;
char str[80];
cin >> i >> x >> str; // input: 100 1.2 string with space // str <- "string"
cin.getline(str, 79); // читает с пробелами

#include <iomanip>
using namespace std;
cout << setw(10) << a << b; // |        15|1.3 - поле ширины 10
oct, dec, hex, setprecision(n) - точность

// in C
int abs(int)
double fabs(double)
long labs(long)

// в С++ функция с одним и тем же именем (разная сигнатура) - перегрузка функций



inline double sum(double x, double y) // вместо функции подставляется тело функции
{
    return x + y;
}


struct s {
    int x;
    static int y; // одно поле на все объекты данной структуры
};

//int s::y = 100;
int main(void) 
{
    s a, b;
    a.y = 10; // ошибка: нужна глобальная память
    cout << b.y << endl; // 10
}

new // аналог calloc
delete // аналог free
// new и delete - операции

int *p = new int[100];
int *q = new int(7); // *q = 7

delete []p; // для освобождения массива
delete q;

p = nothrow new int[70000000000] // bad_calloc. p == NULL => ошибка



void f(int a = 0, int b = 2); // значения по умолчанию. Подставляются при отсутствии параметра
f();
f(10);
f(10, 20);



int a = 10;
int &b = a; // ссылка - b - синоним имени a

void f(int &x) // обращается сразу к памяти аргумента
{
    x += 2;
}

void g(const long &x)
{
    ...
}

int main(void) 
{
    int a = 5;
    f(a); // a = 7
    long &b = a; // не надо так
    /*  
        long temp = (long) a;
        long &b = temp;
    */
    g(a); // а так можно
}



char & f(char *str) // нужно найти первый пробел и 
{
    int i;
    for (i = 0; str[i] && str[i] != ' '; i++);
    return str[i];
}

int main(void)
{
    char m[] = "string with space";
    f(m) = '\t'; // string  with space
}



// найти ошибки
#include <iostream>
float f(/*const*/ float &a) // разные типы
{
    a *= a; // надо удалить
    return a;
}

int main(void)
{
    /*const*/ double &dr = 1; // нельзя непостоянную ссылку инициализировать константой
    double d = 1234;
    cout << "o'k\n";
    float r;
    cout << (r = f(d)) << endl;
}



class Cl {
    int a;
    public: 
    void set_a(int n) { a = n; }
    int get_a() { return a; }
};

int main(void)
{
    Cl obj;
    obj.a = 10; // неправильно
    obj.set_a(10);
    cout << obj.get_a() << endl;
}


class Cl {
    int a;
    public: 
    Cl(int n = 0) {a = n;} // конструктор. Если их нет, создается конструктор по умолчанию. Иначе не создается
};
int main(void)
{
    Cl obj(10);
    Cl *p = new Cl[100]; // Ошибка - нет конструктора по умолчанию
    Cl *p = new Cl(100); // А так норм
}


// еще одна запись конструктора

class Cl {
    int a;
    public: Cl(int n = 0) : a(n);
    ~Cl() {}; // деструктор
}

int main(void)
{
    Cl obj, obj2(10), obj3 = A(20), obj4 = 30; // 4 - неявное преобразование. Если перед конструктором написать explicit, то неяное не будет работать
}


class Cl {
    int a;
    public: Cl(int n) {a = n}
};

int main(void)
{
    Cl *p;
    p = new Cl; // неправильно
    p = new Cl[10]; // и это
    p = new Cl(77); 
    delete p;
}



// описать класс так, чтобы все работало
class String {
    int len; // количество выделенных байт
    char *str;
    public:
    String(int n = 1)
    {
        str = new char[n];
        str[0] = '\0';
    }
    String(const char *s)
    {
        len = strlen(s) + 1;
        str = new char[len];
        strncpy(str, s, len);
    }
    ~String()
    {
        delete []str;
    }
};

int main(void)
{
    string s1("строка"), s2, s3(50), s4 = "string";
    s1 = s2; // будут указывать на одну и ту же область, деструктор 2 раза освободит (беда). Надо писать конструктор копирования
}

// Конструктор копирования
String(const String &v)
{
    len = v.len;
    str = new char[len];
    strncpy(str, v.str, len);
}



// Волкова 1.5

class B {
    int n;
    public:
    B() {n = 10;}
    B(const B &v) 
    {
        n = v.n + 10;
    }
    int get() { return n; }
};

int main()
{
    B b1, b2 = b1, b3(b2);
    cout << b1.get() << b2.get() << cout b3.get() << endl; (10, 20, 30)
    return 0;
}


/* 1.16
ConsCopyConsDesCopyDesDes1Des\

   1.18
ConsCopyConsDesDes1Des
*/


class I {
    int i;
    public:
        I(): i(9) { cout << 1; }
        I(int a): i(a) {cout << 2; }
        I(const I & b): i(b.i) { cout << 3; }
        ~I() {cout << 4}
        I f(const I & x, I y) { cout << 'f'; return y; }
};

int main(void)
{
    I i1;
    I i2(20);
    f(i1, i2);
    i1 = f(10, 15);
}

// 123f34422[3]f344444 - [3] нет из-за оптимизации. Аналогично при return 5;
