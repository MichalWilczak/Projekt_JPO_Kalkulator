
#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>


using std::cout, std::cin, std::endl, std::numeric_limits, std::vector, std::string;

constexpr float kMin{ numeric_limits<float>::min() };     //te linie kodu zosta³y przepisane z filmu
constexpr float kMax{ numeric_limits<float>::max() };     // pod linkiem: https://youtu.be/7aZbYJ5UTC8?t=2480

float epsilon{ numeric_limits<float>::epsilon() };        //linia kodu przepisana z flimu pod linkiem: https://youtu.be/7aZbYJ5UTC8?t=1495

//klasa zawieraj¹ca funkcje do wykonywania dzia³añ matematycznych oraz funkcje do zamiany systemów liczbowych

class calculator
{
    int vector_int_to_dec_int(vector<int> wektor)       //funkcja zamieniaj¹ca vector<int> na liczbê dziesiêtn¹ typu int
    {
        int decimal{ 0 };                                   //funkcja odwracaj¹ca kolejnoœæ elementów wektora
        std::reverse(wektor.begin(), wektor.end());         //pochodzi z biblioteki <algorithm>
        for (int i = 0; i < wektor.size(); i++)
        {
            decimal = decimal + wektor[i] * pow(10, i);
        }
        return decimal;
    }

public:
    float add(float a, float b)         //funkcja realizuj¹ca dodawanie
    {
        float sum = a + b;
        return sum;
    }

    float subtract(float a, float b)    //funkcja realizuj¹ca odejmowanie
    {
        float difference = a - b;
        return difference;
    }

    float multiply(float a, float b)    //funkcja realizuj¹ca mno¿enie
    {
        float product = a * b;
        return product;
    }

    float divide(float a, float b)      //funkcja realizuj¹ca dzielenie
    {
        if ((abs(b) >= epsilon) && (abs(a) <= (epsilon * kMax)))
        {
            float quotient = a / b;
            return quotient;
        }
        else {
            cout << "To big dividend or to small divisor!" << endl;
            return 0;
        }

    }

    int DecToBinary(int decimal)                //wzorowano siê na kodzie ze strony: https://www.geeksforgeeks.org/program-decimal-binary-conversion/
    {                                           //funkcja zamieniaj¹ca lczbê z systemu dziesiêtnego na system binarny
        vector<int>binary{};
        int i{ 0 };
        while (decimal > 0)
        {
            binary.push_back(0);
            binary[i] = decimal % 2;
            decimal = decimal / 2;
            i++;
        }

        std::reverse(binary.begin(), binary.end());     //funkcja odwracaj¹ca kolejnoœæ elementów wektora
                                                        //pochodzi z bibloteki <algorithm>
        int binary_int = vector_int_to_dec_int(binary);
        return binary_int;
    }

    int DecToOct(int decimal)                   //wzorowano siê na kodzie funkcji zamieniaj¹cej liczbê z systemu dziesiêtnego
    {                                           //na system binarny
        vector<int>oct{};                       //funkcja zamieniaj¹ca liczbê z systemu dziesiêtnego na system ósemkowy
        int i{ 0 };
        while (decimal > 0)
        {
            oct.push_back(0);
            oct[i] = decimal % 8;
            decimal = decimal / 8;
            i++;
        }
        std::reverse(oct.begin(), oct.end());           //funkcja odwracaj¹ca kolejnoœæ elementów wektora
                                                        //pochodzi z biblioteki <algorithm>
        int oct_int = vector_int_to_dec_int(oct);
        return oct_int;
    }


    string DecToHex(int decimal)            //wzorowano siê na kodzie ze strony:https://www.geeksforgeeks.org/program-decimal-hexadecimal-conversion/
    {                                       //funkcja zamieniaj¹ca liczbê z systemu dziesiêtnego na system szesnastkowy
        string hex{};

        while (decimal > 0)
        {
            int remainder{ 0 };
            char c{};
            remainder = decimal % 16;

            if (remainder < 10)
            {
                c = remainder + 48;             //znak "0" w tablicy kodów ASCII ma numer 48
            }
            else
            {
                c = remainder + 55;             //znak "A" odpowiadaj¹cy liczbie 10 w tablicy kodów ASCII ma numer 65
            }
            hex = hex + c;
            decimal = decimal / 16;
        }
        std::reverse(hex.begin(), hex.end());           //funkcja odwracaj¹ca kolejnoœæ elementów wektora
        return hex;                                     //pochodzi z biblioteki <algorithm>
    }

