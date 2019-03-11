class B;

class A {
    int a;
    public: A() {} 
    bool method(B & obj);
    friend bool f(A & obj);
};

class B {
    int b;
    friend bool A::method(B & obj);
    //или
    friend class A; // все методы класса А дружественные
}

bool A::method(B &obj)
{
    return obj.b;
}

bool A::f(A & obj) 
{
    return obj.a > 10; // обращение к полю невозможно без "friend"
}

/*
Статический полиморфизм - перегрузка операций и перегрузка функций
Нельзя перегружать операции #, ::, ., .*, ? :, sizeof, typeid
*/

class C {
    double re, im;
    public:
    C(double x = 0.0, double y=0.0) { re = x; im = y; }
    bool isEqual(C &a) { return re == a.re && im == a.im; }
    bool operator==(C &a) { return re == a.re && im == a.im; }
    C operator+(C & a) 
    {
        C tmp;
        tmp.re = re + a.re;
        tmp.im = im + a.im;
        return tmp;
    }
    // или 
    { return c(re + a.re, im + a.im; }
    friend C operator+(const C &a, const C &b);
    friend ostream & operator<<(ostream &os, C &a);
    C operator-() { return c(-re, -im); }
    C & operator++() // префиксная
    {
        re++;
        im++;
        return *this;
    }
    C & operator++(int not_used)
    {
        C tmp(re, im);
        re++;
        im++;
        return tmp;
    }
    C & operator=(const C &a) //= [] () перегружаются только как методы класса, но не дружественные функции
    {
        re = a.re;
        im = a.re;
        return *this;
    }
    operator double() { return re; }
};

C operator+(const C &a, const C&b) {
    return c(a.re + b.re, a.im + b.im);
}

ostream & operator<<(ostream &os, C &a)
{
    os << "re=" << a.re << "im=" << a.im;
    return os;
}

int main(void)
{
    C o1(1, 2), o2(3, 2), o3;
    if (o1.isEqual(o2)) { // Хочется написать o1 == о2 => нужна перегрузка операций
        cout << "==";
    }
    if (o1.operator==(o2)) { 
        cout << "==";
    }
    if (o1 == o2) { // все три записи эквивалентны
        cout << "==";
    }
    o3 = o1 + o2;
    o3 = o1 + 12.3; // нельзя, если аргумент не const C &a
    o3 = 12.3 + o1; // не работает без дружественной функции
    cout << o3 << endl;
    o3 = -o2;
    o3 = ++o2;
    o3 = o2++;
    o3 = o2++++; // во второй раз увеличит временную переменную
    o3 = -o1; // не будет работать без const
    o3 = o1 + 12.3 // неоднозначность, если есть double
}



class String {
    char *str;
    int len;
    public:
    char & operator[](int i) { return str[i]; }
    String operator+(String s)
    {
        String tmp(len + s.len - 1);
        strncpy(tmp.str, str, n);
        strncpy(tmp.str + len, s.str, n); 
        return tmp;
    }
    String & operator=(const String &s)
    {
        if (this == &s) {
            return *this;
        }
        delete[](str)
        str = new char(a.len);
        strncpy(str, s.str, n);
        return *this;
    }
};

int main(void)
{
    String s1("String"), s2("abcde"), s3;
    s2[1] = 'A';
    s3 = s1 + s2;
}

/*
1.10

sun 
venus 20
earth 420
moon
1429 420
moon
moon
*/
