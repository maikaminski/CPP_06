#include "Base.hpp"

int main(void)
{
    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < 5; i++)
    {
        Base* p = generate();

        std::cout << "Pointer  identify: ";
        identify(p);

        std::cout << "Reference identify: ";
        identify(*p);

        delete p;
        std::cout << "---" << std::endl;
    }
    return 0;
}