    int BinToDec(int binary)                                    //funkcja zamieniaj¹ca liczbê z systemu binarnego na system dziesiêtny
    {
        int length{ 0 };
        string binary_str = std::to_string(binary);             //funkcja konwertuj¹ca zmienn¹ typu int na zmienn¹ typu string
        int dec{ 0 };                                           //pochodzi z biblioteki <string>
        std::reverse(binary_str.begin(), binary_str.end());     //funkcja odwracaj¹ca kolejnoœæ elementów wektora 
        for (int i = 0; i < binary_str.size(); i++)             //pochodzi z biblioteki <algorithm>
        {
            if ((binary_str[i] == 48) || (binary_str[i] == 49))
            {
                length = length + 1;
            }
        }
        if (length == binary_str.size())
        {
            for (int i = 0; i < binary_str.size(); i++)
            {
                dec = dec + (binary_str[i] - 48) * pow(2, i);
            }
        }
        return dec;
    }

    int OctToDec(int oct)                                       //funkcja zamieniaj¹ca liczbê z systemu ósemkowego na system dziesiêtny
    {
        int length{ 0 };
        string oct_str = std::to_string(oct);                   //funkcja konwertuj¹ca zmienn¹ typu int na zmienn¹ typu string
        int dec{ 0 };                                           //pochodzi z biblioteki <string>
        std::reverse(oct_str.begin(), oct_str.end());           //funkcja odwracaj¹ca kolejnoœæ elementów wektora 
        for (int i = 0; i < oct_str.size(); i++)                //pochodzi z biblioteki <algorithm>
        {
            if ((oct_str[i] != 56) && (oct_str[i] != 57))
            {
                length = length + 1;
            }
        }
        if (length == oct_str.size())
        {
            for (int i = 0; i < oct_str.size(); i++)
            {
                dec = dec + (oct_str[i] - 48) * pow(8, i);
            }
        }
        return dec;
    }

    int HexToDec(string hex)                    //funkcja zamieniaj¹ca liczbê z systemu szesnastkowego na system dziesietny
    {
        const char kA{ 'A' };
        const char kF{ 'F' };
        const char k0{ '0' };
        const char k9{ '9' };
        int length{ 0 };
        int dec{ 0 };
        std::reverse(hex.begin(), hex.end());           //funkcja odwracaj¹ca kolejnoœæ elementów wektora
        for (int i = 0; i < hex.size(); i++)            //pochodzi z biblioteki <algorithm>
        {
            if (((hex[i] >= k0) && (hex[i] <= k9)) || ((hex[i] >= kA) && (hex[i] <= kF)))
            {
                length = length + 1;
            }
        }
        if (length == hex.size())
        {
            for (int i = 0; i < hex.size(); i++)
            {
                if ((hex[i] >= kA) && (hex[i] <= kF))
                {
                    hex[i] = hex[i] - 55;
                }
                else if ((hex[i] >= k0) && (hex[i] <= k9))
                {
                    hex[i] = hex[i] - 48;
                }
                dec = dec + hex[i] * pow(16, i);
            }
        }
        return dec;
    }

};

calculator kalkulator;


