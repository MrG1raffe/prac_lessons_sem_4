STL

template <class T>

T f abs(const T & x)
{
    return x > 0 ? x : -x;
}

int main(void)
{
    int i = 10;
    long j = -1000l;
    double x = -3.14;
    cout << abs(i) << abs(j) << abs(x);
}


T f(const T &x1, const T &x2)
{
    return x1 > x2 ? x1 : x2;
}

f <double> (10, 1.2);

double f(double a, double b) {} // перекроет шаблонную
f(1.2, 2.3) // вызовет обычную
F <double> (1.2, 2.3) // с <> всегда вызывается шаблон

template <class T, int SIZE = 100> // можно целочисленные типы, нельзя float, double, user, void, указатели можно
class stack 
{
    T st[SIZE];
    int top = 0;
public:
    void push(T &a)
    {
        if (top == SIZE) {
            exit(1);
        }
        st[top++] = a;
    }
    T pop(void);
}

template <class T, int SIZE> T Stack <T, SIZE> pop(void)
{
    if (!top) {
        exit(1)
    }
    return st[--top];
}

STL:
1. контейнеры 
    последовательности (vector, list, deque, stack, queue) 
    ассоциативные массивы (imap, multimap, set, multiset) - отображения, множество
2. итераторы - указатели, 
    iterator
    reverse_iterator
    const_iterator
    const_reverse_iterator
    Типы итераторов
    1. Input ->
    2. Output ->
    3. Forward ->
    4. Bidirectional <-> (list, map, set)
    5. random_access (vector, deque)
3. алгоритмы - с любым контейнером

    begin() - возвращает итератор на первый элемент последовательности
    end() - возвращает за последний элемент
    rbegin() - возвращает реверс-оператор, указывающий на последний элемент
    rend() - указывает на несуществующий элемент за первым
    ++ двигает обычный итератор вперед, реверс-итератор назад

#include <vector>
#include <list>
#include <map>

int mas[] = {1, 2, 3, 4}
vector <int> v1; // создали вектор с целыми элементами нулевой длины
vector <int> v2(5); // 5 элементов, для каждого конструктор по умолчанию
vector <char> v3(10, '*');
vector <int> v4(mas, mas + 4); // первый указатель указывает на первый элемент, второй - за последний

vector <int> v;
for (int i = 0; i < 10; ++i) {
    v.push_back(i); // добавляет элемент
}
for (int i = 0; i < v.size(); i++) {
    cout << v[i]; // через [] можно обращаться к vector и deque. не проверяет выход за пределы
    cout << v.at(i) // то же самое, но проверяет (исключение out_of_range)
}

size() - возвращает размер
push_back() - помещает значение в конец контейнера
pop_back() - удаляет
back() - удаляет и возвращает

для контейнера list
push_front
pop_front
front
insert(p, ..) - вставляет на p место
erase(p1, p2) - удаление с p1 до p2. p2 не удаляется
erase(p)
empty() - true, если size == 0
clear() - удаляет все элементы, не изменяя capacity
resize(n) - capacity = n

Для вектора можно складывать итераторы, для list нельзя
advance(p, 5) - прибавляет 5 к p
n = distance(p1, p2) - считает разницу между p1 и p2


vector <int> v;
for (int i = 0; i < 10; i++) {
    v.push_back(i);
}

//Напечатать наоборот двумя способами

vector <int> :: reverse_iterator rp = v.rbegin();

while (rp != v.rend()) {
    cout << *rp++ << endl;
}

vector <int> :: iterator p = v.end;

while (p != v.begin()) {
    cout << *(--p) << endl;
}



p = rb.base - преобразует обратный итератор в прямой. p будет указывать на следующий

// удалить в лист последний отрицательный элемент

list <int> :: reverse_iterator rp = v.rbegin;
while (rp != v.rend() && *rp++ >= 0);
if (rp != v.rend()) {
    list <int> :: iterator p = rp.base();
    erase(p);
}



// 9.16

void f(vector <char> &v)
{
    vector <char> :: iterator p = v.begin();
    p++;
    while (p < v.end()) {
        v.erase(p++);
    }
    vector <char> :: reverse_iterator rp = v.rbegin();
    while (rp != v.rend()) {
        cout << *rp++ << endl;
    }
}



