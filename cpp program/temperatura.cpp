#include <iostream>

int main(int argc, char const *argv[])
{
    float temp;
    char tip;

    std::cout << "==========SISTEM DE COVERTIRE A TEMPERATURII==========" << std::endl;
    std::cout << "\nEnter temperatura si sistemul de masurare: \nC. Celsius \nF. Fahrenheit \nK. Kelvin " << std::endl;
    std::cout << "\nTemperatura: ";
    std::cin >> temp;
    std::cout << "Sistemul: ";
    std::cin >> tip;
    std::cout << std::endl;
    if (tip == 'c' || tip == 'C')
    {
        std::cout << "Fahrenheit: " << 9.0 / 5.0 * temp + 32 << std::endl;
        std::cout << "Kelvin: " << temp + 273.15;
    }
    else if (tip == 'f' || tip == 'F')
    {
        std::cout << "Celsius: " << 5.0 / 9.0 * (temp - 32) << std::endl;
        std::cout << "Kelvin: " << (temp + 459.67) * 5.0 / 9.0;
    }
    else if (tip == 'k' || tip == 'K')
    {
        std::cout << "Celsius: " << temp - 273.15 << std::endl;
        std::cout << "Fahrenheit: " << temp * 9.0 / 5.0 - 459.67;
    }

    return 0;
}
