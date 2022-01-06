#include <iostream>
#include <string>
#include <ctime>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

size_t CHOICE;

//безопасный ввод данных (против отр, дробных чисел и строк)
int SafeInput(bool strict = true)
{
    int result;
    while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Был выбран неправильный вариант! Введите заново!!" << endl;
    }
    return result;
}

//checking if a sybmbol is digit
bool IsSet(char op)
{
    string str = "QWERTYUIOPASDFGHJKLZXCVBNM";
    if (str.find(op) != -1)
        return true;
    return false;
}

//поверка, содержится ли данный элемент в множестве
bool Contains(set <int> st, int x)
{
    if (st.find(x) != st.end())
        return true;

    return false;
}

//checking if a symbol is operation
bool IsOperator(char op)
{
    string str = "*/+-|";
    if (str.find(op) != -1)
        return true;
    return false;
}

int Priority(char op)
{
    switch (op)
    {
    case '(':
        return 1;
    case '-':
    case '/':
        return 2;
    case '*':
    case '+':
        return 3;
    case '|':
        return 4;
    default:
        return -1;
    }
}

void SetToVector(set<int>& from, vector<int>& to)
{
    for (auto var : from)
    {
        to.push_back(var);
    }
}

set<int> Calculate(string s, map <char, set<int>> Map)
{
    stack <set<int>> storage;
    for (int i = 0; i < s.size(); i++)
    {
        if (IsSet(s[i])) {
            set<int> temp;
            if (s[i] == 'A')
                temp = Map.begin()->second;
            if (s[i] == 'B')
            {
                auto iter = Map.begin();
                ++iter;
                temp = iter->second;
            }
            if (s[i] == 'C')
            {
                auto iter = Map.end();
                --iter;
                temp = iter->second;
            }
            storage.push(temp);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '|')
        {
            set<int> op1 = storage.top(), op2;                              //getting second operand
            vector<int> v1, v2;
            storage.pop();
            if (!storage.empty()) {
                op2 = storage.top();                                        //getting first operand
                storage.pop();
            }

            if (s[i] == '|') {
                set<int> tmpSet;
                for (int i = -20; i <= 20; i++)
                {
                    if (!Contains(op1, i))
                        tmpSet.insert(i);
                }
                op1 = tmpSet;
            }
            if (s[i] == '*') {                                     // if the operation is multiplication                
                op1.insert(op2.begin(), op2.end());
            }
            else if (s[i] == '/') {                                 // if the operation is division
                vector<int> v_difference;
                SetToVector(op1, v1);
                SetToVector(op2, v2);
                set_difference(v2.begin(), v2.end(),
                    v1.begin(), v1.end(),
                    back_inserter(v_difference));
                op1.clear();
                op1.insert(v_difference.begin(), v_difference.end());
            }

            if (s[i] == '+') {                                      // if the operation is additon                
                vector<int> v_intersection;
                SetToVector(op1, v1);
                SetToVector(op2, v2);
                set_intersection(v1.begin(), v1.end(),
                    v2.begin(), v2.end(),
                    back_inserter(v_intersection));
                op1.clear();
                op1.insert(v_intersection.begin(), v_intersection.end());
            }
            else if (s[i] == '-') {                             // if the operation is substraction                
                vector<int> symmetric_difference;
                SetToVector(op1, v1);
                SetToVector(op2, v2);
                set_symmetric_difference(v2.begin(), v2.end(),
                    v1.begin(), v1.end(),
                    back_inserter(symmetric_difference));
                op1.clear();
                op1.insert(symmetric_difference.begin(), symmetric_difference.end());
            }

            storage.push(op1);
        }
    }
    return storage.top();
}

string RemoveLastEl(string result)
{
    string tmp;
    for (size_t i = 0; i < result.size() - 1; i++)
        tmp += result[i];
    return tmp;
}

