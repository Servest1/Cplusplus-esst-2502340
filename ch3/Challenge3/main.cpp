// C++ implementation​​​​​​‌‌​‌‌​​‌‌​‌‌​‌​​‌‌‌​‌​‌​‌ below
#include <iostream>
#include <memory>

struct SimpleNode {
  int mItem = 0;
  std::shared_ptr<SimpleNode> mNext = nullptr;
};

std::shared_ptr<SimpleNode> list = nullptr;

void addElement(const int value)
{
    auto CurrentPointer = std::shared_ptr<SimpleNode>(new SimpleNode);
    CurrentPointer->mItem = value;
    CurrentPointer->mNext = list;

    list = CurrentPointer;
	// TODO: Code that appends a value to the linked list 
}
void printList()
{
    auto CurrentPointer = list;
    while (CurrentPointer) {
        std::cout << CurrentPointer->mItem << std::endl;
        CurrentPointer = CurrentPointer->mNext;
    }
	// TODO: Print all the list items
}

int main() {
    addElement(12);
    addElement(22);
    addElement(342);
    addElement(145);

    printList();

    return 0;
}