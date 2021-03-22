#include <iostream>

struct string {
    char *str;
    size_t size;
    size_t capacity;

    string() // Конструктор пустой строки
    {
        str = NULL;
        size = 0;
        capacity = 0;
    }

    string(size_t cnt, char c) // Заполняющий конструктор
    {
        size = cnt;
        capacity = 2*cnt;

        str = new char[capacity + 1];
        for (int i = 0; i < cnt; i++) {
            str[i] = c;
        }
        str[cnt] = '\0';
    }

    string(const string& s) // Копирующий конструктор
    {
        size = s.size;
        capacity = s.capacity;

        str = new char[capacity + 1];
        for (int i = 0; i < size; i++) {
            str[i] = s.str[i];
        }
        str[size] = '\0';
    }

    string(char c) // Конструктор строки из одного символа
    {
        size = 1;
        capacity = 2;
        str = new char[capacity + 1];
        str[0] = c;
        str[1] = '\0';
    }

    string(const char * c_str)  // Конструктор строки из c-style строки (массива символов)
    {
        int i = 0;
        while (c_str[i] != '\0') {
            str[i] = c_str[i];
            i++;
        }

        size = i - 1;
        capacity = 2*size;
    }

    ~string() //очистить всю используемую память
    {
        delete []str;
        str = NULL;
        size = 0;
        capacity = 0;
    };

    bool operator== (const string& other)
    {
        if (size != other.size) {return false;}

        for (int i = 0; i < size; i++)
        {
            if (str[i] != other.str[i]) {return false;}
        }
        return true;
    }

    bool operator!= (const string& other)
    {
        return !(*this == other);
    }

    bool operator> (const string& other)
    {
        for (int i = 0; i < size; i++)
        {
            if (str[i] != '\0' and other.str[i] == '\0') {return true;}
            if (str[i] > other.str[i]) {return true;}
            if (str[i] < other.str[i]) {return false;}
        }
        return false;
    }

    bool operator< (const string& other)
    {
        if (*this == other) {return false;}
        return !(*this > other);
    }

    string& operator+= (const string& other)
    {
        int new_size = size + other.size;

        while (capacity <= new_size)
        {
            capacity = capacity * 2;
            realloc(str, capacity + 1);
        }

        
        for (int i = size; i < new_size; i++)
        {
            str[i] = other.str[i - size];
        }

        size = new_size;
        str[size] = '\0';

        return *this;
    }

    char operator[] (unsigned int pos) const {return str[pos];}

    void append(const string other) {*this += other;}  // дописать в конец данной строки другую

    void resize(unsigned int new_capacity);  // увеличить/уменьшить емкость строки

    void reserve(unsigned int capacity); // зарезервировать память в нужном объеме

    void insert(unsigned int pos, string other);  // Вставка другой строки внутрь данной

    void shrink_to_fit();  //очистить неиспользуемую память

    void clear() //очистить содержимое строки, занимаемое место при этом не меняется
    {
        *str = 0;
        size = 0;
        str[0] = '\0';
    };

    friend std::ostream& operator<< (std::ostream& ostr, const string& str) {return ostr << str.str;}

    friend std::istream& operator>> (std::istream& istr, const string& str) {return istr >> str.str;}

};


string operator + (const string & str1, const string & str2)
{
    string mem = str1;
    mem += str2;
    return mem;
}


int stoi(const string str, size_t pos = 0, int base = 10 );
// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.

int main() {

    string x(5, 'a');
    std::cout << x << '\n';
    string y(6, 'b');
    std::cout << y << '\n';
    x += y;
    x.append(y);
    std::cout << x << '\n';
    
    return 0;
}