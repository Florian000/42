#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Test Data";

    std::cout << "Original Data:" << std::endl;
    std::cout << "ID: " << data.id << std::endl;
    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Address: " << &data << std::endl;
    std::cout << "------------------------" << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Value: " << raw << std::endl;
    std::cout << "------------------------" << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "ID: " << deserializedData->id << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "------------------------" << std::endl;

    if (&data == deserializedData)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;
    return 0;
}
