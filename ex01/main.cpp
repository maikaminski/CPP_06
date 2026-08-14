#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.id    = 42;
    data.value = "hello";

    std::cout << "Original address : " << &data << std::endl;
    std::cout << "id               : " << data.id << std::endl;
    std::cout << "value            : " << data.value << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "\nSerialized (raw) : " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized addr: " << ptr << std::endl;
    std::cout << "Pointers match   : " << (ptr == &data ? "yes" : "no") << std::endl;
    std::cout << "id               : " << ptr->id << std::endl;
    std::cout << "value            : " << ptr->value << std::endl;

    return 0;
}
