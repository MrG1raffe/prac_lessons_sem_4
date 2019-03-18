vector<int> v;
for (auto &x: v) {
    cout << x;
    x += 2;
}

class A
{
    int a;
public:
    A(int x) { a = x;}
};

class B
{
    int b;
public:
    B(int x) {b = x;}
};

class C: public A, B // public for A
class C: public A, public B
{
    int c;
public:
    C(int x, int y, int z): B(y), A(x), c(z) {} //first constructor A (22)
};


class P {public: int p;};
class A: public P
{
    int a;
public:
    A(int x) { a = x;}
};

class B: public P
{
    int b;
public:
    B(int x) {b = x;}
};

class C: public A, public B
{
    int c;
public:
    C(int x, int y, int z): B(y), A(x), c(z) {}
};

C obj;
obj.p; // error
obj.A::p; // OK

class A: virtual public P {...};


class A {};
class B: public A {};
struct T
{
    B *pb;
};

int main(void)
{
    A a;
    {
        a = B();
        T t;
    }
    B b1, b2 = b1
    return 0;
}
// A(), A(), B(), B~(), ~A(), T(), ~T(), A(), B(), A(const A &), B(const B &), ~B, ~A, ~B, ~A, ~A


// Virtual functions
class A
{
public:
    virtual void f() // полиморфный класс
    {
        cout << 1;
    }
};

class B: public A
{
public:
    void f()
    {
        cout << 2;
    }
};

class C: public B
{
    void f()
    {
        cout << 3;
    }
};

int main(void)
{
    A a, *pa;
    B b;
    C c;
    pa = &a;
    pa->f();
    pa = &b;
    pa->f();
    pa - &c;
    pa->f();
    // 1 2 3
    // 1 1 1 without "virtual"
}

int main(void)
{
    A a;
    B b;
    C c;
    A &ra1 = b;
    A &ra2 = c;
    ra1.f(); // 2
    ra2.f(); // 3
}


class A
{
public:
    virtual void f() = 0; // чисто виртуальная функция. Абстрактный класс - нельзя создать объект этого класса
};

class B: public A
{
public:
    void f()
    {
        ...
    }
};



class A
{
public:
    A() {}
    virtual ~A() {}
};

class B: public A
{
public:
    B() {}
    ~B() {} // ~A() без virtual, а надо ~B(), ~A()
}



class A
{
public:
    virtual void f() {}
};

class B: public A
{
    void f() {}
};

int main(void)
{
    A a, *pa;
    B b;
    pa = &b;
    pa->f(); // закрыта в классе B, но вызовется оттуда
}


class A
{
public:
    virtual void f(int a = 0, int b = 0) // параметры по умолчанию прописываются 1 раз (тут)
    {
        cout << 1;
    }
};

class B: public A
{
public:
    void f(int a, int b)
    {
        cout << 2;
    }
};

int main(void)
{
    B obj;
    A *pa;
    pa = &obj;
    pa->f(); // 2
    pa->f(3); // 2
    pa->f(3, 5); // 2
}


struct B
{
    virtual void f(int a)
    {
        g();
        cout << a << "B::f(int)";
    }
    void g()
    {
        cout << "B::g()";
    }
};

class D: public B
{
public:
    void f(int b = 7)
    {
        g();
        cout << b << "D::f(int)";
    }
    virtual void g()
    {
        cout << "D::g()";
    }
};

int main(void)
{
    D d;
    B b, &rb = d;
    b.f(5); // B::g() 5 B::f(int)
    rb.f(6); // D::g() 6 D::f(int)
}

/*
Из виртуальной функции в не виртуальную: остаемся в том же классе
Из невиртуальной в виртуальную: переход в нужных класс
*/

struct A
{
    int n;
    A() { n = 9;}
    virtual A & operator-()
    {
        n = -(n + 1);
        cout << n << "A::op-";
    }
};

struct B:A
{
    B & operator-()
    {
        cout << n << "B::op-";
    }
};

int main(void)
{
    B b;
    A a, &ra = b;
    a = -a; // -10 A
    ra = -ra; // 9 B
    ra = a;
    ra = -ra; // -10 B
}
