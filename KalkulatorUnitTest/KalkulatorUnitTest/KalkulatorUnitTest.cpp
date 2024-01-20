
#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <random>

using std::cout, std::cin, std::endl, std::numeric_limits, std::vector, std::string;

class calculator
{
    int vector_int_to_dec_int(vector<int> wektor)
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
    int DecToBinary(int decimal)       //wzorowano siê na kodzie ze strony: https://www.geeksforgeeks.org/program-decimal-binary-conversion/
    {                                          //funkcja zamieniaj¹ca lczbê z systemu dziesiêtnego na system binarny
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

bool Kalkulator_Unit_Test(const int kFrom = 0, const int kTo = 1023, const int kAmountOfRandomNumbers = 100)
{
    vector<int>wektor_bin;
    vector<int>wektor_oct;
    vector<int>wektor_hex;
    vector<bool>w_bin;
    vector<bool>w_oct;
    vector<bool>w_hex;

    std::random_device rd;                      //kod do generowania wektora wartoœci losowych pochodzi z ksi¹¿ki "Programowanie
    std::mt19937 mtRandomEngine(rd());          //w jêzyku C++ wprowadzenie dla in¿ynierów" autorstwa prof. dr hab. in¿. Bogus³awa Cyganka
    std::uniform_int_distribution uni_distr(kFrom, kTo);
    vector<int>random_decimals;
    std::generate_n(back_inserter(random_decimals), kAmountOfRandomNumbers, [&]() {return uni_distr(mtRandomEngine);});


    for (int i = 0; i < kAmountOfRandomNumbers; i++)
    {
        int random{ random_decimals[i] };
        int bin = kalkulator.BinToDec(kalkulator.DecToBinary(random));
        int oct = kalkulator.OctToDec(kalkulator.DecToOct(random));
        int hex = kalkulator.HexToDec(kalkulator.DecToHex(random));
        wektor_bin.push_back(bin);
        wektor_oct.push_back(oct);
        wektor_hex.push_back(hex);
        if (random == bin)
        {
            w_bin.push_back(true);
        }
        if (random == oct)
        {
            w_oct.push_back(true);
        }
        if (random == hex)
        {
            w_hex.push_back(true);
        }
    }
    if ((w_bin.size() == w_oct.size())&&(w_oct.size() == w_hex.size())&&(w_hex.size() == kAmountOfRandomNumbers))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    bool result = Kalkulator_Unit_Test();
}