//converting infix to postfix notation using stack
void ToPostfix(string& s)
{
    stack <char> stk;
    string result;

    for (char CurrVar : s) {
        if (IsSet(CurrVar)) {
            result += CurrVar;
            result += ',';
        }
        else {
            if (IsOperator(CurrVar)) {
                int CurrPrior = Priority(CurrVar), StackPrior = 0;  //checking priority of the current variable
                if (!stk.empty())
                    StackPrior = Priority(stk.top()); // checking priority of the variable on top of stack
                if (!stk.empty() && (StackPrior < CurrPrior))
                    stk.push(CurrVar);
                else {
                    while (!stk.empty() && (StackPrior >= CurrPrior)) { // if there is/are elements
                        result += stk.top();                            // having greater precedence on top of stack
                        result += ',';                                  // then we put them in to the result string
                        stk.pop();
                        if (!stk.empty())
                            StackPrior = Priority(stk.top());          // resetting priority of the top element of stack
                    }
                    stk.push(CurrVar);
                }
            }
            if (CurrVar == '(')
                stk.push(CurrVar);
            if (CurrVar == ')') {
                while (stk.top() != '(') {          // moving untill the element is not an open bracket
                    result += stk.top();            // putting to the result string operators from stack
                    result += ',';  //
                    stk.pop();
                }
                stk.pop();
            }
        }
    }                                                                              // infix expr    postfix expr
    // if stack contains some operators then they should be put in the result string: (1+2)*4+3 --> 12+4*3+
    while (!stk.empty()) {
        result += stk.top();
        result += ',';  //
        stk.pop();
    }
    s = RemoveLastEl(result);
}

//заполнение кратными числами
set <int> FillSetWithMultipleNumbers(set <int> st, int multipleTo);

//заполнение множества в зависимости от знака
set <int> MakeSetWithSignDepandingManually(set <int> st);

//заполнение множества по условию
set <int> FillSetWithPredicate(set <int> st);

//заполнение множества вручную
set <int> FillSetManually(set <int> st);

set <int> FillSetRandomly(set <int> st);

//создаём множества
void MakingSets(set <int>& setToMake)
{
    switch (CHOICE)
    {
    case 1: {
        setToMake = FillSetRandomly(setToMake);
        break;
    }
    case 2: {
        setToMake = FillSetManually(setToMake);
        break;
    }
    case 3: {
        setToMake = FillSetWithPredicate(setToMake);
        break;
    }
    default:
        cout << "Был выбран неправильный вариант! Введите заново: ";
        break;
    }
    cout << endl;
}

//печать дерева
void PrintMap(map<char, set<int>> Map);

void ShowSet(set <int> st);
void Menu();

void Operations(map<char, set<int>> storage)
{
    bool selectedToExit = false;
    do
    {
        set<int> tempA = storage.begin()->second;

        cout << "\n\t* - объединение" << endl
            << "\t+ - пересечение" << endl
            << "\t| - дополнение" << endl
            << "\t/ - разность " << endl
            << "\t- - симметрическая разность" << endl
            << "\t0 - выход из программы" << endl
            << "\t>";
        string expr;
        cin >> expr;
        if (expr[0] != '0')
        {
            ToPostfix(expr);
            tempA = Calculate(expr, storage);

            cout << "\n\tРезультат" << endl;
            ShowSet(tempA);
        }
        else
            selectedToExit = true;
    } while (!selectedToExit);  
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    map<char, set<int>> storage;
    set <int> firstSet, secondSet, thirdSet;

    Menu();
    MakingSets(firstSet);
    Menu();
    MakingSets(secondSet);
    Menu();
    MakingSets(thirdSet);

    storage.emplace('A', firstSet);
    storage.emplace('B', secondSet);
    storage.emplace('C', thirdSet);

    PrintMap(storage);

    Operations(storage);
}

void Menu()
{
    bool flag = true;
    cout << "Выберете вариант:" << endl
        << "1) Автозаполнение" << endl
        << "2) Заполнение вручную" << endl
        << "3) Заполнение по условию\n" << "> ";
    do
    {
        CHOICE = SafeInput();
        if (CHOICE > 0 && CHOICE <= 3)
            flag = false;
        else
            cout << "Было введено некорректное значение" << endl
            << "Введите вариант заново: ";
    } while (flag);
}

void ShowSet(set <int> st)
{
    for (auto var : st)
    {
        cout << var << " ";
    }
    cout << endl;
}

//заполнение кратными числами
set <int> FillSetWithMultipleNumbers(set <int> st, int multipleTo)
{
    for (int i = -20; i < 21; i++)
    {
        if (i % multipleTo == 0)
            st.insert(i);
    }
    return st;
}

