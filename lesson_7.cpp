// RTTY - runtime type identififcation

static_cast // обычное приведение
dynamic_cast

int x = 10;
double y;
y = (double) x;
y = static_cast<double>(x);

class A
{
public:

}

class B: public A
{

}

int main()
{
    A a, *pa;
    B b, *pb;
    pa = &b;
    pb = static_cast<B*>(pa); // ошибка
}


class A
{
public:
    virtual void f()
}

class B: public A
{

}

int main()
{
    A a, *pa;
    B b, *pb;
    pa = &b;
    pb = dynamic_cast<B*>(pa); // все нормально, если указывает на нужный объект

    A &ra = a;
    B &rb = dynamic_cast<B&>(ra);
}


#include <typeinfo>

class B: public A {}

int main()
{
    A a, *pa;
    B b, *pb;
    pa = &b;
    if (typeid(*pa) == typeid(B)) { // возвращает ссылку на тип type_info, для которого определены ==, !=

    } 
    typeid(NULL) // исключение bad_typeid
}


// экз 2016

struct B
{
    virtual void f() {}
};
struct D: B
{
    void f() {}
};

int main(void)
{
    D d, &rd = d;
    B b, &rb = b, &rbd = d;
    rb = dynamic_cast<D&>(rbd);
    rd = dynamic_cast<D&>(rb); // bad_cast
    rd.f();
    rb.f();
}
// Решение: написать try catch 

try-throw-catch

int main(void)
{
    try {
        ...
        throw 10;
    } catch(long) {
        ...
    } catch(int) {
        ... // попадем сюда
    }
    catch(...) {
        // ловится все
    }


    try {
        throw "10";
    } catch(const char *) // без const не ловит

    class A {};
    class B: public A {};
    try {
        trow B()
    }
    catch(const A &x) {
        // попадает сюда
        ...
        throw; // исключение летит дальше
    }
    catch(const B &x) {
    }

    void f() throw(int, double) // какие исключения могут из нее приходить
    // если обработать другой тип внутри функции, то ОК
    throw() == noexcept 
}

/*
Что происходит:

копия объекта
свертка try-блока
поиск обработчика
удаление копии 
*/

//5.14
SConstr
Copy
SCatch_S&
Destr
SConstr
main
Destr
Destr


struct A
{
    A()
    {
        cout << "A()";
    }
    A(const A &a)
    {
        cout << "A_Copy";
    }
    ~A()
    {
        cout << "A_Dest";
    }
};

struct B: A
{
    B()
    {
        cout << "B()";
    }
    B(const B &b)
    {
        cout << "B_Copy";
    }
    ~B()
    {
        cout << "B_Dest";
    }
}

void g()
{
    B bg;
    throw bg;
}

int main()
{
    try {
        A a;
        g();
    } catch(A&) {
        cout << "A&Catch";
    } catch(B&) {
        cout << "B&Catch";
    }
}

A()
A()
B()
A()
B_Copy
B_Dest
A_Dest
A_Dest
A&Catch
B_Dest
A_Dest



class A
{
    static int c;
    int n;
public:
    A(): n(++c)
    {
        cout << "A()=" << n;
    }
    A(const A &a): n(++c)
    {
        cout << "A(A&)=" << n;
    }
    ~A()
    {
        cout << "~A()=" << n;
    }
};

int A::c = 0;

void f()
{
    try {
        throw A();
        throw 1;
    } catch(int) {
        cout << "int";
    } catch(A a) {
        throw;
    } 
    cout << "f()";
}

int main()
{
    try {
        try {
            f();
            cout << "after f";
        } catch(A &a) {
            throw a;
        } catch(...) {
            cout << "inner";
        } 
    } catch(...) {
        cout << "...";
    }
}

/*
A()=1
A(A&)=2
~A()=1
A(A&)=3
~A()=3
A(A&)=4
~A()=2
...
~A()=4
*/


T&& - rvalue ссылка
String(const String &v)
{
    len = v.len;
    str = new char[len];
    strcpy(str, v.str);
}

String f()
{
    String tmp;
    ...
    return tmp;
}
// конструктор переноса, чтобы переставить указатель 

String(String &&v)
{
    len = v.len;
    str = v.str;
    v.str = NULL; // чтобы delete не удалил массив
}

struct A
{
    int i = 10;
};

void f(A &&x) {}

int main()
{
    A a;
    int &&n, m; // нужно инициализировать ссылку
    auto b = A();
    decltype(a) c;
    f(b); // обычный объект 
    f(A());
    m = nullptr; // nullptr Не приводится к инту
}