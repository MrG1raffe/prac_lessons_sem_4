value_type // in each container

template <class T>;
typename T::value_type f(const T &k)
{
    typename T::value_type sum = typename T::value_type();
    typename T::const_iterator p = k.begin();
    while (p != k.end()) { // < only in vectors
        sum = sum + *p++;
    }
    return sum;
}

//it1 (begin), it2 (end), predicate class (), values.

class Pred
{
public:
    bool operator()(typename T::value_type x)
    {
        return !x;
    }
};

template <class T, class P> // T - iterator, P - predicate

void some(T first, T last, P pred, typename T::value_type val = typename T::value_type())
{
    while (first != last)
    {
        if (pred(*first)) {
            *first = val;
        }
        first++;
    }
}

int main(void)
{
    vector <int> v;
    //
    some(v.begin(), v.end(), Pred(), 8)
}


class A
{
    protected int a;
public:
    A(int x = 0): a(x) {}
    void f()
    {
        std::cout << a;
    }
};

class B: public A; // [private];
class B: private A;
class B: protected A;

class B: public A
{
    int b;
public:
    B(int x, int y): A(x), b(y) {}
    void f()
    {
        std::cout << a << b;
    }
};

int main(void)
{
    B objb(1, 2);
    A obja;
    obja.f(); // first f
    objb.f(); // second f
    A *pa = &objb; // OK (not OK, if "class B: private A;")
    B *pb = (B*) &obja; // impossible in private inheritance
    pb->f(); // second f
}

//нет перегрузки функций, область видимости производного класса приоритетнее


//3.1(a)

int x = 0;
void f(int a, int b){ x = a + b; }

class A{
    int x;
public:
    void f(){ x = 2; }
};

class B: public A{
public:
    void f (int a){ ::x = a; }
    void g();
};
void B::g(){
    f(); //Error
    f(1);
    f(5,1); //::f(5, 1);
    x = 2; //Error - try x from A
}

B ret(B &x, B &y){
    return x;
}

int main() {
    B b;
    f(5); // Error - global function
    f(С+Т,6);
    b = ret(b, b);
    return 0;
}

// constructor/destructor - A(), B(), A(), B(), ~B(), ~A(), ~B(), ~A()


//3.1(b)

double a = 0;

void f(double x) { a = x; }

struct A{
    double a;
    void f() { a = 2; }
};

class B: A{
public:
    void f(int a) { ::a = a; }
    void g();
};

void B::g(){
    f(1.2);
    f(); //Error
    a = 2;
}

void empty(B &a, B b) {}

int main(){
    B d;
    f();
    f(6);
    empty(d, d);
    return 0;
}