//заполнение множества в зависимости от знака
set <int> MakeSetWithSignDepandingManually(set <int> st)
{
    bool flag = true;
    int size = 0, temp = 0;
    char sign;
    cout << "\tКакой знак вы ходите использовать? (+/-)";
    do
    {
        cout << "\n\t>";
        cin >> sign;
        if (sign == '+')
            flag = false;
        else if (sign == '-')
            flag = false;
        else
        {
            cout << "\tБыл введён не корректный символ" << endl
                << "\tВведите знак заново: ";
        }
    } while (flag);

    flag = true;
    cout << "\tВведите размер множества";
    do
    {
        cout << "\n\t>";
        size = SafeInput();
        if (size > 0 && size < 41)
            flag = false;
        else
        {
            cout << "\tРазмер множества не может превышать 41" << endl
                << "\tВведите рахмер заново" << endl;
        }
    } while (flag);

    cout << "\n\tВведите элементы множества: ";
    for (size_t i = 0; i < size; i++)
    {
        flag = true;
        do
        {
            cout << "\n\t>";
            cin >> temp;
            if (sign == '-')
            {
                if (temp >= -20 && temp <= 0 && !Contains(st, temp))
                {
                    st.insert(temp);
                    flag = false;
                }
                else
                {
                    if (!Contains(st, temp))
                        cout << "\tБыл введён элемент не входящий в множество [-20; 0]" << endl
                        << "\tВведите элемент заново" << endl;
                    else
                        cout << "\tДанный элемент присутсвует в множестве" << endl
                        << "\tВведите элемент заново";
                }
            }
            else
            {
                if (temp > 0 && temp <= 20 && !Contains(st, temp))
                {
                    st.insert(temp);
                    flag = false;
                }
                else
                {
                    if (!Contains(st, temp))
                        cout << "\tБыл введён элемент не входящий в множество (0; 20]" << endl
                        << "\tВведите элемент заново" << endl;
                    else
                        cout << "\tДанный элемент присутсвует в множестве" << endl
                        << "\tВведите элемент заново";
                }
            }

        } while (flag);
    }
    return st;
}

set <int> FillSetWithPredicate(set <int> st)
{
    cout << "   Выберете условие:" << endl
        << "    1) По чётности;" << endl
        << "    2) По кратноти числу;" << endl
        << "    3) По знаку;" << endl << "    >";
    CHOICE = SafeInput();

    switch (CHOICE)
    {
    case 1: {
        st = FillSetWithMultipleNumbers(st, 2);
        break;
    }
    case 2: {
        int divideBy;
        bool flag = true;
        cout << "\tВведите элемент, кратными которому должны быть элементы множества" << endl;
        do
        {
            cout << "\t>";
            cin >> divideBy;
            if (divideBy >= -20 && divideBy <= 20)
                flag = false;
            else
            {
                cout << "\tДанный элемент не входит в диапозон множества!" << endl
                    << "\tВведите новый элемент!" << endl;
            }
        } while (flag);
        st = FillSetWithMultipleNumbers(st, divideBy);
        break;
    }
    case 3: {
        st = MakeSetWithSignDepandingManually(st);
        break;
    }
    default:
        cout << "\tБыл выбран неправильный вариант!" << endl
            << "\tВведите заново! ";
        break;
    }
    return st;
}

//заполнение множества рандомом
set <int> FillSetRandomly(set <int> st)
{
    bool flag = true;
    cout << "\tВведите размер множества: ";
    int size, temp;
    do
    {
        size = SafeInput();
        if (size > 41)
        {
            cout << "\tРазмер множества не может привышать 41" << endl
                << "\tВведите размер заново: ";
        }
        else
            flag = false;
    } while (flag);

    for (size_t i = 0; i < size; i++)
    {
        flag = true;
        do
        {
            temp = -20 + rand() % 41;
            if (!Contains(st, temp))
                flag = false;
            else
                continue;
        } while (flag);
        st.insert(temp);
    }
    return st;
}

//заполнение множества вручную
set <int> FillSetManually(set <int> st)
{
    bool flag = true;
    cout << "\tВведите размер множества: ";
    int size;
    do
    {
        size = SafeInput();
        if (size > 41)
        {
            cout << "\tРазмер множества не может привышать 41" << endl
                << "\tВведите размер заново: ";
        }
        else
            flag = false;
    } while (flag);

    int x;
    cout << "\n\tВведите элементы множества\n";
    for (size_t i = 0; i < size; i++)
    {
        bool flag = true;
        do
        {
            cout << "\t>";
            cin >> x;
            if (!Contains(st, x) && x >= -21 && x <= 20)
            {
                st.insert(x);
                flag = false;
            }
            else
            {
                if (x >= -21 && x <= 20)
                    cout << "\tДанный элемент уже находится в множестве!" << endl
                    << "\tВведите новый элемент!" << endl;
                else
                    cout << "\tДанный элемент не входит в диапозон множества!" << endl
                    << "\tВведите новый элемент!" << endl;
            }
        } while (flag);
    }
    return st;
}

//печать дерева
void PrintMap(map<char, set<int>> Map)
{
    for (auto i = Map.begin(); i != Map.end(); ++i)
    {
        cout << "Множество " << i->first << endl;
        for (auto var : i->second)
        {
            cout << var << "; ";
        }
        cout << endl;
    }
}