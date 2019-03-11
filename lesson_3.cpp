 Перегрузка функций

 = [] () - перегружаются только как методы класса

struct Pred
{
    bool operator()(int v)
    {
        return v > 10;
    }
}

void f(int *arr, int n, Pred c)
{
    for (int i = 0; i < n; i++) {
        if (c(mas[i])) {
            mas[i] *= 2;
        }
    }
}

class A
{
    int b;
    mutable int c;
public:
    static int a; // в глобальной памяти
    static void f(void) // Работает только со статическими полями
    {
        cout << a << endl;
    }
    void g() const // объект не может изменяться (только static и mutable поля)
    {
        a = 10;
        c = 5; // OK
        b = 3; // плохо
    }
};
int A::a = 15;

int main(void)
{
    A::a = 20;
    A::f();
    const A obj; // константный объект нужно инициализировать
    obj.f(); // плохо
    obj.g(); // хорошо
}



С коллоквиума

struct A
{
    static int x;
    int y;
    A() { y = 0; }
    int f(int z) const { return z; }
};

int A::x = 0;

int main(void)
{
    const A a;
    a.x = 3;
    cout << a.y << a.x << a.f(1) << endl;
}



class X
{
    X() {}
    ~X() {}
public:
    static X & create()
    {
        X *x1 = new X;
        return *x1;
    }
    static void destroy(X &x1)
    {
        delete &x1;
    }
};

int main(void)
{
    X & xx1 = X::create();
    ...
    X::destroy(xx1);
}



1. Точность совпадения типов
typedef
T <-> T&
T[] <-> T*
T -> const T

2. Расширение
bool
enum
char
unsigned char
short 
unsigned short (если размер short < размера int)
0
Приводятся к инту

float -> double

3. Стандартные преобразования
любой числовой тип -> к любому числовому типу
любой указатель -> void *
0 -> любой указатель + любой числовой тип

4. Пользовательские преобразования
конструктор преобразования

5. Функции с переменным числом параметров



void f(int *)
void f(int)
void f(char)
void f(long)
void f(unsigned char)

f(0) // 2
f(10) // 2
f('a') // 3



int f(int a = 0) { return a; }
int f(double a) { return a; }
int main() {
    short int s;
    int i;
    bool b;
    enum e {A, B, C};
    float f1 = 1.0f;
    f(); // 1
    f(s); // 1
    f(f1); // 2
    f(b); // 1
    f(A); // 1
}



int f(double a = 1.0){return a;}
int f(long double a = 5.0){return a;}
int main() {
    float f1 = 1.0f;
    double d = 2.0;
    long double ld = 3.0l;
    f(); // error
    f(4); // error
    f(f1); // 1
    f(d); // 1
    f(ld); // 2
}



int f(int a = 1){return a;}
int f(long double a = 5.0){return a;}
int main () {
    short int s;
    int i;
    bool b;
    float f1 = 1.0f;
    double d = 2.0;
    f(s); // 1
    f(i); // 1
    f(b); // 1
    f(f1); // error
    f(d); // error
}


2.2

f(double d, const char *str);
f(double d, int x = 0);



struct A
{
    operator int()
    {
        return 1;
    }
    void f(double d, double c) {}
    void f(double d, int j) {}
    void f(A a, const char *p) {}
    void f(int i, const char *p) {}
};

int main(void)
{
    A a;
    f(a, 0); // error {3} ^ {2}
    f(a, 'a'); // 2
    f('a', 0); // error {4} ^ {2} 
}



struct A
{
    int n;
    A(int i) { n = i; }
    void f(char d, char c) {}
    void f(A d, A j) {}
    void f(const int &a, char p) {}
    void f(char i, const char *p) {}
};

int main(void)
{
    A a(1);
    f('a', 0); // {1, 4} ^ {1, 3, 4} = {1, 4} error
    f(a, 0); // {2} ^ {2} = 2
    f(1, 0); // {3} ^ {1, 3, 4} = {3}
}



int i = 1;
int ri &= i;


const int c1 = 1;
void f(int y) {}
f(ci);
