struct Foo {
    int a;
};

struct Bar {
    Foo b;
};

[[maybe_unused]] static Bar theBar{Foo{2}};

int main() {}
