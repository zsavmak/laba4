#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

struct Deque
{
    Deque *prev,*next;
    int info;
};


void Create_random(Deque **p, Deque **e, int len)
{
    for (int i = 0; i < len; i++)
    {
        int in = (rand() % 100 + 1);
        Deque* t = new Deque;
        t->info = in;
        t->next = t->prev = NULL;
        if (i == 0)
            *p = *e = t;
        else
        {
            (*e)->prev = t;
            t->next = *e;
            t->prev = NULL;
            *e = t;
        }
    }
}

void Create_manual(Deque **p, Deque ** e, int len)
{
    for (int i = 0; i < len; i++)
    {
        int in;
        cin >> in;
        Deque* t = new Deque;
        t->info = in;
        t->next = t->prev = NULL;
        if (i == 0)
            *p = *e = t;
        else
        {
            (*e)->prev = t;
            t->next = *e;
            t->prev = NULL;
            *e = t;
        }
    }
}

Deque* add_to_beg(int info, Deque *p)
{

    Deque* t = new Deque;
    t->info = info;
    t->prev = p;
    t->next = NULL;
    if (p == NULL)
        t->prev = NULL;
    else
        p->next = t;
    return t;
}

Deque* add_to_end(int info, Deque *e)
{
    Deque* t = new Deque;
    t->info = info;
    t->next = e;
    t->prev = NULL;
    e->prev = t;
    if (e == NULL)
        t->next = NULL;
    else
        e->prev = t;
    return t;
}

void view_from_beg(Deque *p)
{
    while(p != NULL)
    {
        cout << p->info << endl;
        p = p->prev;
    }
}

void view_from_end(Deque *e)
{
    while(e != NULL)
    {
        cout << e->info << endl;
        e = e->next;
    }
}

int _min(Deque *p)
{
    int Min = p->info;
    while(p != NULL)
    {
        Min = min(Min, p->info);
        p = p->prev;
    }
    return Min;
}


void Del_All(Deque *p)
{
    while(p != NULL){
        Deque *t = p;
        p = p -> next;
        delete t;
    }
}

int main()
{
    srand (time(NULL));
    char code, bcode;
    int len, i;
    Deque *begin = NULL, *end;
    while(true)
    {
        system("cls");
        cout << "Enter a code:\nCreate - 1\nAdd - 2\nView - 3\nTask - 4\nEXIT - 0" << endl;
        cin >> code;
        switch(code)
        {
        case '1':
            if (begin != NULL){
                cout << "Memory Free!" << endl;
                Del_All(begin);
                begin = end = NULL;
                _getch();
                break;
            }
            cout << "Enter a code:\nrandom - 1\nmanual - 2" << endl;
            cin >> bcode;
            cout << "Input a length: ";
            cin >> len;
            switch(bcode){
                case '1':
                    Create_random(&begin, &end, len);
                break;
                case '2':
                    cout << "Input elements\n";
                    Create_manual(&begin, &end, len);
                break;
            }
            break;
        case '2':
            cout << "Input a length: ";
            cin >> len;
            cout << "To begin - 1\nTo end - 2" << endl;
            cin >> bcode;
            for (i = 0; i < len; i++)
            {
                int in = (rand() % 100 + 1);
                switch(bcode)
                {
                case '1':
                    begin = add_to_beg(in, begin);
                    break;
                case '2':
                    end = add_to_end(in, end);
                    break;
                }
            }

            break;
        case '3':
            cout << "From begin - 1\nFrom end - 2" << endl;
            cin >> bcode;
            switch(bcode)
            {
            case '1':
                view_from_beg(begin);
                break;
            case '2':
                view_from_end(end);
                break;
            }
            _getch();
            break;
        case '4':
        {
            if (begin == NULL)
            {
                cout << "The Deque is empty!\n";
                _getch();
                break;
            }
            int Min = _min(begin);
            Deque *_begin = NULL, *t = end;
            while(t != NULL){

                _begin = add_to_beg(t->info, _begin);
                cout << "Info: " << t->info<<endl;
                if (t->info == Min)
                    break;
                t = t->next;
            }

            view_from_beg(_begin);
            _getch();
            break;
        }
        case '0':
            if (begin != NULL)
                Del_All(begin);
            return 0;

        }
    }
}