int main()
{
    int funkcjonalnosc{ 0 };
    cout << "Funkcjonalnosc:" << endl;
    cout << "1. Kalkulator" << endl;
    cout << "2. Zamiana systemow liczbowych" << endl;
    cout << "Wybierz funkcjonalnosc: ";
    cin >> funkcjonalnosc;
    if (funkcjonalnosc == 1)
    {
        int dzialanie{ 0 };
        cout << "Dzialania matematyczne:" << endl;
        cout << "1. Dodawanie" << endl;
        cout << "2. Odejmowanie" << endl;
        cout << "3. Mnozenie" << endl;
        cout << "4. Dzielenie" << endl;
        cout << "Wybierz dzialanie matematyczne: ";
        cin >> dzialanie;
        if (dzialanie == 1)
        {
            float a{ 0 }, b{ 0 }, suma{ 0 };
            cout << "Podaj pierwsza liczbe: ";
            cin >> a;
            cout << "Podaj druga liczbe: ";
            cin >> b;
            suma = kalkulator.add(a, b);
            cout << "Wynik: " << suma << endl;
        }
        else if (dzialanie == 2)
        {
            float a{ 0 }, b{ 0 }, roznica{ 0 };
            cout << "Podaj pierwsza liczbe: ";
            cin >> a;
            cout << "Podaj druga liczbe: ";
            cin >> b;
            roznica = kalkulator.subtract(a, b);
            cout << "Wynik: " << roznica << endl;
        }
        else if (dzialanie == 3)
        {
            float a{ 0 }, b{ 0 }, iloczyn{ 0 };
            cout << "Podaj pierwsza liczbe: ";
            cin >> a;
            cout << "Podaj druga liczbe: ";
            cin >> b;
            iloczyn = kalkulator.multiply(a, b);
            cout << "Wynik: " << iloczyn << endl;
        }
        else if (dzialanie == 4)
        {
            float a{ 0 }, b{ 0 }, iloraz{ 0 };
            cout << "Podaj pierwsza liczbe: ";
            cin >> a;
            cout << "Podaj druga liczbe: ";
            cin >> b;
            iloraz = kalkulator.divide(a, b);
            cout << "Wynik: " << iloraz << endl;
        }
        else
        {
            cout << "Nieprawidlowy wybor!" << endl;
        }

    }
    else if (funkcjonalnosc == 2)
    {
        int system1{ 0 }, system2{ 0 };
        cout << "Dostepne systemy liczbowe: " << endl;
        cout << "1. Dziesietny" << endl;
        cout << "2. Dwojkowy" << endl;
        cout << "3. Osemkowy" << endl;
        cout << "4. Szesnastkowy" << endl;
        cout << "Podaj system liczbowy przed zamiana: ";
        cin >> system1;
        cout << "Podaj system liczbowy po zamianie: ";
        cin >> system2;
        if (system1 == system2)
        {
            cout << "Nie wybrano roznych systemow liczbowych!" << endl;
        }
        else if ((system1 == 1) && (system2 == 2))
        {
            int liczba{ 0 }, wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.DecToBinary(liczba);
            cout << "Liczba w systemie dwojkowym: " << wynik << endl;
        }
        else if ((system1 == 1) && (system2 == 3))
        {
            int liczba{ 0 }, wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.DecToOct(liczba);
            cout << "Liczba w systemie osemkowym: " << wynik << endl;
        }
        else if ((system1 == 1) && (system2 == 4))
        {
            int liczba{ 0 };
            string wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.DecToHex(liczba);
            cout << "Liczba w systemie szesnastkowym: " << wynik << endl;
        }
        else if ((system1 == 2) && (system2 == 1))
        {
            int liczba{ 0 }, wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.BinToDec(liczba);
            cout << "Liczba w systemie dziesietnym: " << wynik << endl;
        }
        else if ((system1 == 2) && (system2 == 3))
        {
            int liczba{ 0 }, wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.DecToOct(kalkulator.BinToDec(liczba));
            cout << "Liczba w systemie osemkowym: " << wynik << endl;
        }
        else if ((system1 == 2) && (system2 == 4))
        {
            int liczba{ 0 };
            string wynik{ "" };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.DecToHex(kalkulator.BinToDec(liczba));
            cout << "Liczba w systemie szesnastkowym: " << wynik << endl;
        }
        else if ((system1 == 3) && (system2 == 1))
        {
            int liczba{ 0 }, wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.OctToDec(liczba);
            cout << "Liczba w systemie dziesietnym: " << wynik << endl;
        }
        else if ((system1 == 3) && (system2 == 2))
        {
            int liczba{ 0 }, wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.DecToBinary(kalkulator.OctToDec(liczba));
            cout << "Liczba w systemie dwojkowym: " << wynik << endl;
        }
        else if ((system1 == 3) && (system2 == 4))
        {
            int liczba{ 0 };
            string wynik{ "" };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.DecToHex(kalkulator.OctToDec(liczba));
            cout << "Liczba w systemie szesnastkowym: " << wynik << endl;
        }
        else if ((system1 == 4) && (system2 == 1))
        {
            string liczba{ "" };
            int wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.HexToDec(liczba);
            cout << "Liczba w systemie dziesietnym: " << wynik << endl;
        }
        else if ((system1 == 4) && (system2 == 2))
        {
            string liczba{ "" };
            int wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.DecToBinary(kalkulator.HexToDec(liczba));
            cout << "Liczba w systemie dwojkowym: " << wynik << endl;
        }
        else if ((system1 == 4) && (system2 == 3))
        {
            string liczba{ "" };
            int wynik{ 0 };
            cout << "Podaj liczbe: " << endl;
            cin >> liczba;
            wynik = kalkulator.DecToOct(kalkulator.HexToDec(liczba));
            cout << "Liczba w systemie osemkowym: " << wynik << endl;
        }
    }
    else
    {
        cout << "Nieprawidlowy wybor!" << endl;
    }
    
}
