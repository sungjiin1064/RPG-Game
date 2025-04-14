#include <iostream>

int main()
{
	char name[20];

	std::cout << "이름을 입력해주세요." << std::endl;
	std::cin >> name;
	std::cout << "케릭터의 이름 : " << name <<std::endl;
}