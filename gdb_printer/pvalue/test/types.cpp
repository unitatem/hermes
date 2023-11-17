#include <optional>

struct Foo {
    int a;
};

struct Bar {
    Foo b;
};

Bar theBar{Foo{2}};

std::optional<int> theOptionalNotSet{};
std::optional<int> theOptionalSetTo10{10};

int main() {}
